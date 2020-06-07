#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "qsomodel.h"
#include "settingsmodel.h"
#include "dbmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    dbManager db;
    db.createTables();

    qsoModel qModel;
    settingsModel sModel;
    QQmlApplicationEngine engine;

    // Load the QML and set the Context:
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    engine.rootContext()->setContextProperty("qsoModel", QVariant::fromValue(&qModel));
    engine.rootContext()->setContextProperty("settingsModel", QVariant::fromValue(&sModel));

    return app.exec();
}
