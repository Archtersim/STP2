#include "testtpnumbereditor.h"
#include "pnumbereditor.h"
#include <QTest>


testtpnumbereditor::testtpnumbereditor(QObject *parent) :
    QObject(parent)
{

}



void testtpnumbereditor:: Init1() {
   PNumberEditor edit =  PNumberEditor(0.0f, 16, 5);
   QString Input = "2.3F";
   edit.number = Input;
   QString Output = Input;
  QCOMPARE(Output, edit.number);
}

void testtpnumbereditor:: Init2() {
   PNumberEditor edit =  PNumberEditor(0.0f, 2, 5);
   QString Input = "11101.01011";
   edit.number = Input;
   QString Output = Input;
  QCOMPARE(Output, edit.number);
}

void testtpnumbereditor:: Init3() {
   PNumberEditor edit =  PNumberEditor(0.0f, 16, 5);
   QString Input = "-FF.FF";
   edit.number = Input;
   QString Output = Input;
  QCOMPARE(Output, edit.number);
}

void testtpnumbereditor:: Init4() {
   PNumberEditor edit =  PNumberEditor(0.0f, 16, 5);
   QString Input = "aaaaaaaaaaaaa";
   edit.number = Input;
}

void testtpnumbereditor:: Init5() {
   PNumberEditor edit =  PNumberEditor(0.0f, 16, 5);
   QString Input = "16.ppppp";
   edit.number = Input;
}

void testtpnumbereditor:: Init6() {
   PNumberEditor edit =  PNumberEditor(0.0f, 16, 5);
   QString Input = "FFZZZ";
   edit.number = Input;
}

void testtpnumbereditor:: Init7() {
   PNumberEditor edit =  PNumberEditor(0.0f, 16, 5);
   QString Input = "888.8888";
   edit.number = Input;
   QString Output = Input;
  QCOMPARE(Output, edit.number);
}
void testtpnumbereditor:: Init8() {
   PNumberEditor edit =  PNumberEditor("-01.03", 16, 5);
   QString Output = "-1.03";
  QCOMPARE(Output, edit.ToString());
}
void testtpnumbereditor:: Init9() {
   PNumberEditor edit =  PNumberEditor(0.0f, 16, 5);
   QString Input = "-9992D.DDDD";
   edit.number = Input;
   QString Output = Input;
  QCOMPARE(Output, edit.number);
}
void testtpnumbereditor:: Init10() {
   PNumberEditor edit =  PNumberEditor(0.0f, 16, 5);
   QString Input = "7777.7777";
   edit.number = Input;
   QString Output = "7777.7777";
  QCOMPARE(Output, edit.number);
}


void testtpnumbereditor:: AddDeleteTest1() {
   PNumberEditor testClass =  PNumberEditor();
   testClass.AddNumber(0);
   testClass.AddNumber(1);
   testClass.AddNumber(3);
   testClass.AddSeparator();
   testClass.ToogleSign();
   QString result = "-13.";
  QCOMPARE(result, testClass.ToString());
}

void testtpnumbereditor:: AddDeleteTest2() {
   PNumberEditor testClass =  PNumberEditor(0.0f, 16, 5);
   for (int i = 0; i < 16; ++i)
       testClass.AddNumber(i);
   QString result = "12345";
  QCOMPARE(result, testClass.ToString());
}

void testtpnumbereditor:: AddDeleteTest3() {
   PNumberEditor testClass =  PNumberEditor(0.0f, 16, 5);
   for (int i = 0; i < 100; ++i)
       testClass.RemoveSymbol();
   testClass.AddSeparator();
   testClass.AddSeparator();
   testClass.AddSeparator();
   testClass.AddNumber(15);
   QString result = "0.F";
  QCOMPARE(result, testClass.ToString());
}

void testtpnumbereditor:: AddDeleteTest4() {
   PNumberEditor testClass =  PNumberEditor(0.0f, 2, 5);
   for (int i = 2; i < 100; ++i)
       testClass.AddNumber(i);
   QString result = "0";
  QCOMPARE(result, testClass.ToString());
}
