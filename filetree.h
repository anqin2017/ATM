#ifndef FILETREE_H
#define FILETREE_H

#include <QWidget>
#include <QTreeView>
#include <QStandardItemModel>
#include <iostream>
#include <QDebug>
#include <QString>
#include <QFileSystemModel>
#include "third_utils/misc.h"

using namespace std;

class FileTree : public QTreeView
{
    Q_OBJECT
public:
    explicit FileTree(QWidget *parent = 0);

    // eg: QStringList nameFilter; nameFilter << "*.jpg" << "*.png" << "*.bmp";
    int Init(QStringList nameFilter,const QString& rootPath);

    int InitHeadData(QStringList headDdata);

    int SetItemData(QStringList itemData);

    int ShowFileNameFromDir(const QString& fileDir);




signals:
    void SendImageName(QString name);

public slots:
    void SendItemData(const QModelIndex& itemData);

private:
    std::vector< string > filename;
    QStandardItemModel* model_;
    QFileSystemModel* fileModule_;
};

#endif // FILETREE_H
