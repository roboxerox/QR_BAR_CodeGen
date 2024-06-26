/**
* @file QR_BarCodeEncoderDecoder.h
* @author Anil Kumar
* @date 11Dec2021
* @brief This is header QR_BarCodeEncoderDecoder class.
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
#include "QZqrDecode.h"
#include <QFileDialog>
#include "QString"


#define SW_MAJOR_VER        1
#define SW_MINOR_VER        0
#define SW_BUILD_VER        3

extern QString BUILD_VER;

#define SOFTWARE_VERSION    QString::number(SW_MAJOR_VER)+"."+QString::number(SW_MINOR_VER)+"."+BUILD_VER


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
class QR_BarCodeEncoderDecoder;
}

class QR_BarCodeEncoderDecoder : public QMainWindow
{
    Q_OBJECT

public:
    explicit QR_BarCodeEncoderDecoder(QWidget *parent = 0);
    ~QR_BarCodeEncoderDecoder();
    bool m_CreateBarcode(QString str_Barcode, QString fileName);

private slots:
    void on_pushButton_Encode_clicked();

    void on_pushButton_about_clicked();

    void on_pushButton_Browse_clicked();

    void on_pushButton_Decode_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::QR_BarCodeEncoderDecoder *ui;
    QZqrDecode obj_qrdec;
    QString str_BrowsePath = QDir::homePath();
    QString str_selected_fileName = "";
    void m_decode_BarCode();
};

#endif // BARCODEENCODERDECODER_H
