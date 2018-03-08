#ifndef ZOOMGRAPHICSVIEWLITE_H
#define ZOOMGRAPHICSVIEWLITE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include "imageview/paintscene.h"

/**
 * @class ZoomGraphicsView ZoomGraphicsView.h ZoomGraphicsView.cpp
 * @brief for view, reimplement wheelEvent to scale the view with mouse middle button wheel
 */
class ZoomGraphicsViewLite :  public QGraphicsView
{
    Q_OBJECT
public:
    explicit ZoomGraphicsViewLite(QWidget *parent = 0);
    virtual ~ZoomGraphicsViewLite();

public slots:
    // show an image
    void displayImage(cv::Mat image);

protected:
    void wheelEvent(QWheelEvent *event);

public:
     PaintScene *scene_; // for the view

private:
    void scaleImage(const qreal factor);
    QImage cvMat2QImage(const cv::Mat& mat);
    QGraphicsPixmapItem *pixmapitem_; // to display the pixmap
private:
    QPainter* painter_;

};

#endif // ZOOMGRAPHICSVIEW_H
