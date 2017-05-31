#include "tabbedclasses.h"
#include "gradecalc.h"

TabbedClasses::TabbedClasses(QWidget *parent) : QWidget(parent)
{
    classTabs = new QTabWidget;
    classTabs->addTab(new GradeCalc(0), tr("PIC 10B"));
    classTabs->addTab(new GradeCalc(1), tr("PIC 10C"));

    setWindowTitle(tr("Grade Calculator"));
}
