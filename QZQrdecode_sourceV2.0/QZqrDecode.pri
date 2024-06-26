QT       += core gui widgets

greaterThan(QT_VERSION, 4.7): lessThan(QT_VERSION, 5.0): QT += declarative
greaterThan(QT_MAJOR_VERSION, 4): QT += quick

DEFINES += QZQRDECODE_LIBRARY \
        ZQRDECODE_ICONV_CONST \
        DISABLE_LIBRARY_FEATURES
		 
INCLUDEPATH  += $$PWD \
                $$PWD/zqrdecode

HEADERS += $$PWD/QZqrDecode_global.h \
    $$PWD/CameraImageWrapper.h \
    $$PWD/imagehandler.h \
    $$PWD/QZqrDecode.h \
    $$PWD/zqrdecode/zqrdecode/ZQrdecode.h \
    $$PWD/zqrdecode/zqrdecode/IllegalStateException.h \
    $$PWD/zqrdecode/zqrdecode/InvertedLuminanceSource.h \
    $$PWD/zqrdecode/zqrdecode/ChecksumException.h \
    $$PWD/zqrdecode/zqrdecode/ResultPointCallback.h \
    $$PWD/zqrdecode/zqrdecode/ResultPoint.h \
    $$PWD/zqrdecode/zqrdecode/Result.h \
    $$PWD/zqrdecode/zqrdecode/ReaderException.h \
    $$PWD/zqrdecode/zqrdecode/Reader.h \
    $$PWD/zqrdecode/zqrdecode/NotFoundException.h \
    $$PWD/zqrdecode/zqrdecode/MultiFormatReader.h \
    $$PWD/zqrdecode/zqrdecode/LuminanceSource.h \
    $$PWD/zqrdecode/zqrdecode/FormatException.h \
    $$PWD/zqrdecode/zqrdecode/Exception.h \
    $$PWD/zqrdecode/zqrdecode/DecodeHints.h \
    $$PWD/zqrdecode/zqrdecode/BinaryBitmap.h \
    $$PWD/zqrdecode/zqrdecode/Binarizer.h \
    $$PWD/zqrdecode/zqrdecode/BarcodeFormat.h \
    $$PWD/zqrdecode/zqrdecode/aztec/AztecReader.h \
    $$PWD/zqrdecode/zqrdecode/aztec/AztecDetectorResult.h \
    $$PWD/zqrdecode/zqrdecode/aztec/decoder/Decoder.h \
    $$PWD/zqrdecode/zqrdecode/aztec/detector/Detector.h \
    $$PWD/zqrdecode/zqrdecode/common/StringUtils.h \
    $$PWD/zqrdecode/zqrdecode/common/Str.h \
    $$PWD/zqrdecode/zqrdecode/common/Point.h \
    $$PWD/zqrdecode/zqrdecode/common/PerspectiveTransform.h \
    $$PWD/zqrdecode/zqrdecode/common/IllegalArgumentException.h \
    $$PWD/zqrdecode/zqrdecode/common/HybridBinarizer.h \
    $$PWD/zqrdecode/zqrdecode/common/GridSampler.h \
    $$PWD/zqrdecode/zqrdecode/common/GreyscaleRotatedLuminanceSource.h \
    $$PWD/zqrdecode/zqrdecode/common/GreyscaleLuminanceSource.h \
    $$PWD/zqrdecode/zqrdecode/common/GlobalHistogramBinarizer.h \
    $$PWD/zqrdecode/zqrdecode/common/DetectorResult.h \
    $$PWD/zqrdecode/zqrdecode/common/DecoderResult.h \
    $$PWD/zqrdecode/zqrdecode/common/Counted.h \
    $$PWD/zqrdecode/zqrdecode/common/CharacterSetECI.h \
    $$PWD/zqrdecode/zqrdecode/common/BitSource.h \
    $$PWD/zqrdecode/zqrdecode/common/BitMatrix.h \
    $$PWD/zqrdecode/zqrdecode/common/BitArray.h \
    $$PWD/zqrdecode/zqrdecode/common/Array.h \
    $$PWD/zqrdecode/zqrdecode/common/detector/MathUtils.h \
    $$PWD/zqrdecode/zqrdecode/common/detector/JavaMath.h \
    $$PWD/zqrdecode/zqrdecode/common/detector/WhiteRectangleDetector.h \
    $$PWD/zqrdecode/zqrdecode/common/detector/MonochromeRectangleDetector.h \
    $$PWD/zqrdecode/zqrdecode/common/reedsolomon/ReedSolomonException.h \
    $$PWD/zqrdecode/zqrdecode/common/reedsolomon/ReedSolomonDecoder.h \
    $$PWD/zqrdecode/zqrdecode/common/reedsolomon/GenericGFPoly.h \
    $$PWD/zqrdecode/zqrdecode/common/reedsolomon/GenericGF.h \
    $$PWD/zqrdecode/zqrdecode/datamatrix/Version.h \
    $$PWD/zqrdecode/zqrdecode/datamatrix/DataMatrixReader.h \
    $$PWD/zqrdecode/zqrdecode/datamatrix/decoder/Decoder.h \
    $$PWD/zqrdecode/zqrdecode/datamatrix/decoder/DecodedBitStreamParser.h \
    $$PWD/zqrdecode/zqrdecode/datamatrix/decoder/DataBlock.h \
    $$PWD/zqrdecode/zqrdecode/datamatrix/decoder/BitMatrixParser.h \
    $$PWD/zqrdecode/zqrdecode/datamatrix/detector/DetectorException.h \
    $$PWD/zqrdecode/zqrdecode/datamatrix/detector/Detector.h \
    $$PWD/zqrdecode/zqrdecode/datamatrix/detector/CornerPoint.h \
    $$PWD/zqrdecode/zqrdecode/oned/UPCEReader.h \
    $$PWD/zqrdecode/zqrdecode/oned/UPCEANReader.h \
    $$PWD/zqrdecode/zqrdecode/oned/UPCAReader.h \
    $$PWD/zqrdecode/zqrdecode/oned/OneDResultPoint.h \
    $$PWD/zqrdecode/zqrdecode/oned/OneDReader.h \
    $$PWD/zqrdecode/zqrdecode/oned/MultiFormatUPCEANReader.h \
    $$PWD/zqrdecode/zqrdecode/oned/MultiFormatOneDReader.h \
    $$PWD/zqrdecode/zqrdecode/oned/ITFReader.h \
    $$PWD/zqrdecode/zqrdecode/oned/EAN13Reader.h \
    $$PWD/zqrdecode/zqrdecode/oned/EAN8Reader.h \
    $$PWD/zqrdecode/zqrdecode/oned/Code128Reader.h \
    $$PWD/zqrdecode/zqrdecode/oned/Code39Reader.h \
    $$PWD/zqrdecode/zqrdecode/oned/CodaBarReader.h \
    $$PWD/zqrdecode/zqrdecode/oned/Code93Reader.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/Version.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/QRCodeReader.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/FormatInformation.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/ErrorCorrectionLevel.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/decoder/Mode.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/decoder/Decoder.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/decoder/DecodedBitStreamParser.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/decoder/DataMask.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/decoder/DataBlock.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/decoder/BitMatrixParser.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/detector/FinderPatternInfo.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/detector/FinderPatternFinder.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/detector/FinderPattern.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/detector/Detector.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/detector/AlignmentPatternFinder.h \
    $$PWD/zqrdecode/zqrdecode/qrcode/detector/AlignmentPattern.h \
    $$PWD/zqrdecode/zqrdecode/multi/MultipleBarcodeReader.h \
    $$PWD/zqrdecode/zqrdecode/multi/GenericMultipleBarcodeReader.h \
    $$PWD/zqrdecode/zqrdecode/multi/ByQuadrantReader.h \
    $$PWD/zqrdecode/zqrdecode/multi/qrcode/QRCodeMultiReader.h \
    $$PWD/zqrdecode/zqrdecode/multi/qrcode/detector/MultiFinderPatternFinder.h \
    $$PWD/zqrdecode/zqrdecode/multi/qrcode/detector/MultiDetector.h \
    $$PWD/zqrdecode/zqrdecode/pdf417/decoder/ec/ErrorCorrection.h \
    $$PWD/zqrdecode/zqrdecode/pdf417/decoder/ec/ModulusGF.h \
    $$PWD/zqrdecode/zqrdecode/pdf417/decoder/ec/ModulusPoly.h \
    $$PWD/zqrdecode/zqrdecode/pdf417/decoder/BitMatrixParser.h \
    $$PWD/zqrdecode/zqrdecode/pdf417/decoder/DecodedBitStreamParser.h \
    $$PWD/zqrdecode/zqrdecode/pdf417/decoder/Decoder.h \
    $$PWD/zqrdecode/zqrdecode/pdf417/detector/Detector.h \
    $$PWD/zqrdecode/zqrdecode/pdf417/detector/LinesSampler.h \
    $$PWD/zqrdecode/zqrdecode/pdf417/PDF417Reader.h \
    $$PWD/zqrdecode/bigint/NumberlikeArray.hh \
    $$PWD/zqrdecode/bigint/BigUnsignedInABase.hh \
    $$PWD/zqrdecode/bigint/BigUnsigned.hh \
    $$PWD/zqrdecode/bigint/BigIntegerUtils.hh \
    $$PWD/zqrdecode/bigint/BigIntegerLibrary.hh \
    $$PWD/zqrdecode/bigint/BigIntegerAlgorithms.hh \
    $$PWD/zqrdecode/bigint/BigInteger.hh \
    $$PWD/zqrdecode/zqrdecode/WriterException.h

