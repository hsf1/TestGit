#include "mainwidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");
    b1.move(100, 100);

    b2 = new QPushButton(this);
    b2->setText("abc");
    connect(b2, &QPushButton::released, this, &MainWidget::mySlot);


    setWindowTitle("老大");
    //this->setWindowTitle("老大");

    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50, 50);

    connect(&b3, &QPushButton::released, this, &MainWidget::changeWin);

    connect(&subWin, SIGNAL(mySignal(int,QString)),this, SLOT(dealSlot(int,QString)) );


}
void MainWidget::changeWin()
{
    this->hide();
    subWin.show();
}

void MainWidget::dealSlot(int a, QString str)
{
    qDebug() << a ;
    qDebug() << str ;
    //子窗口显示
    subWin.hide();
    //本窗口隐藏
    this->show();
}

void MainWidget::mySlot()
{
    b2->setText("123");
}

MainWidget::~MainWidget()
{

}
