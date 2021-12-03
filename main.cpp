#include "scannergui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScannerGui w;
    w.show();

    return a.exec();
}
