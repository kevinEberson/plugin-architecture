#include "p1plugin.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QUrl>

void P1Plugin::usePlugin()
{
    // Create a QNetworkAccessManager
    QNetworkAccessManager manager;

    // Create a request for the endpoint
    QNetworkRequest request(QUrl("http://localhost:1880/power_delivered"));

    // Make a synchronous GET request
    QEventLoop loop;
    QNetworkReply *reply = manager.get(request);
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Check for errors
    if (reply->error() == QNetworkReply::NoError) {
        // Read the response as a string
        QString response = reply->readAll();
        qDebug() << "Response: " << response;
    } else {
        // Handle errors
        qDebug() << "Error: " << reply->errorString();
    }

    // Clean up
    reply->deleteLater();
}
