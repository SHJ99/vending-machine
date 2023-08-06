#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoff->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money+=diff;
    ui->lcdNumber->display(money);
    pbActive();
}

void Widget::pbActive()
{
    if(money>=100)
        ui->pbCoff->setEnabled(true);
    else
        ui->pbCoff->setEnabled(false);

    if(money>=150)
        ui->pbTea->setEnabled(true);
    else
        ui->pbTea->setEnabled(false);

    if(money>=200)
        ui->pbMilk->setEnabled(true);
    else
        ui->pbMilk->setEnabled(false);
}

QString Widget::backMoney()
{
    QString back="";
    if(money>=500)
    {
        back+="500원 x "+QString::number(money/500)+"\n";
        money%=500;
    }
    if(money>=100)
    {
        back+="100원 x "+QString::number(money/100)+"\n";
        money%=100;
    }
    if(money>=50)
    {
        back+="50원 x "+QString::number(money/50)+"\n";
        money%=50;
    }
    if(money>=10)
    {
        back+="10원 x "+QString::number(money/10)+"\n";
        money%=10;
    }

    if(money)
        back="자판기에 대체 무슨짓을 하신겁니까!";
    else
        back+="동전이 반환되었습니다. 이용해 주셔서 감사합니다!";

    return back;
}

void Widget::on_pushButton_clicked()
{
    changeMoney(10);
}


void Widget::on_pushButton_2_clicked()
{
    changeMoney(50);
}


void Widget::on_pushButton_3_clicked()
{
    changeMoney(100);
}


void Widget::on_pushButton_4_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoff_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    mb.information(nullptr, "잔돈 반환", backMoney());
}

