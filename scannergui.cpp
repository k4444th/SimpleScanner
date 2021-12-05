#include "scannergui.h"
#include <QCoreApplication>
#include <QAbstractSocket>
#include <QTcpSocket>

ScannerGui::ScannerGui(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
}

void ScannerGui::on_startButton_clicked()
{
    QString hostname = this->hostnameEntry->text();
    QString ports = this->portEntry->text();
    QStringList portList = ports.split(",");
    QTcpSocket* socket = new QTcpSocket(this);

    this->resultWindow->setTextColor(QColor("black"));
    this->resultWindow->append("Port scanning " + hostname + " ...");

    foreach (QString portString, portList) {
        quint16 port = quint16(portString.toInt());
        socket->connectToHost( hostname, port);
        bool portOpened;

        if (!socket->waitForConnected(1000)) {
            portOpened = false;
            this->resultWindow->setTextColor(QColor("red"));
        } else {
            portOpened = true;
            socket->disconnectFromHost();
            this->resultWindow->setTextColor(QColor("green"));
        }
        this->resultWindow->append(QString::number(port) + "\t" + (portOpened ? "opened" : "closed"));
    }
}
