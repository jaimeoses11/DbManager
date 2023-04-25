#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "m3uplaylist.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mDb = QSqlDatabase::addDatabase("QSQLITE");
    mDb.setDatabaseName(dbName);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(mDb.open())
    {
        QSqlQuery qry;
        qry.exec("CREATE TABLE IF NOT EXISTS Channels (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                 "name VARCHAR(30) NOT NULL, url VARCHAR(40) NOT NULL)");

        m3uPlayList list(appDir + "\\ListaDeporte.m3u");
        list.parseList();
        foreach(Channel ch, list.channels)
        {
            qry.exec(QString("INSERT INTO Channels (name,url) VALUES ('%1','%2')")
                     .arg(ch.name).arg(ch.url));
        }
        mDb.close();
    }
    else qDebug() << mDb.lastError().text();
}

