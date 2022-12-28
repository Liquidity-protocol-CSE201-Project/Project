#ifndef PROVIDEDIALOG_H
#define PROVIDEDIALOG_H

#include <QDialog>
#include "src/Utilities/Utilities.hpp"
#include "src/Playground.hpp"

namespace Ui {
class ProvideDialog;
}

class ProvideDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProvideDialog(QWidget *parent = nullptr, Playground *playground = nullptr, Account *account = nullptr);
    ~ProvideDialog();

signals:
    void SendData(Token *token1, double quantity1, Token *token2, double quantity2, std::string protocol, double pool_fee);

private slots:
    void on_pushButton_clicked();
    //void display_other_token();


private:
    Ui::ProvideDialog *ui;
    Playground *playground_;
    Account* account_;
};

#endif // PROVIDEDIALOG_H
