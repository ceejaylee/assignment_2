#ifndef GRADEOBJECTS_H
#define GRADEOBJECTS_H

#include <QWidget>

class GradeObjects : public QWidget
{
    Q_OBJECT
public:
    explicit GradeObjects(const QString &hw_num, const QString &mt_num, QWidget *parent = 0);

signals:

public slots:
};

#endif // GRADEOBJECTS_H
