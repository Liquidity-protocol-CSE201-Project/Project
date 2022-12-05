#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->setTitle("Chart for x*y=k");
    chart->createDefaultAxes();

    QValueAxis *axisX = new QValueAxis;
    chart->addAxis(axisX, Qt::AlignBottom);
    axisX->setTitleText("Token A");

    QSplineSeries *series = new QSplineSeries();
    double k=1000;
    for (int i=1;i<100;i++) {
        double j=i/1;
        series->append(j,k/j);
    }
    chart->addSeries(series);

    QValueAxis *axisY = new QValueAxis;
    chart->addAxis(axisY, Qt::AlignLeft);
    axisY->setTitleText("Token B");

    series->attachAxis(axisX);
    series->attachAxis(axisY);



    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);








}

MainWindow::~MainWindow()
{
    delete ui;
}

