#include "testtcomplex.h"
#include "tcomplex.h"
#include <QTest>

testtcomplex::testtcomplex(QObject *parent) : QObject(parent)
{

}


void testtcomplex:: Init1() {
        TComplex testClass =  TComplex(6, 3);
        QString output = "6 + i * 3";
        QCOMPARE(output, testClass.ToString());
    }

     void testtcomplex:: Init2() {
        TComplex testClass =  TComplex(0, 0);
        QString output = "0 + i * 0";
        QCOMPARE(output, testClass.ToString());
    }

     void testtcomplex:: Init3() {
        TComplex testClass =  TComplex(3, -2);
        QString output = "3 + i * -2";
        QCOMPARE(output, testClass.ToString());
    }

     void testtcomplex:: Init4() {
        TComplex testClass =  TComplex(4.01, 6);
        QString output = "4.01 + i * 6";
        QCOMPARE(output, testClass.ToString());
    }

     void testtcomplex:: Init5() {
        TComplex testClass =  TComplex(-3.02, 7);
        QString output = "-3.02 + i * 7";
        QCOMPARE(output, testClass.ToString());
    }

     void testtcomplex:: Init6() {
        TComplex testClass =  TComplex(0, -22.22);
        QString output = "0 + i * -22.22";
        QCOMPARE(output, testClass.ToString());
    }


  /*   void testtcomplex:: Reverse1() {
        TComplex testClass =  TComplex(0, -3);
        testClass = testClass.Reverse() as TComplex;
        QString output = "0 + i * 0.333";
        QCOMPARE(output, testClass.ToString());
    }

     void testtcomplex:: Reverse2() {
        TComplex testClass =  TComplex(3, 4);
        testClass = testClass.Reverse() as TComplex;
        QString output = "0.12 + i * -0.16";
        QCOMPARE(output, testClass.ToString());
    }

     void testtcomplex:: Square1() {
        TComplex testClass =  TComplex(3, 4);
        testClass = testClass.Square() as TComplex;
        QString output = "-7 + i * 24";
        QCOMPARE(output, testClass.ToString());
    }

     void testtcomplex:: Square2() {
        TComplex testClass =  TComplex(0, -3);
        testClass = testClass.Square() as TComplex;
        QString output = "-9 + i * 0";
        QCOMPARE(output, testClass.ToString());
    }*/

     void testtcomplex:: Abs1() {
        TComplex testClass =  TComplex(3, 4);
        double answer = 5;
        QCOMPARE(true,qFloatDistance(answer, testClass.Abs())<(1<<8));
    }

     void testtcomplex:: Abs2() {
        TComplex testClass =  TComplex(0, -3);
        double answer = 3;
       QCOMPARE(true,qFloatDistance(answer, testClass.Abs())<(1<<8));
    }

     void testtcomplex:: GetRad1() {
        TComplex testClass =  TComplex(3, 4);
        double answer = 0.927295;
        QCOMPARE(true,qFloatDistance(answer, testClass.GetRad())<(1<<8));
    }

     void testtcomplex:: GetRad2() {
        TComplex testClass =  TComplex(0, -3);
        double answer = -1.570796;
        QCOMPARE(true,qFloatDistance(answer, testClass.GetRad())<(1<<10));
    }

     void testtcomplex:: GetDegree1() {
        TComplex testClass =  TComplex(3, 4);
        double answer = 53.1301;
        QCOMPARE(true,qFloatDistance(answer, testClass.GetDegree())<(1<<10));
    }

     void testtcomplex:: GetDegree2() {
        TComplex testClass =  TComplex(0, -3);
        double answer = -90;
       QCOMPARE(true,qFloatDistance(answer, testClass.GetDegree())<(1<<8));
    }

     void testtcomplex:: Pow1() {
        TComplex testClass =  TComplex(3, 4);
        testClass = testClass.Pwr(5);
        QString output = "-237 + i * -3116";
        QCOMPARE(output, testClass.ToString());
    }

     void testtcomplex:: Pow2() {
        TComplex testClass =  TComplex(0, -3);
        testClass = testClass.Pwr(5);
        QString output = "0 + i * -243";
        QCOMPARE(output, testClass.ToString());
    }

     void testtcomplex:: Root1() {
        TComplex testClass =  TComplex(3, 4);
        testClass = testClass.Root(5, 3);
        QString output = "-0.353 + i * 1.334";
        QCOMPARE(output, testClass.ToString());
    }

     void testtcomplex:: Root2() {
        TComplex testClass =  TComplex(16, -2);
        testClass = testClass.Root(10, 4);
        QString output = "-0.301 + i * 1.286";
        QCOMPARE(output, testClass.ToString());
    }

