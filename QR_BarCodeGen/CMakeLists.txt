cmake_minimum_required(VERSION 3.12)

project(QR_BarCodeEncoderDecoder
  VERSION
    1.0
  DESCRIPTION
    "QR/BAR code Encoder-Decoder"
  LANGUAGES
    CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.15.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Qt5Core REQUIRED)

set_source_files_properties(../code128.c PROPERTIES LANGUAGE CXX )


set(SRC_FILES
		../main.cpp
		../QR_BarCodeEncoderDecoder.cpp
		../code128.c
		../qrcodegen.cpp
		)

set(HEADER_FILES
		../QR_BarCodeEncoderDecoder.h
		../code128.h
		../qrcodegen.h
		)
		
set(UI_FILES
		../QR_BarCodeEncoderDecoder.ui
		)
		
set(QRC_FILES
		../icons.qrc
		)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES} ${UI_FILES} ${QRC_FILES})

message(**** ${CMAKE_BINARY_DIR})
#ADD_LIBRARY(QZqrDecode_1 STATIC IMPORTED)
#SET_TARGET_PROPERTIES(QZqrDecode_1 PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/QZQrdecode_sourceV2.0/libQZqrDecode.a)

add_definitions(-DQT_NO_VERSION_TAGGING)

target_link_libraries(${PROJECT_NAME} -lpng)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_BINARY_DIR}/QZQrdecode_sourceV2.0/libQZqrDecode.a)

include_directories(.. ../QZQrdecode_sourceV2.0 ../QZQrdecode_sourceV2.0/zqrdecode/zqrdecode ../QZQrdecode_sourceV2.0/zqrdecode/zqrdecode/common ../QZQrdecode_sourceV2.0/zqrdecode)





