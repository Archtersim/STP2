#include "testfrac.h"
#include <QTest>


testfrac::testfrac(QObject *parent) :
    QObject(parent)
{

}

 void testfrac:: InitString1() {
    QString fracString = "1/2";
    TFrac fracClass =  TFrac(fracString);
    QCOMPARE(fracString, fracClass.ToString());
}

 void testfrac:: InitString2() {
    QString fracString = "111/2";
    TFrac fracClass =  TFrac(fracString);
    QCOMPARE(fracString, fracClass.ToString());
}

 void testfrac:: InitString3() {
    QString fracString = "1/999";
    TFrac fracClass =  TFrac(fracString);
    QCOMPARE(fracString, fracClass.ToString());
}

 void testfrac:: InitString4() {
    QString fracString = "100/10";
    TFrac fracClass =  TFrac(fracString);
    QString fracCompar = "10/1";
    QCOMPARE(fracCompar, fracClass.ToString());
}

 void testfrac:: InitString5() {
    QString fracString = "-100/60";
    TFrac fracClass =  TFrac(fracString);
    QString fracCompar = "-5/3";
    QCOMPARE(fracCompar, fracClass.ToString());
}

 void testfrac:: InitString6() {
    QString fracString = "00000003/000004";
    TFrac fracClass =  TFrac(fracString);
    QString fracCompar = "3/4";
    QCOMPARE(fracCompar, fracClass.ToString());
}

 void testfrac:: InitNumber1() {
    TFrac fracClass =  TFrac(2, 4);
    QString fracCompar = "1/2";
    QCOMPARE(fracCompar, fracClass.ToString());
}

 void testfrac:: InitNumber2() {
    TFrac fracClass =  TFrac(17, 9);
    QString fracCompar = "17/9";
    QCOMPARE(fracCompar, fracClass.ToString());
}

 void testfrac:: InitNumber3() {
    TFrac fracClass =  TFrac(100, 100);
    QString fracCompar = "1/1";
    QCOMPARE(fracCompar, fracClass.ToString());
}

 void testfrac:: InitNumber4() {
    TFrac fracClass =  TFrac(-100, -99);
    QString fracCompar = "100/99";
    QCOMPARE(fracCompar, fracClass.ToString());
}

 void testfrac:: InitNumber5() {
    TFrac fracClass =  TFrac(0, 0);
    QString fracCompar = "0/1";
    QCOMPARE(fracCompar, fracClass.ToString());
}

 void testfrac:: InitNumber6() {
    TFrac fracClass =  TFrac(100, -5);
    QString fracCompar = "-20/1";
    QCOMPARE(fracCompar, fracClass.ToString());
}

 void testfrac:: InitCopy1() {
    TFrac fracClass =  TFrac(100, -5);
    TFrac copyClass =  TFrac(fracClass);
    QCOMPARE(fracClass.ToString(), copyClass.ToString());
}

 void testfrac:: InitCopy2() {
    TFrac fracClass =  TFrac(1, 4);
    TFrac copyClass =  TFrac(fracClass);
    QCOMPARE(fracClass.ToString(), copyClass.ToString());
}




 /*void testfrac:: Add1() {
    TFrac fracClass1 =  TFrac(1, 2);
    TFrac fracClass2 =  TFrac(-3, 4);
    fracClass2 = fracClass1 + fracClass2;
    QString answer = "-1/4";
    QCOMPARE(answer, fracClass2.ToString());
}*/

 void testfrac:: Add2() {
    TFrac fracClass1 =  TFrac(-1, 2);
    TFrac fracClass2 =  TFrac(-1, 2);
    fracClass2 = fracClass1 + fracClass2;
    QString answer = "-1/1";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Add3() {
    TFrac fracClass1 =  TFrac(-6, 2);
    TFrac fracClass2 =  TFrac(6, 2);
    fracClass2 = fracClass1 + fracClass2;
    QString answer = "0/1";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Add4() {
    TFrac fracClass1 =  TFrac(50, 3);
    TFrac fracClass2 =  TFrac(0, 1);
    fracClass2 = fracClass1 + fracClass2;
    QString answer = "50/3";
    QCOMPARE(answer, fracClass2.ToString());
}


 void testfrac:: Multiply1() {
    TFrac fracClass1 =  TFrac(-1, 2);
    TFrac fracClass2 =  TFrac(-1, 2);
    fracClass2 = fracClass1 * fracClass2;
    QString answer = "1/4";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Multiply2() {
    TFrac fracClass1 =  TFrac(1, 6);
    TFrac fracClass2 =  TFrac(0, 1);
    fracClass2 = fracClass1 * fracClass2;
    QString answer = "0/1";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Multiply3() {
    TFrac fracClass1 =  TFrac(1, 6);
    TFrac fracClass2 =  TFrac(1, 6);
    fracClass2 = fracClass1 * fracClass2;
    QString answer = "1/36";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Multiply4() {
    TFrac fracClass1 =  TFrac(-1, 6);
    TFrac fracClass2 =  TFrac(12, 1);
    fracClass2 = fracClass1 * fracClass2;
    QString answer = "-2/1";
    QCOMPARE(answer, fracClass2.ToString());
}


 void testfrac:: Substract1() {
    TFrac fracClass1 =  TFrac(0, 1);
    TFrac fracClass2 =  TFrac(1, 1);
    fracClass2 = fracClass1 - fracClass2;
    QString answer = "-1/1";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Substract2() {
    TFrac fracClass1 =  TFrac(5, 1);
    TFrac fracClass2 =  TFrac(1, 1);
    fracClass2 = fracClass1 - fracClass2;
    QString answer = "4/1";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Substract3() {
    TFrac fracClass1 =  TFrac(1, 2);
    TFrac fracClass2 =  TFrac(1, 2);
    fracClass2 = fracClass1 - fracClass2;
    QString answer = "0/1";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Substract4() {
    TFrac fracClass1 =  TFrac(-1, 6);
    TFrac fracClass2 =  TFrac(-1, 6);
    fracClass2 = fracClass1 - fracClass2;
    QString answer = "0/1";
    QCOMPARE(answer, fracClass2.ToString());
}


 void testfrac:: Divide1() {
    TFrac fracClass1 =  TFrac(5, 6);
    TFrac fracClass2 =  TFrac(1, 1);
    fracClass2 = fracClass1 / fracClass2;
    QString answer = "5/6";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Divide2() {
    TFrac fracClass1 =  TFrac(1, 1);
    TFrac fracClass2 =  TFrac(5, 6);
    fracClass2 = fracClass1 / fracClass2;
    QString answer = "6/5";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Divide3() {
    TFrac fracClass1 =  TFrac(0, 1);
    TFrac fracClass2 =  TFrac(5, 6);
    fracClass2 = fracClass1 / fracClass2;
    QString answer = "0/1";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Divide4() {
    TFrac fracClass1 =  TFrac(2, 3);
    TFrac fracClass2 =  TFrac(7, 4);
    fracClass2 = fracClass1 / fracClass2;
    QString answer = "8/21";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Divide5() {
    TFrac fracClass1 =  TFrac(2, 3);
    TFrac fracClass2 =  TFrac(2, 3);
    fracClass2 = fracClass1 / fracClass2;
    QString answer = "1/1";
    QCOMPARE(answer, fracClass2.ToString());
}

 void testfrac:: Divide6() {
    TFrac fracClass1 =  TFrac(-1, 3);
    TFrac fracClass2 =  TFrac(-9, 5);
    fracClass2 = fracClass1 / fracClass2;
    QString answer = "5/27";
    QCOMPARE(answer, fracClass2.ToString());
}



/*
 void testfrac:: Reverse1() {
    TFrac fracClass =  TFrac(-2, 3);
    fracClass = fracClass.Reverse();
    QString answer = "-3/2";
    QCOMPARE(answer, fracClass.Reverse().ToString());
}

 void testfrac:: Reverse2() {
    TFrac fracClass =  TFrac(0, 1);
    fracClass = fracClass.Reverse() ;
    QString answer = "0/1";
    QCOMPARE(answer, fracClass.ToString());
}

 void testfrac:: Reverse3() {
    TFrac fracClass =  TFrac(5, 6);
    fracClass = fracClass.Reverse() ;
    QString answer = "6/5";
    QCOMPARE(answer, fracClass.ToString());
}


 void testfrac:: Square1() {
    TFrac fracClass =  TFrac(1, 3);
    fracClass = fracClass.Square() ;
    QString answer = "1/9";
    QCOMPARE(answer, fracClass.ToString());
}

 void testfrac:: Square2() {
    TFrac fracClass =  TFrac(0, 1);
    fracClass = fracClass.Square() ;
    QString answer = "0/1";
    QCOMPARE(answer, fracClass.ToString());
}

 void testfrac:: Square3() {
    TFrac fracClass =  TFrac(-2, 3);
    fracClass = fracClass.Square() ;
    QString answer = "4/9";
    QCOMPARE(answer, fracClass.ToString());
}

*/

 void testfrac:: Equal1() {
    TFrac fracClass1 =  TFrac(1, 3);
    TFrac fracClass2 =  TFrac(1, 3);
   QVERIFY(fracClass1 == fracClass2);
}

 void testfrac:: Equal2() {
    TFrac fracClass1 =  TFrac(0, 6);
    TFrac fracClass2 =  TFrac(1, 6);
    QCOMPARE(fracClass1 == fracClass2,false);
}

 void testfrac:: Equal3() {
    TFrac fracClass1 =  TFrac(-1, 6);
    TFrac fracClass2 =  TFrac(-1, 6);
   QVERIFY(fracClass1 == fracClass2);
}

 void testfrac:: Equal4() {
    TFrac fracClass1 =  TFrac(-1, 7);
    TFrac fracClass2 =  TFrac(1, 7);
    QCOMPARE(fracClass1 == fracClass2,false);
}

 void testfrac:: Equal5() {
    TFrac fracClass1 =  TFrac(1, 6);
    TFrac fracClass2 =  TFrac(0, 1);
    QCOMPARE(fracClass1 == fracClass2,false);
}

 void testfrac:: Greater1() {
    TFrac fracClass1 =  TFrac(1, 6);
    TFrac fracClass2 =  TFrac(0, 1);
   QCOMPARE(fracClass1 > fracClass2,true);
}

 void testfrac:: Greater2() {
    TFrac fracClass1 =  TFrac(0, 1);
    TFrac fracClass2 =  TFrac(0, 1);
    QCOMPARE(fracClass1 > fracClass2,false);
}

 void testfrac:: Greater3() {
    TFrac fracClass1 =  TFrac(-1, 6);
    TFrac fracClass2 =  TFrac(0, 1);
    QCOMPARE(fracClass1 > fracClass2,false);
}

 void testfrac:: Greater4() {
    TFrac fracClass1 =  TFrac(17, 3);
    TFrac fracClass2 =  TFrac(16, 3);
   QCOMPARE(fracClass1 > fracClass2,true);
}

 void testfrac:: Greater5() {
    TFrac fracClass1 =  TFrac(-2, 3);
    TFrac fracClass2 =  TFrac(-1, 3);
    QCOMPARE(fracClass1 > fracClass2,false);
}
