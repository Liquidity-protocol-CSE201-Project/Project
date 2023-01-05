#ifndef WithdrawDIALOG_H
#define WithdrawDIALOG_H

#include <QDialog>
#include "src/Playground.hpp"

namespace Ui {
class WithdrawDialog;
}

class Selection_2 {
public:
    PoolInterface *pool_;
    Token *input_token_;

    Selection_2();

    bool Valid() const;
    void Reset();
};

class WithdrawDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WithdrawDialog(QWidget *parent = nullptr, Playground *playground = nullptr, Account *account = nullptr);
    ~WithdrawDialog();

signals:
    void WithdrawRequest(Token *input_token, double surrendered_quantity);

private slots:
    void on_protocol_comboBox_currentIndexChanged(int index);
    void on_pool_comboBox_currentIndexChanged(int index);
    void on_pushButton_clicked();

private:
    Ui::WithdrawDialog *ui;
    Playground *playground_;
    Account *account_;
    Selection_2 selection_2;

    void UpdateSelection();
    void UpdateOutputQuantity();
};

#endif // WithdrawDIALOG_H
