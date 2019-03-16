#include "convert_p_10.h"

Convert_p_10::Convert_p_10()
{

}


 int Convert_p_10::char_To_num(QChar ch) {
            QString AllVariants = "0123456789ABCDEF";
            if (!AllVariants.contains(ch))
            {
                    qDebug()<<"Index out of range 1\n";
                    return -1;
                    //throw MyException{};
                    }
            return AllVariants.indexOf(ch);
        }

 double Convert_p_10::convert(QString P_num, long long P, long long weight) {
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

 double Convert_p_10::dval(QString P_num, long long P) {
            if (P < 2 || P > 16)
            {
                    qDebug()<<"Index out of range 3\n";
                    //throw MyException{};
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

            return Number;
        }
