#include "QR_BarCodeEncoderDecoder.h"
#include <QApplication>
#include <QCommandLineParser>

QString BUILD_VER = QString("%1%2").arg(QLocale(QLocale::C).toDate(QString(__DATE__).simplified(), QLatin1String("MMM d yyyy")).toString("yyyyMMdd"))
        .arg(QString("%1%2%3%4%5%6").arg(__TIME__[0])
        .arg(__TIME__[1])
        .arg(__TIME__[3])
        .arg(__TIME__[4])
        .arg(__TIME__[6])
        .arg(__TIME__[7]));

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setWindowIcon(QIcon(":/images/main.png"));
    app.setApplicationName("QR/BAR Code Encode-Decode");
    app.setApplicationVersion(SOFTWARE_VERSION);
    QCommandLineParser parser;
    parser.addVersionOption();
    parser.setApplicationDescription("A Qt/C++ based QR/BAR code encoder & decoder API");
    parser.process(app);


    qDebug().noquote()<<app.applicationDisplayName();
    qDebug().noquote()<<"version "<<app.applicationVersion();
    qDebug().noquote()<<parser.applicationDescription();

    QR_BarCodeEncoderDecoder w;
    w.show();

    return app.exec();
}
