#include "calculator.h"
#include "ui_calculator.h"
#include "qdebug.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QMessageBox>
//#include <QShortcut>
Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    //QShortcut *shortcut = new QShortcut(QKeySequence("1"), ui->tabWidget);
    //QObject::connect(shortcut, SIGNAL(activated()), ui->tabWidget, SLOT(on_pushButton_145_clicked()));
    UpdateButtons(10);

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::UpdateButtons(int value){
    QList < QWidget* > mStateWidgetListEnabled;
    QList < QWidget* > mStateWidgetListDisabled;
    mStateWidgetListEnabled<<
                       ui->pushButton_4<<
                       ui->pushButton_5<<
                       ui->pushButton_6<<
                       ui->pushButton_7<<
                       ui->pushButton_10<<
                       ui->pushButton_11<<
                       ui->pushButton_9<<
                       ui->pushButton_8<<
                       ui->pushButton_14<<
                       ui->pushButton_15<<
                       ui->pushButton_13<<
                       ui->pushButton_12<<
                       ui->pushButton_18<<
                       ui->pushButton_19<<
                       ui->pushButton_17<<
                       ui->pushButton_16;
    value=16-value;
    while(value){
        mStateWidgetListDisabled<<mStateWidgetListEnabled.back();
        mStateWidgetListEnabled.pop_back();
        value--;
    }
    foreach( QWidget *w, mStateWidgetListDisabled )
    w->setEnabled( false );

    foreach( QWidget *w, mStateWidgetListEnabled )
    w->setEnabled( true );
}




void Calculator::on_pushButton_4_clicked()
{

    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cZero));
    //qDebug()<<a.Number;
}

void Calculator::on_pushButton_5_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cOne));
}

void Calculator::on_horizontalSlider_actionTriggered(int value)
{

}

void Calculator::on_horizontalSlider_valueChanged(int value)
{
    /*if(value!=10){ui->pushButton_24->setEnabled(false);
        ui->pushButton_25->setEnabled(false);
        ui->pushButton_26->setEnabled(false);
        ui->pushButton_27->setEnabled(false);
    }else{ui->pushButton_24->setEnabled(true);
        ui->pushButton_25->setEnabled(true);
        ui->pushButton_26->setEnabled(true);
        ui->pushButton_27->setEnabled(true);
    }*/

    ui->lineEdit->setText(QString::number(value));
    ui->lineEdit_2->setText( pNumberController.Edit.p_to_p(value));
    UpdateButtons(value);
}



void Calculator::on_pushButton_6_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cTwo));
}

void Calculator::on_pushButton_7_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cThree));
}

void Calculator::on_pushButton_10_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cFour));
}

void Calculator::on_pushButton_11_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cFive));
}
void Calculator::on_pushButton_9_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cSix));
}

void Calculator::on_pushButton_8_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cSeven));
}

void Calculator::on_pushButton_14_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cEight));
}

void Calculator::on_pushButton_15_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cNine));
}

void Calculator::on_pushButton_13_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cA));
}

void Calculator::on_pushButton_12_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cB));
}

void Calculator::on_pushButton_18_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cC));
}

void Calculator::on_pushButton_19_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cD));
}

void Calculator::on_pushButton_17_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cE));
}

void Calculator::on_pushButton_16_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cF));
}

void Calculator::on_pushButton_32_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cSeparator));
}

void Calculator::on_pushButton_clicked()
{
     ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cBS));
}

void Calculator::on_pushButton_3_clicked()
{
    ui->lineEdit_2->setText( pNumberController.Reset());
}

void Calculator::on_pushButton_2_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::CE));
}

void Calculator::on_pushButton_23_clicked()
{
    //pNumberController.Proc.Rop.Notation=ui->horizontalSlider->value();
    ui->lineEdit_2->setText( pNumberController.ExecOperation(Oper::Add));
}

