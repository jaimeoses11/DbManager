#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QCoreApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    const QString appDir = QCoreApplication::applicationDirPath().replace("/","\\");
    const QString dbName = appDir + "\\data.db";
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;
    QSqlDatabase mDb;
};
#endif // MAINWINDOW_H
