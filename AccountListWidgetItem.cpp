#include "AccountListWidgetItem.h"
#include "ui_AccountListWidgetItem.h"
#include "MintDialog.h"
#include "WalletListWidgetItem.h"
#include <QMessageBox>
#include "MainWindow.h"

AccountListWidgetItem::AccountListWidgetItem(QWidget *parent, Playground *playground, Account *account) :
    QWidget(parent),
    ui(new Ui::AccountListWidgetItem),
    account_(account),
    playground_(playground)
{
    ui->setupUi(this);
    connect(this, &AccountListWidgetItem::UpdatePoolDisplayRequest, qobject_cast<MainWindow *>(parent), &MainWindow::VerifyUpdatePoolDisplayRequest);
    connect(this, &AccountListWidgetItem::UpdatePoolDisplayRequest2, qobject_cast<MainWindow *>(parent), &MainWindow::VerifyUpdatePoolDisplayRequest2);
    ui->lineEdit->setText(QString::fromStdString(account_->name()));
    ui->lineEdit_2->setText(QString::number(account_->total_value()));
}

AccountListWidgetItem::~AccountListWidgetItem()
{
    delete ui;
}

Account *AccountListWidgetItem::account() const
{
    return account_;
}

void AccountListWidgetItem::VerifyMintRequest(Token *token, double quantity)
{
    try {
        account_->Deposit(token, quantity);
        ui->lineEdit_2->setText(QString::number(account_->total_value()));
        UpdateWallet();
        mint_dialog->accept();
    } catch (std::exception &e) {
        QMessageBox::about(mint_dialog, "Mint failed", e.what());
    }
}

void AccountListWidgetItem::on_mint_pushButton_clicked()
{
    if (!playground_->existing_tokens().size()) {
        QMessageBox::about(this, "Minting failed", "There are no tokens at the moment!");
        return;
    }
    mint_dialog = new MintDialog(this, playground_);
    mint_dialog->exec();
}

void AccountListWidgetItem::on_trade_pushButton_clicked()
{
    trade_dialog = new TradeDialog(this, playground_, account_);
    trade_dialog->exec();
}

void AccountListWidgetItem::UpdateWallet()
{
    ui->listWidget->clear();
    for (auto [token, quantity] : account_->wallet()) {
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        ui->listWidget->addItem(item);
        WalletListWidgetItem *wallet_item = new WalletListWidgetItem(this, token, quantity);
        item->setSizeHint(wallet_item->sizeHint());
        ui->listWidget->setItemWidget(item, wallet_item);
    }
}

void AccountListWidgetItem::SendUpdatePoolDisplayRequest(PROTOCOL protocol, const std::unordered_map<Token *, double> &quantities)
{
    std::unordered_set<Token *> tokens;
    for (auto [token, quantity] : quantities) {
        tokens.emplace(token);
    }
    emit UpdatePoolDisplayRequest(playground_->GetPool(protocol, tokens));
}

void AccountListWidgetItem::SendUpdatePoolDisplayRequest2(PROTOCOL protocol, const std::unordered_map<Token *, double> &quantities, std::unordered_map<Token *, double> last_quants, std::unordered_map<Token *, std::unordered_map<Token *, double>> last_spots)
{
    std::unordered_set<Token *> tokens;
    for (auto [token, quantity] : quantities) {
        tokens.emplace(token);
    }
    emit UpdatePoolDisplayRequest2(playground_->GetPool(protocol, tokens), last_quants, last_spots);
}

void AccountListWidgetItem::SendUpdatePoolDisplayRequest3(PoolInterface* pool, std::unordered_map<Token *, double> last_quants, std::unordered_map<Token *, std::unordered_map<Token *, double>> last_spots) {
    emit UpdatePoolDisplayRequest2(pool, last_quants, last_spots);
}

