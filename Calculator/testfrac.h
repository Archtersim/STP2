#ifndef testfrac_H
#define testfrac_H
#include "tfrac.h"
#include <QObject>


class testfrac : public QObject {
Q_OBJECT
public:
    explicit testfrac(QObject *parent=0);
private slots:
     void InitString1();
     void InitString2();
     void InitString3();
     void InitString4();
     void InitString5();
     void InitString6();
     void InitNumber1();
     void InitNumber2();
     void InitNumber3();
     void InitNumber4();
     void InitNumber5();
     void InitNumber6();
     void InitCopy1();
     void InitCopy2();
     //void Add1();
     void Add2();
     void Add3();
     void Add4();
     void Multiply1();
     void Multiply2();
     void Multiply3() ;
     void Multiply4();
     void Substract1();
     void Substract2();
     void Substract3();
     void Substract4();
     void Divide1();
     void Divide2();
     void Divide3();
     void Divide4();
     void Divide5();
     void Divide6();
     void Equal1();
     void Equal2();
     void Equal3() ;
     void Equal4();
     void Equal5();
     void Greater1();
     void Greater2();
     void Greater3();
     void Greater4();
     void Greater5();
};


#endif // testfrac_H
