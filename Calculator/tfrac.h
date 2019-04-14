#ifndef TFRAC_H
#define TFRAC_H
#include "anumber.h"
#include "qstring.h"
#include "algorithm"
#include <QList>
#include "string"
#include "qdebug.h"
        class TFrac : ANumber {
        public: long long Numerator;
        public: long long Denominator;
        public: double Notation;
        public:
        TFrac() {
            Numerator = (0);
            Denominator = (1);
        }
        public:
        TFrac(long long a, long long b) {

                if (a < 0 && b < 0) {
                    a *= -1;
                    b *= -1;
                }
                else if (b < 0 && a > 0) {
                    b *= -1;
                    a *= -1;
                }
                else if ((a == 0 && b == 0) || b == 0 || (a == 0 && b == 1)) {
                    Numerator = (0);
                    Denominator =(1);
                    return;
                }
                Numerator = (a);
                Denominator = (b);
                long gcdResult = std::__gcd((long long)a, (long long)b);
                if(gcdResult < 0)gcdResult*=-1;
                if (gcdResult > 1) {
                    Numerator /= gcdResult;
                    Denominator /= gcdResult;
                }
        }
        public:
        TFrac(int a, int b) {
            if (a < 0 && b < 0) {
                a *= -1;
                b *= -1;
            }
            else if (b < 0 && a > 0) {
                b *= -1;
                a *= -1;
            }
            else if ((a == 0 && b == 0) || b == 0 || (a == 0 && b == 1)) {
                Numerator = (0);
                Denominator =(1);
                return;
            }
            Numerator = (a);
            Denominator = (b);
            long gcdResult = std::__gcd(a, b);
            if (gcdResult > 1) {
                Numerator /= gcdResult;
                Denominator /= gcdResult;
            }
        }
        public:
        TFrac(QString frac) {
            QRegExp FracRegex("^-?[0-9]{,25}/\[0-9]{1,25}$");
            QRegExp NumberRegex("^-?[0-9]{,25}/\?$");
            if (FracRegex.exactMatch(frac)) {
                QStringList FracParts=frac.split("/");

                Numerator = (FracParts[0].toLongLong());
                Denominator = (FracParts[1].toLongLong());
                if (Denominator==0) {
                    Numerator = (0);
                    Denominator = (1);
                    return;
                }
                long long gcdResult = std::__gcd((long long)Numerator, (long long)Denominator);
                if (gcdResult > 1) {
                    Numerator /= gcdResult;
                    Denominator /= gcdResult;
                }
                return;
            }
            else if (NumberRegex.exactMatch(frac)) {
                Numerator =(frac.toLongLong());
                Denominator = (1);
                return;
            }
            else {
                Numerator = (0);
                Denominator = (1);
                return;
            }
        }

        TFrac(std::string fra) {
            QString frac=QString::fromStdString(fra);
            QRegExp FracRegex("^-?[0-9]{,25}/\[0-9]{1,25}$");
            QRegExp NumberRegex("^-?[0-9]{,25}/\?$");
            if (FracRegex.exactMatch(frac)) {
                QStringList FracParts=frac.split("/");

                Numerator = (FracParts[0].toLongLong());
                Denominator = (FracParts[1].toLongLong());
                if (Denominator==0) {
                    Numerator = (0);
                    Denominator = (1);
                    return;
                }
                long long gcdResult = std::__gcd((long long)Numerator, (long long)Denominator);
                if (gcdResult > 1) {
                    Numerator /= gcdResult;
                    Denominator /= gcdResult;
                }
                return;
            }
            else if (NumberRegex.exactMatch(frac)) {
                if(frac.lastIndexOf(QChar('/')==((frac.size()-1))))
                    Numerator =(frac.left(frac.lastIndexOf(QChar('/')))).toLongLong();
                else Numerator =frac.toLongLong();
                Denominator = (1);
                return;
            }
            else {
                Numerator = (0);
                Denominator = (1);
                return;
            }
        }

        public: TFrac(const TFrac& anotherFrac) {
            Numerator = anotherFrac.Numerator;
            Denominator = anotherFrac.Denominator;
        }


        public: TFrac& operator =(const TFrac& b) {

            this->Numerator= b.Numerator;
            this->Denominator= b.Denominator;
            return *this;
        }


        public: TFrac& operator +(const TFrac& b) {

            this->Numerator=this->Numerator * b.Denominator + this->Denominator * b.Numerator;
            this->Denominator=this->Denominator * b.Denominator;
            TFrac a(this->Numerator, this->Denominator);
             Numerator=a.Numerator;
             Denominator=a.Denominator;
            return *this;
        }
        public: TFrac& operator *(const TFrac& b) {

            this->Numerator=this->Numerator * b.Numerator;
            this->Denominator=this->Denominator * b.Denominator;
            TFrac a(this->Numerator, this->Denominator);
             Numerator=a.Numerator;
             Denominator=a.Denominator;
            return *this;

        }
        public: TFrac& operator -(const TFrac& b) {

             this->Numerator=this->Numerator * b.Denominator - this->Denominator * b.Numerator;
             this->Denominator=this->Denominator * b.Denominator;
            TFrac a(this->Numerator, this->Denominator);
             Numerator=a.Numerator;
             Denominator=a.Denominator;
            return *this;
        }


        public: TFrac& operator /(const TFrac& b) {
            long long Tn,Td;
            Tn=this->Numerator * b.Denominator;
            Td=this->Denominator * b.Numerator;
            TFrac a(Tn, Td);
             Numerator=a.Numerator;
             Denominator=a.Denominator;
            return *this;

        }
        public: TFrac& operator -() {
            this->Numerator*=-1;
            return *this;
        }
        public:  bool operator ==(const TFrac& b) {
            return this->Numerator == b.Numerator && this->Denominator == b.Denominator;
        }
        public:  bool operator !=(const TFrac& b) {
            return this->Numerator != b.Numerator && this->Denominator != b.Denominator;
        }
        public:  bool operator >(const TFrac& b) {
            return (((double)this->Numerator / (double)this->Denominator) > ((double)b.Numerator / (double)b.Denominator));
        }
        public: bool operator <(const TFrac& b) {
            return ((double)this->Numerator / (double)this->Denominator) < ((double)b.Numerator / (double)b.Denominator);
        }



        public:  ANumber& Square(void) {

            Numerator=Numerator*Numerator;
            Denominator=Denominator*Denominator;
           return *this;
        }
        public:  ANumber& Reverse(void) {
            TFrac a(Denominator,Numerator);
            Numerator=a.Numerator;
            Denominator=a.Denominator;
            return  *this;
        }
        public:  bool IsZero() {
            return (Numerator==0);
        }
        public:  void SetString(QString str) {
            //std::string qtsucks=str.toStdString();
            TFrac TempFrac= TFrac(str);

            Numerator = TempFrac.Numerator;
            Denominator = TempFrac.Denominator;

        }


        public:  QString ToString() {
            return QString::number(Numerator) + "/" + QString::number(Denominator);
        }
    };


#endif // TFRAC_H
