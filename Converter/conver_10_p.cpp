#include "conver_10_p.h"
#include <QDebug>
Conver_10_p::Conver_10_p()
{

}

QString Conver_10_p::Do(double n, long long p, long long c) {
        if (p < 2 || p > 16){
        qDebug()<<"Index out of range 4\n";
        //throw MyException{};
        }

        if (c < 0 || c > 10)
        { qDebug()<<"Index out of range 5\n";
            //throw MyException{};
        }

        long long LeftSide = (long long)n;

        double RightSide = 0;
        RightSide = n - LeftSide;
        if (RightSide < 0)
            RightSide *= -1;

        QString LeftSideString = int_to_P(LeftSide, p);
        QString RightSideString = flt_to_P(RightSide, p, c);

        return LeftSideString + (RightSideString == "" ? "" : ".") + RightSideString;
    }

QString Conver_10_p::int_to_P(long long n, long long p) {
            if (p < 2 || p > 16)
            {
                    qDebug()<<"Index out of range 6\n";
                    //throw MyException{};
                    }
            if (n == 0)
                return "0";
            bool HaveMinus = false;
            if (n < 0) {
                HaveMinus = true;
                n *= -1;
            }
            QString PNumber = "";

            while (n > 0) {
                PNumber.push_front(int_to_Char((int)(n % p)));
                n /= p;
            }

            if (HaveMinus)
                PNumber.push_front( "-");

            return PNumber;
        }

        QString Conver_10_p::flt_to_P(double n, long long p, long long c) {
            if (p < 2 || p > 16)
            {
                    qDebug()<<"Index out of range 6\n";
                    //throw MyException{};
                    }
            if (c < 0 || c > 10)
            {
                    qDebug()<<"Index out of range 7\n";
                    //throw MyException{};
                    }

            QString PNumber = "";
            for (int i = 0; i < c; ++i) {

                PNumber += int_to_Char((int)(n * p));
                n = n * p - (int)(n * p);
            }
            return PNumber;
        }

         QChar Conver_10_p:: int_to_Char(int d) {
                    if (d < 0 || d > 15)
                    {
                           qDebug()<<d<<"Index out of range 8\n";
                           return -1;
                            //throw MyException{};
                            }


                    QString SymbolArray = "0123456789ABCDEF";
                    return SymbolArray[d];
                }
