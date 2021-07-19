#pragma once
#include "myitem.h"
#include "myaniitem.h"
#include <iostream>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QMovie>
#include <ctime>
#include <vector>
#include <string>
#include <set>

using std::set;
using std::cin;
using std::cout;
using std::string;
using std::vector;

class Game : public QGraphicsView
{
public:
    Game(QWidget* parent = nullptr);
    void keyPressEvent(QKeyEvent* e);
    int getTurn();
    void setTurn();
    void play();
    int getWhite();
    void setWhite(int pos);
    static vector<MyAniItem*> team1;
    static vector<MyAniItem*> team2;
    static int team1Size;
    static int team2Size;
    static Units currentUnit;
    static int turn;
    static bool canPlay;
    static set<int> dead1;
    static set<int> dead2;
    static int currentPos;
private:
    set<int> fought1;
    set<int> fought2;
    int white;
    QGraphicsScene* scene;
    QLabel* info;
    qreal x1 = 555;
    qreal y1 = 890;
    qreal x2 = 555;
    qreal y2 = 790;
protected:
    void mousePressEvent(QMouseEvent *event);
};
