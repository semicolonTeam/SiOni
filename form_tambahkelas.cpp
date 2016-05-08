#include "form_tambahkelas.h"
#include "ui_form_tambahkelas.h"

form_tambahKelas::form_tambahKelas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form_tambahKelas)
{
    ui->setupUi(this);
}

form_tambahKelas::~form_tambahKelas()
{
    delete ui;
}

void form_tambahKelas::on_btnSelesai_clicked()
{
    QString nama = ui->editNamaKelas->text(),
            nip_wali = ui->editNIPWali->text(),
            jml_sis = ui->editJmlSiswa->text();

    if(nama.count() < 1 || nip_wali.count() < 1 || jml_sis.count() < 1){
        QMessageBox::information(this, tr("Ada kesalahan"), "Ada data yang Anda kosongkan.\nMohon untuk melengkapi isian!");
    }else{
        QSqlDatabase kon_tambahKelas = QSqlDatabase::addDatabase("QSQLITE");
        kon_tambahKelas.setDatabaseName("siOni.db");
        kon_tambahKelas.open();
        QSqlQuery qr_tambahKelas;
        qr_tambahKelas.exec("INSERT INTO kelas VALUES('"+nama+"',"+jml_sis+","+nip_wali+")");
        QMessageBox::information(this, tr("Berhasil"), "Kelas '"+nama+jml_sis+"' berhasil dibuat.");

        kon_tambahKelas.close();
        kon_tambahKelas.removeDatabase(QSqlDatabase::defaultConnection);
        this->hide();
    }
}

void form_tambahKelas::on_btnBatal_clicked()
{
    this->hide();
}
