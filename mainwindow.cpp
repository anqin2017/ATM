#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileTree_ = ui ->treeView;
    QStringList list = QStringList()<<QStringLiteral("ImageName");
    fileTree_ ->InitHeadData(list);
    //QStringList list1 = QStringList()<<QStringLiteral("dog") << QStringLiteral("pig");
    //fileTree_ ->SetItemData(list1);
    QString dir = "C:/Users/AQ/Desktop/deeplabel/JDeepLabel/images/icon";
    fileTree_ ->ShowFileNameFromDir(dir);

}

MainWindow::~MainWindow()
{
    delete ui;
}
