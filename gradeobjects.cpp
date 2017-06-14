#include "gradeobjects.h"
#include "slidergroup.h"

GradeObjects::GradeObjects(const QString &name, const int &number, QWidget *parent) : QWidget(parent)
{
    name_of_sect = name;
    number_of_sect = number;

    QGridLayout *sectionLayout = new QGridLayout;
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
    sectionLayout->setSizeConstraint(QLayout::SetNoConstraint);
#else
    sectionLayout->setSizeConstraint(QLayout::SetFixedSize);
#endif
    const int n = number_of_sect;
    gradeObjects[n];
    scoresList[n];

    if (n == 0)
    {
        return;
    }
    else if (n == 1)
    {
        gradeObjects[0] = createSlider(name_of_sect);
        sectionLayout->addWidget(gradeObjects[0], 0, 0);
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            int j = i + 1;
            QString numbering = QString(j) + " ";
            QString label = name_of_sect;
            label += numbering;
            gradeObjects[i] = createSlider(label);
            sectionLayout->addWidget(gradeObjects[i], i, 0);
        }
    }
    calculateSectionGrade();
}

SliderGroup *GradeObjects::createSlider(QString &text)
{
    SliderGroup *sldrgrp = new SliderGroup(text);
    connect(sldrgrp, SIGNAL(valueChanged(value)), this, SLOT(addToList(value)));
    return sldrgrp;
}

void GradeObjects::addToList(int value)
{
    SliderGroup *changedSlider = qobject_cast<SliderGroup *>(sender());
    QString nameOfSlider = changedSlider->getObjectName();
    QString num = nameOfSlider.right(1);
    if (num == " ")
    {
        scoresList[0] = value;
    }
    else
    {
        int i = num.toInt() - 1;
        scoresList[i] = value;
    }
    calculateSectionGrade();
    emit valueChanged(value);
}

void GradeObjects::calculateSectionGrade()
{
    double total = 0;
    for (int i = 0; i < number_of_sect; ++i)
    {
        int score = scoresList[i];
        total += score / 100;
    }
    double percentage = total / number_of_sect;
    sectionScore = percentage;
}

void GradeObjects::dropLowestScore()
{
    double total = 0;
    double min = scoresList[0];
    for (int i = 0; i < number_of_sect; ++i)
    {
        total += scoresList[i];
    }
    for (int i = 0; i < number_of_sect; ++i)
    {
        int score = scoresList[i];
        if (score < min)
        {
            double minNum = scoresList[i];
            min = minNum;
        }
    }
    total = total - min;
    double percentage = total / (number_of_sect - 1);
    percentage = percentage / 100;
    sectionScoreDrop = percentage;
}

double GradeObjects::returnSectionScore()
{
    return sectionScore;
}

double GradeObjects::returnSectionScoreDrop()
{
    return sectionScoreDrop;
}
