#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <connectevent.h>
#include <countnumber.h>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ConnectEvent *event = new ConnectEvent();
    CountNumber *event2 = new CountNumber();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *root = engine.rootObjects()[0];                // qrc:/main.qml를 등록한 엔진의 object 값을 가져옴

    event->setWindow(qobject_cast<QQuickWindow *>(root));   // qrc:/main.qml를 등록한 엔진의 object 값을 window 타입으로 변경해준다.
    event2->setWindow(qobject_cast<QQuickWindow *>(root));  // 이 부분을 작성해주지 않으면 CountNumber 클래스를 import 할 수 없어서 오류가 발생한다.(★★★)

    if(engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
