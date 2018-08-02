#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include<mainwindow.h>
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_loginPushButton_clicked();

private:
    Ui::login *ui;
    MainWindow * mainwin;
};

#endif // LOGIN_H
