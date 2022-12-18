#include "MyRect.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug.h>
#include "Bullet.h"
#include "Enemy.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Left) {
		if(pos().x()>0)
		setPos(x() - 10, y());
	}
	else if (event->key() == Qt::Key_Right) {
		if (pos().x()+100 < 800)
			setPos(x() + 10, y());
	}
	else if (event->key() == Qt::Key_Space) {
		//create a bullet
		Bullet* bullet = new Bullet();
		bullet->setPos(x(), y());
		scene() -> addItem(bullet);
		qDebug() << "Bullet created";
	}

}

void MyRect::spawn() {
	//create an enemy
	Enemy* enemy = new Enemy();
	scene()->addItem(enemy);
}
