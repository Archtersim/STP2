#include "editor.h"



         QString Editor::AddDigit(int n) {
            if (n < 0 || n > 16)
            {
                    qDebug()<<"Index out of range 9\n";
                    //throw MyException{};
                    number=QString::number(-1);
                    return QString::number(-1);
                    }
            Conver_10_p a;
            if (number == zero)
                number = QString(a.int_to_Char(n));
            else
                number += a.int_to_Char(n);

            //qDebug()<<number;
            return number;
        }

        //Возвращает точность
        int Editor::Acc() {
            return number.contains(delim) ? (number.length() - number.indexOf(delim) - 1) : 0;
        }

        QString Editor::AddZero() {
            return AddDigit(0);
        }

        QString  Editor::AddDelim() {
            if (number.length() > 0 && !number.contains(delim))
                number += delim;
            return number;
        }

        //Удалить символ справа
        QString  Editor::Bs() {
            if (number.length() > 1)
                number = number.left(number.length() - 1);
            else
                number = zero;
            return number;
        }

        QString  Editor::Clear() {
            number = zero;
            return number;
        }

        QString  Editor::DoEdit(Commands j) {
            switch (j) {
                case ADD0:
                AddZero();
                break;
                case ADD1:
                AddDigit(1);
                break;
                case ADD2:
                AddDigit(2);
                break;
                case ADD3:
                AddDigit(3);
                break;
                case ADD4:
                AddDigit(4);
                break;
                case ADD5:
                AddDigit(5);
                break;
                case ADD6:
                AddDigit(6);
                break;
                case ADD7:
                AddDigit(7);
                break;
                case ADD8:
                AddDigit(8);
                break;
                case ADD9:
                AddDigit(9);
                break;
                case ADDA:
                AddDigit(10);
                break;
                case ADDB:
                AddDigit(11);
                break;
                case ADDC:
                AddDigit(12);
                break;
                case ADDD:
                AddDigit(13);
                break;
                case ADDE:
                AddDigit(14);
                break;
                case ADDF:
                AddDigit(15);
                break;
                case ADDDOT:
                AddDelim();
                break;
                case BS:
                Bs();
                break;
                case CLEAR:
                Clear();
                break;
                default:
                return number;
            }
            return number;
        }