void Calculator::on_pushButton_28_clicked()
{
    //pNumberController.Proc.Rop.Notation=ui->horizontalSlider->value();
    if(pNumberController.Proc.Lop_Res.Number>100000000||pNumberController.Proc.Rop.Number>100000000)
    {   TPNumber a(pNumberController.Proc.Lop_Res.Number,ui->horizontalSlider->value(),5);
        ui->lineEdit_2->setText(a.ToString());
        qDebug()<<"overflow";
        return;}
    ui->lineEdit_2->setText(pNumberController.Calculate());
}

void Calculator::on_pushButton_22_clicked()
{
    //pNumberController.Proc.Rop.Notation=ui->horizontalSlider->value();
    ui->lineEdit_2->setText( pNumberController.ExecOperation(Oper::Sub));
}

void Calculator::on_pushButton_21_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecOperation(Oper::Mul));
}

void Calculator::on_pushButton_20_clicked()
{
    //pNumberController.Proc.Rop.Notation=ui->horizontalSlider->value();
    ui->lineEdit_2->setText( pNumberController.ExecOperation(Oper::Div));
}

void Calculator::on_pushButton_30_clicked()
{
    //pNumberController.Proc.Rop.Notation=ui->horizontalSlider->value();
    ui->lineEdit_2->setText( pNumberController.ExecFunction(Func::Sqr));
}

void Calculator::on_pushButton_29_clicked()
{
    //pNumberController.Proc.Rop.Notation=ui->horizontalSlider->value();
    ui->lineEdit_2->setText( pNumberController.ExecFunction(Func::Rev));
}

void Calculator::on_pushButton_31_clicked()
{
    ui->lineEdit_2->setText( pNumberController.ExecCommandEditor(AEditor::Command::cSign));
}

void Calculator::on_pushButton_26_clicked()
{
    TPNumber a(ui->lineEdit_2->text(),ui->horizontalSlider->value(),5);

    pNumberController.ExecCommandMemory(Commands::Store,QString::number(a.Number));//MS
    if(pNumberController.Memory.FState==ON) ui->lineEdit_3->setText("M");
            else ui->lineEdit_3->setText("");
}

void Calculator::on_pushButton_24_clicked()
{
    TPNumber a(QString::number(pNumberController.ExecCommandMemory(Commands::Copy,"3").first.Number),10,5);
    pNumberController.Edit.number=TPNumber::Conver_10_p::int_to_P(a.Number,ui->horizontalSlider->value());
    ui->lineEdit_2->setText(pNumberController.Edit.number);//MR
    if(pNumberController.Memory.FState==ON) ui->lineEdit_3->setText("M");
            else ui->lineEdit_3->setText("");
}

void Calculator::on_pushButton_25_clicked()
{
   pNumberController.ExecCommandMemory(Commands::Add,ui->lineEdit_2->text()); //M+
   if(pNumberController.Memory.FState==ON) ui->lineEdit_3->setText("M");
           else ui->lineEdit_3->setText("");
}

void Calculator::on_pushButton_27_clicked()
{
    pNumberController.ExecCommandMemory(Commands::Clear,"3");//MC
    if(pNumberController.Memory.FState==ON) ui->lineEdit_3->setText("M");
            else ui->lineEdit_3->setText("");
}

void Calculator::on_pushButton_119_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cOne));
}

void Calculator::on_pushButton_102_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cTwo));
}

void Calculator::on_pushButton_99_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cThree));
}

void Calculator::on_pushButton_108_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cFour));
}

void Calculator::on_pushButton_120_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cFive));
}

void Calculator::on_pushButton_104_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cSix));
}

void Calculator::on_pushButton_103_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cSeven));
}

void Calculator::on_pushButton_97_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cEight));
}

void Calculator::on_pushButton_116_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cNine));
}

void Calculator::on_pushButton_107_clicked()
{
ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cZero));
}

void Calculator::on_pushButton_111_clicked()
{
ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cSign));
}

void Calculator::on_pushButton_118_clicked()
{
     ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cSeparator));
}

void Calculator::on_pushButton_117_clicked()
{
     ui->lineEdit_7->setText( fracController.ExecOperation(Oper::Add));
}

void Calculator::on_pushButton_122_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecOperation(Oper::Sub));
}

