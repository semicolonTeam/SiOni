#ifndef WINHOME_H
#define WINHOME_H

#include <QMainWindow>

#include "form_masuk.h"
#include "lib.h"
#include "form_tentang.h"
#include "form_tambahkelas.h"

namespace Ui {
class winHome;
}

class winHome : public QMainWindow
{
    Q_OBJECT

public:
    explicit winHome(QWidget *parent = 0);
    ~winHome();

private slots:
    void on_actionGanti_Kelas_triggered();

    void on_actionTentang_Si_Oni_triggered();

    void closeEvent(QCloseEvent *close);

    void on_actionKeluar_triggered();

    void on_btnTambaKelas_clicked();

    void on_actionKelas_Baru_triggered();

private:
    Ui::winHome *ui;
};

#endif // WINHOME_H
