#ifndef CONCRETEUSER_H
#define CONCRETEUSER_H

#include "interfaceuser.h"
#include <QString>

/**
 * @brief Usuario conectado con todas sus funciones
 */
class ConcreteUser : public InterfaceUser
{
public:
    ConcreteUser();
    ConcreteUser(const qintptr &handle,
                 const QString &nick,
                 const bool &new_msg_from=0);
    void
    setHandle(const qintptr &handle)
    {
        this->handle = handle;
    }

    /**
     * @brief el usuario no es
     * valido cuando se ha
     * desconectado, mientras esta conectado
     * es valido
     */
    bool
    isValid() override { return handle!=-1;}
};

#endif // CONCRETEUSER_H
