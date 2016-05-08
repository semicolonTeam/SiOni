#include "winhome.h"
#include "ui_winhome.h"

QString root = "/home/";

winHome::winHome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winHome)
{
    ui->setupUi(this);
    ui->textEdit->setStyleSheet("background:rgba(0, 0, 0, 0)");

    cekLog cl;
    bool clo = cl.sdhMsk();
    if(clo == false){
        form_masuk fm;
        fm.setModal(true);
        fm.exec();
    }
    QSqlDatabase baca = QSqlDatabase::addDatabase("QSQLITE");
    baca.setDatabaseName("siOni.db");
    baca.open();

    QSqlQueryModel * mod = new QSqlQueryModel();
    QSqlQuery *qr = new QSqlQuery();
    qr->exec("SELECT * FROM kelas");
    mod->setQuery(*qr);
    ui->tableView->setModel(mod);
    baca.close();
    baca.removeDatabase(QSqlDatabase::defaultConnection);
}

winHome::~winHome()
{

    delete ui;
}

void winHome::on_actionGanti_Kelas_triggered()
{
    QString namaFile = QFileDialog::getOpenFileName(
                            this,
                            tr("Pilih Kelas"),
                            root,
                            "All Files (*.*);;Data Kelas (*.oni)"
                        );
}

void winHome::on_actionTentang_Si_Oni_triggered()
{
    this->setEnabled(false);
    form_tentang ft;
    ft.setModal(true);
    ft.exec();
    this->setEnabled(true);
}

void winHome::closeEvent(QCloseEvent *close){
    QMessageBox::StandardButton btn = QMessageBox::question(this,
                                                            tr("Si Oni - Tutup Aplikasi"),
                                                            tr("Hanya menutup aplikasi, log aktivitas Anda tetap aktif.\n"
                                                               "Pastikan Anda telah menutup log untuk keamanan data Anda.\n\n"
                                                               "Apakah Anda ingin menutup aplikasi?"),
                                                            QMessageBox::No | QMessageBox::Yes,
                                                            QMessageBox::Yes);
    if(btn != QMessageBox::Yes) close->ignore();
    else{
        close->accept();
    }
}

void winHome::on_actionKeluar_triggered()
{
    QMessageBox::StandardButton btn = QMessageBox::question(this,
                                                            tr("Si Oni - Keluar"),
                                                            tr("Log aktivitas Anda akan ditutup.\n"
                                                               "Buka aplikasi dan masuk sesuai prosedur untuk melanjutkan pekerjaan.\n\n"
                                                               "Apakah Anda yakin ingin keluar?"),
                                                            QMessageBox::No | QMessageBox::Yes,
                                                            QMessageBox::Yes);
    if(btn == QMessageBox::Yes){
        cekLog logCek;
        logCek.keluar();
        exit(0);
    }
}

void winHome::on_btnTambaKelas_clicked()
{
    form_tambahKelas tk;
    tk.setModal(true);
    tk.exec();
}

void winHome::on_actionKelas_Baru_triggered()
{
    form_tambahKelas tk;
    tk.setModal(true);
    tk.exec();
}
