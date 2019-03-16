#include "testconvert_p_10.h"
#include "convert_p_10.h"
#include <QTest>


testconvert_p_10::testconvert_p_10(QObject *parent) :
    QObject(parent)
{

}


void testconvert_p_10::TestConvert1(){
Convert_p_10 a;
QString P_num="ABC";
long long p = 16;
long long weight = 16;
double ExpectedValue = 171.75;
double ActualValue = a.convert(P_num, p, weight);
double delta=0.01;
QVERIFY((ActualValue-delta<=ExpectedValue)&&(ActualValue+delta>=ExpectedValue));
}
void testconvert_p_10::TestConvert2(){
    Convert_p_10 a;
    QString P_num="1010111";
    long long p = 2;
    long long weight = 8;
    double ExpectedValue = 10.875;
    double ActualValue = a.convert(P_num, p, weight);
    double delta=0.01;
    QVERIFY((ActualValue-delta<=ExpectedValue)&&(ActualValue+delta>=ExpectedValue));
}
void testconvert_p_10::TestConvert3(){
    Convert_p_10 a;
    QString P_num="FFFF";
    long long p = 16;
    long long weight = 256;
    double ExpectedValue = 4095.94;
    double ActualValue = a.convert(P_num, p, weight);
    double delta=0.01;
    QVERIFY((ActualValue-delta<=ExpectedValue)&&(ActualValue+delta>=ExpectedValue));
}
void testconvert_p_10::TestConvert4(){
    Convert_p_10 a;
    QString P_num="9999";
    long long p = 10;
    long long weight = 100;
    double ExpectedValue = 999.9;
    double ActualValue = a.convert(P_num, p, weight);
    double delta=0.01;
    QVERIFY((ActualValue-delta<=ExpectedValue)&&(ActualValue+delta>=ExpectedValue));
}
void testconvert_p_10::TestDval1(){
    QString Number = "222.222";
    int P = 4;
    double ExpectedValue = 42.65625;
    Convert_p_10 a;

    double ActualValue = a.dval(Number, P);
    QCOMPARE(true,(qFloatDistance(ExpectedValue,ActualValue)< (1 <<8)));
}
void testconvert_p_10::TestDval2(){
    QString Number = "FFF.FFF";
    int P = 16;
    double ExpectedValue = 4095.999755859375;
    Convert_p_10 a;
    double ActualValue = a.dval(Number, P);
    QCOMPARE(true,(qFloatDistance(ExpectedValue,ActualValue)< (1 <<8)));
}
void testconvert_p_10::TestDval3(){
    QString Number = "100.001";
    int P = 2;
    double ExpectedValue = 4.125;
    Convert_p_10 a;
    double ActualValue = a.dval(Number, P);
    QCOMPARE(true,(qFloatDistance(ExpectedValue,ActualValue)< (1 <<8)));
}
void testconvert_p_10::TestDval4(){
    QString Number = "888.888";
    int P = 9;
    double ExpectedValue = 728.998628257887517;
    Convert_p_10 a;
    double ActualValue = a.dval(Number, P);
    QCOMPARE(true,(qFloatDistance(ExpectedValue,ActualValue)< (1 <<8)));
}
void testconvert_p_10::TestChar_To_num1(){
    Convert_p_10 a;
    QChar Char ='A';
    int ExpectedValue=10;
    QCOMPARE(ExpectedValue,a.char_To_num(Char));
}
void testconvert_p_10::TestChar_To_num2(){
    Convert_p_10 a;
    QChar Char ='0';
    int ExpectedValue=0;
    QCOMPARE(ExpectedValue,a.char_To_num(Char));
}
void testconvert_p_10::TestChar_To_num3(){
    Convert_p_10 a;
    QChar Char ='F';
    int ExpectedValue=15;
    QCOMPARE(ExpectedValue,a.char_To_num(Char));
}
void testconvert_p_10::TestChar_To_num4(){
    Convert_p_10 a;
    QChar Char ='?';
    int ExpectedValue=-1;
    QCOMPARE(ExpectedValue,a.char_To_num(Char));
}
