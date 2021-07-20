#pragma once
#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

class Units
{
public:
    Units(QString _name = "Wizard");
    Units(const Units& unit);
    int getHp();
    int getInitiative();
    int getDamage();
    bool inDef();
    void setDef(bool b);
    void setHp(int damage);
    void setInitiative(int ini);
    friend std::ostream& operator<< (std::ostream &out, const Units &unit);
    static QSqlDatabase mydb;
    static int counter;
private:
    QString name;
    int hp;
    int damage;
    int initiative;
    int accuracy;
    int armor;
    bool range;
    bool ismage;
    int size;
    bool inDefence;
    QSqlQuery query;
    QString query_str = "select * from units where name = '%1'";
};

