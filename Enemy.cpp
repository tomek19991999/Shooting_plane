#include "Enemy.h"
#include <QGraphicsScene>
#include <QDebug.h>
#include <QTimer>
#include <stdlib.h>	//randomize

Enemy::Enemy()
{
	//set random position
	int random_number = rand() % 700;
	setPos(random_number, 0);

	//drew the rect
	setRect(0, 0, 100, 100);

	//connect
	QTimer* timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

	timer->start(50);	//every 50miliseconds there is timeout SIGNAL
}

void Enemy::move() {
	//move enemy down
	setPos(x(), y() + 5);
	if (pos().y() + rect().height() < rect().height()) {
		scene()->removeItem(this);
		delete this;
	}
}
