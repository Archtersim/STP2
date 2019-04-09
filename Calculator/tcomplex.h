#ifndef TCOMPLEX_H
#define TCOMPLEX_H
#include "QString"
#include "anumber.h"
#include "QStringList"
#include "QRegExp"
#include "QRegularExpression"
#include "QDebug"
class TComplex : public ANumber {
    public: double Real;
    public: double Imaginary;
    public: double Notation;
    QString Separator = " + i * ";

    public: double Abs() {
        return sqrt(Real * Real + Imaginary * Imaginary);
    }
    public: double GetRad() {
        if (Real > 0)
            return atan((Imaginary / Real));
        else if (Real == 0 && Imaginary > 0)
            return M_PI / 2;
        else if (Real < 0 && Imaginary >= 0)
            return atan((Imaginary / Real) + M_PI);
        else if (Real < 0 && Imaginary < 0)
            return atan((Imaginary / Real) - M_PI);
        else if (Real == 0 && Imaginary < 0)
            return -M_PI / 2;
        return 0;
    }
    public: double GetDegree() {
        return GetRad() * 180 / M_PI;
    }
    public: TComplex Pwr(int n) {
        return  TComplex(pow(Abs(), n) * cos(n * GetRad()), pow(Abs(), n) *sin(n * GetRad()));
    }
    public: TComplex Root(int n, int i) {
        if (i >= n || i < 0 || n < 0)
            return TComplex();
        return TComplex(pow(Abs(), 1.0 / n) *cos((GetDegree() + 2 * M_PI * i) / n),pow(Abs(), 1.0 / n) * sin((GetDegree() + 2 * M_PI * i) / n));
    }


    public: TComplex() {
        Real = double(0);
        Imaginary =  double(0);
    }

    public: TComplex(int anReal, int anImaginary) {
        Real =  double(anReal);
        Imaginary = double(anImaginary);
    }
    public: TComplex(double anReal, double anImaginary) {
        Real = anReal;
        Imaginary = anImaginary;
    }
public: TComplex(double anReal, int anImaginary) {
    Real = anReal;
    Imaginary = (double)anImaginary;
}
public: TComplex(int anReal, double anImaginary) {
    Real = (double)anReal;
    Imaginary = anImaginary;
}

    public: TComplex(const TComplex& anotherComplex) {
        Real = anotherComplex.Real;
        Imaginary = anotherComplex.Imaginary;
    }
    public: TComplex(QString str) {
        QRegExp FullNumber("^-?(\\d+.?\\d*)\\s+[+]\\s+i\\s+[*]\\s+-?(\\d+.?\\d*)$");
       QRegExp LeftPart("^-?(\\d+.?\\d*)(\\s+[+]\\s+i\\s+[*]\\s+)?$");
       qDebug()<<str;
        if (FullNumber.exactMatch(str)) {

            QStringList Parts ;
            Parts = str.split(Separator);
            Real =  (Parts[0].toDouble());
            Imaginary =  (Parts[1].toDouble());
        }
        else if (LeftPart.exactMatch(str)) {
            if (str.contains(Separator))
                str = str.replace(Separator, "");
            Real =  str.toDouble();
            Imaginary =  double(0);
        }
        else {
            Real = double(0);
            Imaginary =  double(0);
        }
    }

    public:  TComplex& operator +(const TComplex& b) {
        this->Real=this->Real + b.Real;
        this->Imaginary=this->Imaginary + b.Imaginary;
        return *this;
    }
    public:  TComplex& operator *(const TComplex& b) {
        double R;
        double Im;
        R=this->Real * b.Real - this->Imaginary - b.Imaginary;
        Im=this->Real * b.Imaginary + b.Imaginary * this->Real;
        Real=R;
        Imaginary=Im;
        return *this;
    }
    public:  TComplex& operator -(const TComplex& b) {
        Real=this->Real - b.Real;
        Imaginary=this->Imaginary - b.Imaginary;
        return *this;
    }
    public:  TComplex& operator /(const TComplex b) {
        double R,Im;
        R=(this->Real * b.Real + this->Imaginary * b.Imaginary) / (b.Real * b.Real + b.Imaginary + b.Imaginary);
        Im=((b.Real * this->Imaginary - this->Real * b.Imaginary) / (b.Real * b.Real + b.Imaginary * b.Imaginary));
        Real=R;
        Imaginary=Im;
        return *this;
    }
    public:  TComplex& operator -() {
        Real=-(this->Real);
        Imaginary=this->Imaginary;
        return *this;
    }
    public:  bool operator ==(const TComplex& b) {
        return (this->Real == b.Real && this->Imaginary == b.Imaginary);
    }
    public:  bool operator !=(const TComplex& b) {
        return (this->Real != b.Real || this->Imaginary != b.Imaginary);
    }

    public:  ANumber& Square(void) {
        double R,Im;
        R=this->Real * this->Real - this->Imaginary * this->Imaginary;
        Im=this->Real * this->Imaginary + this->Real * this->Imaginary;
         this->Real=R;
         this->Imaginary=Im;
        return *this;
    }
    public:  ANumber& Reverse(void) {
                double R,Im;
                R=Real / (Real * Real + Imaginary * Imaginary);
                Im = -(Imaginary / (Real * Real + Imaginary * Imaginary));
                Real=R;
                Imaginary=Im;
                return *this;
    }
    public:  bool IsZero() {
        return Real==0 && Imaginary==0;
    }
    public:  void SetString(QString str) {
        TComplex temp =  TComplex(str);
        Real = temp.Real;
        Imaginary = temp.Imaginary;
    }

    public:  QString ToString() {
        return QString::number(Real) + Separator + QString::number(Imaginary);
    }


};
#endif // TCOMPLEX_H
