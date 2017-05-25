#ifndef GRADECALC_H
#define GRADECALC_H

#include <QWidget>

class QProgressBar;

class GradeCalc : public QWidget
{
    Q_OBJECT
public:
    explicit GradeCalc(const QString &hw_num, const QString &mt_num, QString &fp_num, QWidget *parent = 0);

signals:

public slots:

private:
    QString &hw_num;
    QString &mt_num;
    QString &fp_num;
};

#endif // GRADECALC_H
