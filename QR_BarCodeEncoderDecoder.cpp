/**
* @file QR_BarCodeEncoderDecoder.cpp
* @author Anil Kumar
* @date 11Dec2021
* @brief This is QR_BarCodeEncoderDecoder class and main window of UI.
* It generate BAR code using code128.
* It generate QR code using qrcodegen.
* Its also decode QR Code
*/

#include "QR_BarCodeEncoderDecoder.h"
#include "ui_QR_BarCodeEncoderDecoder.h"

/**
 * @brief QR_BarCodeEncoderDecoder::QR_BarCodeEncoderDecoder
 * @param parent
 */
QR_BarCodeEncoderDecoder::QR_BarCodeEncoderDecoder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QR_BarCodeEncoderDecoder)
{
    ui->setupUi(this);
    ui->widget_Barcode->hide();
    ui->widget_QrCode->hide();
    ui->label_version->setText(SOFTWARE_VERSION);

    ui->statusBar->setStyleSheet("background-color: none;color: rgb(52, 101, 164);");

    ui->tabWidget->setCurrentIndex(0);
}

/**
 * @brief QR_BarCodeEncoderDecoder::~QR_BarCodeEncoderDecoder
 */
QR_BarCodeEncoderDecoder::~QR_BarCodeEncoderDecoder()
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
 * @brief QR_BarCodeEncoderDecoder::m_CreateBarcode
 * @param str_Barcode   Bar Code String
 * @param fileName      File name String
 * This method create Bar code and save that as image fileName+str_Barcode
 */
void QR_BarCodeEncoderDecoder::m_CreateBarcode(QString str_Barcode, QString fileName)
{
    char out[4096];
    int width;
    int height = 40;

    const char *str = str_Barcode.toLatin1();
    width = code128_estimate_len(str);
    width = code128_encode_gs1(str, out, width);

    if (width == 0)
        QMessageBox::warning(0,"Invalid error","Invalid characters in string");


    FILE *fp = fopen(fileName.toLatin1(), "wb");
    if (!fp)
        QMessageBox::warning(this,"File error","can't open output");

    png_structp png_ptr = png_create_write_struct
            (PNG_LIBPNG_VER_STRING, NULL,
             png_error_callback, png_warning_callback);
    if (!png_ptr)
        QMessageBox::warning(0,"PNG error","png_create_write_struct");

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
        png_destroy_write_struct(&png_ptr,
                                 (png_infopp)NULL);
        QMessageBox::warning(0,"PNG error","png_create_info_struct");
    }

    if (setjmp(png_jmpbuf(png_ptr)))
    {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        QMessageBox::warning(0,"lib error","libpng error");
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
 * @brief QR_BarCodeEncoderDecoder::on_pushButton_Encode_clicked
 * This slot call method m_CreateBarcode and QrCode as per selected type
 */
void QR_BarCodeEncoderDecoder::on_pushButton_Encode_clicked()
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
        QString strInputString = ui->lineEdit->text();
        if(ui->comboBox_code_type->currentIndex() == CODE_TYPE::BAR)
        {
//            if(strInputString.contains('/'))
//                return ;
            ui->widget_Barcode->show();
            ui->widget_QrCode->hide();
            /////// BAR CODE
            QString outFile = str_Barcodes+QDir::separator()+str_timestamp+"barcode-"+strInputString+".png";
            m_CreateBarcode(strInputString,outFile);
            QPixmap pixmap;
            if(pixmap.load(outFile))
            {
                /** scale pixmap to fit in label'size and keep ratio of pixmap */
                pixmap = pixmap.scaled(ui->label_BarCode->size(),Qt::KeepAspectRatio);
                ui->label_BarCode->setPixmap(pixmap);
            }
            ui->label_BarStr->setText(strInputString);
        }
        else
        {
            ui->widget_Barcode->hide();
            ui->widget_QrCode->show();

            /////// QR CODE
            using namespace qrcodegen;
            // Create the QR Code object
            QrCode qr = QrCode::encodeText( strInputString.toUtf8().data(), QrCode::Ecc::MEDIUM );
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
                qrPix.scaled(512,512,Qt::KeepAspectRatio,Qt::FastTransformation).save(str_QRcodes+QDir::separator()+str_timestamp+"qrcode-"+strInputString+".png","PNG");
                break;
            case IMG_FORMAT::JPG:
                qrPix.scaled(512,512,Qt::KeepAspectRatio,Qt::FastTransformation).save(str_QRcodes+QDir::separator()+str_timestamp+"qrcode-"+strInputString+".jpg","JPG");
                break;
            default:
                break;
            }
            ui->label_QrStr->setText(strInputString);

        }

        ui->statusBar->showMessage("ID : "+str_timestamp.mid(0,str_timestamp.size()-1),5000);

    }
    else
        QMessageBox::warning(this,"Text error", "Code text not found.");

}

