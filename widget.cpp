#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(this, SIGNAL(clickLagrangeCheckBox(int)), ui->drawWidget, SLOT(onClickLagrangeCheckBox(int)));
    connect(this, SIGNAL(clickGaussCheckBox(int)), ui->drawWidget, SLOT(onClickGaussCheckBox(int)));
    connect(this, SIGNAL(clickOLSCheckBox(int)), ui->drawWidget, SLOT(onClickOLSCheckBox(int)));
    connect(this, SIGNAL(clickCancelButton()), ui->drawWidget, SLOT(onClickCancelButton()));
    connect(ui->drawWidget, SIGNAL(pointsNumberChange(int)), this, SLOT(onPointsNumberChange(int)));
    connect(this, SIGNAL(changeOLSTimes(int)), ui->drawWidget, SLOT(onChangeOLSTimes(int)));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_lagrangeCheckBox_stateChanged(int arg1)
{
    emit(clickLagrangeCheckBox(arg1));
}

void Widget::on_gaussCheckBox_stateChanged(int arg1)
{
    emit(clickGaussCheckBox(arg1));
}

void Widget::on_olsCheckBox_stateChanged(int arg1)
{
    emit(clickOLSCheckBox(arg1));
}

void Widget::on_cancelButton_clicked()
{
    emit(clickCancelButton());
}

void Widget::onPointsNumberChange(int point_num)
{
    QString str = QString("Number of Points: %1").arg(point_num);
    this->ui->pointsNumberLabel->setText(str);
}


void Widget::on_olsSpinBox_valueChanged(int arg1)
{
    emit(changeOLSTimes(arg1));
}

