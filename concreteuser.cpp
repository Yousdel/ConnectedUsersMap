#include "concreteuser.h"

ConcreteUser::ConcreteUser()
{
    handle=-1; new_msg_from=0;
}

ConcreteUser::ConcreteUser(
        const qintptr &handle,
        const QString &nick, const bool &new_msg_from)
{
    this->handle=handle;    this->nick=nick;
    this->new_msg_from=new_msg_from;
}
