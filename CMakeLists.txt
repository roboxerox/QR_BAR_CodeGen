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

find_package(Qt5Core REQUIRED)

set_source_files_properties(code128.c PROPERTIES LANGUAGE CXX )


set(SRC_FILES
		main.cpp
		QR_BarCodeEncoder.cpp
		code128.c
		qrcodegen.cpp
		)

set(HEADER_FILES
		QR_BarCodeEncoder.h
		code128.h
		qrcodegen.h
		)
		
set(UI_FILES
		QR_BarCodeEncoder.ui
		)
		
#set(QRC_FILES
#		resources.qrc
#		)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES} ${UI_FILES} ${QRC_FILES})

add_definitions(-DQT_NO_VERSION_TAGGING)

target_link_libraries(${PROJECT_NAME} -lpng)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

include_directories(.)




