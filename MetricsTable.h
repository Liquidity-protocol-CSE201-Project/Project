#ifndef METRICSTABLE_H
#define METRICSTABLE_H

#include <QWidget>
#include "src/Playground.hpp"
namespace Ui {
class MetricsTable;
}

class MetricsTable : public QWidget
{
    Q_OBJECT

public:
    explicit MetricsTable(QWidget *parent = nullptr, Playground* playground = nullptr);
    ~MetricsTable();

private:
    Ui::MetricsTable *ui;
};

#endif // METRICSTABLE_H
