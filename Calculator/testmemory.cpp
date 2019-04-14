#include "testmemory.h"
#include <QTest>
#include "tfrac.h"
#include "enums.h"
#include "tmemory.h"

testmemory::testmemory(QObject *parent) :
    QObject(parent)
{

}


void testmemory::InitAndOutput1() {
   TFrac frac =  TFrac(22, 33);
   TMemory<TFrac> memory =  TMemory<TFrac>(frac);
   QString answer = "2/3";
   QCOMPARE(answer, memory.FNumber.ToString());
}

void testmemory::InitAndOutput2() {
   TFrac frac =  TFrac();
   TMemory<TFrac> memory =  TMemory<TFrac>(frac);
   QString answer = "0/1";
   QCOMPARE(answer, memory.FNumber.ToString());
}

void testmemory::InitAndOutput3() {
   TFrac frac =  TFrac(-1, 5);
   TMemory<TFrac> memory =  TMemory<TFrac>(frac);
   QString answer = "-1/5";
   QCOMPARE(answer, memory.FNumber.ToString());
}


void testmemory::Sum1() {
   TFrac frac =  TFrac(-1, 5);
   TMemory<TFrac> memory =  TMemory<TFrac>(frac);
   TFrac summator =  TFrac(1, 2);
   memory.Add(summator);
   QString answer = "3/10";
   QCOMPARE(answer, memory.FNumber.ToString());
}

void testmemory::Sum2() {
   TFrac frac =  TFrac(8, 9);
   TMemory<TFrac> memory =  TMemory<TFrac>(frac);
   TFrac summator =  TFrac(-16, 3);
   memory.Add(summator);
   QString answer = "-40/9";
   QCOMPARE(answer, memory.FNumber.ToString());
}


void testmemory::TestFState1() {
   TFrac frac =  TFrac(8, 9);
   TMemory<TFrac> memory =  TMemory<TFrac>(frac);
   memory.Clear();
   auto expected =NumStates::OFF;
   QCOMPARE(expected, memory.FState);
}

void testmemory::TestFState2() {
   TFrac frac =  TFrac(8, 9);
   TMemory<TFrac> memory =  TMemory<TFrac>(frac);
   auto expected =NumStates::OFF;
   QCOMPARE(expected, memory.FState);
}

void testmemory::TestFState3() {
   TFrac frac =  TFrac(8, 9);
   TMemory<TFrac> memory =  TMemory<TFrac>(frac);
   memory.Add(frac);
   auto expected =NumStates::ON;
   QCOMPARE(expected, memory.FState);
}

