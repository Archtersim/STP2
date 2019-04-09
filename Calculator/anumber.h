#ifndef ANUMBER_H
#define ANUMBER_H
#include "QString"
 class ANumber {
        public:
         virtual bool IsZero()=0;
         virtual ANumber& Square(void)=0;
         virtual ANumber& Reverse(void)=0;
         virtual void SetString(QString str)=0;
    };
#endif // ANUMBER_H
