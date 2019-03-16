#include "testconver_10_p.h"
#include "conver_10_p.h"
#include <QTest>


testconver_10_p::testconver_10_p(QObject *parent) :
    QObject(parent)
{

}

void testconver_10_p::TestDo1(){
    double n = 123.000;
    int p = 12;
    int c = 3;
    QString ExpectedString = "A3.000";
    Conver_10_p conv;
    QString ActualString = conv.Do(n, p, c);
    QCOMPARE(ExpectedString, ActualString);
}

void testconver_10_p::TestDo2(){
    double n = 0.523;
    int p = 3;
    int c = 10;
    QString ExpectedString = "0.1120100210";
    Conver_10_p conv;
    QString ActualString = conv.Do(n, p, c);
    QCOMPARE(ExpectedString, ActualString);
}
void testconver_10_p::TestDo3(){
    double n = 999.999;
    int p = 2;
    int c = 3;
    QString ExpectedString = "1111100111.111";
    Conver_10_p conv;
    QString ActualString = conv.Do(n, p, c);
    QCOMPARE(ExpectedString, ActualString);
}
void testconver_10_p::TestDo4(){
    double n = 0.01;
    int p = 12;
    int c = 2;
    QString ExpectedString = "0.01";
    Conver_10_p conv;
    QString ActualString = conv.Do(n, p, c);
    QCOMPARE(ExpectedString, ActualString);
}
void testconver_10_p::TestIntToChar1(){
    int n = 0;
    QChar ExpectedChar = '0';
    Conver_10_p a;
    QChar ActualChar = a.int_to_Char(n);
    QCOMPARE(ExpectedChar,ActualChar);
}
void testconver_10_p::TestIntToChar2(){
    int n = 12;
    QChar ExpectedChar = 'C';
    Conver_10_p a;
    QChar ActualChar = a.int_to_Char(n);
    QCOMPARE(ExpectedChar,ActualChar);
}
void testconver_10_p::TestIntToChar3(){
    int n = 15;
    QChar ExpectedChar = 'F';
    Conver_10_p a;
    QChar ActualChar = a.int_to_Char(n);
    QCOMPARE(ExpectedChar,ActualChar);
}
void testconver_10_p::TestIntToChar4(){
    int n = -1;
    QChar ExpectedChar = -1;
    Conver_10_p a;
    QChar ActualChar=a.int_to_Char(n);
    QCOMPARE(ExpectedChar,ActualChar);
}
void testconver_10_p::TestIntToP1(){
    int n = 321;
    int p = 11;
    QString ExpectedString = "272";
    Conver_10_p a;
    QString ActualString = a.int_to_P(n, p);
    QCOMPARE(ExpectedString, ActualString);
}
void testconver_10_p::TestIntToP2(){
    int n = 222;
    int p = 3;
    QString ExpectedString = "22020";
    Conver_10_p a;
    QString ActualString = a.int_to_P(n, p);
    QCOMPARE(ExpectedString, ActualString);
}
void testconver_10_p::TestIntToP3(){
    int n = 123;
    int p = 12;
    QString ExpectedString = "A3";
    Conver_10_p a;
    QString ActualString = a.int_to_P(n, p);
    QCOMPARE(ExpectedString, ActualString);
}
void testconver_10_p::TestIntToP4(){
    int n = 999;
    int p = 2;
    QString ExpectedString = "1111100111";
    Conver_10_p a;
    QString ActualString = a.int_to_P(n, p);
    QCOMPARE(ExpectedString, ActualString);
}
void testconver_10_p::TestFlttoP1(){
    double n = 0.222;
    int p = 12;
    int c = 3;
    QString ExpectedString = "27B";
    Conver_10_p a;
    QString ActualString = a.flt_to_P(n, p, c);
    QCOMPARE(ExpectedString, ActualString);
}
void testconver_10_p::TestFlttoP2(){
    double n = 0.999;
    int p = 16;
    int c = 6;
    QString ExpectedString = "FFBE76";
    Conver_10_p a;
    QString ActualString = a.flt_to_P(n, p, c);
    QCOMPARE(ExpectedString, ActualString);
}
void testconver_10_p::TestFlttoP3(){
    double n = 0.001;
    int p = 12;
    int c = 3;
    QString ExpectedString = "001";
    Conver_10_p a;
    QString ActualString = a.flt_to_P(n, p, c);
    QCOMPARE(ExpectedString, ActualString);
}
void testconver_10_p::TestFlttoP4(){
    double n = 0.101010;
    int p = 2;
    int c = 10;
    QString ExpectedString = "0001100111";
    Conver_10_p a;
    QString ActualString = a.flt_to_P(n, p, c);
    QCOMPARE(ExpectedString, ActualString);
}

