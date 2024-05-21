#ifndef HELLOWORLDPLUGIN_H
#define HELLOWORLDPLUGIN_H

#include <QObject>
#include "helloplugininterface.h"

class HelloWorldPlugin : public QObject, public HelloPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(HelloPluginInterface)
    Q_PLUGIN_METADATA(IID "org.example.HelloPluginInterface" FILE "helloworld.json")

public:
    void hello() override;
};

#endif // HELLOWORLDPLUGIN_H
