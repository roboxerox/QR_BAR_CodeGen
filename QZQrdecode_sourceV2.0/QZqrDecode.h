#ifndef QZQRDECODE_H
#define QZQRDECODE_H

#include "QZqrDecode_global.h"
#include <QObject>
#include <QImage>

#if QT_VERSION >= 0x040700 && QT_VERSION < 0x050000
#include <QtDeclarative>
#elif QT_VERSION >= 0x050000
#include <QtQml/qqml.h>
#endif

// forward declaration
namespace zqrdecode {
class MultiFormatReader;
}
class ImageHandler;

/**
  * A class containing a very very small subset of the ZqrDecode library.
  * Created for ease of use.
  *
  * Anyone interested in using more technical stuff
  * from the ZqrDecode library is welcomed to add/edit on free will.
  *
  * Regarding DecoderFormat, by default all of those are enabled (except DataMatrix will is still not supported)
  */
class
#ifndef DISABLE_LIBRARY_FEATURES
    QZQRDECODESHARED_EXPORT
#endif
    QZqrDecode : public QObject {

    Q_OBJECT
    Q_ENUMS(DecoderFormat)
    Q_PROPERTY(int processingTime READ getProcessTimeOfLastDecoding)
    Q_PROPERTY(uint enabledDecoders READ getEnabledFormats WRITE setDecoder NOTIFY enabledFormatsChanged)

public:
    /*
     *
     */
    enum DecoderFormat {
        DecoderFormat_None = 0,
        DecoderFormat_Aztec = 1 << 1,
        DecoderFormat_CODABAR = 1 << 2,
        DecoderFormat_CODE_39 = 1 << 3,
        DecoderFormat_CODE_93 = 1 << 4,
        DecoderFormat_CODE_128 = 1 << 5,
        DecoderFormat_DATA_MATRIX = 1 << 6,
        DecoderFormat_EAN_8 = 1 << 7,
        DecoderFormat_EAN_13 = 1 << 8,
        DecoderFormat_ITF = 1 << 9,
        DecoderFormat_MAXICODE = 1 << 10,
        DecoderFormat_PDF_417 = 1 << 11,
        DecoderFormat_QR_CODE = 1 << 12,
        DecoderFormat_RSS_14 = 1 << 13,
        DecoderFormat_RSS_EXPANDED = 1 << 14,
        DecoderFormat_UPC_A = 1 << 15,
        DecoderFormat_UPC_E = 1 << 16,
        DecoderFormat_UPC_EAN_EXTENSION = 1 << 17
    } ;
    typedef unsigned int DecoderFormatType;

    QZqrDecode(QObject *parent = NULL);
    ~QZqrDecode();

    QZqrDecode(DecoderFormat decodeHints, QObject *parent = NULL);

#if QT_VERSION >= 0x040700
    static void registerQMLTypes()
    {
        qmlRegisterType<QZqrDecode>("QZqrDecode", 2, 3, "QZqrDecode");
    }
#endif

    QString decoderFormatToString(int fmt);
    QString foundedFormat() const;
    QString charSet() const;

public slots:
    /**
      * The decoding function. Will try to decode the given image based on the enabled decoders.
      * If the image width is larger than maxWidth or image height is larger
      * than maxHeight then the image will be scaled down. Either way, in case of scaling, the aspect
      * ratio of the image will be kept.
      *
      * The smoothTransformation flag determines whether the transformation will be smooth or fast.
      * Smooth transformation provides better results but fast transformation is...faster.
      */
    QString decodeImage(QImage &image, int maxWidth = -1, int maxHeight = -1, bool smoothTransformation = false);

    /**
      * The decoding function. Will try to decode the given image based on the enabled decoders.
      * The input image is read from a local image file.
      */
    QString decodeImageFromFile(const QString& imageFilePath, int maxWidth=-1, int maxHeight=-1, bool smoothTransformation = false);
    /**
     * The decoding function accessible from QML. (Suggested for Qt 4.x)
     */
    QString decodeImageQML(QObject *item);

    /**
     * The decoding function accessible from QML. Able to set the decoding
     * of a portion of the image. (Suggested for Qt 4.x)
     */
    QString decodeSubImageQML(QObject *item,
                              const double offsetX = 0 , const double offsetY = 0,
                              const double width = 0, const double height = 0);

    /**
     * The decoding function accessible from QML. (Suggested for Qt 5.x)
     * Can be used to decode image from the Camera element preview by providing
     * the following string: image://camera/preview_1
     */
    QString decodeImageQML(const QUrl &imageUrl);

    /**
     * The decoding function accessible from QML. Able to set the decoding
     * of a portion of the image.
     * Can be used to decode image from the Camera element preview by providing
     * the following string: image://camera/preview_1
     * (Suggested for Qt 5.x)
     */
    QString decodeSubImageQML(const QUrl &imageUrl,
                              const double offsetX = 0, const double offsetY = 0,
                              const double width = 0, const double height = 0);

    /**
      * Get the prossecing time in millisecond of the last decode operation.
      * Added mainly as a statistic measure.
      * Decoding operation fails, the processing time equals to -1.
      */
    int getProcessTimeOfLastDecoding();

    /**
      * Get the decoders that are enabled at the moment.
      * Returns a uint which is a bitwise OR of DecoderFormat enumeration values.
      */
    uint getEnabledFormats() const;
    /**
      * Set the enabled decoders.
      * As argument it is possible to pass conjuction of decoders by using logic OR.
      * e.x. setDecoder ( DecoderFormat_QR_CODE | DecoderFormat_EAN_13 | DecoderFormat_CODE_39 )
      */
    void setDecoder(const uint &hint);

signals:
    void decodingStarted();
    void decodingFinished(bool succeeded);
    void tagFound(QString tag);
    void enabledFormatsChanged();
    void tagFoundAdvanced(QString tag, QString format, QString charSet);
    void error(QString msg);

private:
    zqrdecode::MultiFormatReader *decoder;
    DecoderFormatType enabledDecoders;
    ImageHandler *imageHandler;
    int processingTime;
    QString foundedFmt;
    QString charSet_;

    /**
      * If true, the decoding operation will take place at a different thread.
      */
    bool isThreaded;
};

#endif // QZQRDECODE_H

