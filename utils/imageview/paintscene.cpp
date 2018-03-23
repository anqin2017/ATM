#include "paintscene.h"

PaintScene::PaintScene(QObject *obj)
{

}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Press " << event ->scenePos();
    if(event ->scenePos().x() <= 0)
    {
        qDebug() << "event ->scenePos().setX";
        event ->scenePos().setX(0.);

    }
    else if(event ->scenePos().y() <= 0)
    {
        event ->scenePos().setY(0);
    }
    //qDebug() << "Press " << event ->scenePos();
    pointStart = event ->scenePos();
    rect_ = new DrawRect;
    rect_ ->StartDraw(event);
    addItem(rect_);
    rectList_.push_back(rect_);
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"Release" << event ->scenePos();
    if(event ->scenePos().x() <= 0)
    {
        event ->scenePos().setX(0);
    }
    else if(event ->scenePos().y() <=0)
    {
        event ->scenePos().setY(0);
    }
    pointEnd = event ->scenePos();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    rect_ ->Drawing(event);
}

void PaintScene::keyPressEvent(QKeyEvent *event)
{
    if(Qt::Key_Delete == event ->key())
    {
        if(rectList_.size() >0)
        {
            DrawRect* rect = rectList_.back();
            removeItem(rect);
            rectList_.pop_back();
        }
        qDebug() << "remove";
    }
}

void PaintScene::removeRoi(QKeyEvent *event)
{
    if(Qt::Key_Delete == event ->key())
    {
        if(rectList_.size() >0)
        {
            DrawRect* rect = rectList_.back();
            removeItem(rect);
            rectList_.pop_back();
        }
        qDebug() << "remove";
    }
}

void PaintScene::autoRemoveRoi()
{
    if(rectList_.size() >0)
    {
        DrawRect* rect = rectList_.back();
        removeItem(rect);
        rectList_.pop_back();
    }

}

