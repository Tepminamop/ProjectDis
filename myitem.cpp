#include "myitem.h"

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event)
    qDebug() << "Item clicked" << '\n';
    this->setScale(0.3);
    this->setScale(0.3);
    this->setPixmap(QPixmap("D:/Qt/Images/girl.png"));
}
