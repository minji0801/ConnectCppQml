#include "connectevent.h"

ConnectEvent::ConnectEvent()
{

}

ConnectEvent::~ConnectEvent()
{

}

void ConnectEvent::cppSignaltoQmlSlot() // cpp에서 signal을 보내면 qml에서 slot함수를 실행하는 함수
{
    /*
     * 23번째 줄의 의미 : 현재 클래스의 cppSignaltestData의 signal을 호출하면 main.qml이 등록된 윈도우인 mMainView의 qmlSlotTestData 함수를 호출하겠다.
     *
     * 여기서 매개 변수에 QVariant로 한 이유는 qml이 자바스크립트 문법을 그대로 사용하는 언어인데
     * 자바스크립트의 var 즉 variables를 표현하기 위한 것으로 따로 지정한 타입이 없어서 넣은 값에 따라 타입이 바뀌게 하는 것이다.
     *
     * 그래서 int형을 넣으면 int 형으로 보내지고 string형으로 보내면 string형식으로 보내지는 것이다.
    */
    QObject::connect(this, SIGNAL(cppSignaltestData(QVariant)), mMainView, SLOT(qmlSlotTestData(QVariant)));// cpp 시그널과 슬롯을 연결해주는 connection
    /*
     * 27번째 줄의 의미 : 메인 윈도우의 signal이 발생하면 현재 클래스의 slot이 발생한다.
    */
    QObject::connect(mMainView, SIGNAL(qmlSignalStringData(QVariant)), this, SLOT(cppSlotStringData(QVariant)));    // qml 시그널과 cpp 슬롯을 연결해주는 connection
    QObject::connect(mMainView, SIGNAL(qmlSignalintData(QVariant)), this, SLOT(cppSlotintData(QVariant)));  // qml 시그널과 cpp 슬롯을 연결해주는 connection

    emit cppSignaltestData(3);  // cpp에서 시그널을 호출하는 부분 매개변수에 3을 넣어서 3이 qml 함수에 전달됨
    emit cppSignaltestData(4);  // emit 키워드를 통해 시그널을 발생시킨다.
    emit cppSignaltestData(5);
    emit cppSignaltestData("test");
}

void ConnectEvent::setWindow(QQuickWindow *Window)
{
    mMainView = Window;     // connection을 해주기 위해 윈도우를 등록

    cppSignaltoQmlSlot();   // 윈도우 등록과 동시에 connection 등록
}

void ConnectEvent::cppSlotStringData(QVariant stringData)
{
    cout<<"cppSlotTestData call" << endl;
    std::string data_str = stringData.toString().toStdString(); // QVarint를 std::string으로 변환
    cout<<"cppSlotTestData data_str: "<<data_str<<endl;
}

void ConnectEvent::cppSlotintData(QVariant intData)
{
    cout<<"cppSlotintData call" << endl;
    int data = intData.toInt(); // QVarint를 int형으로 변환
    cout<<"cppSlotintData data: "<<data<<endl;
}
