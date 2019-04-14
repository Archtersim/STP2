#ifndef TESTTCOMPLEX_H
#define TESTTCOMPLEX_H
#include <QObject>


class testtcomplex : public QObject {


    Q_OBJECT
    public:
        explicit testtcomplex(QObject *parent=0);
    private slots:

void Init1() ;

     void Init2();

     void Init3();

     void Init4();

     void Init5();

     void Init6();


/*     void Reverse1();

     void Reverse2();

     void Square1() ;

     void Square2();*/

     void Abs1();

     void Abs2();

     void GetRad1();

     void GetRad2();

     void GetDegree1();

     void GetDegree2();

     void Pow1();

     void Pow2();

     void Root1();

     void Root2();

};

#endif // TESTTCOMPLEX_H
