#ifndef TPROC_H
#define TPROC_H
#include "anumber.h"
#include "enums.h"

     template <class T> class TProc {


     public: T Lop_Res ;
     public: T Rop ;
     public: Oper Operation ;

     public:
        TProc() {
            Operation = Oper::None;
            Lop_Res =  T();
            Rop =  T();
        }

     public: TProc(T leftObj, T rightObj) {
            Operation = Oper::None;
            Lop_Res = leftObj;
            Rop = rightObj;
        }

     public: void Reset() {
            Operation = Oper::None;
            T newObj = T();
            Lop_Res = Rop = newObj;
        }

     public: void DoOper() {

                T a = Lop_Res;
                T b = Rop;
                switch (Operation) {
                    case Oper::Add:
                        Lop_Res = T(a + b);
                        break;
                    case Oper::Sub:
                        Lop_Res = T(a - b);
                        break;
                    case Oper::Mul:
                        Lop_Res = T(a * b);
                        break;
                    case Oper::Div:
                        Lop_Res = T(a / b);
                        break;
                    default:
                        break;
                }

        }

     public:
        void DoFunc(Func func) {

            switch (func) {
                case Rev:                   
                    Rop.Reverse();
                    break;
                case Sqr:                 
                    Rop.Square();
                    break;
                default:
                    break;
            }
        }

    };


#endif // TPROC_H
