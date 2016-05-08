#ifndef FORM_TENTANG_H
#define FORM_TENTANG_H

#include <QDialog>

namespace Ui {
class form_tentang;
}

class form_tentang : public QDialog
{
    Q_OBJECT

public:
    explicit form_tentang(QWidget *parent = 0);
    ~form_tentang();

private slots:
    void on_btnTutup_clicked();

    void on_btnLisensi_clicked();

    void on_btnKembali_clicked();

private:
    Ui::form_tentang *ui;
};

#endif // FORM_TENTANG_H
