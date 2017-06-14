#ifndef TABBEDCLASSES_H
#define TABBEDCLASSES_H

#include <QWidget>
#include <QTabWidget>

#include "gradecalc.h"

class TabbedClasses : public QWidget
{
    Q_OBJECT
public:
    explicit TabbedClasses(QWidget *parent = 0);

signals:

public slots:

private:
    QTabWidget *classTabs;
};

#endif // TABBEDCLASSES_H
