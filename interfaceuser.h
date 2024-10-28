#ifndef INTERFACEUSER_H
#define INTERFACEUSER_H

#include <QString>

/**
 * @brief Clase base para identificar
 * un usuario conectado en red
 */
class InterfaceUser
{
public:
    InterfaceUser();

    qintptr handle;
    QString nick;
    bool new_msg_from;

    virtual bool isValid()=0;
};

#endif // INTERFACEUSER_H
