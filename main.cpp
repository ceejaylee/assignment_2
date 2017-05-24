#include <QApplication>
#include <QPushButton>

int main (int argc, char**argv)
{
    QApplication app (argc, argv);


    QPushButton button ("Hello world!");
    button.setToolTip("So this is what a tooltip is...");
    QFont font ("Courier");
    button.setFont(font);
    button.show();

    return app.exec();
}