SOURCES += $$PWD/CameraImageWrapper.cpp \
    $$PWD/QZqrDecode.cpp \
    $$PWD/imagehandler.cpp \
    $$PWD/zqrdecode/zqrdecode/ResultIO.cpp \
    $$PWD/zqrdecode/zqrdecode/InvertedLuminanceSource.cpp \
    $$PWD/zqrdecode/zqrdecode/ChecksumException.cpp \
    $$PWD/zqrdecode/zqrdecode/ResultPointCallback.cpp \
    $$PWD/zqrdecode/zqrdecode/ResultPoint.cpp \
    $$PWD/zqrdecode/zqrdecode/Result.cpp \
    $$PWD/zqrdecode/zqrdecode/Reader.cpp \
    $$PWD/zqrdecode/zqrdecode/MultiFormatReader.cpp \
    $$PWD/zqrdecode/zqrdecode/LuminanceSource.cpp \
    $$PWD/zqrdecode/zqrdecode/FormatException.cpp \
    $$PWD/zqrdecode/zqrdecode/Exception.cpp \
    $$PWD/zqrdecode/zqrdecode/DecodeHints.cpp \
    $$PWD/zqrdecode/zqrdecode/BinaryBitmap.cpp \
    $$PWD/zqrdecode/zqrdecode/Binarizer.cpp \
    $$PWD/zqrdecode/zqrdecode/BarcodeFormat.cpp \
    $$PWD/zqrdecode/zqrdecode/aztec/AztecReader.cpp \
    $$PWD/zqrdecode/zqrdecode/aztec/AztecDetectorResult.cpp \
    $$PWD/zqrdecode/zqrdecode/common/StringUtils.cpp \
    $$PWD/zqrdecode/zqrdecode/common/Str.cpp \
    $$PWD/zqrdecode/zqrdecode/common/PerspectiveTransform.cpp \
    $$PWD/zqrdecode/zqrdecode/common/IllegalArgumentException.cpp \
    $$PWD/zqrdecode/zqrdecode/common/HybridBinarizer.cpp \
    $$PWD/zqrdecode/zqrdecode/common/GridSampler.cpp \
    $$PWD/zqrdecode/zqrdecode/common/GreyscaleRotatedLuminanceSource.cpp \
    $$PWD/zqrdecode/zqrdecode/common/GreyscaleLuminanceSource.cpp \
    $$PWD/zqrdecode/zqrdecode/common/GlobalHistogramBinarizer.cpp \
    $$PWD/zqrdecode/zqrdecode/common/DetectorResult.cpp \
    $$PWD/zqrdecode/zqrdecode/common/DecoderResult.cpp \
    $$PWD/zqrdecode/zqrdecode/common/CharacterSetECI.cpp \
    $$PWD/zqrdecode/zqrdecode/common/BitSource.cpp \
    $$PWD/zqrdecode/zqrdecode/common/BitMatrix.cpp \
    $$PWD/zqrdecode/zqrdecode/common/BitArray.cpp \
    $$PWD/zqrdecode/zqrdecode/common/BitArrayIO.cpp \
    $$PWD/zqrdecode/zqrdecode/common/detector/WhiteRectangleDetector.cpp \
    $$PWD/zqrdecode/zqrdecode/common/detector/MonochromeRectangleDetector.cpp \
    $$PWD/zqrdecode/zqrdecode/common/reedsolomon/ReedSolomonException.cpp \
    $$PWD/zqrdecode/zqrdecode/common/reedsolomon/ReedSolomonDecoder.cpp \
    $$PWD/zqrdecode/zqrdecode/common/reedsolomon/GenericGFPoly.cpp \
    $$PWD/zqrdecode/zqrdecode/common/reedsolomon/GenericGF.cpp \
    $$PWD/zqrdecode/zqrdecode/datamatrix/DataMatrixReader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/UPCEReader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/UPCEANReader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/UPCAReader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/OneDResultPoint.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/OneDReader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/MultiFormatUPCEANReader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/MultiFormatOneDReader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/ITFReader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/EAN13Reader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/EAN8Reader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/Code128Reader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/Code39Reader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/CodaBarReader.cpp \
    $$PWD/zqrdecode/zqrdecode/oned/Code93Reader.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/QRCodeReader.cpp \
    $$PWD/zqrdecode/zqrdecode/multi/MultipleBarcodeReader.cpp \
    $$PWD/zqrdecode/zqrdecode/multi/GenericMultipleBarcodeReader.cpp \
    $$PWD/zqrdecode/zqrdecode/multi/ByQuadrantReader.cpp \
    $$PWD/zqrdecode/zqrdecode/multi/qrcode/QRCodeMultiReader.cpp \
    $$PWD/zqrdecode/zqrdecode/multi/qrcode/detector/MultiFinderPatternFinder.cpp \
    $$PWD/zqrdecode/zqrdecode/multi/qrcode/detector/MultiDetector.cpp \
    $$PWD/zqrdecode/zqrdecode/aztec/decoder/AztecDecoder.cpp \
    $$PWD/zqrdecode/zqrdecode/aztec/detector/AztecDetector.cpp \
    $$PWD/zqrdecode/zqrdecode/datamatrix/DataMatrixVersion.cpp \
    $$PWD/zqrdecode/zqrdecode/datamatrix/decoder/DataMatrixDecoder.cpp \
    $$PWD/zqrdecode/zqrdecode/datamatrix/decoder/DataMatrixBitMatrixParser.cpp \
    $$PWD/zqrdecode/zqrdecode/datamatrix/decoder/DataMatrixDataBlock.cpp \
    $$PWD/zqrdecode/zqrdecode/datamatrix/decoder/DataMatrixDecodedBitStreamParser.cpp \
    $$PWD/zqrdecode/zqrdecode/datamatrix/detector/DataMatrixCornerPoint.cpp \
    $$PWD/zqrdecode/zqrdecode/datamatrix/detector/DataMatrixDetector.cpp \
    $$PWD/zqrdecode/zqrdecode/datamatrix/detector/DataMatrixDetectorException.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/decoder/QRBitMatrixParser.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/decoder/QRDataBlock.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/decoder/QRDataMask.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/decoder/QRDecodedBitStreamParser.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/decoder/QRDecoder.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/decoder/QRMode.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/detector/QRAlignmentPattern.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/detector/QRAlignmentPatternFinder.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/detector/QRDetector.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/detector/QRFinderPattern.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/detector/QRFinderPatternFinder.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/detector/QRFinderPatternInfo.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/QRVersion.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/QRFormatInformation.cpp \
    $$PWD/zqrdecode/zqrdecode/qrcode/QRErrorCorrectionLevel.cpp \
    $$PWD/zqrdecode/zqrdecode/pdf417/decoder/ec/ErrorCorrection.cpp \
    $$PWD/zqrdecode/zqrdecode/pdf417/decoder/ec/ModulusGF.cpp \
    $$PWD/zqrdecode/zqrdecode/pdf417/decoder/ec/ModulusPoly.cpp \
    $$PWD/zqrdecode/zqrdecode/pdf417/decoder/PDF417BitMatrixParser.cpp \
    $$PWD/zqrdecode/zqrdecode/pdf417/decoder/PDF417DecodedBitStreamParser.cpp \
    $$PWD/zqrdecode/zqrdecode/pdf417/decoder/PDF417Decoder.cpp \
    $$PWD/zqrdecode/zqrdecode/pdf417/detector/PDF417Detector.cpp \
    $$PWD/zqrdecode/zqrdecode/pdf417/detector/LinesSampler.cpp \
    $$PWD/zqrdecode/zqrdecode/pdf417/PDF417Reader.cpp \
    $$PWD/zqrdecode/bigint/BigUnsignedInABase.cc \
    $$PWD/zqrdecode/bigint/BigUnsigned.cc \
    $$PWD/zqrdecode/bigint/BigIntegerUtils.cc \
    $$PWD/zqrdecode/bigint/BigIntegerAlgorithms.cc \
    $$PWD/zqrdecode/bigint/BigInteger.cc

