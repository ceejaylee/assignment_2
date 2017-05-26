#ifndef GRADEOBJECTS_H
#define GRADEOBJECTS_H

#include <QWidget>

class SliderGroup;

class GradeObjects : public QWidget
{
    Q_OBJECT
public:
    explicit GradeObjects(const QString &name, const QString &number, QWidget *parent = 0);

signals:
    valueChanged(int value);

private slots:
    void addToList(int value);

private:
    QString &name;
    QString &number;

    QString *scoresList[number];
    SliderGroup *gradeObjects[number];
    QString &sectionScore;

    SliderGroup *createSlider(int &num, QString &text);
    void calculateSectionGrade();
};

#endif // GRADEOBJECTS_H
