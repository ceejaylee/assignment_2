#include "gradeobjects.h"
#include "slidergroup.h"

GradeObjects::GradeObjects(const QString &name, const QString &number, QWidget *parent) : QWidget(parent)
{
    QGridLayout *sectionLayout = new QGridLayout;
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
    sectionLayout->setSizeConstraint(QLayout::SetNoConstraint);
#else
    sectionLayout->setSizeConstraint(QLayout::SetFixedSize);
#endif
    int n = QString::number(number);

    if (n == 0)
    {
        return;
    }
    else if (n == 1)
    {
        gradeObjects[0] = createSlider(0, name);
        sectionLayout->addWidget(gradeObject[0], 0, 0);
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            int j = i + 1;
            QString numbering = j + " ";
            QString label = name;
            label += numbering;
            gradeObjects[i] = createSlider(i, label);
            sectionLayout->addWidget(gradeObjects[i], i, 0);
        }
    }
    calculateSectionGrade();
}

SliderGroup *GradeObjects::createSlider(int &num, QString &text)
{
    SliderGroup *sldrgrp = new SliderGroup(text);
    connect(sldrgrp, SIGNAL(valueChanged(value), this, SLOT(addToList(value));
    return sldrgrp;
}

void GradeObjects::addToList(int value)
{
    SliderGroup *changedSlider = qobject_cast<SliderGroup *>(sender());
    QString nameOfSlider = changedSlider->object_name();
    QString num = nameOfSlider.right(1);
    if (num == " ")
    {
        scoresList[0] = value;
    }
    else
    {
        int i = QString::number(num) - 1;
        scoresList[i] = value;
    }
    calculateSectionGrade();
    emit valueChanged(value);
}

void GradeObjects::calculateSectionGrade()
{
    double total = 0;
    for (int i = 0; i < number; ++i)
    {
        total += QString::number(scoresList[i]) / 100;
    }
    double percentage = total / number;
    sectionScore = percentage;
}

void GradeObjects::dropLowestScore()
{
    double total = 0;
    double min = QString::number(scoresList[0]);
    for (int i = 0; i < number; ++i)
    {
        total += QString::number(scoresList[i]) ;
    }
    for (int i = 0; i < number; ++i)
    {
        if (QString::number(scoresList[i]) < min)
        {
            min = QString::number(scoresList[i]);
        }
    }
    total = total - min;
    double percentage = total / (number - 1);
    percentage = percentage / 100;
    sectionScoreDrop = percentage;
}
