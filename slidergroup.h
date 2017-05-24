#ifndef SLIDERGROUP_H
#define SLIDERGROUP_H

#include <QWidget>

class QLabel;
class QSlider;
class QSpinBox;
class QLineEdit;

class SliderGroup : public QWidget
{
    Q_OBJECT
public:
    explicit SliderGroup(const QString &name, QWidget *parent = 0);

signals:
    valueChanged(int value);

public slots:
    void setMaximum(int value);
    void setValue(int value);

private:
    QLabel *object_name;
    QSlider *slider;
    QSpinBox *spinbox;
    QLabel *slash;
    QLineEdit *max_display;
};

#endif // SLIDERGROUP_H
