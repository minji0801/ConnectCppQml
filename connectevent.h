#ifndef CONNECTEVENT_H
#define CONNECTEVENT_H

#include <QQuickView>   // Qt Quick 사용자 인터페이스를 표시하는 창을 제공해준다.
#include <QObject>      // 모든 Qt 객체의 기본 클래스이다.

class ConnectEvent : public QObject // connection을 사용하기 위해 상속받아야 하는 클래스
{
public:
    Q_OBJECT    // Q_OBJECT 추가한 후 Build->Run qmake 하기(중요★★★)

public:
    ConnectEvent();
    ~ConnectEvent();

    void cppSignaltoQmlSlot();  // cpp에서 시그널을 날리고 qml에서 받기 위해 connection을 해두는 함수
    void setWindow(QQuickWindow *Window);

private:
    QQuickWindow *mMainView;

signals:    // 클래스에서 siganl 등록하는 방법
    void cppSignaltestData(QVariant);
};

#endif // CONNECTEVENT_H
