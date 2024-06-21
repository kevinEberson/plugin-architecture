#ifndef plugininterface_H
#define plugininterface_H

#include <QObject>

class PluginInterface {
public:
    virtual ~PluginInterface() {}
    virtual void usePlugin() = 0;
};

#define PluginInterface_iid "org.example.PluginInterface"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)

#endif // plugininterface_H
