#include "gradeobjects.h"

GradeObjects::GradeObjects(const QString &hw_num, const QString &mt_num, QString &fp_num, QWidget *parent) : QWidget(parent)
{
    int hwslider_num = QString::number(&hw_num);
    int mtslider_num = QString::number(&mt_num);
    int fpslider_num = QString::number(&fp_num);

    for (int i = 1; i <= hwslider_num, ++i) {
        QLabel hw_label;
        QSlider hw_slider;

        QString label_text = "HW " + i;
        hw_label -> setText(label_text);

        hw_slider -> setMinimum(0);
        hw_slider -> setMinimum(100);
        hw_slider -> setSingleStep(1);


    }

    for (int j = 0; j < mtslider_num, ++j) {

    }

    if (fpslider_num != 0) {

    }
}
