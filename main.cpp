#include <QApplication>

#include "gradecalc.h"

int main (int argc, char**argv)
{
    QApplication app (argc, argv);
    GradeCalc grade_calculator;
    grade_calculator.show();

    return app.exec();
}
