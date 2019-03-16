#include "converter.h"
#include <QApplication>
#include "convert_p_10.h"
#include <QDebug>
#include <QTest>
#include "testeditor.h"
#include "testconver_10_p.h"
#include "testconvert_p_10.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Converter w;
    w.show();
    QTest::qExec(new testeditor,argc,argv);
    QTest::qExec(new testconver_10_p,argc,argv);
    QTest::qExec(new testconvert_p_10,argc,argv);
    return a.exec();
}
