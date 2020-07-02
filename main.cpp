#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <connectevent.h>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ConnectEvent *event = new ConnectEvent();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *root = engine.rootObjects()[0];                // qrc:/main.qml를 등록한 엔진의 object 값을 가져옴

    event->setWindow(qobject_cast<QQuickWindow *>(root));   // qrc:/main.qml를 등록한 엔진의 object 값을 window 타입으로 변경해준다.

    if(engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

//test
