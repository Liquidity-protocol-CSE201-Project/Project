#include "piechartwidget.h"

#include <QPainter>

PieChartWidget::PieChartWidget(QWidget *parent)
    : QWidget{parent}
{

}

void PieChartWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRectF size = QRectF(50,0, this->width()-100, this->width()-100);
    painter.setBrush(Qt::red);
    painter.drawPie(size, 0, 10*16);
    painter.setBrush(Qt::blue);
    painter.drawPie(size, 10*16,350*16);
}


