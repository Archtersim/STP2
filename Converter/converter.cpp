#include "converter.h"
#include "ui_converter.h"
#include "editor.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
Converter::Converter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Converter)
{
    ui->setupUi(this);
}

Converter::~Converter()
{
    delete ui;
}

void Converter::UpdateButtons(int value){
    QList < QWidget* > mStateWidgetListEnabled;
    QList < QWidget* > mStateWidgetListDisabled;
    mStateWidgetListEnabled<<
                       ui->pushButton_0<<
                       ui->pushButton_1<<
                       ui->pushButton_2<<
                       ui->pushButton_3<<
                       ui->pushButton_4<<
                       ui->pushButton_5<<
                       ui->pushButton_6<<
                       ui->pushButton_7<<
                       ui->pushButton_8<<
                       ui->pushButton_9<<
                       ui->pushButton_A<<
                       ui->pushButton_B<<
                       ui->pushButton_C<<
                       ui->pushButton_D<<
                       ui->pushButton_E<<
                       ui->pushButton_F;
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

void Converter::on_spinBox_from_valueChanged(int arg1)
{
ui->horizontalSlider_from->setValue(arg1);
//UpdateButtons(arg1);

}

void Converter::on_horizontalSlider_from_actionTriggered(int action)
{
}


void Converter::on_spinBox_to_valueChanged(int arg1)
{
ui->horizontalSlider_to->setValue(arg1);
}

void Converter::on_horizontalSlider_to_valueChanged(int value)
{

    ui->spinBox_to->setValue(value);
    ui->label_to->setText(QString("В %1ичную сист. счисления").arg(value));
    contr.pout=value;
    ui->lineEdit_2->setText( contr.DoCmnd(Editor::EXECUTE));
}

void Converter::on_horizontalSlider_from_valueChanged(int value)
{

    ui->spinBox_from->setValue(value);
    contr.pin=value;
    ui->label_from->setText(QString("Из системы %1ичной сист. счисления").arg(value));
    ui->lineEdit->setText(contr.DoCmnd(Editor::CLEAR));
    UpdateButtons(value);
}

void Converter::on_pushButton_0_clicked()
{
 if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
 ui->lineEdit->setText( contr.DoCmnd(Editor::ADD0));
}

void Converter::on_pushButton_1_clicked()
{
   if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
   ui->lineEdit->setText( contr.DoCmnd(Editor::ADD1));
}

void Converter::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADD2));
}

void Converter::on_pushButton_3_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADD3));
}

void Converter::on_pushButton_4_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADD4));
}

void Converter::on_pushButton_5_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADD5));
}

void Converter::on_pushButton_6_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADD6));
}

void Converter::on_pushButton_7_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADD7));
}

void Converter::on_pushButton_8_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADD8));
}

void Converter::on_pushButton_9_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADD9));
}

void Converter::on_pushButton_A_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADDA));
}

void Converter::on_pushButton_B_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADDB));
}

void Converter::on_pushButton_C_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADDC));
}

void Converter::on_pushButton_D_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADDD));
}

void Converter::on_pushButton_E_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADDE));
}

void Converter::on_pushButton_F_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
    ui->lineEdit->setText( contr.DoCmnd(Editor::ADDF));
}

void Converter::on_pushButton_dot_clicked()
{
    if(ui->lineEdit->text().length()> maxtextlength[ui->spinBox_from->value()])return;
ui->lineEdit->setText( contr.DoCmnd(Editor::ADDDOT));
}

void Converter::on_pushButton_bs_clicked()
{
ui->lineEdit->setText( contr.DoCmnd(Editor::BS));
}

void Converter::on_pushButton_ce_clicked()
{
ui->lineEdit->setText( contr.DoCmnd(Editor::CLEAR));
}

void Converter::on_pushButton_execut_clicked()
{
contr.pout=ui->spinBox_to->value();
 contr.pin=ui->spinBox_from->value();
ui->lineEdit_2->setText( contr.DoCmnd(Editor::EXECUTE));
}

void Converter::on_action_autor_triggered()
{
    QMessageBox::information(this,"Автор","Дворников Александр Николаевич, группа ИП-512(514)");
}

void Converter::on_action_3_triggered()
{

}

void Converter::on_action_quit_triggered()
{
     QApplication::quit();
}

void Converter::on_action_history_triggered()
{
if(contr.hist.size()==0){
    QMessageBox messageBox;
    messageBox.critical(0,"Warning","History is empty !");
    messageBox.setFixedSize(500,200);
    return;
    }

   QStandardItemModel *model = new QStandardItemModel;

QStandardItem *itempin,* itemout,* itemednumber,* itemresnumber;

    for(int i=0; i<contr.hist.size(); i++)
    {
        itempin = new QStandardItem(contr.hist[i].pin);
        model->setItem(i, 0, itempin);
        itemout = new QStandardItem(contr.hist[i].pout);
         model->setItem(i, 1, itemout);
         itemednumber = new QStandardItem(contr.hist[i].ednumber);
          model->setItem(i, 2, itemednumber);
          itemresnumber = new QStandardItem(contr.hist[i].resnumber);
           model->setItem(i, 3, itemresnumber);
           model->setHeaderData(i,Qt::Vertical,i+1);

    }
    model->setHeaderData(0,Qt::Horizontal,"Из какой сист.сч.");
     model->setHeaderData(1,Qt::Horizontal,"В какую сист.сч");
      model->setHeaderData(2,Qt::Horizontal,"Число до");
       model->setHeaderData(3,Qt::Horizontal,"Число после");

       QTableView *HistoryTable = new QTableView;


    HistoryTable->setModel(model);
    HistoryTable->setFixedHeight(HistoryTable->verticalHeader()->length()+50);
    HistoryTable->setFixedWidth(HistoryTable->horizontalHeader()->length()+50);
    HistoryTable->resizeRowsToContents();
    HistoryTable->resizeColumnsToContents();
    HistoryTable->show();

}

void Converter::on_lineEdit_textChanged(const QString &arg1)
{

}
