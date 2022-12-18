#pragma once
#include <QGraphicsRectItem>
#include <QObject>

class MyRect: public QObject, public QGraphicsRectItem
{	Q_OBJECT
	public:
		void keyPressEvent(QKeyEvent* event);
public slots:
	void spawn();
};

