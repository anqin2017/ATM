#ifndef FILETREE_H
#define FILETREE_H

#include <QWidget>
#include <QTreeView>
#include <QStandardItemModel>
#include <iostream>
#include <QDebug>
#include <QString>
#include "third_utils/misc.h"

using namespace std;

class FileTree : public QTreeView
{
    Q_OBJECT
public:
    explicit FileTree(QWidget *parent = 0);

    int InitHeadData(QStringList headdata);

    int SetItemData(QStringList itemdata);

    int ShowFileNameFromDir(const QString& filedir);


signals:
    void SendImageName(QString name);

public slots:
    void SendItemData(const QModelIndex& itemdata);

private:
    std::vector< string > filename;
    QStandardItemModel* model_;

};

#endif // FILETREE_H
