#ifndef AEDITOR_H
#define AEDITOR_H
#include <QString>


      class  AEditor {
      public:
         enum class Command {
            cZero, cOne, cTwo, cThree, cFour, cFive, cSix, cSeven, cEight, cNine, cA, cB, cC, cD, cE, cF, cSign, cSeparator, cBS, CE, cNumbSeparator, cNone
         };
         public:

         virtual bool IsZero(void)=0;
         virtual QString ToogleSign(void)=0;
         virtual QString AddNumber(int num)=0;
         virtual QString AddZero(void)=0;
         virtual QString RemoveSymbol(void)=0;
         virtual QString Clear(void)=0;
         virtual QString Edit(Command com)=0;
         virtual QString AddSeparator(void)=0;
         virtual bool HaveSeparator(void)=0;

    };


#endif // AEDITOR_H
