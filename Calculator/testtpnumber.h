#ifndef TESTTPNUMBER_H
#define TESTTPNUMBER_H
#include <QObject>

class testtpnumber: public QObject {

    Q_OBJECT
    public:
        explicit testtpnumber(QObject *parent=0);
private slots:
    void Init1();

    void Init2();

    void Init3();

    void Init4();
    void Init5();

    void Init6();

    void Init7();

    void Init8();

    void Init9() ;

    void Init10();

    void Init11();

    void Init12();


    void Add1();
    void Add2();


    void Multiply1() ;

    void Multiply2();


    void Substract1() ;

    void Substract2() ;


    void Divide1();

    void Divide2() ;


   // void Square1();

};

#endif // TESTTPNUMBER_H
