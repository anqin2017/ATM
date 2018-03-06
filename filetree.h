#ifndef FILETREE_H
#define FILETREE_H

#include <QWidget>
#include <QTreeView>
#include <QStandardItemModel>
#include <iostream>
#include <QDebug>
using namespace std;

class FileTree : public QTreeView
{
    Q_OBJECT
public:
    explicit FileTree(QWidget *parent = 0);

    int InitHeadData(QStringList list);


signals:

public slots:

private:
    QStandardItemModel* model_;
};

#endif // FILETREE_H
