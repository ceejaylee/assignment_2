#ifndef SLIDERGROUP_H
#define SLIDERGROUP_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QLineEdit>

class SliderGroup : public QWidget
{
    Q_OBJECT
public:
    explicit SliderGroup(const QString &name, QWidget *parent = 0);
    QString getObjectName();

signals:
    void valueChanged(int value);

public slots:
    void setValue(int value);

private:
    QLabel *object_name;
    QSlider *slider;
    QSpinBox *spinbox;
    QLabel *slash;
};

#endif // SLIDERGROUP_H
