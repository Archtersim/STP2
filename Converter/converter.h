#ifndef CONVERTER_H
#define CONVERTER_H

#include <QMainWindow>
#include <QMessageBox>
#include <editor.h>
#include <control.h>
namespace Ui {
class Converter;
}

class Converter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Converter(QWidget *parent = 0);
    Control contr;
    ~Converter();

private slots:
    void on_spinBox_from_valueChanged(int arg1);

    void on_horizontalSlider_from_actionTriggered(int action);

    void on_spinBox_to_valueChanged(int arg1);

    void on_horizontalSlider_to_valueChanged(int value);

    void on_horizontalSlider_from_valueChanged(int value);

    void UpdateButtons(int value);

    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_A_clicked();

    void on_pushButton_B_clicked();

    void on_pushButton_C_clicked();

    void on_pushButton_D_clicked();

    void on_pushButton_E_clicked();

    void on_pushButton_F_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_bs_clicked();

    void on_pushButton_ce_clicked();

    void on_pushButton_execut_clicked();

    void on_action_autor_triggered();

    void on_action_3_triggered();

    void on_action_quit_triggered();

    void on_action_history_triggered();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Converter *ui;

    int maxtextlength[17]={0, 0, 20, 20, 19, 19, 19, 18, 17, 16, 15, 14, 13, 12, 12, 12, 12};

};

#endif // CONVERTER_H
