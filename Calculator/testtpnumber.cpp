#include "testtpnumber.h"
#include "tpnumber.h"
#include <QTest>


testtpnumber::testtpnumber(QObject *parent) :
    QObject(parent)
{

}



     void testtpnumber:: Init1() {
        TPNumber tPNumber =  TPNumber(10, 10, 3);
        QString answer = "10";
        QCOMPARE(answer, tPNumber.ToString());
    }

     void testtpnumber:: Init2() {
        TPNumber tPNumber =  TPNumber("-12100.11201002", 3, 8);
        QString answer = "-12100.11201002";
        QCOMPARE(answer, tPNumber.ToString());
    }

     void testtpnumber:: Init3() {
        TPNumber tPNumber =  TPNumber(16, 16, 3);
        QString answer = "10";
        QCOMPARE(answer, tPNumber.ToString());
    }

     void testtpnumber:: Init4() {
        TPNumber tPNumber =  TPNumber(255, 2, 3);
        QString answer = "11111111";
        QCOMPARE(answer, tPNumber.ToString());
    }
     void testtpnumber:: Init5() {
        TPNumber tPNumber =  TPNumber(14.471, 7, 5);
        QString answer = "20.32036";
        QCOMPARE(answer, tPNumber.ToString());
    }

     void testtpnumber:: Init6() {
        TPNumber tPNumber =  TPNumber(145.1742, 15, 8);
        QString answer = "9A.292DD1D1";
        QCOMPARE(answer, tPNumber.ToString());
    }

     void testtpnumber:: Init7() {
        TPNumber tPNumber =  TPNumber(36.09, 16, 2);
        QString answer = "24.17";
        QCOMPARE(answer, tPNumber.ToString());
    }

     void testtpnumber:: Init8() {
        TPNumber tPNumber =  TPNumber(88.88, 8, 9);
        QString answer = "130.70243656";
        QCOMPARE(answer, tPNumber.ToString());
    }

     void testtpnumber:: Init9() {
        TPNumber tPNumber =  TPNumber(256.256, 2, 5);
        QString answer = "100000000.01";
        QCOMPARE(answer, tPNumber.ToString());
    }

     void testtpnumber:: Init10() {
        TPNumber tPNumber =  TPNumber(-356.22, 10, 5);
        QString answer = "-356.22";
        QCOMPARE(answer, tPNumber.ToString());
    }

     void testtpnumber:: Init11() {
        TPNumber tPNumber =  TPNumber(0, 2, 1);
        QString answer = "0";
        QCOMPARE(answer, tPNumber.ToString());
    }

     void testtpnumber:: Init12() {
        TPNumber tPNumber =  TPNumber("A3.158", 12, 3);
        QString answer = "A3.158";
        QCOMPARE(answer, tPNumber.ToString());
    }


     void testtpnumber:: Add1() {
        TPNumber class1 =  TPNumber(15, 7, 5);
        TPNumber class2 =  TPNumber(66.66, 7, 5);
        class1 = class1 + class2;
        double answer = 81.66;
        QCOMPARE(answer, class1.Number);
    }

     void testtpnumber:: Add2() {
        TPNumber class1 =  TPNumber(12, 16, 10);
        TPNumber class2 =  TPNumber(-13, 3, 6);
        class1 = class1 + class2;
        double answer = -1;
        QCOMPARE(answer, class1.Number);
    }


     void testtpnumber:: Multiply1() {
        TPNumber class1 =  TPNumber(12.23, 7, 5);
        TPNumber class2 =  TPNumber(-6.66, 7, 5);
        class1 = class1 * class2;
        double answer = -81.4518;
        QCOMPARE(answer, class1.Number);
    }

     void testtpnumber:: Multiply2() {
        TPNumber class1 =  TPNumber(15.6, 16, 11);
        TPNumber class2 =  TPNumber(0, 7, 5);
        class1 = class1 - class2;
        double answer = 0;
        QCOMPARE(answer, class1.Number);
    }


     void testtpnumber:: Substract1() {
        TPNumber class1 =  TPNumber(12.23, 7, 5);
        TPNumber class2 =  TPNumber(6.66, 7, 5);
        class1 = class1 - class2;
        double answer = 5.57;
        QCOMPARE(answer, class1.Number);
    }

     void testtpnumber:: Substract2() {
        TPNumber class1 =  TPNumber(12.22, 16, 10);
        TPNumber class2 =  TPNumber(-6.67, 7, 5);
        class1 = class1 - class2;
        double answer = 18.89;
        QCOMPARE(answer, class1.Number);
    }


     void testtpnumber:: Divide1() {
        TPNumber class1 =  TPNumber(3, 7, 5);
        TPNumber class2 =  TPNumber(8, 7, 5);
        class1 = class1 / class2;
        double answer = 0.375;
        QCOMPARE(answer, class1.Number);
    }

     void testtpnumber:: Divide2() {
        TPNumber class1 =  TPNumber(666, 16, 5);
        TPNumber class2 =  TPNumber(-333, 2, 5);
        class1 = class1 / class2;
        double answer = -2;
        QCOMPARE(answer, class1.Number);
    }


 /*    void testtpnumber:: Square1() {
        TPNumber testClass =  TPNumber(-1.57, 7, 5);
        testClass = testClass.Square();
        double answer = 2.4649;
        QCOMPARE(answer, testClass.Number);
    }*/