void Calculator::on_pushButton_101_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecOperation(Oper::Mul));
}

void Calculator::on_pushButton_110_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecOperation(Oper::Div));
}

void Calculator::on_pushButton_113_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecFunction(Func::Rev));
}

void Calculator::on_pushButton_109_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecFunction(Func::Sqr));
}

void Calculator::on_pushButton_98_clicked()
{
    ui->lineEdit_7->setText(fracController.Calculate());
}

void Calculator::on_pushButton_105_clicked()
{
     ui->lineEdit_7->setText(fracController.Reset());
}

void Calculator::on_pushButton_112_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::CE));
}

void Calculator::on_pushButton_121_clicked()
{
    ui->lineEdit_7->setText( fracController.ExecCommandEditor(AEditor::Command::cBS));
}

void Calculator::on_pushButton_121_clicked(bool checked)
{

}

void Calculator::on_pushButton_114_clicked()
{
    fracController.ExecCommandMemory(Commands::Add,ui->lineEdit_7->text()); //M+
    if(fracController.Memory.FState==ON) ui->lineEdit_4->setText("M");
            else ui->lineEdit_4->setText("");
}

void Calculator::on_pushButton_100_clicked()
{
    fracController.ExecCommandMemory(Commands::Store,ui->lineEdit_7->text());//MS
    if(fracController.Memory.FState==ON) ui->lineEdit_4->setText("M");
            else ui->lineEdit_4->setText("");
}

void Calculator::on_pushButton_115_clicked()
{
   ui->lineEdit_7->setText((fracController.ExecCommandMemory(Commands::Copy,"3").first.ToString()));//MR
    if(fracController.Memory.FState==ON) ui->lineEdit_4->setText("M");
            else ui->lineEdit_4->setText("");
}

void Calculator::on_pushButton_106_clicked()
{
    fracController.ExecCommandMemory(Commands::Clear,"3");//MC
    if(fracController.Memory.FState==ON) ui->lineEdit_4->setText("M");
            else ui->lineEdit_4->setText("");
}

void Calculator::on_pushButton_145_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cOne));
}

void Calculator::on_pushButton_128_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cTwo));
}

void Calculator::on_pushButton_125_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cThree));
}

void Calculator::on_pushButton_134_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cFour));
}

void Calculator::on_pushButton_146_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cFive));
}

void Calculator::on_pushButton_130_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cSix));
}

void Calculator::on_pushButton_129_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cSeven));
}

void Calculator::on_pushButton_123_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cEight));
}

void Calculator::on_pushButton_142_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cNine));
}

void Calculator::on_pushButton_133_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cZero));
}

void Calculator::on_pushButton_144_clicked()
{
   ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cNumbSeparator));
}

void Calculator::on_pushButton_143_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cSeparator));
}

void Calculator::on_pushButton_131_clicked()
{
     ui->lineEdit_8->setText(complexController.Reset());
}

void Calculator::on_pushButton_138_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::CE));
}

void Calculator::on_pushButton_147_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cBS));
}

void Calculator::on_pushButton_137_clicked()
{
     ui->lineEdit_8->setText( complexController.ExecCommandEditor(AEditor::Command::cSign));
}

void Calculator::on_pushButton_124_clicked()
{
     ui->lineEdit_8->setText( complexController.ExecOperation(Oper::Add));
}

void Calculator::on_pushButton_148_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecOperation(Oper::Sub));
}

void Calculator::on_pushButton_127_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecOperation(Oper::Mul));
}

void Calculator::on_pushButton_136_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecOperation(Oper::Div));
}

void Calculator::on_pushButton_150_clicked()
{
    ui->lineEdit_8->setText(complexController.Calculate());
}

void Calculator::on_pushButton_135_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecFunction(Func::Sqr));
}

void Calculator::on_pushButton_139_clicked()
{
    ui->lineEdit_8->setText( complexController.ExecFunction(Func::Rev));

}

void Calculator::on_pushButton_153_clicked()
{
    TComplex num(complexController.Edit.number);
    ui->lineEdit_9->setText(num.Pwr(ui->spinBox_3->value()).ToString());
}

