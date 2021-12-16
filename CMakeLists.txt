cmake_minimum_required(VERSION 3.1.0)

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

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(QR_BarCodeEncoder
    QR_BarCodeEncoder.ui
    QR_BarCodeEncoder.cpp
    main.cpp
    code128.c
    code128.h
    qrcodegen.cpp
    qrcodegen.h
)

add_definitions(-DQT_NO_VERSION_TAGGING)

target_link_libraries(QR_BarCodeEncoder -lpng)

target_link_libraries(QR_BarCodeEncoder Qt5::Widgets)






