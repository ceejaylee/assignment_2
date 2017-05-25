#include "gradeobjects.h"
#include "slidergroup.h"

GradeObjects::GradeObjects(const QString &hw_num, const QString &mt_num, QString &fp_num, QWidget *parent) : QWidget(parent)
{
    int hwslider_num = QString::number(&hw_num);
    int mtslider_num = QString::number(&mt_num);
    int fpslider_num = QString::number(&fp_num);

    QGridLayout *mainLayout = new QGridLayout;
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
#else
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
#endif

    for (int i = 0; i < 4; ++i)
    {
        int n;
        QString label;

        if (i == 0)
        {
            n = hwslider_num+1;
            label = "Homework ";

            for (int j = 1; j < n; ++j)
            {
                QString numbering = j + " ";
                label += numbering;
                hw_objs[j-1] = creategradeObjects(label);
                mainLayout->addWidget(hw_objs[j-1], j-1, 0);
            }
        }
        else if (i == 1)
        {
            n = mtslider_num+1;
            label = "Midterm ";

            for (int j = 1; j < n; ++j)
            {
                if (n > 2)
                {
                    QString numbering = j + " ";
                    label += j;
                }
                mt_objs[j-1] = creategradeObjects(label);
                mainLayout->addWidget(mt_objs[j-1], j-1, 1);
            }
        }
        else if (i == 2)
        {
            n = fpslider_num+1;
            label = "Final Project ";
            if (n < 2)
            {
                continue;
            }
            fp_obj = creategradeObjects(label);
            int j = mtslider_num;
            mainLayout->addWidget(fp_obj, j , 1);
        }
        else if (i == 3)
        {
            n = 2;
            label = "Final Exam ";

            final_obj = creategradeObjects(label);
            int j = mtslider_num + fpslider_num;
            mainLayout->addWidget(fp_obj, j , 1);
        }
    }

SliderGroup *GradeObjects::creategradeObjects(QString &text)
{
    SliderGroup *sldrgrp = new SliderGroup(text);
    return sldrgrp;
}
