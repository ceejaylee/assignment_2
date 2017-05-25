#ifndef GRADEOBJECTS_H
#define GRADEOBJECTS_H

#include <QWidget>

class SliderGroup;

class GradeObjects : public QWidget
{
    Q_OBJECT
public:
    explicit GradeObjects(const QString &number, QWidget *parent = 0);

signals:
    valueChanged(int value);

private slots:
    void Entered();


private:
    QString &number;

    SliderGroup *hw_objs[hw_num];
    SliderGroup *mt_objs[mt_num];

    SliderGroup *fp_obj;
    SliderGroup *final_obj;

    QProgressBar *class_score;

    SliderGroup *createSlider(const QString &text);
};

#endif // GRADEOBJECTS_H
