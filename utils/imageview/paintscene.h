#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include "drawrect.h"
#include <QKeyEvent>
#include <QObject>

class PaintScene: public QGraphicsScene
{

public:
    PaintScene(QObject *obj = 0);

    void removeRoi(QKeyEvent *event);

    void autoRemoveRoi();

    // QGraphicsScene interface
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);


public:
    bool      drawing = false;
    QPointF   pointStart,pointEnd;
    DrawRect* rect_;
    QVector < DrawRect*> rectList_;
    Qt::MouseButton button_;
};

#endif // PAINTSCENE_H
