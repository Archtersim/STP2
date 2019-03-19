#ifndef TESTCONVET_P_10_H
#define TESTCONVERT_P_10_H

#include <QObject>

class testconvert_p_10 : public QObject
{
    Q_OBJECT
public:
     explicit testconvert_p_10(QObject *parent=0);
private slots:

    void TestConvert1();
    void TestConvert2();
    void TestConvert3();
    void TestConvert4();
    void TestDval1();
    void TestDval2();
    void TestDval3();
    void TestDval4();
    void TestChar_To_num1();
    void TestChar_To_num2();
    void TestChar_To_num3();
    void TestChar_To_num4();
};




#endif // TESTCONVERT_P_10_H
