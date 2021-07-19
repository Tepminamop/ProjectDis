#pragma once
#include "units.h"
#include <QGraphicsProxyWidget>
#include <QDebug>
#include <QLabel>
#include <QMovie>

class MyAniItem : public QGraphicsProxyWidget
{
public:
    MyAniItem(int team, int pos, QString name, QGraphicsItem* parent = nullptr);
    QLabel* getHp();
    int getTeam();
    int getPos();
    Units getUnit();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QLabel* gif_lbl;
    QMovie* movie;
    QLabel* hp;
    Units unit;
    int team;
    int pos;
    bool canFight;
};

