/**
* @file QR_BarCodeEncoder.h
* @author Anil Kumar
* @date 11Dec2021
* @brief This is header QR_BarCodeEncoder class.
*/
#ifndef BARCODEENCODERDECODER_H
#define BARCODEENCODERDECODER_H

#include <QMainWindow>
#include "code128.h"
#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <string.h> // needed for memset()
#include <png.h>
#include <QMessageBox>
#include <QPixmap>
#include <QBitmap>
#include <QDir>
#include <QFile>
#include <QDateTime>
#include <QDebug>
#include "qrcodegen.h"
#include "QZXing.h"
#include <QFileDialog>


#define SW_MAJOR_VER        QString("1")
#define SW_MINOR_VER        QString("0")
#define SW_BUILD_VER        QString("3")

#define SOFTWARE_VERSION    QString(SW_MAJOR_VER+"."+SW_MINOR_VER+"."+SW_BUILD_VER)


using qrcodegen::QrCode;
using qrcodegen::QrSegment;

namespace IMG_FORMAT {
enum
{
    PNG,
    JPG
};
}

namespace CODE_TYPE {
enum
{
    BAR,
    QR
};
}


namespace Ui {
class QR_BarCodeEncoder;
}

class QR_BarCodeEncoder : public QMainWindow
{
    Q_OBJECT

public:
    explicit QR_BarCodeEncoder(QWidget *parent = 0);
    ~QR_BarCodeEncoder();
    void m_CreateBarcode(QString str_Barcode, QString fileName);

private slots:
    void on_pushButton_Encode_clicked();

    void on_pushButton_about_clicked();

    void on_pushButton_Browse_clicked();

    void on_pushButton_Decode_clicked();

private:
    Ui::QR_BarCodeEncoder *ui;
    QZXing obj_zxing;
    QString str_selected_fileName = "";
    void m_decode_BarCode();
};

#endif // BARCODEENCODERDECODER_H
