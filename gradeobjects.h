#ifndef GRADEOBJECTS_H
#define GRADEOBJECTS_H

#include <QWidget>
#include <QGridLayout>

#include "slidergroup.h"

class GradeObjects : public QWidget
{
    Q_OBJECT
public:
    explicit GradeObjects(const QString &name, const int &number, QWidget *parent = 0);
    double returnSectionScore();
    double returnSectionScoreDrop();

signals:
    void valueChanged(int value);

private slots:
    void addToList(int value);

private:
    QString name_of_sect;
    int number_of_sect;

    double scoresList[0];
    SliderGroup *gradeObjects[0];
    double sectionScore;
    double sectionScoreDrop;

    SliderGroup *createSlider(QString &text);
    void calculateSectionGrade();
    void dropLowestScore();
};

#endif // GRADEOBJECTS_H
