#ifndef TPNUMBER_H
#define TPNUMBER_H
#include "anumber.h"
//#include "tnumber.h"
#include "QString"
#include "QDebug"
#include "math.h"
class TPNumber : public ANumber {
public:
//TPNumber();


double Number;
double Notation;
double Precision;


TPNumber() {
   Number =  0;
   Notation =  ((double)10);
   Precision =  ((double)5);
}

TPNumber(double num, double notat, double pre) {
   if (notat < 2 || notat > 16 || pre < 0 || pre > 10) {
       Number =  0;
       Notation =  ((double)10);
       Precision =  ((double)5);
   }
   else {
       Number =  (num);
       Notation =  (notat);
       Precision =  (pre);
   }
}

TPNumber(const TPNumber &anotherTPNumber) {
   Number = anotherTPNumber.Number;
   Notation = anotherTPNumber.Notation;
   Precision = anotherTPNumber.Precision;
}

TPNumber(QString str, int notat, int pre) {
        TPNumber::Conver_p_10 a;
       Number =  (a.dval(str, notat));
       Notation =  (notat);
       Precision =  (pre);


}


  TPNumber& operator +( TPNumber &b) {
    this->Number+=b.Number;
    return *this;
}
  TPNumber& operator *(const TPNumber &b) {
    this->Number*=b.Number;
    return *this;
}
  TPNumber& operator -(const TPNumber &b) {
   this->Number -= b.Number;
    return  *this;
}
  TPNumber& operator /(const TPNumber &b) {
    this->Number /= b.Number;
     return  *this;
}
  TPNumber& operator -() {
   this->Number*=-1;
    return *this;
}



  bool operator ==(const TPNumber &b) {
   return this->Number == b.Number;
}
  bool operator !=(const TPNumber &b) {
   return this->Number != b.Number;
}
  bool operator >(const TPNumber &b) {
   return this->Number > b.Number;
}
  bool operator <(const TPNumber &b) {
   return this->Number < b.Number;
}





 ANumber& Square(void) {
   this->Number*=this->Number;
    return *this;
}
 ANumber& Reverse(void) {
   this->Number=1/this->Number;
     return *this;
}
  bool IsZero() {
   return (Number==0);
}
  void SetString(QString str) {

    TPNumber::Conver_p_10 a;

   Number = a.dval(str, (long long)(Notation));
    qDebug()<<Number<<"tut";
}


  QString ToString()  {
   QString str;
         TPNumber::Conver_10_p a;
       str = a.Do(Number, (long long)(Notation), (long long)(Precision));

   return str;
}


public: QString plf_to_pstr(QString ednum,long long pin, long long pout,double precision){
Conver_p_10 a; Conver_10_p b;
double r = a.dval(ednum, pin);
QString res = b.Do(r, pout, precision);
return res;
}


public:
     class Conver_10_p {
     public:
    static QString Do(double n, long long p, long long c) {
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
        static QChar int_to_Char(int d) {
            if (d < 0 || d > 15)
                                {
                                       qDebug()<<d<<"Index out of range 8\n";
                                       return -1;
                                        //throw MyException{};
                                        }


                                QString SymbolArray = "0123456789ABCDEF";
                                return SymbolArray[d];
       }
        static QString int_to_P(long long n, long long p) {
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
       static QString flt_to_P(double n, long long p, long long c) {
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
                       PNumber.remove(QRegExp("[0]*$"));
                       return PNumber;
       }
   };
     public :
      class Conver_p_10 {

       static int char_To_num(QChar ch) {
           QString AllVariants = "0123456789ABCDEF";
                       if (!AllVariants.contains(ch))
                       {
                               qDebug()<<"Index out of range 1\n";
                               return -1;
                               //throw MyException{};
                               }
                       return AllVariants.indexOf(ch);
       }
        static double convert(QString P_num, long long P, long long weight) {
            if (weight % P != 0 && weight!=1)//not complete check
                        {
                                qDebug()<<"Incorrect P or Weight\n";
                                //throw MyException2{};
                                }

                        long long Degree=-1;
                        while(weight){Degree++;weight/=P;if(weight % P != 0&& weight!=1){
                                qDebug()<<"Incorrect P or Weight2\n";
                            }
                        }


                        double Result = 0.0f;

                        for (int i = 0; i < P_num.length(); i++)
                        {
                            Result += char_To_num(P_num[i]) * pow(P, Degree);
                            Degree--;
                        }

                        return Result;
                    }
                public:
             double dval(QString P_num, long long P) {
                        if (P < 2 || P > 16)
                        {
                                qDebug()<<"Index out of range 3\n";
                                //throw MyException{};
                                }

                        bool HaveMinus = false;
                                        if (P_num.at(0) == '-') {
                                            HaveMinus = true;
                                            P_num = P_num.remove(0, 1);
                                        }
                        foreach (QChar ch, P_num) {
                            if (ch == '.')
                                continue;
                            if (char_To_num(ch) > P)
                            {
                                    qDebug()<<"Index out of range 2\n";
                                    //throw MyException{};
                                    }
                        }

                        double Number = 0.0f;
                        //qDebug()<<P_num;
                       QRegExp LeftRight("^[0-9A-F]+\\.[0-9A-F]+$");
                        QRegExp Right("^0\\.[0-9A-F]+$");
                        QRegExp Left("^[0-9A-F]+$");
                        QRegExp Leftdot("^[0-9A-F]+\\.$");
                        if (LeftRight.exactMatch(P_num)) {
                            double deg=P_num.indexOf('.');
                            Number = convert(P_num.remove(P_num.indexOf('.'), 1), P, pow(P, deg-1));

                        } else if (Left.exactMatch(P_num)) {
                            Number = convert(P_num, P, pow(P, P_num.length()-1));
                        } else if (Right.exactMatch(P_num)) {
                            Number = convert(P_num.remove(P_num.indexOf('.'), 1), P, 0);
                        } else if(Leftdot.exactMatch(P_num)){

                            Number = convert(P_num.remove(P_num.indexOf('.'), 1), P, pow(P, P_num.length()-2));

                        }else {
                            qDebug()<<"REGEX FAIL\n"; //throw MyException3{};
                        }

           return HaveMinus ? -Number : Number;
       }
   };

   };



#endif // TPNUMBER_H
