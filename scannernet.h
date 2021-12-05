#ifndef SCANNERNET_H
#define SCANNERNET_H

#include <QObject>

class ScannerNet : public QObject
{
    Q_OBJECT
public:
    explicit ScannerNet(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SCANNERNET_H