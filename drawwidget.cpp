#include "drawwidget.h"
#include "ui_drawwidget.h"
#include <QDebug>
#include <QPainter>

DrawWidget::DrawWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawWidget)
{
    ui->setupUi(this);
}

DrawWidget::~DrawWidget()
{
    delete ui;
}

void DrawWidget::paintEvent(QPaintEvent *e)
{
//    qDebug() << "paint event";
    QPainter painter(this);
    painter.setWindow(-width() / 2, height() / 2, width(), -height()); // set the coordinate system like cartesian.
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::green, 6, Qt::SolidLine, Qt::RoundCap));
    painter.drawPoints(points);
}

void DrawWidget::mousePressEvent(QMouseEvent *e)
{
//    qDebug() << "mouse event";
    QPointF p_ = e->position();
    qreal x_off = width() / 2, y_off = height() / 2;
    QPointF clickPoint(p_.x() - x_off, y_off - p_.y());
    qDebug() << "click position: " << clickPoint.x() << ", " << clickPoint.y();
    points.append(clickPoint);
    update();
}
