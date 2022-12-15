#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "src/Utilities/Utilities.hpp"
#include "src/Protocols/UniswapV2Pool.hpp"
#include "MetricsTable.h"
#include "AccountListWidgetItem.h"
#include "TokenListWidgetItem.h"
#include <QMessageBox>
#include <tuple>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QListWidgetItem *item = new QListWidgetItem(ui->listWidget_3);
//    ui->listWidget_3->addItem(item);
//    MetricsTable *table_item = new MetricsTable(this, &pool_init);
//    item->setSizeHint(table_item->sizeHint());
//    ui->listWidget_3->setItemWidget(item, table_item);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::string account_name = ui->lineEdit->text().toStdString();
    ui->lineEdit->clear();
    Account *account; bool is_new; std::tie(account, is_new) = Account::GetAccount(account_name);
    if (!is_new) {
        QMessageBox::about(this, "Adding account failed", "This name has been used by another account!");
    } else {
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        ui->listWidget->addItem(item);
        AccountListWidgetItem *account_item = new AccountListWidgetItem(this, account);
        item->setSizeHint(account_item->sizeHint());
        ui->listWidget->setItemWidget(item, account_item);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    std::string token_name = ui->lineEdit_2->text().toStdString();
    double token_price = ui->lineEdit_3->text().toDouble();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    Token *token; bool is_new; std::tie(token, is_new) = Token::GetToken(token_name, token_price);
    if (!is_new) {
        QMessageBox::about(this, "Adding token failed", "This name has been used by another token!");
    } else {
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_2);
        ui->listWidget_2->addItem(item);
        TokenListWidgetItem *token_item = new TokenListWidgetItem(this, token);
        item->setSizeHint(token_item->sizeHint());
        ui->listWidget_2->setItemWidget(item, token_item);
    }
}

//void MainWindow::CreatePool(Account* account, Token* token1, double quantity1, Token* token2, double quantity2, std::string protocol, double pool_fee) {
//    UniswapV2Pool pool({token1, token2}, pool_fee);
//    QListWidgetItem *item = new QListWidgetItem(ui->listWidget_3);
//    ui->listWidget_3->addItem(item);
//    MetricsTable *metrics_table = new MetricsTable(this, &pool);
//    //item->setSizeHint(metrics_table>sizeHint());
//    ui->listWidget_3->setItemWidget(item, metrics_table);
//}

//void MainWindow::UpdatePool(Account* account, Token* token1, double quantity1, Token* token2, double quantity2, std::string protocol, double pool_fee) {
//    return;
//}

void MainWindow::VerifyPool(Token* token1, double quantity1, Token* token2, std::string protocol)
{
    //UniswapV2Pool::Provide(account, token1, token2, quantity1, quantity2, pool_fee);
    return;
}

