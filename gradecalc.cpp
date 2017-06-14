#include "gradecalc.h"
#include "gradeobjects.h"

GradeCalc::GradeCalc(const int option, QWidget *parent) : QWidget(parent)
{
    int select = option;

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

    QGridLayout *mainLayout = new QGridLayout(this);
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
#else
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
#endif

    mainLayout->addWidget(homeworkSect, 0, 0, hw_num, 1);
    mainLayout->addWidget(midtermSect, 0, 1, mt_num, 1);
    if (fp_num != 0)
    {
    mainLayout->addWidget(finalproSect, mt_num, 1, 1, 1);
    }
    int fe_row = mt_num + fp_num;
    mainLayout->addWidget(finalexamSect, fe_row, 1, 1, 1);
    mainLayout->addWidget(final_grade_all, 9, 0);
    mainLayout->addWidget(final_grade_drop, 10, 0);
    mainLayout->addWidget(class_score, 11, 0, 1, 2);

    setLayout(mainLayout);
}

void GradeCalc::calculateFinalGradeAll()
{
    double homework = homeworkSect->returnSectionScore();
    double midterm = midtermSect->returnSectionScore();
    double finalProject = finalproSect->returnSectionScore();
    double finalExam = finalexamSect->returnSectionScore();
    double finalGrade = 0;

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
    double homework = homeworkSect->returnSectionScoreDrop();
    double midterm = midtermSect->returnSectionScoreDrop();
    double finalProject = finalproSect->returnSectionScoreDrop();
    double finalExam = finalexamSect->returnSectionScoreDrop();
    double finalGrade = 0;

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