/**
 * @brief QR_BarCodeEncoderDecoder::on_pushButton_about_clicked
 * This slot show About us popup MessageBox
 */
void QR_BarCodeEncoderDecoder::on_pushButton_about_clicked()
{
    QMessageBox *msg = new QMessageBox(this);
    msg->setStyleSheet("background-color: none; color: rgb(52, 101, 164);");
    msg->setIconPixmap(QPixmap(":/images/main.png").scaled(60,60,Qt::IgnoreAspectRatio));
    msg->setText("QR/BAR Code Encoder\nVersion : "+SOFTWARE_VERSION+"\nDescription: This is a example of Bar code & QR Code Generator as will as Decoder\n\n\
Copyright 2020-2025 The Xerox Robo Tech Pvt. Ltd.\nAll rights reserved.");
    msg->setStandardButtons(QMessageBox::Ok);
    msg->show();

}

/**
 * @brief QR_BarCodeEncoderDecoder::on_pushButton_Browse_clicked
 */
void QR_BarCodeEncoderDecoder::on_pushButton_Browse_clicked()
{
    ui->label_selected_img->clear();
    ui->plainTextEdit_decoded->clear();
    str_selected_fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), str_BrowsePath, tr("Image Files (*.png *.jpg)"));

    //qDebug()<<"Selected File : "<<str_selected_fileName;

    QFile checkFile(str_selected_fileName);

    if(!checkFile.exists())
        QMessageBox::warning(0,"Not Found","Selected file is not exists .");
    else
    {
        QString tmpFile = str_selected_fileName;
        QString basename = QUrl(tmpFile).fileName();
        ui->label_imgPath->setText(basename);
        str_BrowsePath = tmpFile.remove(basename);
    }
}

/**
 * @brief QR_BarCodeEncoderDecoder::on_pushButton_Decode_clicked
 */
void QR_BarCodeEncoderDecoder::on_pushButton_Decode_clicked()
{
    QFile checkFile(str_selected_fileName);

    if(!checkFile.exists())
    {
        QMessageBox::warning(0,"Not Found","Selected file is not exists .");
        return;
    }

    obj_qrdec.setDecoder( QZqrDecode::DecoderFormat_QR_CODE );

    ui->label_selected_img->setPixmap( QPixmap( str_selected_fileName ) );

    m_decode_BarCode();
}

/**
 * @brief QR_BarCodeEncoderDecoder::m_decode_BarCode
 */
void QR_BarCodeEncoderDecoder::m_decode_BarCode()
{
    QImage qrImage = ui->label_selected_img->pixmap()->toImage();
    const QString & decodeText = obj_qrdec.decodeImage( qrImage );

    ui->plainTextEdit_decoded->setPlainText(decodeText);
}

/**
 * @brief QR_BarCodeEncoderDecoder::on_tabWidget_currentChanged
 * @param index
 */
void QR_BarCodeEncoderDecoder::on_tabWidget_currentChanged(int index)
{
    if(!index)
    {
        ui->label_selected_img->clear();
        ui->plainTextEdit_decoded->clear();
        ui->label_imgPath->setText("....");
    }
    else if(index)
    {
        //ui->widget_Barcode->hide();
        //ui->widget_QrCode->hide();
    }
}
