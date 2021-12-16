#include "QR_BarCodeEncoder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QR_BarCodeEncoder w;
    w.show();

    return a.exec();
}
