#ifndef FRACEDITOR_H
#define FRACEDITOR_H
#include "QString"
#include "enums.h"
#include "tfrac.h"
#include "aeditor.h"

        class FracEditor : AEditor {
        public: QString number;
        public: double Notation;
         QString ZeroFraction = "0/";
        QString Separator = "/";
         int LeftSideOnlyLimit = 14;
         int BothSideLimit = 22;


        public: FracEditor() {
            number = "0";
        }
        public: FracEditor(int a, int b) {
            number = TFrac(a, b).ToString();
        }
        public: FracEditor(QString str) {

            number =  TFrac(str.toStdString()).ToString();
        }



        public:  bool IsZero() {
            return number.startsWith(ZeroFraction) || number == "0";
        }
        public:  QString ToogleSign() {
            if (number.at(0) == '-')
                number = number.remove(0, 1);
            else
                number = "-" + number;
            return number;
        }
        public:  QString AddNumber(int a) {
            if (!HaveSeparator() && number.length() > LeftSideOnlyLimit)
                return number;
            else if (number.length() > BothSideLimit)
                return number;
            if (a < 0 || a > 9)
                return number;
            if (a == 0)
                AddZero();
            else if (number == "0" || number == "-0")
                number = number.at(0) == '-' ? "-" + QString::number(a) : QString::number(a);
            else
                number += QString::number(a);
            return number;
        }

        public:  QString AddZero() {
            if (HaveSeparator() && number.at(number.length()-1) == Separator)
                return number;
            if (number == "0" || number == "0/")
                return number;
            if (number.length() > BothSideLimit)
             return number;
            number += "0";
            return number;
        }
        public:  QString RemoveSymbol() {
            qDebug()<<number;
             if (number.length() == 1)
                number = "0";
            else if (number.length() == 2 && number.at(0) == '-')
                number = "-0";
            else
                number.chop(1);
            return number;
        }
        public:  QString Clear() {
            number = "0";
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
        public:  QString ToString() {
            return number;
        }


    };


#endif // FRACEDITOR_H
