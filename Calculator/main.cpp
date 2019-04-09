#include "calculator.h"
#include <QApplication>
#include "qstylefactory.h"
#include "string"
#include "testfrac.h"
#include "testfraceditor.h"
#include "testmemory.h"
#include "testproc.h"
#include "testtpnumber.h"
#include "testtpnumbereditor.h"
#include "testtcomplex.h"
#include "testcomplexeditor.h"
#include <QTest>
//#include "boost_mingw_qt/include/boost-1_69/boost/multiprecision/cpp_int.hpp"



int main(int argc, char *argv[])
{
//using namespace boost::multiprecision;
    //int1024_t aa=100000000000000;

   // TPNumber a;
    QApplication a(argc, argv);
    Calculator w;


    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette p;
    p = qApp->palette();
    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(142,45,197));
    p.setColor(QPalette::ButtonText, QColor(255,255,255));
    qApp->setPalette(p);


     w.show();

     //QTest::qExec(new testproc228,argc,argv);
     //QTest::qExec(new testtpnumber,argc,argv);
                    //QTest::qExec(new testtpnumbereditor,argc,argv);
     //QTest::qExec(new testtcomplex,argc,argv);
     //QTest::qExec(new testcomplexeditor,argc,argv);
     //QTest::qExec(new testfrac,argc,argv);
     //QTest::qExec(new testfraceditor,argc,argv);
     //QTest::qExec(new testmemory,argc,argv);
    return a.exec();

}
