#ifndef TESTCONVER_10_P_H
#define TESTCONVER_10_P_H

#include <QObject>

class testconver_10_p : public QObject
{
    Q_OBJECT
public:
     explicit testconver_10_p(QObject *parent=0);
private slots:
    void TestDo1();
    void TestDo2();
    void TestDo3();
    void TestDo4();
    void TestIntToChar1();
    void TestIntToChar2();
    void TestIntToChar3();
    void TestIntToChar4();
    void TestIntToP1();
    void TestIntToP2();
    void TestIntToP3();
    void TestIntToP4();
    void TestFlttoP1();
    void TestFlttoP2();
    void TestFlttoP3();
    void TestFlttoP4();



};




#endif // TESTCONVER_10_P_H
