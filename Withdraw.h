#ifndef Withdraw_H
#define Withdraw_H

#include <QDialog>
#include "src/Utilities/Utilities.hpp"
#include "src/Playground.hpp"

namespace Ui {
class Withdraw;
}

class Withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit Withdraw(QWidget *parent = nullptr, Playground *playground = nullptr, Account* account_=nullptr);
    ~Withdraw();

signals:
    void SendData(Token *token, double quantity);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Withdraw *ui;
    Playground *playground_;
    Account* account_;
};

#endif // Withdraw_H
