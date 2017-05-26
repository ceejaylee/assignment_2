#include "gradecalc.h"
#include "gradeobjects.h"

GradeCalc::GradeCalc(const QString &option; QWidget *parent) : QWidget(parent)
{
    int select = QString::number(option);

    if (select == 0)
    {
        hw_num = 8;
        mt_num = 2;
        fp_num = 0;
    }
    else if (select == 1)
    {
        hw_num = 3;
        mt_num = 1;
        fp_num = 1;
    }
    else return;

    homeworkSect = new GradeObjects("Homework ", hw_num);
    midtermSect = new GradeObjects("Midterm ", mt_num);
    finalproSect = new GradeObjects("Final Project ", fp_num);
    finalexamSect = new GradeObjects("Final Exam ", 1);


    final_grade_all = new QRadioButton ("Grading Scheme 1");
    final_grade_all->setChecked(true);
    connect(final_grade_all, SIGNAL(toggled(bool)), class_score, SLOT(calculateFinalGradeAll()));

    final_grade_drop = new QRadioButton("Grading Scheme 2");
    connect(final_grade_drop, SIGNAL(toggled(bool)), class_score, SLOT(calculateFinalGradeDrop()));

    class_score = new QProgressBar;
    class_score->setRange(0, 100);
    class_score->setOrientation(Qt::Horizontal);
    class_score->setTextVisible(true);

    QGridLayout *mainLayout = new QGridLayout;
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
#else
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
#endif






    }
}

void GradeCalc::calculateFinalGradeAll()
{
    double homework = QString::toDouble(homeworkSect->sectionScore);
    double midterm = QString::toDouble(midtermSect->sectionScore);
    double finalProject = QString::toDouble(finalproSect->sectionScore);
    double finalExam = QString::toDouble(finalexamSect->sectionScore);
    double finalGrade;

    if (QString::number(option) == 0)
    {
        finalGrade = homework * 25 + midterm * 40 + finalExam * 35;
    }
    else if (QString::number(option) == 1)
    {
        finalGrade = homework * 15 + midterm * 25 + finalExam * 30 + finalProject * 35;
        finalGrade = finalGrade / 105 * 100;
    }

    class_score->setValue(finalGrade);
}
void GradeCalc::calculateFinalGradeDrop()
{
    double homework = QString::toDouble(homeworkSect->sectionScore);
    double midterm = QString::toDouble(midtermSect->sectionScore);
    double finalProject = QString::toDouble(finalproSect->sectionScore);
    double finalExam = QString::toDouble(finalexamSect->sectionScore);
    double finalGrade;

    if (QString::number(option) == 0)
    {
        finalGrade = homework * 25 + midterm * 30 + finalExam * 44;
        finalGrade = finalGrade / 99 * 100;
    }
    else if (QString::number(option) == 1)
    {
        finalGrade = homework * 15 + finalExam * 50 + finalProject * 35;

    }

    class_score->setValue(finalGrade);
}
