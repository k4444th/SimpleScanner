#ifndef SCANNERGUI_H
#define SCANNERGUI_H

#include "ui_scannergui.h"

class ScannerGui : public QMainWindow, private Ui::ScannerGui
{
    Q_OBJECT

public:
    explicit ScannerGui(QWidget *parent = nullptr);
private slots:
    void on_startButton_clicked();
};

#endif // SCANNERGUI_H
