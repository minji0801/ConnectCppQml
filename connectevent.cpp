#include "connectevent.h"

ConnectEvent::ConnectEvent()
{

}

ConnectEvent::~ConnectEvent()
{

}

void ConnectEvent::cppSignaltoQmlSlot() // cpp에서 signal을 보내면 qml에서 slot함수를 실행하는 함수
{
    QObject::connect(this, SIGNAL(cppSignaltestData(QVariant)), mMainView, SLOT(qmlSlotTestData(QVariant)));// 시그널과 슬롯을 연결해주는 connection
    emit cppSignaltestData(3);  // cpp에서 시그널을 호출하는 부분 매개변수에 3을 넣어서 3이 qml 함수에 전달됨
    emit cppSignaltestData(4);  // emit 키워드를 통해 시그널을 발생시킨다.
    emit cppSignaltestData(5);
    emit cppSignaltestData(6);
}

void ConnectEvent::setWindow(QQuickWindow *Window)
{
    mMainView = Window;     // connection을 해주기 위해 윈도우를 등록

    cppSignaltoQmlSlot();   // 윈도우 등록과 동시에 connection 등록
}
