#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/Utilities/Utilities.hpp"
#include "ProvideDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void CreatePool(Account* account, Token* token1, double quantity1, Token* token2, double quantity2, std::string protocol, double pool_fee);
    //void UpdatePool(Account* account, Token* token1, double quantity1, Token* token2, double quantity2, std::string protocol, double pool_fee);

public slots:
    void VerifyPool(Token* token1, double quantity1, Token* token2, std::string protocol);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    ProvideDialog *provide_dialog;
};
#endif // MAINWINDOW_H
