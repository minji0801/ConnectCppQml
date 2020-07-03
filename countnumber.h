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
    Q_INVOKABLE QString countUp(QString stringData);
    Q_INVOKABLE QString countDown(QString stringData);

private:
    QQuickWindow *mMainView;
};

#endif // COUNTNUMBER_H
