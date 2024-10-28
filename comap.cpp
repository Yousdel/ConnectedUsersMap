#include "comap.h"
#include <QDebug>

ConnectedUsersMap::ConnectedUsersMap()
{

}



void ConnectedUsersMap::append(const qintptr &handle,
                   const QString &nick,
                   const bool new_msg_from)
{
    InterfaceUser *u = new ConcreteUser(handle,nick,new_msg_from);
    v.append(u);
}

void ConnectedUsersMap::setNewMsgFromByHandle(const qintptr &handle,
                                  const bool new_msg_from)
{
    for (InterfaceUser *cu : v) {
        if (handle==cu->handle){
            cu->new_msg_from = new_msg_from; break;
        }
    }
}

void ConnectedUsersMap::setNewMsgFromByNick(const QString &nick,
                                const bool new_msg_from)
{
    for (InterfaceUser *cu : v) {
        if (nick==cu->nick){
            cu->new_msg_from = new_msg_from; break;
        }
    }
}

void ConnectedUsersMap::removeElement(const qintptr &handle)
{
    for (InterfaceUser *cu : v) {
        if (handle==cu->handle){
            v.removeOne(cu);
        }
    }
}



void ConnectedUsersMap::showItemsByConsole() const
{
#ifndef QDEBUG_H
    return;
#endif

    qDebug() << "Items of Map:";
    qDebug() << "--------------------------------";
    for (const InterfaceUser *cu : v) {
        qDebug() << "handle: " << cu->handle;
        qDebug() << "nick:   " << cu->nick;
        qDebug() << "new msg from: " << cu->new_msg_from;
        qDebug() << "--------------------------------";
    }
}

QString ConnectedUsersMap::nickForHandle(const qintptr &handle) const
{
    for (const InterfaceUser *cu : v) {
        if (handle==cu->handle){
            return cu->nick;
        }
    }
    return QString();
}

qintptr ConnectedUsersMap::handleForNick(const QString &nick) const
{
    //buscar en mmap el nick
    const auto k = handles();
    for (auto kk : k) {
        if (nickForHandle(kk)==nick) return kk;
    }
    return -1;
}

bool ConnectedUsersMap::newMsgFromForHandle(const qintptr &handle) const
{
    for (const InterfaceUser *cu : v) {
        if (handle==cu->handle){
            return cu->new_msg_from;
        }
    }
    return 0;
}

bool ConnectedUsersMap::contains(const qintptr &handle) const
{
    for (const InterfaceUser *cu : v) {
        if (handle==cu->handle){
            return 1;
        }
    }
    return 0;

}

int ConnectedUsersMap::indexOfHandle(const qintptr &handle) const
{
    if (contains(handle))
    {
        for (int i = 0; i < v.size(); ++i) {
            if (handle == v.at(i)->handle) return i;
        }
    }
    return -1;
}

QList<qintptr> ConnectedUsersMap::handles() const
{
    QList<qintptr> l;
    for (const InterfaceUser *cu : v) {
        l<<cu->handle;
    }
    return l;
}
