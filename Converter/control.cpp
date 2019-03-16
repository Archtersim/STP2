#include "control.h"

Control::Control()
{
    st = Edit;
}



        QString Control::DoCmnd(Editor::Commands j) {

            if (j == Editor::EXECUTE) {
                 Convert_p_10 a; Conver_10_p b;
                double r = a.dval(ed.number, pin);
                QString res = b.Do(r, pout, acc());
                st = Converted;
                recordofhistory record;
                record.pin=QString::number(pin);
                record.pout=QString::number(pout);
                record.ednumber=ed.number;
                record.resnumber=res;
                hist.push_back(record);
                return res;
            } else {
                st = Edit;

                return ed.DoEdit(j);
            }
        }

