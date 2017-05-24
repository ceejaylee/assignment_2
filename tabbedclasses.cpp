#include "tabbedclasses.h"
#include "gradeobjects.h"

TabbedClasses::TabbedClasses(QWidget *parent) : QWidget(parent)
{
    tabWidget = new QTabWidget;
    tabWidget->addTab(new GradeObjects(8,2), tr("PIC 10B"));
    tabWidget->addTab(new GradeObjects(3,1), tr("PIC 10C"));

    setWindowTitle(tr("Grade Calculator"));
}
