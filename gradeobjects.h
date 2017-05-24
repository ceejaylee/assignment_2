#ifndef GRADEOBJECTS_H
#define GRADEOBJECTS_H

#include <QWidget>

class QSLider;
class QDial;
class QLabel;
class QSpinBox;

class GradeObjects : public QWidget
{
    Q_OBJECT
public:
    explicit GradeObjects(const QString &hw_num, const QString &mt_num, QString &fp_num, QWidget *parent = 0);

signals:

public slots:

private:
    QString &hw_num;
    QString &mt_num;
    QString &fp_num;
};

#endif // GRADEOBJECTS_H
