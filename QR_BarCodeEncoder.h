/**
* @file QR_BarCodeEncoder.h
* @author Anil Kumar
* @date 11Dec2021
* @brief This is header QR_BarCodeEncoder class.
* It generate BAR code using code128 [https://github.com/fhunleth/code128]
* It generate QR code using qrcodegen [https://github.com/nayuki/QR-Code-generator/tree/master/cpp]
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

#include "qrcodegen.h"

using qrcodegen::QrCode;
using qrcodegen::QrSegment;

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

private:
    Ui::QR_BarCodeEncoder *ui;
};

#endif // BARCODEENCODERDECODER_H
