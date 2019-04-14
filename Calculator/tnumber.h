#ifndef TNUMBER_H
#define TNUMBER_H
#include "anumber.h"
#include "QDebug"
  class TNumber :public ANumber {
        public:
        double Number;
        TNumber() {
            Number = 0;
        }
        TNumber(double n) {
            Number = n;
        }
         TNumber(QString str) {

                Number = str.toDouble();

        }
         TNumber(const TNumber &num) {
            Number = num.Number;
        }



        public:
          TNumber Add(TNumber a){
            return TNumber(Number+a.Number);
        }
         TNumber Div(TNumber a) {
            if (a .IsZero()){
                qDebug()<<"Div by 0";
                //throw new DivideByZeroException();
            }
            return TNumber(Number / a.Number);
        }
          TNumber Sub(TNumber a) {
            return TNumber(Number - a.Number);
        }
          TNumber Mul(TNumber a) {
            return TNumber(Number * a.Number);
        }
          bool IsZero() {
            return Number == 0;
        }
          TNumber Reverse(){
            return TNumber(1 / this->Number);
        }
          TNumber Square() {
            return TNumber(Number*Number);
        }


         /* string ToString() override {
            return Number.ToString("0.###", CultureInfo.InvariantCulture);
        }
         override bool Equals(object obj) {
            var number = obj as TNumber;
            return number != null &&
                   Number == number.Number;
        }


         override void SetString(string str) { }*/


          TNumber operator +(const TNumber & b) {
            return  TNumber(this->Number + b.Number);
        }
         TNumber operator *(const TNumber & b) {
            return  TNumber(this->Number * b.Number);
        }
          TNumber operator -(const TNumber & b) {
            return  TNumber(this->Number - b.Number);
        }
         TNumber operator /(const TNumber & b) {
            if (b.Number==0)
                {
                    qDebug()<<"div by 0 (2)";
                }
            return  TNumber(this->Number / b.Number);
        }
          bool operator ==(const TNumber & b) {
             return (this->Number == b.Number);
        }
          bool operator ==(const int & b) {
            return this->Number == b;
        }
          bool operator !=(const TNumber & b) {
            return this->Number != b.Number;
        }
          bool operator !=(const int & b) {
            return this->Number != b;
        }
         bool operator >(const TNumber & b) {
            return (this->Number) > (b.Number);
        }
          bool operator <(const TNumber & b) {
            return (this->Number < b.Number);
        }
          bool operator >(const int & b) {
            return (this->Number) > (b);
        }
          bool operator <(const int & b) {
            return (this->Number < b);
        }
          TNumber operator -() {
            return  TNumber(-(this->Number));
        }
          TNumber operator /(const int & b) {
            if (b == 0){
                qDebug()<<"div by 0 (2)";                
            }
            return  TNumber(this->Number / b);
        }
          TNumber operator /(const long long & b) {
              if (b == 0){
                  qDebug()<<"div by 0 (2)";               
              }
            return  TNumber(this->Number / b);
        }
          TNumber operator +(const int & b) {
            return  TNumber(this->Number + b);
        }
          TNumber operator -(const int & b) {
            return  TNumber(this->Number - b);
        }
          TNumber operator *(const int & b) {
            return  TNumber(this->Number * b);
        }

    };
#endif // TNUMBER_H
