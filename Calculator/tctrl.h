#ifndef TCTRL_H
#define TCTRL_H
#include "QString"
#include "tproc.h"
#include "aeditor.h"
#include "anumber.h"
#include "tmemory.h"
#include "tpnumber.h"
#include <typeinfo>
#include "enums.h"

     template <class T, class Editor> class TCtrl {
        public:
         enum TCtrlState {
            cStart, cEditing, FunDone, cOperDone, cExpDone, cOpChange, cError
        };

        //Editor edit;
        //TProc<T> proc;
        //TMemory<T> memory;
        //TCtrlState curState;

     public: TCtrlState CurState;
     public: TProc<T> Proc ;
     public: TMemory<T> Memory ;
     public: Editor Edit ;

     public:
        TCtrl() {
            Edit = Editor();
            Proc = TProc<T>();
            Memory =  TMemory<T>();
            CurState = cStart;
        }



     public:
        QString ExecCommandEditor(AEditor::Command cmd) {
            QString ToReturn;
            if (CurState == cExpDone) {
                Proc.Reset();
                CurState = cStart;
            }
            if (CurState != cStart)
                CurState = cEditing;
            ToReturn = Edit.Edit(cmd);
            T TempObj = T();
            if (typeid(T)== typeid(TPNumber)) {
                T a = TempObj;
                Editor b = Edit;
                a.Notation = b.Notation;
                TempObj = a;
            }

            TempObj.SetString(ToReturn);

            Proc.Rop = TempObj;
            return ToReturn;
        }

     public:
        QString ExecOperation(Oper oper) {
            if (oper == Oper::None)return NULL;//Edit.number;
            QString ToReturn;

                switch (CurState) {
                    case TCtrlState::cStart:
                        Proc.Lop_Res = Proc.Rop;
                        Proc.Operation = oper;
                        CurState = TCtrlState::cOperDone;
                        Edit.Clear();
                        break;
                    case TCtrlState::cEditing:
                        Proc.DoOper();
                        Proc.Operation = oper;
                        Edit.Clear();
                        CurState = TCtrlState::cOperDone;
                        break;
                    case TCtrlState::FunDone:
                        if (Proc.Operation == Oper::None)
                            Proc.Lop_Res = Proc.Rop;
                        else
                            Proc.DoOper();
                        Proc.Operation = oper;
                        Edit.Clear();
                        CurState = TCtrlState::cOpChange;
                        break;
                    case TCtrlState::cOperDone:
                        CurState = TCtrlState::cOpChange;
                        Edit.Clear();
                        break;
                    case TCtrlState::cExpDone:
                        Proc.Operation = oper;
                        Proc.Rop = Proc.Lop_Res;
                        CurState = TCtrlState::cOpChange;
                        Edit.Clear();
                        break;
                    case TCtrlState::cError:
                        Proc.Reset();
                        return "ERR";
                        break;
                    case TCtrlState::cOpChange:
                        Proc.Operation = oper;
                        Edit.Clear();
                        break;
                    default:
                        break;
                }
                ToReturn = Proc.Lop_Res.ToString();


            return ToReturn;
        }


        public:
            QString ExecFunction(Func func) {
            QString ToReturn;

                if (CurState == TCtrlState::cExpDone) {
                    Proc.Rop = Proc.Lop_Res;
                    Proc.Operation = Oper::None;
                }
                Proc.DoFunc(func);
                CurState = TCtrlState::FunDone;

                ToReturn = Proc.Rop.ToString();
                Edit.number=ToReturn;

            return ToReturn;
        }

        public:
            QString Calculate() {
            QString ToReturn;

                if (CurState == TCtrlState::cStart)
                    Proc.Lop_Res = Proc.Rop;
                Proc.DoOper();
                CurState = TCtrlState::cExpDone;
                CurState = TCtrlState::cExpDone;
                ToReturn = Proc.Lop_Res.ToString();
                Edit.number=ToReturn;
            return ToReturn;
        }

        public:
            QString Reset() {
            Edit.Clear();
            Proc.Reset();
            Memory.Clear();
            CurState = TCtrlState::cStart;
            return Edit.ToString();
        }

        public:
            std::pair<T, NumStates> ExecCommandMemory(Commands command, QString str) {
            T TempObj =  T();
            TempObj.SetString(str);
            std::pair <T, NumStates> obj(T(), NumStates::OFF);

            obj = Memory.Edit(command, TempObj);


            if (command == Commands::Copy) {
                Edit.number = obj.first.ToString();
                Proc.Rop = obj.first;
            }
            return obj;
        }
    };


#endif // TCTRL_H
