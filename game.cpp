#include "game.h"

Game::Game(QWidget* parent) :
    QGraphicsView(parent)
{
    info = new QLabel("Turn 0");

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1918, 1078);

    vector<QString> names1;
    names1.push_back("Wizard");
    names1.push_back("Barbarian");
    names1.push_back("Ranger");
    names1.push_back("Wizard");
    names1.push_back("Healer");
    names1.push_back("Barbarian");
    vector<QString> names2;
    names2.push_back("Wizard");
    names2.push_back("Barbarian");
    names2.push_back("Wizard");
    names2.push_back("Wizard");
    names2.push_back("Healer");
    names2.push_back("Barbarian");
    if (team1.size() == 0) {
        for (int i = 0; i < team1Size; i++) {
            team1.push_back(new MyAniItem(1, i, names1[i]));
            team1[i]->setPos(x1, y1);
            scene->addWidget(team1[i]->getHp())->setPos(x1 + 25, y1 - 10);
            x1 += 100;
        }
    }
    if (team2.size() == 0) {
        for (int i = 0; i < team2Size; i++) {
            team2.push_back(new MyAniItem(2, i, names2[i]));
            team2[i]->setPos(x2, y2);
            scene->addWidget(team2[i]->getHp())->setPos(x2 + 25, y2 - 10);
            x2 += 100;
        }
    }

    for (int i = 0; i < team1Size; i++) {
        scene->addItem(team1[i]);
    }
    for (int i = 0; i < team2Size; i++) {
        scene->addItem(team2[i]);
    }
    scene->addWidget(info);
    scene->setBackgroundBrush(QBrush(QImage("D:/Qt/Images/field1.png")));
    this->setScene(scene);
    play();
}

void Game::mousePressEvent(QMouseEvent *event) {
    qDebug() << "View event" << '\n';//добавить очередность ходов, возможность сделать статический флаг
    QGraphicsView::mousePressEvent(event);
    if (canPlay) {
        canPlay = false;
        qDebug() << "can play" << '\n';
        play();//play только в том случае, если юнит ударил врага (если ударил своего ход должен продолжаться)
    }
}

int Game::currentPos = 0;

bool Game::canPlay = false;

int Game::turn = 0;

int Game::team1Size = 6;
int Game::team2Size = 6;

set<int> Game::dead1;
set<int> Game::dead2;

vector<MyAniItem*> Game::team1;
vector<MyAniItem*> Game::team2;
Units Game::currentUnit = Units();

void Game::keyPressEvent(QKeyEvent* e) {
    if(e->key() == Qt::Key_Escape)
        qApp->quit();
}

int Game::getTurn() {
    return turn;
}

void Game::setTurn() {

}

int Game::getWhite() {
    return white;
}

void Game::setWhite(int pos) {
    white = pos;
}

void Game::play() {

    srand(time(NULL));//добавить множества в которых будут храниться юниты, которые уже атаковали в текущем ходу, как только все проатакуют, множества обнуляются

    if (turn == 1)
        team1[getWhite()]->getHp()->setStyleSheet("QLabel { color : black; }");
    else if (turn == 2)
        team2[getWhite()]->getHp()->setStyleSheet("QLabel { color : black; }");

    int maxInitiative_1 = 0;
    int maxPos1 = 0;
    int maxInitiative_2 = 0;
    int maxPos2 = 0;

    qDebug() << "116" << '\n';
    int currentSize1 = dead1.size();
    int currentSize2 = dead2.size();
    for (int i = 0; i < 6; i++) {
        if (dead1.find(i) == dead1.end() && fought1.find(i) != fought1.end())
            currentSize1++;
    }
    for (int i = 0; i < 6; i++) {
        if (dead2.find(i) == dead2.end() && fought2.find(i) != fought2.end())
            currentSize2++;
    }
    if (currentSize1 == 6 && currentSize2 == 6) {
        fought1.clear();
        fought2.clear();
    }
    /*
    if ((fought1.size() + dead1.size() >= 6) && (fought2.size() + dead2.size() >= 6)) {//исправить, так как во время битвы могли быть потери
        fought1.clear();
        fought2.clear();
    }
    */

    qDebug() << "set 1 size: " << fought1.size() + dead1.size() << '\n';;

    for (unsigned int i = 0; i < team1.size(); i++) {
        if (dead1.find(i) == dead1.end()) {
            if (team1[i]->getUnit().getInitiative() > maxInitiative_1 && fought1.find(i) == fought1.end()) {
                maxInitiative_1 = team1[i]->getUnit().getInitiative();
                maxPos1 = i;
            }
        }
    }

    qDebug() << "set2 size: " << fought2.size() + dead2.size() << '\n';

    for (unsigned int i = 0; i < team2.size(); i++) {
        if (dead2.find(i) == dead2.end()) {
            if (team2[i]->getUnit().getInitiative() > maxInitiative_2 && fought2.find(i) == fought2.end()) {
                maxInitiative_2 = team2[i]->getUnit().getInitiative();
                maxPos2 = i;
            }
        }
    }

    qDebug() << "137" << '\n';

    if (maxInitiative_1 == maxInitiative_2)
        turn = 1 + std::rand() % 2;
    else if (maxInitiative_1 > maxInitiative_2)
        turn = 1;
    else if (maxInitiative_1 < maxInitiative_2)
        turn = 2;

    qDebug() << "151" << '\n';
    qDebug() << "turn " << turn << " maxpos1 " << maxPos1 << " maxpos2 " << maxPos2 << '\n';

    if (turn == 1) {
        currentUnit = team1[maxPos1]->getUnit();
        currentPos = maxPos1;
        info->setText("Turn 1");
        team1[maxPos1]->getHp()->setStyleSheet("QLabel { color : white; }");
        setWhite(maxPos1);
        fought1.insert(maxPos1);
    }
    else {
        info->setText("Turn 2");
        currentUnit = team2[maxPos2]->getUnit();
        currentPos = maxPos2;
        team2[maxPos2]->getHp()->setStyleSheet("QLabel { color : white; }");
        setWhite(maxPos2);
        fought2.insert(maxPos2);
    }

    if (team1Size == 0 && team2Size == 0)
        info->setText("Draw");
    if (team1Size == 0)
        info->setText("2 won");
    if (team2Size == 0)
        info->setText("1 won");

    qDebug() << "end of play" << '\n';
}

