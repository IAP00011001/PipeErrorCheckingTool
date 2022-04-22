#include "widget.h"
#include "ui_widget.h"

#include <iostream>
#include <stdio.h>

#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}




void Widget::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(5432);
    db.setUserName("postgres");
    db.setPassword("123456");
    db.setDatabaseName("test20220422");

    if(!db.open())
    {
        QMessageBox::information(this, "提示", "Falied!");
    }
    else
    {
        QMessageBox::information(this, "提示", "Succeed!");
    }
}



