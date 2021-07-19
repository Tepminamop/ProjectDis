#include "myaniitem.h"
#include "game.h"

void MyAniItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event)
    qDebug() << "AniItem clicked" << '\n';//добавить очередность ходов, возможно сделать статический флаг
    if (Game::currentUnit.getDamage() >= 0) {
        if (Game::turn != this->team) {
            Game::canPlay = true;
        }
        else if (Game::turn == this->team)
            Game::canPlay = false;

        if (Game::turn != this->getTeam()) {
            unit.setHp(Game::currentUnit.getDamage());
            if (unit.getHp() <= 0) {
                hp->clear();
                if (this->getTeam() == 1) {
                    Game::team1Size--;
                    Game::team1[this->getPos()]->getUnit().setInitiative(-1);
                    qDebug() << Game::team1Size << '\n';
                }
                else if (this->getTeam() == 2) {
                    Game::team2Size--;
                    Game::team2[this->getPos()]->getUnit().setInitiative(-1);
                    qDebug() << Game::team2Size << '\n';
                }
                if (Game::turn == 1)
                    Game::dead2.insert(this->getPos());
                else if (Game::turn == 2)
                    Game::dead1.insert(this->getPos());
                delete this;
            }
            else
                hp->setText(QString::number(unit.getHp()));
        }
    }
    else {
        if (Game::turn == this->team) {
            Game::canPlay = true;
        }
        else
            Game::canPlay = false;

        if (Game::turn == this->team) {
            unit.setHp(Game::currentUnit.getDamage());
            hp->setText(QString::number(unit.getHp()));
        }
    }
    qDebug() << "end of ani event" << '\n';
}

MyAniItem::MyAniItem(int _team, int _pos, QString _name, QGraphicsItem* parent)
    : QGraphicsProxyWidget(parent), team(_team), pos(_pos)
{
    unit = Units(_name);
    canFight = true;
    hp = new QLabel(QString::number(unit.getHp()));
    hp->setAttribute(Qt::WA_TranslucentBackground);
    gif_lbl = new QLabel();
    movie = new QMovie("D:/Qt/Images/wizard_gif.gif");//добавить картинки для различных юнитов
    gif_lbl->setMovie(movie);
    gif_lbl->setAttribute(Qt::WA_TranslucentBackground);
    this->setWidget(gif_lbl);
    this->setPos(400, 350);
    this->setScale(5);
    movie->start();
}

Units MyAniItem::getUnit() {
    return unit;
}

QLabel* MyAniItem::getHp() {
    return hp;
}

int MyAniItem::getTeam() {
    return team;
}

int MyAniItem::getPos() {
    return pos;
}
