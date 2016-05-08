#include "form_masuk.h"
#include "ui_form_masuk.h"
#include "lib.h"

QSqlDatabase kon = QSqlDatabase::addDatabase("QSQLITE");

form_masuk::form_masuk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form_masuk)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
}

form_masuk::~form_masuk()
{
    cekLog lc; lc.db_close();
    delete ui;
}

void form_masuk::on_btnMasuk_clicked()
{
    QString identitas, kataSandi;
    identitas = ui->inIdentitas->text();
    kataSandi = ui->inKataSandi->text();

    kon.close();
    kon.setDatabaseName("siOni.db");
    kon.open();

    if(identitas.isEmpty() || kataSandi.isEmpty()){
        ui->labelNotifikasi->setText("Gagal masuk.\nAda bagian yang Anda kosongkan.");
    }else{
        if(!kon.isOpen()){
            ui->labelNotifikasi->setText("Gagal masuk.\n"
                                         "Tidak dapat mengidentifikasi data.");
            kon.close();
        }else{
            QSqlQuery admin;
            if(admin.exec("SELECT * FROM admin WHERE username='"+identitas+"' AND password='"+kataSandi+"'")){
                int i = 0;
                while (admin.next()) {
                    i++;
                }
                if(i != 1){
                    ui->labelNotifikasi->setText("Gagal masuk.\nData yang Anda masukkan tidak cocok.");
                }else{
                    cekLog cl;
                    cl.masuk();
                    cl.db_close();
                    this->hide();
                }
            }
        }
        kon.close();
        kon.removeDatabase(QSqlDatabase::defaultConnection);
    }
}

void form_masuk::on_btnBatal_clicked()
{
    exit(0);
}

void form_masuk::closeEvent(QCloseEvent *close){
    exit(0);
    close->accept();
}