void AccountListWidgetItem::VerifyTradeRequest(PoolInterface *pool, Token *input_token, Token *output_token, double input_quantity) {
    try {
        std::unordered_map<Token *, std::unordered_map<Token *, double>> last_spots;
        for (auto inp_token : pool->tokens()) {
            for (auto token : pool->tokens()) {
                last_spots[inp_token][token] = pool->GetSpotPrice(inp_token, token);
            }
        }
        std::unordered_map<Token *, double> last_quants = pool->quantities();


        playground_->ExecuteSwap(account_, pool, input_token, output_token, input_quantity);
        ui->lineEdit_2->setText(QString::number(account_->total_value()));
        UpdateWallet();
        SendUpdatePoolDisplayRequest3(pool, last_quants, last_spots);
        trade_dialog->accept();
    } catch (std::exception &e) {
        QMessageBox::about(trade_dialog, "Trade failed", e.what());
    }
}

void AccountListWidgetItem::VerifyProvisionTypeDeclaration(bool initial_provision)
{
    provide_dialog->accept();
    if (initial_provision) {
        new_pool_provision_dialog = new NewPoolProvisionDialog(this, playground_);
        new_pool_provision_dialog->exec();
    } else {
        existing_pool_provision_dialog = new ExistingPoolProvisionDialog(this, playground_);
        existing_pool_provision_dialog->exec();
    }
}

void AccountListWidgetItem::VerifyProvideRequest1(PROTOCOL protocol, const std::unordered_map<Token *, double> &quantities, double pool_fee)
{
    try {

        playground_->ExecuteInitialProvision(account_, protocol, quantities, pool_fee);
        ui->lineEdit_2->setText(QString::number(account_->total_value()));
        UpdateWallet();
        SendUpdatePoolDisplayRequest(protocol, quantities);
        new_pool_provision_dialog->accept();
    }  catch (std::exception &e) {
        QMessageBox::about(new_pool_provision_dialog, "Provide failed", e.what());
    }
}

void AccountListWidgetItem::VerifyProvideRequest2(PROTOCOL protocol, const std::unordered_map<Token *, double> &quantities, double pool_fee, double slippage_controller)
{
    try {

        playground_->ExecuteInitialProvision(account_, protocol, quantities, pool_fee, slippage_controller);
        ui->lineEdit_2->setText(QString::number(account_->total_value()));
        UpdateWallet();
        SendUpdatePoolDisplayRequest(protocol, quantities);
        new_pool_provision_dialog->accept();
    }  catch (std::exception &e) {
        QMessageBox::about(new_pool_provision_dialog, "Provide failed", e.what());
    }
}

void AccountListWidgetItem::VerifyProvideRequest3(PROTOCOL protocol, const std::unordered_map<Token *, double> &quantities, double pool_fee, const std::unordered_map<Token *, double> &weights)
{
    try {

        playground_->ExecuteInitialProvision(account_, protocol, quantities, pool_fee, weights);
        ui->lineEdit_2->setText(QString::number(account_->total_value()));
        UpdateWallet();
        SendUpdatePoolDisplayRequest(protocol, quantities);
        new_pool_provision_dialog->accept();
    }  catch (std::exception &e) {
        QMessageBox::about(new_pool_provision_dialog, "Provide failed", e.what());
    }
}

void AccountListWidgetItem::VerifyExistingProvideRequest(PROTOCOL protocol, const std::unordered_map<Token *, double> &quantities)
{
    try {
        std::unordered_set<Token *> tokens;
        std::unordered_map<Token *, std::unordered_map<Token *, double>> last_spots;
        for (auto [inp_token, inp_quantity] : quantities) {
            tokens.emplace(inp_token);
        }
        PoolInterface *curr_pool = playground_->GetPool(protocol, tokens);
        for (auto [inp_token, inp_quantity] : quantities) {
            for (auto [token, quantity] : quantities) {
                last_spots[inp_token][token] = curr_pool->GetSpotPrice(inp_token, token);
            }
        }
        std::unordered_map<Token *, double> last_quants = curr_pool->quantities();
        playground_->ExecuteProvision(account_, protocol, quantities);
        ui->lineEdit_2->setText(QString::number(account_->total_value()));
        UpdateWallet();
        SendUpdatePoolDisplayRequest2(protocol, quantities, last_quants, last_spots);
        existing_pool_provision_dialog->accept();
    }  catch (std::exception &e) {
        QMessageBox::about(existing_pool_provision_dialog, "Provide failed", e.what());
    }
}

void AccountListWidgetItem::on_provide_pushButton_clicked()
{
    provide_dialog = new ProvideDialog(this);
    provide_dialog->exec();
}
