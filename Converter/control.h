#ifndef CONTROL_H
#define CONTROL_H
#include <cmath>
#include <QString>
#include <editor.h>
class Control
{
public:
    Control();
enum State { Edit, Converted };
QString DoCmnd(Editor::Commands j);
Editor ed;
int pin = 16;
int pout = 16;
const int accuracy = 10;
State st;
//hist
struct recordofhistory {QString pin;QString pout;QString ednumber;QString resnumber;};
QVector <recordofhistory> hist;
private:
    int acc() {
        return (int)round(ed.Acc() * log10(pin) / log10(pout) + 0.5); ;
        //return 5;
    }
};

#endif // CONTROL_H
