#ifndef EDITOR_H
#define EDITOR_H
#include <QString>
#include <QDebug>
#include <convert_p_10.h>
#include <conver_10_p.h>

class Editor
{
public:
    Editor(){}
    enum Commands {
         ADD0, ADD1, ADD2, ADD3, ADD4, ADD5, ADD6, ADD7, ADD8, ADD9, ADDA, ADDB, ADDC, ADDD, ADDE, ADDF, ADDDOT, BS, CLEAR, EXECUTE
    };
public:
    const QString delim = ".";
    const QString zero = "0";
    QString number=zero;
QString AddDigit(int n);
int Acc();
QString AddZero();
QString  AddDelim();
 QString  Bs();
  QString  Clear();
   QString  DoEdit(Commands j);


};


#endif // EDITOR_H
