#ifndef CONVERT_P_10_H
#define CONVERT_P_10_H
#include <QString>
#include <QDebug>
#include <cmath>
#include <QRegExp>
class Convert_p_10
{
public:
    Convert_p_10();

    double convert(QString P_num, long long P, long long weight);
    double dval(QString P_num, long long P);
    int char_To_num(QChar ch);
};

#endif // CONVERT_P_10_H
