#ifndef LIB_H
#define LIB_H

#include <QtSql/QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QDateTime>
#include <QCloseEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

#include "winhome.h"

class cekLog
{
public:
    QString tanggal = QDate::currentDate().toString(Qt::ISODate);
    QString jam     = QTime::currentTime().toString();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");


    void db_kon(QString a){
        db.setDatabaseName(a);
        db.open();
    }

    void db_close(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool sdhMsk(){
        db_kon("log.db");

        QSqlQuery cek;
        if(!cek.exec("SELECT MAX(id) AS id,tanggal,status FROM masuk WHERE id=id")){
            //ret = false;
        }else{
            while (cek.next()) {
                QString status  = cek.value(2).toString();
                if(status == "masuk")
                    return true;
                else
                    return false;
            }
        }
        db_close();
    }
    void masuk(){
        db_kon("log.db");
        QSqlQuery in;
        in.exec("INSERT INTO masuk(tanggal,status) VALUES('"+tanggal+" "+jam+"','masuk')");
        db_close();
    }
    void keluar(){
        db_kon("log.db");
        QSqlQuery out;
        out.exec("INSERT INTO masuk(tanggal,status) VALUES('"+tanggal+" "+jam+"','keluar')");
        db_close();
    }
};

#endif // LIB_H
