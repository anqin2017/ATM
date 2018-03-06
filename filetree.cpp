#include "filetree.h"

FileTree::FileTree(QTreeView *parent) : QTreeView(parent)
{
    //setHorizontalHeaderLabels(QStringList()<<QStringLiteral("项目") << QStringLiteral("信息"));
    //setHeader(QHeaderView());
    QStandardItemModel* model = new QStandardItemModel(4,2);
        model->setHeaderData(0, Qt::Horizontal, tr("Service"));
        model->setHeaderData(1, Qt::Horizontal, tr("Details"));
        QStandardItem *item1 = new QStandardItem("avahi-daemon");
        //item1->setIcon(QIcon("gparted.png"));
        QStandardItem *item2 = new QStandardItem("bluetooth");
        //item2->setIcon(QIcon("gparted.png"));
        QStandardItem *item3 = new QStandardItem("crond");
        //item3->setIcon(QIcon("gparted.png"));
        QStandardItem *item4 = new QStandardItem("cups");
       //item4->setIcon(QIcon("gparted.png"));
        model->setItem(0, 0, item1);
        model->setItem(1, 0, item2);
        model->setItem(2, 0, item3);
        model->setItem(3, 0, item4);
        QStandardItem *item5 = new QStandardItem("fifth");
        item4->appendRow(item5);
//        QModelIndex parent;
//        for (int i = 0; i < 4; ++i) {
//            parent = model->index(0, 0, parent);
//            model->insertRows(0, 1, parent);
//            model->insertColumns(0, 1, parent);
//            QModelIndex index = model->index(0, 0, parent);
//            model->setData(index, i);
//        }
        setModel(model);

}
