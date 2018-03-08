#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filetree.h"
#include "imageview/ZoomGraphicsViewLite.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:
    void ShowImage(QString name);

private slots:
    void on_pushButtonDirectory_clicked();

private:
    QString directoryPath_;
    Ui::MainWindow *ui;
    FileTree* fileTree_;
    ZoomGraphicsViewLite* imageView_;

};

#endif // MAINWINDOW_H
