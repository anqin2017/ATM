#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileTree_ = ui ->treeView;
    QStringList list = QStringList()<<QStringLiteral("Item") << QStringLiteral("Info");
    fileTree_ ->InitHeadData(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}
