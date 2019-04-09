#include "testfraceditor.h"
#include <Qtest>

testfraceditor::testfraceditor(QObject *parent) :
    QObject(parent)
{

}

void testfraceditor:: TestInit1() {
   FracEditor testClass =  FracEditor();
   QString input = "3/4";
   testClass.number = input;
   QCOMPARE(input, testClass.number);
}

void testfraceditor:: TestInit2() {
   FracEditor testClass =  FracEditor();
   QString input = "-16/3";
   testClass.number = input;
   QCOMPARE(input, testClass.number);
}

void testfraceditor:: TestInit3() {
   QString input = "0/8";
   FracEditor testClass =  FracEditor(input);
   QString result = "0/1";
   QCOMPARE(result, testClass.number);
}

void testfraceditor:: TestInit4() {
   FracEditor testClass =  FracEditor();
   QString input = "-17/4";
   testClass.number = input;
   QCOMPARE(input, testClass.number);
}

void testfraceditor:: TestInit5() {
   FracEditor testClass =  FracEditor();
   QString input = "0/1";
   testClass.number = input;
   QCOMPARE(input, testClass.number);
}

void testfraceditor:: TestInit6() {
   QString input = "666/6666";
   FracEditor testClass =  FracEditor(input);
   QString result = "111/1111";
   QCOMPARE(result, testClass.number);
}

void testfraceditor:: TestInit7() {
   QString input = "aaaa";
   FracEditor testClass =  FracEditor(input);
   QString result = "0/1";
   QCOMPARE(result, testClass.number);
}

void testfraceditor:: TestInit8() {
   FracEditor testClass =  FracEditor();
   QString input = "0/1";
   testClass.number = input;
   QCOMPARE(input, testClass.number);
}

void testfraceditor:: TestInit9() {
   FracEditor testClass =  FracEditor();
   QString input = "0/1";
   testClass.number = input;
   QCOMPARE(input, testClass.number);
}

void testfraceditor:: TestInit10() {
    QString input = "16/000000";
   FracEditor testClass =  FracEditor(input);
   QString result = "0/1";
   QCOMPARE(result, testClass.number);
}

void testfraceditor:: IsZero1() {
   FracEditor testClass =  FracEditor("14/3");
   QCOMPARE(false, testClass.IsZero());
}

void testfraceditor:: IsZero2() {
   FracEditor testClass =  FracEditor("16/00000");
   QCOMPARE(true, testClass.IsZero());
}


void testfraceditor:: ToogleMinus1() {
   FracEditor testClass =  FracEditor("14/3");
   testClass.ToogleSign();
   QString result = "-14/3";
   QCOMPARE(result, testClass.ToString());
}

void testfraceditor:: ToogleMinus2() {
   FracEditor testClass =  FracEditor("-14/3");
   testClass.ToogleSign();
   QString result = "14/3";
   QCOMPARE(result, testClass.ToString());
}


void testfraceditor:: AddDeleteTest1() {
   FracEditor testClass =  FracEditor("123/123");
   testClass.AddNumber(0);
   testClass.AddNumber(1);
   testClass.AddNumber(3);
   testClass.AddSeparator();
   testClass.ToogleSign();
   QString result = "-1/1013";
   QCOMPARE(result, testClass.ToString());
}

void testfraceditor:: AddDeleteTest2() {
   FracEditor testClass =  FracEditor(123, 123);
   testClass.RemoveSymbol();
   testClass.RemoveSymbol();
   testClass.RemoveSymbol();
   testClass.RemoveSymbol();
   testClass.RemoveSymbol();
   testClass.RemoveSymbol();
   testClass.RemoveSymbol();
   testClass.AddNumber(1);
   testClass.AddNumber(2);
   testClass.AddNumber(3);
   testClass.AddNumber(4);
   testClass.AddNumber(5);
   testClass.AddSeparator();
   testClass.AddNumber(1);
   testClass.AddNumber(1);
   testClass.AddNumber(1);
   testClass.AddNumber(1);
   QString result = "12345/1111";
   QCOMPARE(result, testClass.ToString());
}

void testfraceditor:: AddDeleteTest3() {
   FracEditor testClass =  FracEditor(1234567, 12345678);
   for (int i = 0; i < 100; ++i)
       testClass.RemoveSymbol();
   for (int i = 0; i < 100; ++i)
       testClass.AddSeparator();
   testClass.AddNumber(1);
   testClass.AddNumber(1);
   testClass.AddNumber(1);
   testClass.AddNumber(1);
   QString result = "0/1111";
   QCOMPARE(result, testClass.ToString());
}

void testfraceditor:: AddDeleteTest4() {
   FracEditor testClass =  FracEditor("0/1");
   for (int i = 0; i < 100; ++i)
       testClass.AddNumber(i);
   QString result = "0/10123456789";
   QCOMPARE(result, testClass.ToString());
}

void testfraceditor:: Clear() {
   FracEditor testClass =  FracEditor("2345678/345678");
   testClass.Clear();
   QString result = "0";
   QCOMPARE(result, testClass.ToString());
}

