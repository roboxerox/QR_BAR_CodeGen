/**
* @file QR_BarCodeEncoder.cpp
* @author Anil Kumar
* @date 11Dec2021
* @brief This is QR_BarCodeEncoder class and main window of UI.
* It generate BAR code using code128.
* It generate QR code using qrcodegen.
*/

#include "QR_BarCodeEncoder.h"
#include "ui_QR_BarCodeEncoder.h"

/**
 * @brief QR_BarCodeEncoder::QR_BarCodeEncoder
 * @param parent
 */
QR_BarCodeEncoder::QR_BarCodeEncoder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QR_BarCodeEncoder)
{
    ui->setupUi(this);
    ui->widget_Barcode->hide();
    ui->label_QrCode->hide();
    ui->label_version->setText(SOFTWARE_VERSION);
}

/**
 * @brief QR_BarCodeEncoder::~QR_BarCodeEncoder
 */
QR_BarCodeEncoder::~QR_BarCodeEncoder()
{
    delete ui;
}

/**
 * @brief png_error_callback
 * @param png_ptr
 * @param msg
 */
static void png_error_callback(png_structp png_ptr, const char *msg)
{
    (void) png_ptr;
//    errx(EXIT_FAILURE, "libpng: %s", msg);
    QMessageBox::warning(0,"libpng",msg);

}

/**
 * @brief png_warning_callback
 * @param png_ptr
 * @param msg
 */
static void png_warning_callback(png_structp png_ptr, const char *msg)
{
    (void) png_ptr;
//    warnx("libpng: %s", msg);
    QMessageBox::warning(0,"libpng",msg);
}

/**
 * @brief QR_BarCodeEncoder::m_CreateBarcode
 * @param str_Barcode
 * @param fileName
 */
void QR_BarCodeEncoder::m_CreateBarcode(QString str_Barcode, QString fileName)
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


/**
 * @brief QR_BarCodeEncoder::on_pushButton_Encode_clicked
 */
void QR_BarCodeEncoder::on_pushButton_Encode_clicked()
{
    QString str_Barcodes = QDir::currentPath()+QDir::separator()+"bar_codes";
    QString str_QRcodes = QDir::currentPath()+QDir::separator()+"qr_codes";

    QDir dir;
    bool bcode = dir.mkpath(str_Barcodes);
    bool qcode = dir.mkpath(str_QRcodes);

    if(!bcode || !qcode )
    {
        QMessageBox::warning(this,"Not created","Dir not created.");
        return;
    }

    QString str_timestamp = QString::number(QDateTime::currentSecsSinceEpoch())+"_";


    if(ui->lineEdit->text()!="")
    {
        if(ui->comboBox_code_type->currentIndex() == CODE_TYPE::BAR)
        {
//            if(ui->lineEdit->text().contains('/'))
//                return ;
            ui->widget_Barcode->show();
            ui->label_QrCode->hide();
            /////// BAR CODE
            QString outFile = str_Barcodes+QDir::separator()+str_timestamp+"barcode.png";
            m_CreateBarcode(ui->lineEdit->text(),outFile);
            QPixmap pixmap;
            if(pixmap.load(outFile))
            {
                /** scale pixmap to fit in label'size and keep ratio of pixmap */
                pixmap = pixmap.scaled(ui->label_BarCode->size(),Qt::KeepAspectRatio);
                ui->label_BarCode->setPixmap(pixmap);
            }
            ui->label_Str->setText(ui->lineEdit->text());
        }
        else
        {
            ui->widget_Barcode->hide();
            ui->label_QrCode->show();

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

            QPixmap qrPix(QPixmap::fromImage(im.scaled(300,300,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly));
            ui->label_QrCode->setPixmap( qrPix );
            switch (ui->comboBox_image_type->currentIndex())
            {
            case IMG_FORMAT::PNG:
                qrPix.scaled(512,512,Qt::KeepAspectRatio,Qt::FastTransformation).save(str_QRcodes+QDir::separator()+str_timestamp+"qrcode.png","PNG");
                break;
            case IMG_FORMAT::JPG:
                qrPix.scaled(512,512,Qt::KeepAspectRatio,Qt::FastTransformation).save(str_QRcodes+QDir::separator()+str_timestamp+"qrcode.jpg","JPG");
                break;
            default:
                break;
            }
        }

        ui->statusBar->showMessage("ID : "+str_timestamp.mid(0,str_timestamp.size()-1),3000);

    }
    else
        QMessageBox::warning(this,"Text error", "Code text not found.");

}
