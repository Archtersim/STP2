#include "testcomplexeditor.h"
#include "complexeditor.h"
#include <QTest>

testcomplexeditor::testcomplexeditor(QObject *parent) :
    QObject(parent)
{

}


    void testcomplexeditor:: Init1() {
        QString input = "10.3";
        ComplexEditor testClass =  ComplexEditor(input);
        QString output = "10.3 + i * 0";
       QCOMPARE(output, testClass.ToString());
    }

   void testcomplexeditor:: Init2() {
       QString input = "10. + i * -12.";
        ComplexEditor testClass =  ComplexEditor(input);


        QString output = "10 + i * -12";
       QCOMPARE(output, testClass.ToString());
    }

    void testcomplexeditor:: Init3() {
        QString input = "-0 + i * -0";
        ComplexEditor testClass =  ComplexEditor(input);


        QString output = "0 + i * 0";
       QCOMPARE(output, testClass.ToString());
    }

     void testcomplexeditor:: Init4() {
         QString input = "66.66 + i * 66.66";
        ComplexEditor testClass =  ComplexEditor(input);


        QString output = "66.66 + i * 66.66";
       QCOMPARE(output, testClass.ToString());
    }

    void testcomplexeditor:: Init5() {
        QString input = "10.3 + ";
        ComplexEditor testClass =  ComplexEditor(input);


        QString output = "0 + i * 0";
       QCOMPARE(output, testClass.ToString());
    }

     void testcomplexeditor:: AddDeleteTest1() {
        ComplexEditor testClass =  ComplexEditor();
        testClass.AddNumber(0);
        testClass.AddNumber(1);
        testClass.AddNumber(3);
        testClass.AddSeparator();
        testClass.ToogleSign();
        QString result = "-13 + i * -0";
       QCOMPARE(result, testClass.ToString());
    }

   void testcomplexeditor:: AddDeleteTest2() {
        ComplexEditor testClass =  ComplexEditor();
        testClass.AddNumber(0);
        testClass.AddNumber(1);
        testClass.AddNumber(3);
        testClass.AddSeparator();
        testClass.ToogleSign();
        testClass.RemoveSymbol();
        QString result = "-13 + i * -";
       QCOMPARE(result, testClass.ToString());
    }

     void testcomplexeditor:: AddDeleteTest3() {
        ComplexEditor testClass =  ComplexEditor();
        testClass.AddNumber(0);
        testClass.AddNumber(1);
        testClass.AddNumber(3);
        testClass.AddNumberSeparator();
        testClass.AddSeparator();
        testClass.ToogleSign();
        testClass.AddNumber(0);
        testClass.AddNumber(1);
        testClass.AddNumber(3);
        testClass.AddNumberSeparator();
        QString result = "-13. + i * -13.";
       QCOMPARE(result, testClass.ToString());
    }

