#ifndef TESTPROC_H
#define TESTPROC_H
#include <QObject>
#include "tproc.h"

class testproc228 : public QObject {




    Q_OBJECT
    public:


 private slots:
     void Init1();

     void Init2();

     void Init3();


     void Operation1();

     void Operation2();

     void Operation3();

     void Operation4();


     void TestFState1();

     void TestFState2();

};


#endif // TESTPROC_H
