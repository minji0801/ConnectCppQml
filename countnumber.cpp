#include "countnumber.h"

CountNumber::CountNumber()
{
    cout<<"CountNumber"<<endl;
    qmlRegisterType<CountNumber>("CountNumber", 1, 0, "CountNumber");   // qml 파일에서 import CountNumber 1.0 해주기 위해서
}

CountNumber::~CountNumber()
{

}

void CountNumber::setWindow(QQuickWindow *Window)
{
    mMainView = Window;
}

QString CountNumber::countUp(QString stringData)
{
    // + 버튼을 클릭했을 때 실행될 함수
    // text 값을 인수로받아 + 1 한 값을 string으로 return해주기
    int inputNumber = stringData.toInt() + 1;
    QString output = QString::number(inputNumber);
    return output;
}

QString CountNumber::countDown(QString stringData)
{
    // - 버튼을 클릭했을 때 실행될 함수
    // text 값을 인수로받아 - 1 한 값을 string으로 return해주기
    int inputNumber = stringData.toInt() - 1;
    QString output = QString::number(inputNumber);
    return output;
}
