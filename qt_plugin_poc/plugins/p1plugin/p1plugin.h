#ifndef P1PLUGIN_H
#define P1PLUGIN_H

#include <QObject>
#include "plugininterface.h"

class P1Plugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID "org.example.PluginInterface" FILE "plugininterface.json")

public:
    void usePlugin() override;
};

#endif // P1PLUGIN_H
