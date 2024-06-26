cmake_minimum_required(VERSION 3.10)

project(QR_BarCodeEncodeDecode)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


add_subdirectory(QZQrdecode_sourceV2.0)
add_subdirectory(QR_BarCodeGen)
