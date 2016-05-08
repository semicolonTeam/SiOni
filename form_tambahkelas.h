#ifndef FORM_TAMBAHKELAS_H
#define FORM_TAMBAHKELAS_H

#include <QDialog>

#include "lib.h"

namespace Ui {
class form_tambahKelas;
}

class form_tambahKelas : public QDialog
{
    Q_OBJECT

public:
    explicit form_tambahKelas(QWidget *parent = 0);
    ~form_tambahKelas();

private slots:
    void on_btnSelesai_clicked();

    void on_btnBatal_clicked();

private:
    Ui::form_tambahKelas *ui;
};

#endif // FORM_TAMBAHKELAS_H
