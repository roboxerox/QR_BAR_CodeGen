cmake_minimum_required(VERSION 3.9)

project(QZqrDecode VERSION 1.0.1 DESCRIPTION "QZqrDecode QR decoder")

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Qt5Core REQUIRED)

set_property(SOURCE zqrdecode/bigint/BigIntegerUtils.hh PROPERTY SKIP_AUTOGEN ON)
set_property(SOURCE zqrdecode/bigint/BigInteger.hh PROPERTY SKIP_AUTOGEN ON)
set_property(SOURCE zqrdecode/bigint/BigUnsigned.hh PROPERTY SKIP_AUTOGEN ON)
set_property(SOURCE zqrdecode/bigint/BigUnsignedInABase.hh PROPERTY SKIP_AUTOGEN ON)
set_property(SOURCE zqrdecode/bigint/BigIntegerAlgorithms.hh PROPERTY SKIP_AUTOGEN ON)

set (SRC_FILES
	CameraImageWrapper.cpp 
    QZqrDecode.cpp 
    imagehandler.cpp 
    zqrdecode/zqrdecode/ResultIO.cpp 
    zqrdecode/zqrdecode/InvertedLuminanceSource.cpp 
    zqrdecode/zqrdecode/ChecksumException.cpp 
    zqrdecode/zqrdecode/ResultPointCallback.cpp 
    zqrdecode/zqrdecode/ResultPoint.cpp 
    zqrdecode/zqrdecode/Result.cpp 
    zqrdecode/zqrdecode/Reader.cpp 
    zqrdecode/zqrdecode/MultiFormatReader.cpp 
    zqrdecode/zqrdecode/LuminanceSource.cpp 
    zqrdecode/zqrdecode/FormatException.cpp 
    zqrdecode/zqrdecode/Exception.cpp 
    zqrdecode/zqrdecode/DecodeHints.cpp 
    zqrdecode/zqrdecode/BinaryBitmap.cpp 
    zqrdecode/zqrdecode/Binarizer.cpp 
    zqrdecode/zqrdecode/BarcodeFormat.cpp 
    zqrdecode/zqrdecode/aztec/AztecReader.cpp 
    zqrdecode/zqrdecode/aztec/AztecDetectorResult.cpp 
    zqrdecode/zqrdecode/common/StringUtils.cpp 
    zqrdecode/zqrdecode/common/Str.cpp 
    zqrdecode/zqrdecode/common/PerspectiveTransform.cpp 
    zqrdecode/zqrdecode/common/IllegalArgumentException.cpp 
    zqrdecode/zqrdecode/common/HybridBinarizer.cpp 
    zqrdecode/zqrdecode/common/GridSampler.cpp 
    zqrdecode/zqrdecode/common/GreyscaleRotatedLuminanceSource.cpp 
    zqrdecode/zqrdecode/common/GreyscaleLuminanceSource.cpp 
    zqrdecode/zqrdecode/common/GlobalHistogramBinarizer.cpp 
    zqrdecode/zqrdecode/common/DetectorResult.cpp 
    zqrdecode/zqrdecode/common/DecoderResult.cpp 
    zqrdecode/zqrdecode/common/CharacterSetECI.cpp 
    zqrdecode/zqrdecode/common/BitSource.cpp 
    zqrdecode/zqrdecode/common/BitMatrix.cpp 
    zqrdecode/zqrdecode/common/BitArray.cpp 
    zqrdecode/zqrdecode/common/BitArrayIO.cpp 
    zqrdecode/zqrdecode/common/detector/WhiteRectangleDetector.cpp 
    zqrdecode/zqrdecode/common/detector/MonochromeRectangleDetector.cpp 
    zqrdecode/zqrdecode/common/reedsolomon/ReedSolomonException.cpp 
    zqrdecode/zqrdecode/common/reedsolomon/ReedSolomonDecoder.cpp 
    zqrdecode/zqrdecode/common/reedsolomon/GenericGFPoly.cpp 
    zqrdecode/zqrdecode/common/reedsolomon/GenericGF.cpp 
    zqrdecode/zqrdecode/datamatrix/DataMatrixReader.cpp 
    zqrdecode/zqrdecode/oned/UPCEReader.cpp 
    zqrdecode/zqrdecode/oned/UPCEANReader.cpp 
    zqrdecode/zqrdecode/oned/UPCAReader.cpp 
    zqrdecode/zqrdecode/oned/OneDResultPoint.cpp 
    zqrdecode/zqrdecode/oned/OneDReader.cpp 
    zqrdecode/zqrdecode/oned/MultiFormatUPCEANReader.cpp 
    zqrdecode/zqrdecode/oned/MultiFormatOneDReader.cpp 
    zqrdecode/zqrdecode/oned/ITFReader.cpp 
    zqrdecode/zqrdecode/oned/EAN13Reader.cpp 
    zqrdecode/zqrdecode/oned/EAN8Reader.cpp 
    zqrdecode/zqrdecode/oned/Code128Reader.cpp 
    zqrdecode/zqrdecode/oned/Code39Reader.cpp 
    zqrdecode/zqrdecode/oned/CodaBarReader.cpp 
    zqrdecode/zqrdecode/oned/Code93Reader.cpp 
    zqrdecode/zqrdecode/qrcode/QRCodeReader.cpp 
    zqrdecode/zqrdecode/multi/MultipleBarcodeReader.cpp 
    zqrdecode/zqrdecode/multi/GenericMultipleBarcodeReader.cpp 
    zqrdecode/zqrdecode/multi/ByQuadrantReader.cpp 
    zqrdecode/zqrdecode/multi/qrcode/QRCodeMultiReader.cpp 
    zqrdecode/zqrdecode/multi/qrcode/detector/MultiFinderPatternFinder.cpp 
    zqrdecode/zqrdecode/multi/qrcode/detector/MultiDetector.cpp 
    zqrdecode/zqrdecode/aztec/decoder/AztecDecoder.cpp 
    zqrdecode/zqrdecode/aztec/detector/AztecDetector.cpp 
    zqrdecode/zqrdecode/datamatrix/DataMatrixVersion.cpp 
    zqrdecode/zqrdecode/datamatrix/decoder/DataMatrixDecoder.cpp 
    zqrdecode/zqrdecode/datamatrix/decoder/DataMatrixBitMatrixParser.cpp 
    zqrdecode/zqrdecode/datamatrix/decoder/DataMatrixDataBlock.cpp 
    zqrdecode/zqrdecode/datamatrix/decoder/DataMatrixDecodedBitStreamParser.cpp 
    zqrdecode/zqrdecode/datamatrix/detector/DataMatrixCornerPoint.cpp 
    zqrdecode/zqrdecode/datamatrix/detector/DataMatrixDetector.cpp 
    zqrdecode/zqrdecode/datamatrix/detector/DataMatrixDetectorException.cpp 
    zqrdecode/zqrdecode/qrcode/decoder/QRBitMatrixParser.cpp 
    zqrdecode/zqrdecode/qrcode/decoder/QRDataBlock.cpp 
    zqrdecode/zqrdecode/qrcode/decoder/QRDataMask.cpp 
    zqrdecode/zqrdecode/qrcode/decoder/QRDecodedBitStreamParser.cpp 
    zqrdecode/zqrdecode/qrcode/decoder/QRDecoder.cpp 
    zqrdecode/zqrdecode/qrcode/decoder/QRMode.cpp 
    zqrdecode/zqrdecode/qrcode/detector/QRAlignmentPattern.cpp 
    zqrdecode/zqrdecode/qrcode/detector/QRAlignmentPatternFinder.cpp 
    zqrdecode/zqrdecode/qrcode/detector/QRDetector.cpp 
    zqrdecode/zqrdecode/qrcode/detector/QRFinderPattern.cpp 
    zqrdecode/zqrdecode/qrcode/detector/QRFinderPatternFinder.cpp 
    zqrdecode/zqrdecode/qrcode/detector/QRFinderPatternInfo.cpp 
    zqrdecode/zqrdecode/qrcode/QRVersion.cpp 
    zqrdecode/zqrdecode/qrcode/QRFormatInformation.cpp 
    zqrdecode/zqrdecode/qrcode/QRErrorCorrectionLevel.cpp 
    zqrdecode/zqrdecode/pdf417/decoder/ec/ErrorCorrection.cpp 
    zqrdecode/zqrdecode/pdf417/decoder/ec/ModulusGF.cpp 
    zqrdecode/zqrdecode/pdf417/decoder/ec/ModulusPoly.cpp 
    zqrdecode/zqrdecode/pdf417/decoder/PDF417BitMatrixParser.cpp 
    zqrdecode/zqrdecode/pdf417/decoder/PDF417DecodedBitStreamParser.cpp 
    zqrdecode/zqrdecode/pdf417/decoder/PDF417Decoder.cpp 
    zqrdecode/zqrdecode/pdf417/detector/PDF417Detector.cpp 
    zqrdecode/zqrdecode/pdf417/detector/LinesSampler.cpp 
    zqrdecode/zqrdecode/pdf417/PDF417Reader.cpp 
    zqrdecode/bigint/BigUnsignedInABase.cc 
    zqrdecode/bigint/BigUnsigned.cc 
    zqrdecode/bigint/BigIntegerUtils.cc 
    zqrdecode/bigint/BigIntegerAlgorithms.cc 
    zqrdecode/bigint/BigInteger.cc
		)

add_library(${PROJECT_NAME} ${SRC_FILES} )

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER api/${PROJECT_NAME}.h)
    
add_definitions(-DQT_NO_VERSION_TAGGING)

target_link_libraries(${PROJECT_NAME} -lpng)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

include_directories(. ./zqrdecode/zqrdecode ./zqrdecode/zqrdecode/common ./zqrdecode)


    
