#ifndef CONVER_10_P_H
#define CONVER_10_P_H
#include <QString>

class Conver_10_p
{
public:
    Conver_10_p();
    QString Do(double n, long long p, long long c);
    QString int_to_P(long long n, long long p);
    QString flt_to_P(double n, long long p, long long c);
    QChar int_to_Char(int d);
};

#endif // CONVER_10_P_H
