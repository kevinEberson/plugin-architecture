#include <QCoreApplication>
#include <QPluginLoader>
#include <QTextStream>
#include <QDebug>

#include "../plugins/helloworldplugin/plugininterface.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Setup user input
    QTextStream stream(stdin);

    // Plugin paths
    QString pluginPath = QCoreApplication::applicationDirPath() + "/plugins";
    QString helloPluginPath = pluginPath + "/helloworldplugin.dll";
    QString p1PluginPath = pluginPath + "/p1plugin.dll";

    // Hello plugin load
    // Load the helloworld plugin
    QPluginLoader helloLoader(helloPluginPath);
    if (!helloLoader.load()) {
        qDebug() << "Error loading plugin:" << helloLoader.errorString();
        return 1;
    }

    // Access the helloworld plugin
    PluginInterface *helloPlugin = qobject_cast<PluginInterface*>(helloLoader.instance());
    if (!helloPlugin) {
        qDebug() << "Error casting hello plugin instance";
        return 1;
    }

    // p1 plugin load
    // Load the helloworld plugin
    QPluginLoader p1Loader(p1PluginPath);
    if (!p1Loader.load()) {
        qDebug() << "Error loading plugin:" << p1Loader.errorString();
        return 1;
    }

    // Access the helloworld plugin
    PluginInterface *p1Plugin = qobject_cast<PluginInterface*>(p1Loader.instance());
    if (!p1Plugin) {
        qDebug() << "Error casting p1 plugin instance";
        return 1;
    }

    qInfo();
    qInfo() << "EASY backend plugin manager";
    qInfo() << "Available commands:";
    qInfo() << "hello";
    qInfo() << "p1";
    qInfo() << "quit";
    qInfo();

    while (true)
    {
        qInfo() << "Enter a command:" << Qt::endl;
        QString command = stream.readLine().toLower();

        if(command == "quit")
        {
            break;
        }
        else if(command == "hello")
        {
            helloPlugin->usePlugin();
        }
        else if(command == "p1")
        {
            p1Plugin->usePlugin();
        }
        else
        {
            qInfo() << "Invalid command";
        }
    }

    // Unload the plugins
    if(!helloLoader.unload())
    {
        qDebug() << "Failed to unload HelloWorld plugin";
        return 1;
    }

    if(!p1Loader.unload())
    {
        qDebug() << "Failed to unload P1 plugin";
        return 1;
    }


    return 0;
}
