#ifndef TESTFRACEDITOR_H
#define TESTFRACEDITOR_H
#include <QObject>
#include "fraceditor.h"

 class testfraceditor: public QObject {

     Q_OBJECT
     public:
         explicit testfraceditor(QObject *parent=0);

    private slots:
     void TestInit1();

     void TestInit2();

     void TestInit3();

     void TestInit4();

     void TestInit5();

     void TestInit6();

     void TestInit7();

     void TestInit8() ;

     void TestInit9();

     void TestInit10();

     void IsZero1();

    void IsZero2();


     void ToogleMinus1();

     void ToogleMinus2();


     void AddDeleteTest1();

     void AddDeleteTest2() ;

     void AddDeleteTest3();

     void AddDeleteTest4();

    void Clear();

};


#endif // TESTFRACEDITOR_H
