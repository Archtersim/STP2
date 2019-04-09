#ifndef COMPLEXEDITOR_H
#define COMPLEXEDITOR_H
#include "QString"
#include "aeditor.h"
#include "QRegExp"
#include "tcomplex.h"
#include "qstringlist.h"
#include "qdebug.h"

class ComplexEditor : AEditor {



    public: QString number;
    public: double Notation;
     QString Separator = " + i * ";


     public:
     ComplexEditor() {
         number = "0";
     }
     public:
     ComplexEditor(int a, int b) {
         number =  TComplex(a, b).ToString();
     }
     public:
     ComplexEditor(QString str) {
         number =  TComplex(str).ToString();
     }



     public:
     bool IsZero() {
         QRegExp ZeroComplex("^-?(0+.?0*)(/s*/+/s*i/s*/*/s*-?(0+.?0*)|(/s*/+/s*i/s*/*/s*-?))?$");
         return ZeroComplex.exactMatch(number);
     }
     public:
     QString ToogleSign() {
         if (HaveSeparator()) {

             QStringList Parts = number.split(Separator);
             if (Parts[0].at(0) == '-')
                 Parts[0] = Parts[0].remove(0, 1);
             else
                 Parts[0] = '-' + Parts[0];
             if (Parts[1].at(0) == '-')
                 Parts[1] = Parts[1].remove(0, 1);
             else
                 Parts[1] = '-' + Parts[1];
             number = Parts[0] + Separator + Parts[1];
             return number;
         }
         if (number.at(0) == '-')
             number = number.remove(0, 1);
         else
             number = '-' + number;
         return number;
     }
     public:
     QString AddNumber(int a) {
         if (a < 0 || a > 9)
             return number;
         if (a == 0)
             AddZero();
         else if (number == "0" || number == "-0")
             number = number.at(0) == '-' ? "-" + QString::number(a) : QString::number(a);
         else if (number.endsWith(" 0") || number.endsWith(" -0")) {number.chop(1);number += QString::number(a);}
         else number += QString::number(a);
         return number;
     }

     public:
     QString AddZero() {
         if (number.at(number.length()-1) == '0' || number == "-0" || number.endsWith(" 0") || number.endsWith(" -0")|| number.endsWith(Separator)
                 )
             return number;
         number += "0";
         return number;
     }
     public:  QString RemoveSymbol() {
         if (number.length() == 1)
             number = "0";
         else if (number.length() == 2 && number.at(0) == '-')
             number = "-0";
         else if (HaveSeparator() && number.at(number.length() - 2) == ' ')
         {number.remove(Separator);number.chop(1);}
         else
             number.chop(1);
         return number;
     }
     public:
     QString Clear() {
         number = "0";
         qDebug()<<"chistim";
         return number;
     }
     public:
     QString Edit(Command com) {
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
             case Command::cSign:
                 ToogleSign();
                 break;
             case Command::cSeparator:
                 AddNumberSeparator();
                 break;
             case Command::cBS:
                 RemoveSymbol();
                 break;
             case Command::CE:
                 Clear();
                 break;
             case Command::cNumbSeparator:
                 AddSeparator();
                 break;
             default:
                 break;
         }
         return number;
     }
     public:  QString AddSeparator() {
         if (!HaveSeparator())
             number = number+ Separator+ "0";
         return number;
     }
     public:  bool HaveSeparator() {
         return number.contains(Separator);
     }
     public:  QString ToString() {
         return number;
     }


     public: QString AddNumberSeparator() {
         if (!HaveSeparator() && !number.contains("."))
             number += ".";
         else if (HaveSeparator()) {
            QStringList Parts;
             Parts = number.split(  Separator );
             if (!Parts[1].contains("."))
                 number += ".";
         }
         return number;
     }

 };

#endif // COMPLEXEDITOR_H
