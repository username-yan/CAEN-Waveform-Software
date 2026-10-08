#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ==== 下面是测试 QCustomPlot 的代码 ====
    // 只要你的 UI 文件里有一个名为 customPlot 的 QCustomPlot 控件，它就能跑
    ui->customPlot->addGraph();
    QVector<double> x(101), y(101);
    for (int i=0; i<101; ++i) {
        x[i] = i/50.0 - 1;
        y[i] = x[i]*x[i];
    }
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}