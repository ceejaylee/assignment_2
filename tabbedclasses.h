#ifndef TABBEDCLASSES_H
#define TABBEDCLASSES_H

#include <QWidget>

class QTabWidget;

class GradeCalc;

class TabbedClasses : public QWidget
{
    Q_OBJECT
public:
    explicit TabbedClasses(QWidget *parent = 0);

signals:

public slots:

private:
    QTabWidget *tabWidget;
};

#endif // TABBEDCLASSES_H
