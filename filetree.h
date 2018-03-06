#ifndef FILETREE_H
#define FILETREE_H

#include <QWidget>
#include <QTreeView>
#include <QStandardItemModel>

class FileTree : public QTreeView
{
    Q_OBJECT
public:
    explicit FileTree(QTreeView *parent = 0);


signals:

public slots:
};

#endif // FILETREE_H
