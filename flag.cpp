#include "flag.h"

Flag::Flag()
{
}

Flag::Flag(QPoint startPos) : xPos(startPos.x()), yPos(startPos.y()), increment(50)
{
    this->life = 10;
    this->attack = 1;
    this->rate = 0.5;
    this->speed = 3.75;

    this->setPos(startPos);
    flagPixmap = (QPixmap(":/Images/Flag.png")).scaledToHeight(50);
}

Flag::~Flag()
{
    delete collisionRect;
}

void Flag::move()
{
    if (!(this->collidesWithItem(this)) && (xPos != 0))
    {
        xPos += increment;
        increment--;
        this->setPos(xPos,yPos);
    }
}

void Flag::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect(), flagPixmap, boundingRect());
}

QRectF Flag::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void Flag::advance(int phase)
{
    if (!phase) return;
    move();

    collisionRect = new QGraphicsRectItem(this->x(), this->y(), flagPixmap.width(), flagPixmap.height());
    QList<QGraphicsItem *> list = scene()->collidingItems(collisionRect);
    for (int i = 0; i < (int)list.size(); i++)
    {
        Bullet *item = dynamic_cast<Bullet *>(list.at(i));
        if (item)
        {
            this->life--;
        }
    }

    if (this->life <= 0)
        delete this;
}
