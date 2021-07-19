#pragma once
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QGraphicsProxyWidget>

class MyItem : public QGraphicsPixmapItem
{
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};
