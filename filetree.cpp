#include "filetree.h"

FileTree::FileTree(QWidget *parent) :
    QTreeView(parent)
{
    model_ = new QStandardItemModel(this);
    setSortingEnabled(true);//item sorting enable
    //setStyleSheet("QTreeView::item {height: 25px;}");
    //sortByColumn(3, Qt::DescendingOrder);
    setSelectionMode(QAbstractItemView::ExtendedSelection);//set item selection mode
    setEditTriggers(QAbstractItemView::SelectedClicked |
                    QAbstractItemView::EditKeyPressed);// set edit file name key
    connect(this,SIGNAL(doubleClicked(const QModelIndex)),this,SLOT(SendItemData(const QModelIndex)));

    //setHorizontalHeaderLabels(QStringList()<<QStringLiteral("项目") << QStringLiteral("信息"));
    //setHeader(QHeaderView());
//    QStandardItemModel* model = new QStandardItemModel(4,2);
//        model->setHeaderData(0, Qt::Horizontal, tr("Service"));
//        model->setHeaderData(1, Qt::Horizontal, tr("Details"));
//        QStandardItem *item1 = new QStandardItem("avahi-daemon");
//        //item1->setIcon(QIcon("gparted.png"));
//        QStandardItem *item2 = new QStandardItem("bluetooth");
//        //item2->setIcon(QIcon("gparted.png"));
//        QStandardItem *item3 = new QStandardItem("crond");
//        //item3->setIcon(QIcon("gparted.png"));
//        QStandardItem *item4 = new QStandardItem("cups");
//       //item4->setIcon(QIcon("gparted.png"));
//        model->setItem(0, 0, item1);
//        model->setItem(1, 0, item2);
//        model->setItem(2, 0, item3);
//        model->setItem(3, 0, item4);
//        QStandardItem *item5 = new QStandardItem("fifth");
//        item4->appendRow(item5);
//        QModelIndex parent;
//        for (int i = 0; i < 4; ++i) {
//            parent = model->index(0, 0, parent);
//            model->insertRows(0, 1, parent);
//            model->insertColumns(0, 1, parent);
//            QModelIndex index = model->index(0, 0, parent);
//            model->setData(index, i);
//        }
       // setModel(model);

}

int FileTree::InitHeadData(QStringList headdata)
{
   // qDebug() << list.size();
    if(headdata.size() == 0)
    {
        cerr << "the headdata list is empty!!!" << endl;
        return -1;
    }
    model_ ->setColumnCount(headdata.size());

    for(int i = 0; i < headdata.size(); ++i)
    {
        model_ ->setHeaderData(i,Qt::Horizontal,headdata[i]);
        qDebug() << headdata[i];
    }
    setModel(model_);
    return 0;
}

int FileTree::SetItemData(QStringList itemdata)
{
    if(itemdata.size() == 0)
    {
        cerr << "the itemdata is empty!!!" << endl;
        return -1;
    }
    for(int i = 0 ; i< itemdata.size() ; ++i)
    {
        QStandardItem* item = new QStandardItem(itemdata[i]);
        model_ ->setItem(i,item);
    }
    setModel(model_);
}

int FileTree::ShowFileNameFromDir(const QString &filedir)
{
    GetFileNameFromDir(filedir.toStdString(),filename);
    QStringList list ;
    for(int i = 0 ; i < filename.size(); ++i)
    {
        list << QString::fromStdString(filename[i]);
    }
    SetItemData(list);
    return 0;
}

void FileTree::SendItemData(const QModelIndex& itemdata)
{
    if(filename.empty())
    {
        return;
    }
    qDebug() << QString::fromStdString(filename[itemdata.row()]);
    emit SendImageName(QString::fromStdString(filename[itemdata.row()]));
}


