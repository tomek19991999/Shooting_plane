#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include "MyRect.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    //create an item to put into the scene
    MyRect* player = new MyRect();
    player->setRect(0, 0, 100, 100);

    //add the item to the scene
    scene->addItem(player);

    //make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);  //make focusable
    player->setFocus();   //make this one focus

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    //show view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0, 0, 800, 600);

    player->setPos(view->width() / 2, view->height() - player->rect().height());

    //spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
