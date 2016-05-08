#include "form_tentang.h"
#include "ui_form_tentang.h"

form_tentang::form_tentang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form_tentang)
{
    ui->setupUi(this);

    this->setFixedSize(this->width(),this->height());

    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->textEdit_2->hide();
    ui->textEdit_3->hide();
    ui->btnKembali->hide();
}

form_tentang::~form_tentang()
{
    delete ui;
}

void form_tentang::on_btnTutup_clicked()
{
    this->hide();
}

void form_tentang::on_btnLisensi_clicked()
{
    ui->btnLisensi->hide();
    ui->btnTutup->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->textEdit->hide();

    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->textEdit_2->show();
    ui->textEdit_3->show();
    ui->btnKembali->show();
}

void form_tentang::on_btnKembali_clicked()
{
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->textEdit_2->hide();
    ui->textEdit_3->hide();
    ui->btnKembali->hide();

    ui->btnLisensi->show();
    ui->btnTutup->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->textEdit->show();
}
