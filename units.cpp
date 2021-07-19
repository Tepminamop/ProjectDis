#include "units.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

Units::Units(QString _name) :
    name(_name)
{
    counter++;
    if (counter == 1)
        mydb.setDatabaseName("D:/Sqlite/SQLiteStudio/army.db");
    if(!mydb.open())
        qDebug() << mydb.lastError().text();
    //query = QSqlQuery();
    query.exec(query_str.arg(_name));
    while (query.next()) {
        hp = query.value(1).toInt();
        damage = query.value(2).toInt();
        initiative = query.value(3).toInt();
        accuracy = query.value(4).toInt();
        armor = query.value(5).toInt();
        range = query.value(6).toBool();
        ismage = query.value(7).toBool();
        size = query.value(8).toInt();
    }
    if (counter == 12)
        mydb.close();
}

Units::Units(const Units& unit) :
    name(unit.name), inDefence(false)
{
    hp = unit.hp;
    damage = unit.damage;
    initiative = unit.initiative;
    accuracy = unit.accuracy;
    armor = unit.armor;
    range = unit.range;
    ismage = unit.ismage;
    size = unit.size;
    query = QSqlQuery();
    query_str = "select * from units where name = '%1'";
}

int Units::counter = 0;

QSqlDatabase Units::mydb = QSqlDatabase::addDatabase("QSQLITE");

std::ostream& operator<< (std::ostream &out, const Units &unit) {
    out << unit.name.toStdString() << "(HP: " << unit.hp << ", DAMAGE: " << unit.damage << ", INITIATIVE: " << unit.initiative << ", ACCURACY: " << unit.accuracy << \
           ", ARMOR: " << unit.armor << ", RANGE: " << (int)unit.range << ", ISMAGE: " << (int)unit.ismage << ", SIZE: " << unit.size << ")" << '\n';
    return out;
}

void Units::setInitiative(int ini) {
    initiative = ini;
}

int Units::getHp() {
    return this->hp;
}

void Units::setHp(int damage) {
    hp -= damage;
}

int Units::getInitiative() {
    return this->initiative;
}

int Units::getDamage() {
    return damage;
}
