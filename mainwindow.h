
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Declare the eventFilter function
 bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_startButton_clicked();
    void on_startwindow_itemClicked(QListWidgetItem *);
    void runCode();
    void on_run_clicked();
    void on_tab_clicked();
    void on_close_clicked();

private:
    Ui::MainWindow *ui;
    void fcfs(int bt[], int at[], int n);
    void memory_alloc(int demand[], int block_size[], int n, int k);
    void dead(int res_needed[],int max_needed[],int avail[],int cpu_avail, int n);
};

#endif // MAINWINDOW_H
