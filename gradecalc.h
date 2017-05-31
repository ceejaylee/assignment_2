#ifndef GRADECALC_H
#define GRADECALC_H

#include <QWidget>

class QProgressBar;
class QRadioButton;
class GradeObjects;

class GradeCalc : public QWidget
{
    Q_OBJECT
public:
    explicit GradeCalc(const QString &option, QWidget *parent = 0);

signals:

private slots:
    void hwEntered();
    void mtEntered();
    void fpEntered();
    void finalEntered();
    void calculateFinalGradeAll();
    void calculateFinalGradeDrop();

private:
    QString &option;
    QString &hw_num;
    QString &mt_num;
    QString &fp_num;

    GradeObjects *homeworkSect;
    GradeObjects *midtermSect;
    GradeObjects *finalproSect;
    GradeObjects *finalexamSect;

    QRadioButton *final_grade_all;
    QRadioButton *final_grade_drop;
    QProgressBar *class_score;
};

#endif // GRADECALC_H
