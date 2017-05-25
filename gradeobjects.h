#ifndef GRADEOBJECTS_H
#define GRADEOBJECTS_H

#include <QWidget>

class SliderGroup;

class QSLider;
class QDial;
class QLabel;
class QSpinBox;
class QVector;

class GradeObjects : public QWidget
{
    Q_OBJECT
public:
    explicit GradeObjects(const QString &hw_num, const QString &mt_num, QString &fp_num, QWidget *parent = 0);

signals:

private slots:
    void hwEntered();
    void mtEntered();
    void fpEntered();
    void finalEntered();


private:
    QString &hw_num;
    QString &mt_num;
    QString &fp_num;

    SliderGroup *hw_objs[hw_num];
    SliderGroup *mt_objs[mt_num];

    SliderGroup *fp_obj;
    SliderGroup *final_obj;

    SliderGroup *creategradeObjects(QString &text);
};

#endif // GRADEOBJECTS_H
