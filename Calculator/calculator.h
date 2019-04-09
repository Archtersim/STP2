#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "tctrl.h"
#include "pnumbereditor.h"
#include "tfrac.h"
#include "fraceditor.h"
#include "complex.h"
#include "complexeditor.h"
namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT
public:
    TCtrl<TPNumber, PNumberEditor> pNumberController;
    TCtrl<TFrac, FracEditor> fracController;
    TCtrl<TComplex,ComplexEditor> complexController;
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_horizontalSlider_actionTriggered(int value);

    void UpdateButtons(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_11_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_119_clicked();

    void on_pushButton_102_clicked();

    void on_pushButton_99_clicked();

    void on_pushButton_108_clicked();

    void on_pushButton_120_clicked();

    void on_pushButton_104_clicked();

    void on_pushButton_103_clicked();

    void on_pushButton_97_clicked();

    void on_pushButton_116_clicked();

    void on_pushButton_107_clicked();

    void on_pushButton_111_clicked();

    void on_pushButton_118_clicked();

    void on_pushButton_117_clicked();

    void on_pushButton_122_clicked();

    void on_pushButton_101_clicked();

    void on_pushButton_110_clicked();

    void on_pushButton_113_clicked();

    void on_pushButton_109_clicked();

    void on_pushButton_98_clicked();

    void on_pushButton_105_clicked();

    void on_pushButton_112_clicked();

    void on_pushButton_121_clicked();

    void on_pushButton_121_clicked(bool checked);

    void on_pushButton_114_clicked();

    void on_pushButton_100_clicked();

    void on_pushButton_115_clicked();

    void on_pushButton_106_clicked();

    void on_pushButton_145_clicked();

    void on_pushButton_128_clicked();

    void on_pushButton_125_clicked();

    void on_pushButton_134_clicked();

    void on_pushButton_146_clicked();

    void on_pushButton_130_clicked();

    void on_pushButton_129_clicked();

    void on_pushButton_123_clicked();

    void on_pushButton_142_clicked();

    void on_pushButton_133_clicked();

    void on_pushButton_144_clicked();

    void on_pushButton_143_clicked();

    void on_pushButton_131_clicked();

    void on_pushButton_138_clicked();

    void on_pushButton_147_clicked();

    void on_pushButton_137_clicked();

    void on_pushButton_124_clicked();

    void on_pushButton_148_clicked();

    void on_pushButton_127_clicked();

    void on_pushButton_136_clicked();

    void on_pushButton_150_clicked();

    void on_pushButton_135_clicked();

    void on_pushButton_139_clicked();

    void on_pushButton_153_clicked();

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_pushButton_151_clicked();

    void on_pushButton_149_clicked();

    void on_pushButton_154_clicked();

    void on_pushButton_152_clicked();

    void on_pushButton_140_clicked();

    void on_pushButton_126_clicked();

    void on_pushButton_141_clicked();

    void on_pushButton_132_clicked();

    void on_pushButton_155_clicked();

    void on_action_exit_triggered();

    void on_action_about_triggered();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::Calculator *ui;
};

#endif // CALCULATOR_H