symbian {
    TARGET.UID3 = 0xE618743C
    TARGET.EPOCALLOWDLLDATA = 1

    #TARGET.CAPABILITY = All -TCB -AllFiles -DRM
    TARGET.CAPABILITY += NetworkServices \
        ReadUserData \
        WriteUserData \
        LocalServices \
        UserEnvironment \
        Location
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }

    DEFINES += NOFMAXL
    INSTALLS += target
}

win32-msvc*{

    INCLUDEPATH += $$PWD/zqrdecode/win32/zqrdecode \
                    $$PWD/zqrdecode/win32/zqrdecode/msvc
    HEADERS += $$PWD/zqrdecode/win32/zqrdecode/msvc/stdint.h \
                $$PWD/zqrdecode/win32/zqrdecode/iconv.h

    SOURCES += $$PWD/zqrdecode/win32/zqrdecode/win_iconv.c
}

win32-g++{

    INCLUDEPATH += $$PWD/zqrdecode/win32/zqrdecode

    HEADERS += $$PWD/zqrdecode/win32/zqrdecode/iconv.h

    SOURCES += $$PWD/zqrdecode/win32/zqrdecode/win_iconv.c
}

!win32{
    DEFINES += NO_ICONV
}
winrt {
    DEFINES += NO_ICONV
}
