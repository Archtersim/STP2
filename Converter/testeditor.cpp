#include "testeditor.h"
#include "editor.h"
#include <QTest>


testeditor::testeditor(QObject *parent) :
    QObject(parent)
{

}


void testeditor::TestAcc1(){
    Editor editor;
    editor.AddDigit(2);
    editor.AddDigit(2);
    editor.AddDigit(8);
    editor.AddDelim();
    editor.AddDigit(1);
    editor.AddDigit(4);
    editor.AddDigit(8);
    editor.AddDigit(8);
    int ExpectedValue = 4;
    int ActualValue = editor.Acc();
    QCOMPARE(ExpectedValue, ActualValue);
}
void testeditor::TestAcc2(){
    Editor editor;
    editor.AddDigit(2);
    editor.AddDigit(2);
    editor.AddDigit(8);
    editor.AddDelim();
    int ExpectedValue = 0;
    int ActualValue = editor.Acc();
    QCOMPARE(ExpectedValue, ActualValue);
}
void testeditor::TestAcc3(){
    Editor editor;
    int ExpectedValue = 0;
    int ActualValue = editor.Acc();
    QCOMPARE(ExpectedValue, ActualValue);
}
void testeditor::TestAcc4(){
    Editor editor;
    editor.AddDigit(0);
    editor.AddDigit(0);
    editor.AddDigit(1);
    editor.AddDelim();
    editor.AddDigit(0);
    editor.AddDelim();
    editor.AddDigit(1);
    editor.AddDigit(0);
    int ExpectedValue = 3;
    int ActualValue = editor.Acc();
    QCOMPARE(ExpectedValue, ActualValue);
}
void testeditor::TestAddDelim1(){
    Editor editor;
    editor.AddDelim();
    QString ExpectedValue = "0.";
    QString ActualValue = editor.number;
    QCOMPARE(ExpectedValue, ActualValue);
}
void testeditor::TestAddDelim2(){
    Editor editor;

    editor.AddDigit(0);
    editor.AddDelim();
    editor.AddDigit(0);
    editor.AddDelim();
    editor.AddDigit(1);
    editor.AddDelim();
    editor.AddDigit(0);
    editor.AddDelim();
    editor.AddDigit(1);
    editor.AddDelim();
    editor.AddDigit(0);
    editor.AddDelim();
    QString ExpectedValue = "0.01010";
    QString ActualValue = editor.number;
    QCOMPARE(ExpectedValue, ActualValue);
}
void testeditor::TestAddDelim3(){
    Editor editor;
    editor.AddDelim();
    editor.AddDigit(0);
    editor.AddDelim();
    editor.AddDigit(0);
    editor.AddDelim();
    editor.AddDigit(1);
    editor.AddDelim();
    editor.AddDigit(0);
    editor.AddDelim();
    editor.AddDigit(1);
    editor.AddDelim();
    editor.AddDigit(0);
    editor.AddDelim();
    QString ExpectedValue = "0.001010";
    QString ActualValue = editor.number;
    QCOMPARE(ExpectedValue, ActualValue);
}

void testeditor::TestAddDigit1(){
    Editor editor;
    editor.AddDigit(0);
    QString ExpectedValue = "0";
    QString ActualValue = editor.number;
    QCOMPARE(ExpectedValue, ActualValue);
}
void testeditor::TestAddDigit2(){
    Editor editor;
    editor.AddDigit(0);
    editor.AddDigit(1);
    editor.AddDigit(2);
    editor.AddDigit(3);
    editor.AddDigit(4);
    editor.AddDigit(5);
    editor.AddDigit(6);
    editor.AddDigit(7);
    editor.AddDigit(8);
    editor.AddDigit(9);
    editor.AddDelim();
    editor.AddDigit(10);
    editor.AddDigit(11);
    editor.AddDigit(12);
    editor.AddDigit(13);
    editor.AddDigit(14);
    editor.AddDigit(15);
    QString ExpectedValue = "123456789.ABCDEF";
    QString ActualValue = editor.number;
    QCOMPARE(ExpectedValue, ActualValue);
    editor.AddDigit(15);
}
void testeditor::TestAddDigit3(){
    Editor editor;
    editor.AddDigit(0);
    editor.AddDigit(0);
    editor.AddDigit(0);
    QString ExpectedValue = "0";
    QString ActualValue = editor.number;
    QCOMPARE(ExpectedValue, ActualValue);
}
void testeditor::TestAddDigit4(){
    Editor editor;
    editor.AddDigit(-1);
    QString ExpectedValue = "-1";
    QString ActualValue = editor.number;
    QCOMPARE(ExpectedValue, ActualValue);
}
void testeditor::TestBs1(){
    Editor editor;
    editor.AddDigit(0);
    editor.AddDigit(0);
    editor.AddDigit(0);
    editor.AddDelim();
    editor.AddDigit(1);
    editor.AddDigit(1);
    editor.AddDigit(1);
    editor.Bs();
    editor.Bs();
    editor.Bs();
    QString ExpectedValue = "0.";
    QString ActualValue = editor.number;
    QCOMPARE(ExpectedValue, ActualValue);
}
void testeditor::TestBs2(){
    Editor editor;
    editor.AddDigit(0);
    editor.Bs();
    editor.AddDigit(0);
    editor.Bs();
    editor.AddDigit(0);
    editor.Bs();
    editor.AddDelim();
    editor.Bs();
    editor.AddDigit(1);
    editor.Bs();
    editor.AddDigit(1);
    editor.Bs();
    editor.AddDigit(1);
    QString ExpectedValue = "1";
    QString ActualValue = editor.number;
    QCOMPARE(ExpectedValue, ActualValue);
}
void testeditor::TestBs3(){
    Editor editor;
    editor.AddDigit(1);
    editor.AddDigit(0);
    editor.AddDigit(0);
    editor.AddDigit(0);
    editor.AddDigit(1);
    editor.Bs();
    editor.Bs();
    editor.Bs();
    editor.Bs();
    editor.Bs();
    QString ExpectedValue = "0";
    QString ActualValue = editor.number;
    QCOMPARE(ExpectedValue, ActualValue);
}
void testeditor::TestBs4(){}
