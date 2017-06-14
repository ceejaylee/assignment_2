#include "tabbedclasses.h"
#include "gradecalc.h"

TabbedClasses::TabbedClasses(QWidget *parent) : QWidget(parent)
{
    classTabs = new QTabWidget(this);
    GradeCalc *pic10b = new GradeCalc(0);
    GradeCalc *pic10c = new GradeCalc(1);
    classTabs->addTab(pic10b, tr("PIC 10B"));
    classTabs->addTab(pic10c, tr("PIC 10C"));

    setWindowTitle(tr("Grade Calculator"));
}
