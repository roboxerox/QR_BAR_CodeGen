/**
* @file BarCodeEncoderDecoder.cpp
* @author Anil Kumar
* @date 11Dec2021
* @brief This is BarCodeEncoderDecoder class.
*/
#include "BarCodeEncoderDecoder.h"
#include "ui_BarCodeEncoderDecoder.h"

BarCodeEncoderDecoder::BarCodeEncoderDecoder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BarCodeEncoderDecoder)
{
    ui->setupUi(this);
}

BarCodeEncoderDecoder::~BarCodeEncoderDecoder()
{
    delete ui;
}

static void png_error_callback(png_structp png_ptr, const char *msg)
{
    (void) png_ptr;
//    errx(EXIT_FAILURE, "libpng: %s", msg);
    QMessageBox::warning(0,"libpng",msg);

}

static void png_warning_callback(png_structp png_ptr, const char *msg)
{
    (void) png_ptr;
//    warnx("libpng: %s", msg);
    QMessageBox::warning(0,"libpng",msg);
}

void BarCodeEncoderDecoder::m_CreateBarcode(QString str_Barcode, QString fileName)
{
    char out[4096];
    int width;
    int height = 40;



    const char *str = str_Barcode.toLatin1();
    width = code128_estimate_len(str);
    width = code128_encode_gs1(str, out, width);

    if (width == 0)
        QMessageBox::warning(this,"Invalid error","Invalid characters in string");


    FILE *fp = fopen(fileName.toLatin1(), "wb");
    if (!fp)
        QMessageBox::warning(this,"File error","can't open output");

    png_structp png_ptr = png_create_write_struct
            (PNG_LIBPNG_VER_STRING, NULL,
             png_error_callback, png_warning_callback);
    if (!png_ptr)
        QMessageBox::warning(this,"PNG error","png_create_write_struct");

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
        png_destroy_write_struct(&png_ptr,
                                 (png_infopp)NULL);
        QMessageBox::warning(this,"PNG error","png_create_info_struct");
    }

    if (setjmp(png_jmpbuf(png_ptr)))
    {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        QMessageBox::warning(this,"lib error","libpng error");
    }

    png_init_io(png_ptr, fp);

    png_set_IHDR(png_ptr, info_ptr, width, height,
                 1, PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    png_text note;
    memset(&note, 0, sizeof(note));
    note.compression = PNG_TEXT_COMPRESSION_NONE;
    note.key = "gs1-128";
    note.text = fileName.toLatin1().data();
    note.text_length = strlen(fileName.toLatin1().data());

    png_set_text(png_ptr, info_ptr, &note, 1);
    png_write_info(png_ptr, info_ptr);
    png_set_packing(png_ptr);
    png_set_invert_mono(png_ptr);

    png_byte *row_pointers[height];
    int i;
    for (i = 0; i < height; i++)
        row_pointers[i] = (png_byte*) out;
    png_write_image(png_ptr, row_pointers);
    png_write_end(png_ptr, info_ptr);
    png_destroy_write_struct(&png_ptr, &info_ptr);

    fclose(fp);
}

void BarCodeEncoderDecoder::on_pushButton_Encode_clicked()
{
    if(ui->lineEdit->text()!="")
    {
        /////// BAR CODE
        QString outFile = "/tmp/b1.png";
        m_CreateBarcode(ui->lineEdit->text(),outFile);
        QPixmap pixmap;
        if(pixmap.load(outFile)){
            /** scale pixmap to fit in label'size and keep ratio of pixmap */
            pixmap = pixmap.scaled(ui->label_BarCode->size(),Qt::KeepAspectRatio);
            ui->label_BarCode->setPixmap(pixmap);
        }
        ui->label_Str->setText(ui->lineEdit->text());


        /////// QR CODE
        using namespace qrcodegen;
        // Create the QR Code object
        QrCode qr = QrCode::encodeText( ui->lineEdit->text().toUtf8().data(), QrCode::Ecc::MEDIUM );
        qint32 sz = qr.getSize();
        QImage im(sz,sz, QImage::Format_RGB32);
        QRgb black = qRgb(  0,  0,  0);
        QRgb white = qRgb(255,255,255);
        for (int y = 0; y < sz; y++)
            for (int x = 0; x < sz; x++)
                im.setPixel(x,y,qr.getModule(x, y) ? black : white );
        ui->label_QrCode->setPixmap( QPixmap::fromImage(im.scaled(256,256,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );
    }
    else
        QMessageBox::warning(this,"Text error", "Code text not found.");

}
