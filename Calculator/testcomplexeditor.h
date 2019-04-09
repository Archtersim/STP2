#ifndef TESTCOMPLEXEDITOR_H
#define TESTCOMPLEXEDITOR_H
#include <QObject>

class testcomplexeditor: public QObject {

    Q_OBJECT
    public:
        explicit testcomplexeditor(QObject *parent=0);
private slots:

         void Init1();
         void Init2();
         void Init3();
        void Init4();
         void Init5();
         void AddDeleteTest1();
         void AddDeleteTest2();
         void AddDeleteTest3();
};

#endif // TESTCOMPLEXEDITOR_H
