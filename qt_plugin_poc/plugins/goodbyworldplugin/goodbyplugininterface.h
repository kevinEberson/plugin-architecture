#ifndef GOODBYPLUGININTERFACE_H
#define GOODBYPLUGININTERFACE_H

#include <QObject>

class GoodbyPluginInterface {
public:
    virtual ~GoodbyPluginInterface() {}
    virtual void goodby() = 0;
};

#define GoodbyPluginInterface_iid "org.example.GoodbyPluginInterface"

Q_DECLARE_INTERFACE(GoodbyPluginInterface, GoodbyPluginInterface_iid)

#endif // GOODBYPLUGININTERFACE_H
