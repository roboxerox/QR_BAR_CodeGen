cmake_minimum_required(VERSION 3.9)

project(qzxing VERSION 1.0.1 DESCRIPTION "qzxing QR decoder")

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Qt5Core REQUIRED)


set (SRC_FILES
	CameraImageWrapper.cpp 
    qzxing.cpp 
    imagehandler.cpp 
    zxing/zxing/ResultIO.cpp 
    zxing/zxing/InvertedLuminanceSource.cpp 
    zxing/zxing/ChecksumException.cpp 
    zxing/zxing/ResultPointCallback.cpp 
    zxing/zxing/ResultPoint.cpp 
    zxing/zxing/Result.cpp 
    zxing/zxing/Reader.cpp 
    zxing/zxing/MultiFormatReader.cpp 
    zxing/zxing/LuminanceSource.cpp 
    zxing/zxing/FormatException.cpp 
    zxing/zxing/Exception.cpp 
    zxing/zxing/DecodeHints.cpp 
    zxing/zxing/BinaryBitmap.cpp 
    zxing/zxing/Binarizer.cpp 
    zxing/zxing/BarcodeFormat.cpp 
    zxing/zxing/aztec/AztecReader.cpp 
    zxing/zxing/aztec/AztecDetectorResult.cpp 
    zxing/zxing/common/StringUtils.cpp 
    zxing/zxing/common/Str.cpp 
    zxing/zxing/common/PerspectiveTransform.cpp 
    zxing/zxing/common/IllegalArgumentException.cpp 
    zxing/zxing/common/HybridBinarizer.cpp 
    zxing/zxing/common/GridSampler.cpp 
    zxing/zxing/common/GreyscaleRotatedLuminanceSource.cpp 
    zxing/zxing/common/GreyscaleLuminanceSource.cpp 
    zxing/zxing/common/GlobalHistogramBinarizer.cpp 
    zxing/zxing/common/DetectorResult.cpp 
    zxing/zxing/common/DecoderResult.cpp 
    zxing/zxing/common/CharacterSetECI.cpp 
    zxing/zxing/common/BitSource.cpp 
    zxing/zxing/common/BitMatrix.cpp 
    zxing/zxing/common/BitArray.cpp 
    zxing/zxing/common/BitArrayIO.cpp 
    zxing/zxing/common/detector/WhiteRectangleDetector.cpp 
    zxing/zxing/common/detector/MonochromeRectangleDetector.cpp 
    zxing/zxing/common/reedsolomon/ReedSolomonException.cpp 
    zxing/zxing/common/reedsolomon/ReedSolomonDecoder.cpp 
    zxing/zxing/common/reedsolomon/GenericGFPoly.cpp 
    zxing/zxing/common/reedsolomon/GenericGF.cpp 
    zxing/zxing/datamatrix/DataMatrixReader.cpp 
    zxing/zxing/oned/UPCEReader.cpp 
    zxing/zxing/oned/UPCEANReader.cpp 
    zxing/zxing/oned/UPCAReader.cpp 
    zxing/zxing/oned/OneDResultPoint.cpp 
    zxing/zxing/oned/OneDReader.cpp 
    zxing/zxing/oned/MultiFormatUPCEANReader.cpp 
    zxing/zxing/oned/MultiFormatOneDReader.cpp 
    zxing/zxing/oned/ITFReader.cpp 
    zxing/zxing/oned/EAN13Reader.cpp 
    zxing/zxing/oned/EAN8Reader.cpp 
    zxing/zxing/oned/Code128Reader.cpp 
    zxing/zxing/oned/Code39Reader.cpp 
    zxing/zxing/oned/CodaBarReader.cpp 
    zxing/zxing/oned/Code93Reader.cpp 
    zxing/zxing/qrcode/QRCodeReader.cpp 
    zxing/zxing/multi/MultipleBarcodeReader.cpp 
    zxing/zxing/multi/GenericMultipleBarcodeReader.cpp 
    zxing/zxing/multi/ByQuadrantReader.cpp 
    zxing/zxing/multi/qrcode/QRCodeMultiReader.cpp 
    zxing/zxing/multi/qrcode/detector/MultiFinderPatternFinder.cpp 
    zxing/zxing/multi/qrcode/detector/MultiDetector.cpp 
    zxing/zxing/aztec/decoder/AztecDecoder.cpp 
    zxing/zxing/aztec/detector/AztecDetector.cpp 
    zxing/zxing/datamatrix/DataMatrixVersion.cpp 
    zxing/zxing/datamatrix/decoder/DataMatrixDecoder.cpp 
    zxing/zxing/datamatrix/decoder/DataMatrixBitMatrixParser.cpp 
    zxing/zxing/datamatrix/decoder/DataMatrixDataBlock.cpp 
    zxing/zxing/datamatrix/decoder/DataMatrixDecodedBitStreamParser.cpp 
    zxing/zxing/datamatrix/detector/DataMatrixCornerPoint.cpp 
    zxing/zxing/datamatrix/detector/DataMatrixDetector.cpp 
    zxing/zxing/datamatrix/detector/DataMatrixDetectorException.cpp 
    zxing/zxing/qrcode/decoder/QRBitMatrixParser.cpp 
    zxing/zxing/qrcode/decoder/QRDataBlock.cpp 
    zxing/zxing/qrcode/decoder/QRDataMask.cpp 
    zxing/zxing/qrcode/decoder/QRDecodedBitStreamParser.cpp 
    zxing/zxing/qrcode/decoder/QRDecoder.cpp 
    zxing/zxing/qrcode/decoder/QRMode.cpp 
    zxing/zxing/qrcode/detector/QRAlignmentPattern.cpp 
    zxing/zxing/qrcode/detector/QRAlignmentPatternFinder.cpp 
    zxing/zxing/qrcode/detector/QRDetector.cpp 
    zxing/zxing/qrcode/detector/QRFinderPattern.cpp 
    zxing/zxing/qrcode/detector/QRFinderPatternFinder.cpp 
    zxing/zxing/qrcode/detector/QRFinderPatternInfo.cpp 
    zxing/zxing/qrcode/QRVersion.cpp 
    zxing/zxing/qrcode/QRFormatInformation.cpp 
    zxing/zxing/qrcode/QRErrorCorrectionLevel.cpp 
    zxing/zxing/pdf417/decoder/ec/ErrorCorrection.cpp 
    zxing/zxing/pdf417/decoder/ec/ModulusGF.cpp 
    zxing/zxing/pdf417/decoder/ec/ModulusPoly.cpp 
    zxing/zxing/pdf417/decoder/PDF417BitMatrixParser.cpp 
    zxing/zxing/pdf417/decoder/PDF417DecodedBitStreamParser.cpp 
    zxing/zxing/pdf417/decoder/PDF417Decoder.cpp 
    zxing/zxing/pdf417/detector/PDF417Detector.cpp 
    zxing/zxing/pdf417/detector/LinesSampler.cpp 
    zxing/zxing/pdf417/PDF417Reader.cpp 
    zxing/bigint/BigUnsignedInABase.cc 
    zxing/bigint/BigUnsigned.cc 
    zxing/bigint/BigIntegerUtils.cc 
    zxing/bigint/BigIntegerAlgorithms.cc 
    zxing/bigint/BigInteger.cc
		)

add_library(${PROJECT_NAME} ${SRC_FILES} )

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER api/${PROJECT_NAME}.h)
    
add_definitions(-DQT_NO_VERSION_TAGGING)

target_link_libraries(${PROJECT_NAME} -lpng)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

include_directories(. ./zxing/zxing ./zxing/zxing/common ./zxing)


    
