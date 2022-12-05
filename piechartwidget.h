
#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>

class PieChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PieChartWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent*);

signals:

};

#endif // PIECHARTWIDGET_H
