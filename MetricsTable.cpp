#include "ui_MetricsTable.h"
#include "MetricsTable.h"
#include "src/Playground.hpp"

MetricsTable::MetricsTable(QWidget *parent, Playground* playground = nullptr) :
    QWidget(parent),
    ui(new Ui::MetricsTable),
    playground_(playground),
{
    ui->setupUi(this);

    //edit table to update metrics based on pool

    //edit the current values by iterating through the unordered set of tokens with pool_->tokens()
    //and then using pool_->GetQuantity(token) to get the quantity of each token
    //and pool_->GetPrice(token) to get the price of each token

}

MetricsTable::~MetricsTable()
{
    delete ui;
}

