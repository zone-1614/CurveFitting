#include "drawwidget.h"
#include "ui_drawwidget.h"
#include <QDebug>
#include <QPainter>

DrawWidget::DrawWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawWidget)
{
    ui->setupUi(this);
    draw_lag = false;
    draw_gauss = false;
    draw_ols = false;
    ols_times = 1;
}

DrawWidget::~DrawWidget()
{
    delete ui;
}

void DrawWidget::onClickLagrangeCheckBox(int arg1)
{
    if (arg1 == 0) {
        draw_lag = false;
    } else {
        draw_lag = true;
    }
    qDebug() << "draw_lag: " << draw_lag;
}

void DrawWidget::onClickGaussCheckBox(int arg1)
{
    if (arg1 == 0) {
        draw_gauss = false;
    } else {
        draw_gauss = true;
    }
    qDebug() << "draw_gauss: " << draw_gauss;
}

void DrawWidget::onClickOLSCheckBox(int arg1)
{
    if (arg1 == 0) {
        draw_ols = false;
    } else {
        draw_ols = true;
    }
    qDebug() << "draw_ols: " << draw_ols;
}

void DrawWidget::onClickCancelButton()
{
    if (points.empty()) return;
    points.pop_back();
    emit(pointsNumberChange(points.size()));
    update();
}

void DrawWidget::onChangeOLSTimes(int arg1)
{
    this->ols_times = arg1;
    qDebug() << "ols_times: " << ols_times;
}

void DrawWidget::paintEvent(QPaintEvent *e)
{
//    qDebug() << "paint event";
    QPainter painter(this);
    painter.setWindow(-width() / 2, height() / 2, width(), -height()); // set the coordinate system like cartesian.
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::green, 6, Qt::SolidLine, Qt::RoundCap));
    painter.drawPoints(points);

    if (draw_lag) {
        lagrange_interpolation();
        painter.drawPoints(lag_points);
    }
    if (draw_gauss) {
        gauss_basis();
        painter.drawPoints(gauss_points);
    }
    if (draw_ols) {
        ordinary_least_square();
        painter.drawPoints(ols_points);
    }
}

void DrawWidget::mousePressEvent(QMouseEvent *e)
{
//    qDebug() << "mouse event";
    QPointF p_ = e->position();
    qreal x_off = width() / 2, y_off = height() / 2;
    QPointF clickPoint(p_.x() - x_off, y_off - p_.y());
    qDebug() << "click position: " << clickPoint.x() << ", " << clickPoint.y();
    points.append(clickPoint);
    emit(pointsNumberChange(points.size()));
    update();
}

void DrawWidget::lagrange_interpolation()
{

}

void DrawWidget::ordinary_least_square()
{

}

void DrawWidget::gauss_basis()
{

}
