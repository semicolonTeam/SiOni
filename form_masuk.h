#ifndef FORM_MASUK_H
#define FORM_MASUK_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtDebug>
#include <QFileInfo>

#include "winhome.h"
#include "lib.h"

namespace Ui {
class form_masuk;
}

class form_masuk : public QDialog
{
    Q_OBJECT

public:
    explicit form_masuk(QWidget *parent = 0);
    ~form_masuk();
    QSqlDatabase kon = QSqlDatabase::addDatabase("QSQLITE");

private slots:
    void on_btnMasuk_clicked();

    void on_btnBatal_clicked();

    void closeEvent(QCloseEvent * close);

private:
    Ui::form_masuk *ui;
};

#endif // FORM_MASUK_H
