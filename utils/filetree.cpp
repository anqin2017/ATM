#include "filetree.h"

FileTree::FileTree(QWidget *parent) :
    QTreeView(parent)
{
    setSortingEnabled(true);//item sorting enable
    //setStyleSheet("QTreeView::item {height: 25px;}");
    //sortByColumn(3, Qt::DescendingOrder);
    setSelectionMode(QAbstractItemView::ExtendedSelection);//set item selection mode
    setEditTriggers(QAbstractItemView::SelectedClicked |
                    QAbstractItemView::EditKeyPressed);
    setContextMenuPolicy(Qt::CustomContextMenu);// must set for the signal customContextMenuRequested
    model_ = new QStandardItemModel(this);
    fileModule_ = new QFileSystemModel(this);
    menu_ = new QMenu(this);
    actionDelete_ = new QAction("delete",this);
    actionDelete_ ->setShortcut(QKeySequence::Delete);
    connect(this,SIGNAL(doubleClicked(const QModelIndex)),this,SLOT(SendItemData(const QModelIndex)));
    connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(CustomContextDeal(QPoint)));
    connect(actionDelete_,&QAction::triggered,this,&FileTree::DeleteItemData);
}

int FileTree::Init(QStringList nameFilter, const QString &rootPath)
{
    QDir dir;
    if(!dir.exists(rootPath))
    {
        cerr << "the rootpath not exits " << endl;
        return -1;
    }
    // set the file to write,delete...
    fileModule_ ->setReadOnly(false);
    // list only files
    fileModule_ ->setFilter(QDir::Files);
    // list only files with defined name
    fileModule_ ->setNameFilterDisables(false);
    fileModule_ ->setNameFilters(nameFilter);
    fileModule_ ->setRootPath(rootPath);
    setModel(fileModule_);
    setRootIndex(fileModule_ ->index(rootPath));
}

int FileTree::InitHeadData(QStringList headData)
{
   // qDebug() << list.size();
    if(headData.size() == 0)
    {
        cerr << "the headdata list is empty!!!" << endl;
        return -1;
    }
    model_ ->setColumnCount(headData.size());

    for(int i = 0; i < headData.size(); ++i)
    {
        model_ ->setHeaderData(i,Qt::Horizontal,headData[i]);
        qDebug() << headData[i];
    }
    setModel(model_);
    return 0;
}

int FileTree::SetItemData(QStringList itemData)
{
    if(itemData.size() == 0)
    {
        cerr << "the itemdata is empty!!!" << endl;
        return -1;
    }
    for(int i = 0 ; i< itemData.size() ; ++i)
    {
        QStandardItem* item = new QStandardItem(itemData[i]);
        model_ ->setItem(i,item);
    }
    setModel(model_);
}

void FileTree::SendItemData(const QModelIndex& itemData)
{
//    if(filename.empty())
//    {
//        return;
//    }
//    qDebug() << QString::fromStdString(filename[itemData.row()]);
//    emit SendImageName(QString::fromStdString(filename[itemData.row()]));
    qDebug() << fileModule_ ->fileName(itemData);
    emit SendImageName(fileModule_ ->fileName(itemData));
}

void FileTree::CustomContextDeal(const QPoint&)
{
    qDebug() << "request";
    menu_ ->addAction(actionDelete_);
    menu_ ->exec(QCursor::pos());
}

void FileTree::DeleteItemData()
{
    QModelIndexList list =selectionModel()->selectedIndexes();

    QList<QModelIndex>::Iterator modelIndex;
    for (modelIndex = list.begin(); modelIndex != list.end(); ++modelIndex)
    {
        fileModule_->remove(*modelIndex);
    }
}


