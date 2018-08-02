#include "login.h"
#include "ui_login.h"
#include <synchapi.h>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_loginPushButton_clicked()
{


        this->hide();
        Sleep(150);
        mainwin = new MainWindow(this);
        mainwin->show();
}
