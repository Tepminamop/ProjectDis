#include "battle.h"
#include "units.h"
#include "game.h"
#include "myitem.h"
#include "myaniitem.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include <string>
#include <QIcon>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPixmap>
#include <QBrush>
#include <QImage>
#include <QLabel>
#include <QDebug>

using std::vector;
using std::string;
using std::cin;
using std::cout;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTextStream out(stdout);
    //QTextStream in(stdin);

    //Battle w;
    //w.setWindowIcon(QIcon("D:/Qt/Images/icon.png"));
    //w.show();
    //Units unit = Units("Barbarian");
    //std::cout << unit << '\n';
    //scene->removeItem(rect);  
    /*
    rect = new MyItem();
    rect1 = new MyItem();
    rect->setPixmap(QPixmap("D:/Qt/Images/wizard.png"));
    rect1->setPixmap(QPixmap("D:/Qt/Images/wizard.png"));
    rect->setScale(3);
    rect1->setScale(3);
    rect->setPos(250, 300);
    rect1->setPos(0, 300);
    */

    /*
    string name;
    vector<string> names1;
    vector<string> names2;
    for (int i = 0; i < 6; i++) {
        cout << "Input name for team 1: ";
        cin >> name;
        names1.push_back(name);
        cout << '\n';
    }
    for (int i = 0; i < 6; i++) {
        cout << "Input name for team 2: ";
        cin >> name;
        names2.push_back(name);
        cout << '\n';
    }
    */

    Game* game = new Game();
    game->setWindowIcon(QIcon("D:/Qt/Images/wizard.png"));
    game->showFullScreen();
    return a.exec();
}
