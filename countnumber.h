#ifndef COUNTNUMBER_H
#define COUNTNUMBER_H

#include <QQuickView>
#include <QObject>
#include <iostream>
using namespace std;

class CountNumber : public QObject
{
public:
    Q_OBJECT

public:
    CountNumber();
    ~CountNumber();

    void setWindow(QQuickWindow *Window);
    Q_INVOKABLE QString countUp(QString stringData);    // Q_INVOKABLE을 해줘야 qml에서 이 함수를 호출해서 쓸 수 있다.(★★★)
    Q_INVOKABLE QString countDown(QString stringData);

private:
    QQuickWindow *mMainView;
};

#endif // COUNTNUMBER_H
