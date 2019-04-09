#include "testproc.h"
#include <QTest>
#include "tfrac.h"


    void testproc228:: Init1() {
       TFrac leftFrac =  TFrac();
       TFrac rightFrac =  TFrac();
       TProc<TFrac> proc =  TProc<TFrac>(leftFrac, rightFrac);
       QString answer = "0/1";
      QCOMPARE(answer, proc.Lop_Res.ToString());
      QCOMPARE(answer, proc.Rop.ToString());
   }

    void testproc228:: Init2() {
       TFrac leftFrac =  TFrac(11, 3);
       TFrac rightFrac =  TFrac();
       TProc<TFrac> proc =  TProc<TFrac>(leftFrac, rightFrac);
       QString answer = "11/3";
      QCOMPARE(answer, proc.Lop_Res.ToString());
   }

    void testproc228 :: Init3() {
       TFrac leftFrac =  TFrac(16, 4);
       TFrac rightFrac =  TFrac(17, 9);
       TProc<TFrac> proc =  TProc<TFrac>(leftFrac, rightFrac);
       QString answer = "17/9";
      QCOMPARE(answer, proc.Rop.ToString());
   }


    void testproc228:: Operation1() {
       TFrac leftFrac =  TFrac(1, 2);
       TFrac rightFrac =  TFrac(1, 2);
       TProc<TFrac> proc =  TProc<TFrac>(leftFrac, rightFrac);
       proc.Operation = Oper::Add;
       proc.DoOper();
       QString answer = "1/1";
      QCOMPARE(answer, proc.Lop_Res.ToString());
   }

    void testproc228:: Operation2() {
       TFrac leftFrac =  TFrac(3, 4);
       TFrac rightFrac =  TFrac(5, 6);
       TProc<TFrac> proc =  TProc<TFrac>(leftFrac, rightFrac);
       proc.Operation = Oper::Sub;
       proc.DoOper();
       QString answer = "-1/12";
      QCOMPARE(answer, proc.Lop_Res.ToString());
   }

    void testproc228:: Operation3() {
       TFrac leftFrac =  TFrac(12, 7);
       TFrac rightFrac =  TFrac(5, 9);
       TProc<TFrac> proc =  TProc<TFrac>(leftFrac, rightFrac);
       proc.Operation = Oper::Mul;
       proc.DoOper();
       QString answer = "20/21";
      QCOMPARE(answer, proc.Lop_Res.ToString());
   }

    void testproc228:: Operation4() {
       TFrac leftFrac =  TFrac(56, 7);
       TFrac rightFrac =  TFrac(-22, 3);
       TProc<TFrac> proc =  TProc<TFrac>(leftFrac, rightFrac);
       proc.Operation = Oper::Div;
       proc.DoOper();
       QString answer = "-12/11";
      QCOMPARE(answer, proc.Lop_Res.ToString());
   }


    void testproc228:: TestFState1() {
       TFrac leftFrac =  TFrac(56, 7);
       TFrac rightFrac =  TFrac(-22, 3);
       TProc<TFrac> proc =  TProc<TFrac>(leftFrac, rightFrac);
       proc.DoFunc(Func::Rev);
       QString answer = "-3/22";
      QCOMPARE(answer, proc.Rop.ToString());
   }

    void testproc228:: TestFState2() {
       TFrac leftFrac =  TFrac(56, 7);
       TFrac rightFrac =  TFrac(-22, 3);
       TProc<TFrac> proc =  TProc<TFrac>(leftFrac, rightFrac);
       proc.DoFunc(Func::Sqr);
       QString answer = "484/9";
      QCOMPARE(answer, proc.Rop.ToString());
   }


