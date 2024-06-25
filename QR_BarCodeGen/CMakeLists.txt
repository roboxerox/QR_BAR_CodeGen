cmake_minimum_required(VERSION 3.10)

project(QR_BarCodeEncoder
  VERSION
    1.0
  DESCRIPTION
    "QR and BAR code generator"
  LANGUAGES
    CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.11.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Qt5Core REQUIRED)

set_source_files_properties(../code128.c PROPERTIES LANGUAGE CXX )


set(SRC_FILES
		../main.cpp
		../QR_BarCodeEncoder.cpp
		../code128.c
		../qrcodegen.cpp
		)

set(HEADER_FILES
		../QR_BarCodeEncoder.h
		../code128.h
		../qrcodegen.h
		)
		
set(UI_FILES
		../QR_BarCodeEncoder.ui
		)
		
#set(QRC_FILES
#		resources.qrc
#		)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES} ${UI_FILES} ${QRC_FILES})

message(**** ${CMAKE_BINARY_DIR})
#ADD_LIBRARY(qzxing_1 STATIC IMPORTED)
#SET_TARGET_PROPERTIES(qzxing_1 PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/QZXing_sourceV2.4/libqzxing.a)

add_definitions(-DQT_NO_VERSION_TAGGING)

target_link_libraries(${PROJECT_NAME} -lpng)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_BINARY_DIR}/QZXing_sourceV2.4/libqzxing.a)

include_directories(.. ../QZXing_sourceV2.4 ../QZXing_sourceV2.4/zxing/zxing ../QZXing_sourceV2.4/zxing/zxing/common ../QZXing_sourceV2.4/zxing)





