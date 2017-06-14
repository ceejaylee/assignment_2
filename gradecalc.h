#ifndef GRADECALC_H
#define GRADECALC_H

#include <QWidget>
#include <QProgressBar>
#include <QRadioButton>
#include "gradeobjects.h"

class GradeCalc : public QWidget
{
    Q_OBJECT
public:
    explicit GradeCalc(const int option, QWidget *parent = 0);

signals:

private slots:
    void calculateFinalGradeAll();
    void calculateFinalGradeDrop();

private:
    int option;
    int hw_num;
    int mt_num;
    int fp_num;

    GradeObjects *homeworkSect;
    GradeObjects *midtermSect;
    GradeObjects *finalproSect;
    GradeObjects *finalexamSect;

    QRadioButton *final_grade_all;
    QRadioButton *final_grade_drop;
    QProgressBar *class_score;
};

#endif // GRADECALC_H
