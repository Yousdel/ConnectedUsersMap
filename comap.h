#ifndef MAPA_H
#define MAPA_H

#include "concreteuser.h"
#include <QVector>

/**
 * @brief Clase con los usuarios conectados
 */
class ConnectedUsersMap
{
private:
    QVector<InterfaceUser *> v;
public:
    ConnectedUsersMap();
    void clear()
    {
        v.clear();
    }
    void append(const qintptr&handle,const QString &nick,
                const bool new_msg_from=0);
    void setNewMsgFromByHandle(const qintptr&handle,
                               const bool new_msg_from);
    void setNewMsgFromByNick(const QString &nick,
                             const bool new_msg_from);
    void removeElement(const qintptr&handle);
    void removeElement(const QString &nick)
    {
        removeElement(handleForNick(nick));
    }

    void showItemsByConsole() const;
    //----------------------getters-----------------------------
    /**
     * @brief devuelve el nick
     * correspondiente al handle, si no
     * es posible devuelve una cadena vacia.
     */
    QString nickForHandle(const qintptr&handle) const;
    qintptr handleForNick(const QString &nick) const;
    bool newMsgFromForHandle(const qintptr &handle) const;
    bool contains(const qintptr&handle) const;
    int indexOfHandle(const qintptr &handle) const;
    QList<qintptr> handles() const;
    int size() const
    {
        return v.size();
    }
    const InterfaceUser *at(const int &index) const
    {
        return v.at(index);
    }

};

#endif // MAPA_H
