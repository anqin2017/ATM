#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileTree_ = ui ->treeView;
    imageView_ = ui ->imageView;
    QStringList list = QStringList()<<"*.jpg" << "*.png" << "*.bmp";
    //fileTree_ ->InitHeadData(list);
    QString dir = "C:/Users/pvt1001/Desktop/pvt_utils-6/pvt_utils/icon";
    //fileTree_ ->ShowFileNameFromDir(dir);
    connect(fileTree_,&FileTree::SendImageName,this,&MainWindow::ShowImage);
    fileTree_ ->Init(list,dir);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowImage(QString name)
{
    //qDebug() << name;
    QString imagePath = directoryPath_ + "/" + name;
    cv::Mat src = cv::imread(imagePath.toStdString());
    if(!src.data)
    {
        cerr << "null image!!!" << endl;
    }
    imageView_ ->displayImage(src);
}

void MainWindow::on_pushButtonDirectory_clicked()
{
   directoryPath_ = QFileDialog::getExistingDirectory(this,tr("Choose the directory"));
   if(!directoryPath_.isEmpty())
   {
       qDebug() << directoryPath_;
       ui ->lineEditDirectoryAddress ->setText(directoryPath_);
       fileTree_ ->ShowFileNameFromDir(directoryPath_);
   }
}

