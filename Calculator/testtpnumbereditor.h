#ifndef TESTTPNUMBEREDITOR_H
#define TESTTPNUMBEREDITOR_H
#include <QObject>

 class testtpnumbereditor: public QObject {

     Q_OBJECT
     public:
         explicit testtpnumbereditor(QObject *parent=0);
 private slots:

     void Init1();

     void Init2();

     void Init3();

     void Init4();

     void Init5();

     void Init6();

     void Init7();
     void Init8();
     void Init9();
     void Init10();


     void AddDeleteTest1();

     void AddDeleteTest2();

     void AddDeleteTest3();

     void AddDeleteTest4();
};
#endif // TESTTPNUMBEREDITOR_H
