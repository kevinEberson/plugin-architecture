#ifndef GOODBYWORLDPLUGIN_H
#define GOODBYWORLDPLUGIN_H

#include <QObject>
#include "goodbyplugininterface.h"

class GoodbyWorldPlugin : public QObject, public GoodbyPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(GoodbyPluginInterface)
    Q_PLUGIN_METADATA(IID "org.example.GoodbyPluginInterface" FILE "goodbyworld.json")

public:
    void goodby() override;
};

#endif // GOODBYWORLDPLUGIN_H
