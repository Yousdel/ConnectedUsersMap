#include <QCoreApplication>
#include "comap.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ConnectedUsersMap c;
    c.append(1000,"sely",0);
    c.append(2000,"may", 0);
    c.append(505,"you",0);
    c.append(939, "jair",0);

    c.showItemsByConsole();

    c.setNewMsgFromByNick("may",1);
    c.setNewMsgFromByHandle(939,1);

    c.showItemsByConsole();

    qDebug()<<"nickForHandle(505): "<<
              c.nickForHandle(505);
    qDebug()<<"contains(1000):"<<
              c.contains(1000) <<
              "      contains(9)"<<c.contains(9);
    qDebug()<<"handles: " << c.handles();
    qDebug() << "handlefornick(\"may\"): "<< c.handleForNick("may");

    c.removeElement(505);
    qDebug("c.removeElement(505) and :");
    c.showItemsByConsole();

    return a.exec();
}