void Calculator::on_spinBox_2_valueChanged(int arg1)
{
    if(ui->spinBox_4->value()<arg1)ui->spinBox_2->setValue(ui->spinBox_4->value());
}

void Calculator::on_spinBox_4_valueChanged(int arg1)
{
   if(ui->spinBox_2->value()>arg1)ui->spinBox_2->setValue(ui->spinBox_4->value());
}

void Calculator::on_pushButton_151_clicked()
{
    TComplex num(complexController.Edit.number);
    ui->lineEdit_9->setText(num.Root(ui->spinBox_4->value(),ui->spinBox_2->value()-1).ToString());
}

void Calculator::on_pushButton_149_clicked()
{
    TComplex num(complexController.Edit.number);
    ui->lineEdit_9->setText(QString::number(num.Abs()));
}

void Calculator::on_pushButton_154_clicked()
{
    TComplex num(complexController.Edit.number);
    ui->lineEdit_9->setText(QString::number(num.GetRad()));
}

void Calculator::on_pushButton_152_clicked()
{
    TComplex num(complexController.Edit.number);
    ui->lineEdit_9->setText(QString::number(num.GetDegree()));
}





void Calculator::on_pushButton_140_clicked()
{
    complexController.ExecCommandMemory(Commands::Add,ui->lineEdit_8->text()); //M+
    if(complexController.Memory.FState==ON) ui->lineEdit_5->setText("M");
            else ui->lineEdit_5->setText("");
}

void Calculator::on_pushButton_126_clicked()
{
    complexController.ExecCommandMemory(Commands::Store,ui->lineEdit_8->text());//MS
    if(complexController.Memory.FState==ON) ui->lineEdit_5->setText("M");
            else ui->lineEdit_5->setText("");
}

void Calculator::on_pushButton_141_clicked()
{
    ui->lineEdit_8->setText((complexController.ExecCommandMemory(Commands::Copy,"3").first.ToString()));//MR
     if(complexController.Memory.FState==ON) ui->lineEdit_5->setText("M");
             else ui->lineEdit_5->setText("");
}

void Calculator::on_pushButton_132_clicked()
{
    complexController.ExecCommandMemory(Commands::Clear,"3");//MC
    if(complexController.Memory.FState==ON) ui->lineEdit_5->setText("M");
            else ui->lineEdit_5->setText("");
}




void Calculator::on_pushButton_155_clicked()
{

       QStandardItemModel *model = new QStandardItemModel;

    QStandardItem *rootnum,* rootvalue;

        for(int i=0; i<ui->spinBox_4->value(); i++)
        {
             TComplex num(complexController.Edit.number);
            rootnum = new QStandardItem(QString::number(i+1));
            model->setItem(i, 0, rootnum);
            rootvalue = new QStandardItem(num.Root(ui->spinBox_4->value(),i).ToString());
             model->setItem(i, 1, rootvalue);


        }
        model->setHeaderData(0,Qt::Horizontal,"Root:");
         model->setHeaderData(1,Qt::Horizontal,"Value");

           QTableView *HistoryTable = new QTableView;


        HistoryTable->setModel(model);
        HistoryTable->setFixedHeight(HistoryTable->verticalHeader()->length()+50);
        HistoryTable->setFixedWidth(HistoryTable->horizontalHeader()->length()+50);
        HistoryTable->resizeRowsToContents();
        HistoryTable->resizeColumnsToContents();
        HistoryTable->show();
}

void Calculator::on_action_exit_triggered()
{
     QApplication::quit();
}

void Calculator::on_action_about_triggered()
{
     QMessageBox::information(this,"Автор","Дворников Александр Николаевич, группа ИП-512(514)");
}


void Calculator::on_tabWidget_currentChanged(int index)
{
    qDebug()<<index;

    if(index==0){ui->tabWidget->resize(400,470); this->resize(450,520);}
    if(index==1){ui->tabWidget->resize(350,430); this->resize(400,480);}
    if(index==2){ui->tabWidget->resize(500,500); this->resize(550,550);}

}
