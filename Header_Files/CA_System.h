#pragma once

#include <QtWidgets/QMainWindow>
//#include "ui_CA_System.h"
#include "../x64/Debug/uic/ui_CA_System.h"
class CA_System : public QMainWindow
{
    Q_OBJECT

public:
    CA_System(QWidget *parent = Q_NULLPTR);

private:
    Ui::CA_SystemClass ui;
};
