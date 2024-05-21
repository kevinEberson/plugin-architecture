#ifndef HELLOPLUGININTERFACE_H
#define HELLOPLUGININTERFACE_H

#include <QObject>

class HelloPluginInterface {
public:
    virtual ~HelloPluginInterface() {}
    virtual void hello() = 0;
};

#define HelloPluginInterface_iid "org.example.HelloPluginInterface"

Q_DECLARE_INTERFACE(HelloPluginInterface, HelloPluginInterface_iid)

#endif // HELLOPLUGININTERFACE_H
