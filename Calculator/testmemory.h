#ifndef TESTMEMORY_H
#define TESTMEMORY_H
#include "QObject"
#include "tmemory.h"
class testmemory: public QObject {



    Q_OBJECT
    public:
        explicit testmemory(QObject *parent=0);

        private slots:

         void InitAndOutput1();

         void InitAndOutput2();

         void InitAndOutput3();


         void Sum1();

         void Sum2();


         void TestFState1();

         void TestFState2();

         void TestFState3();
    };


#endif // TESTMEMORY_H
