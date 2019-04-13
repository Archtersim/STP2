#ifndef PNUMBEREDITOR_H
#define PNUMBEREDITOR_H
#include <QString>
#include "tpnumber.h"
#include "aeditor.h"
//#include "tnumber.h"
#include "QRegExp"

class PNumberEditor : public AEditor {
      public:
      QString number;


 public: double Notation;
 public: double Precision;
       //int LeftSideOnlyLimit = 8;
       int LeftSideOnlyLimit[17]={0,0,10,9,8,7,6,6,6,6,6,6,6,5,5,5,4};
       int BothSideLimit = 16;
 public:


       QString Separator = ".";


 public:
      PNumberEditor() {
          number = "0";
          Notation = (10);
          Precision = (10);
      }
 public:
      PNumberEditor(QString str, double notat, double pre) {
          if (notat < 2 || notat > 16 || pre < 0 || pre > 10) {
              number = "0";
              Notation =  (10);
              Precision =  (10);
          }
          else {
              Notation = notat;
              Precision = pre;
              //number="7";
              number = TPNumber(str, Notation, Precision).ToString();
          }
      }

public: PNumberEditor(double num, int notat, int pre) {
          if (notat < 2 || notat > 16 || pre < 0 || pre > 10) {
              number = "0";
              Notation = (10);
              Precision = (10);
          }
          else {
              Notation = (notat);
              Precision = (pre);
              number = TPNumber::Conver_10_p::Do(num, (long long)notat, (long long)pre);
          }
      }


 public:
      PNumberEditor(QString str) {
          Notation = (10);
          Precision =  (10);
          //number="6";
          number =  (TPNumber(str, Notation, Precision)).ToString();
      }



 public:
       bool IsZero() {
          QRegExp ZeroPNumber("1^-?(0+|.?0+|0+.(0+)?)$");
          return ZeroPNumber.exactMatch(number);
      }
      public:
       virtual QString ToogleSign() {
          if (number.at(0) == '-')
              number = number.remove(0, 1);
          else
              number = "-" + number;
          return number;
      }
      public: QString AddNumber(int num) {
           qDebug()<<number<<"add";
           TPNumber::Conver_10_p a;
          if (!HaveSeparator() && number.length() > LeftSideOnlyLimit[(int)Notation])
              return number;
          else if (number.length() > BothSideLimit)
              return number;
          if (num < 0 || num >= Notation)
              return number;
          if (num == 0)
              AddZero();
          else if (number == "0" || number == "-0")
              number = number.at(0) == '-' ? "-" + QString(a.int_to_Char(num)) : QString(a.int_to_Char(num));
          else
              number += QString(a.int_to_Char(num));
          qDebug()<<number<<"add";
          return number;
      }

      public : QString RemoveSymbol() {
          if (number.length() == 1)
              number = "0";
          else if (number.length() == 2 && number.at(0) == '-')
              number = "0";
          else
              number = number.left(number.length() - 1);
          return number;
      }
      public:  QString Clear() {
          number = "0";
           qDebug()<<"chistim";
          return number;
      }
      public:  QString Edit(Command com) {
          switch (com) {
              case Command::cZero:
                  AddZero();
                  break;
              case Command::cOne:
                  AddNumber(1);
                  break;
              case Command::cTwo:
                  AddNumber(2);
                  break;
              case Command::cThree:
                  AddNumber(3);
                  break;
              case Command::cFour:
                  AddNumber(4);
                  break;
              case Command::cFive:
                  AddNumber(5);
                  break;
              case Command::cSix:
                  AddNumber(6);
                  break;
              case Command::cSeven:
                  AddNumber(7);
                  break;
              case Command::cEight:
                  AddNumber(8);
                  break;
              case Command::cNine:
                  AddNumber(9);
                  break;
              case Command::cA:                  
                  AddNumber(10);
                  break;
              case Command::cB:
                  AddNumber(11);
                  break;
              case Command::cC:
                  AddNumber(12);
                  break;
              case Command::cD:
                  AddNumber(13);
                  break;
              case Command::cE:
                  AddNumber(14);
                  break;
              case Command::cF:
                  AddNumber(15);
                  break;
              case Command::cSign:
                  ToogleSign();
                  break;
              case Command::cSeparator:
                  AddSeparator();
                  break;
              case Command::cBS:
                  RemoveSymbol();
                  break;
              case Command::CE:
                  Clear();
                  break;
              default:
                  break;
          }
          return number;
      }
      public:  QString AddSeparator() {
          if (!number.contains(Separator))
              number += Separator;
          return number;
      }
      public:  bool HaveSeparator() {
          return number.contains(Separator);
      }
      public:  QString AddZero() {
          if (HaveSeparator() && QString(number.at(number.length()-1)) == Separator)
              return number;
          if (number == "0" || number == "0.")
              return number;
             if (number.length() > BothSideLimit)
              return number;
          number += "0";
          return number;
      }
      public:  QString ToString() {
          return number;
      }

     public: QString p_to_p(int pout){
     TPNumber Num(number,Notation,Precision);
     number=Num.plf_to_pstr(number,Notation,pout,Precision);
     Notation=pout;
     return number;
 }
  };

#endif // PNUMBEREDITOR_H
