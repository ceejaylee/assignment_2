#include <QApplication>

#include "tabbedclasses.h"

int main (int argc, char**argv)
{
    QApplication app (argc, argv);
    TabbedClasses grade_calculator;
    grade_calculator.show();

    return app.exec();
}
