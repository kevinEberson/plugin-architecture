#include <QCoreApplication>
#include <QPluginLoader>
#include <QDebug>

#include "../plugins/helloworldplugin/helloplugininterface.h"
#include "../plugins/goodbyworldplugin/goodbyplugininterface.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString pluginPath = QCoreApplication::applicationDirPath() + "/helloworldplugin/helloworldplugin.dll";

    // Load the helloworld plugin
    QPluginLoader helloLoader(pluginPath);
    if (!helloLoader.load()) {
        qDebug() << "Error loading plugin:" << helloLoader.errorString();
        return 1;
    }

    // Access the helloworld plugin
    HelloPluginInterface *helloPlugin = qobject_cast<HelloPluginInterface*>(helloLoader.instance());
    if (!helloPlugin) {
        qDebug() << "Error casting plugin instance";
        return 1;
    }

    // Use the plugin
    helloPlugin->hello();

    // Unload the plugin
    if(!helloLoader.unload())
    {
        qDebug() << "Failed to unload HelloWorld plugin";
        return 1;
    }

    // Set the plugin path to the other plugin
    pluginPath = QCoreApplication::applicationDirPath() + "/goodbyworldplugin/goodbyworldplugin.dll";

    // Load the goodbyworld plugin
    QPluginLoader goodbyLoader(pluginPath);
    if (!goodbyLoader.load()) {
        qDebug() << "Error loading plugin:" << goodbyLoader.errorString();
        return 1;
    }

    // Access the goodbyworld plugin
    GoodbyPluginInterface *goodbyPlugin = qobject_cast<GoodbyPluginInterface*>(goodbyLoader.instance());
    if (!goodbyPlugin) {
        qDebug() << "Error casting plugin instance";
        return 1;
    }

    // Use the plugin
    goodbyPlugin->goodby();

    // Unload the plugin
    if(!goodbyLoader.unload())
    {
        qDebug() << "Failed to unload GoodbyWorld plugin";
        return 1;
    }

    return 0;
}
