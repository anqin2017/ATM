#ifndef DRAWRECT_H
#define DRAWRECT_H
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QPainter>

class DrawRect:public QGraphicsRectItem
{
public:
    DrawRect();

    void StartDraw(QGraphicsSceneMouseEvent * event);

    void Drawing(QGraphicsSceneMouseEvent * event);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QRectF r;

};

#endif // DRAWRECT_H
