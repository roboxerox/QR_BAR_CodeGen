
# ![](https://github.com/roboxerox/QR_BAR_CodeGen/blob/main/images/qrcode.png) QR_BAR_CodeGen ![](https://github.com/roboxerox/QR_BAR_CodeGen/blob/main/images/barcode.png)
QR_BAR_CodeGen is a Bar code and QR code generator as will as decode QR code. It's also able to save as images (jpg/png). BAR code encoded by CODE128.


### Install Dependencies
1. [png library](https://github.com/pnggroup/libpng)
2. [Qt5](https://wiki.qt.io/Install_Qt_5_on_Ubuntu)

		sudo apt-get install build-essential libpng-dev qt5-default

### Cmake build & run

		git clone https://github.com/roboxerox/QR_BAR_CodeGen.git
		cd QR_BAR_CodeGen
		mkdir cbuild && cd cbuild
		cmake ..
		make
		
		cd QR_BarCodeGen/
		./QR_BarCodeEncoderDecoder
    
### Qmake build & run

		git clone https://github.com/roboxerox/QR_BAR_CodeGen.git
		cd QR_BAR_CodeGen
		mkdir qbuild && cd qbuild
		qmake ..
		make
		
		./QR_BarCodeEncoderDecoder
		
    
### Refrences


1. Bar Code using [Code 128](https://en.wikipedia.org/wiki/Code_128)
2. [QR Codegen](https://github.com/nayuki/QR-Code-generator/tree/master/cpp) source code
3. [QR Code](https://en.wikipedia.org/wiki/QR_code) wiki
