#include "tabbedclasses.h"
#include "gradecalc.h"

TabbedClasses::TabbedClasses(QWidget *parent) : QWidget(parent)
{
    tabWidget = new QTabWidget;
    tabWidget->addTab(new GradeCalc(8,2,0), tr("PIC 10B"));
    tabWidget->addTab(new GradeCalc(3,1,1), tr("PIC 10C"));

    setWindowTitle(tr("Grade Calculator"));
}
