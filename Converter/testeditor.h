#ifndef TESTEDITOR_H
#define TESTEDITOR_H

#include <QObject>

class testeditor : public QObject
{
    Q_OBJECT
public:
     explicit testeditor(QObject *parent=0);
private slots:
    void TestAcc1();
    void TestAcc2();
    void TestAcc3();
    void TestAcc4();
    void TestAddDelim1();
    void TestAddDelim2();
    void TestAddDelim3();
    void TestAddDigit1();
    void TestAddDigit2();
    void TestAddDigit3();
    void TestAddDigit4();
    void TestBs1();
    void TestBs2();
    void TestBs3();
    void TestBs4();
};
#endif // TESTEDITOR_H



