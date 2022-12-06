#include "QR_BarCodeEncoder.h"
#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qDebug()<< app.arguments();
    app.setApplicationName("QR/BAR Code Encoder");
    app.setApplicationVersion(SOFTWARE_VERSION);
    QCommandLineParser parser;
    parser.addVersionOption();
    parser.setApplicationDescription("Qt/C++ based QR/BAR code encoder API");
    parser.process(app);

    QR_BarCodeEncoder w;
    w.show();

    return app.exec();
}
