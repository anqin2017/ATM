#include "drawrect.h"

DrawRect::DrawRect()
{

}

void DrawRect::StartDraw(QGraphicsSceneMouseEvent * event)
{
    setRect(QRectF(event ->scenePos(),QSizeF(0,0)));
}

void DrawRect::Drawing(QGraphicsSceneMouseEvent * event)
{
    qreal width = event ->scenePos().x()-rect().topLeft().x();
    qreal height = event ->scenePos().y()-rect().topLeft().y();
    r =  QRectF(rect().topLeft(),QSizeF(width,height));
    setRect(r);
}

void DrawRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter ->setPen(QPen(Qt::red,4,Qt::SolidLine));
    painter ->drawRect(r);
}
