#include "BarCodeEncoderDecoder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BarCodeEncoderDecoder w;
    w.show();

    return a.exec();
}
