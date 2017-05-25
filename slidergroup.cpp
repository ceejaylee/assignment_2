#include "slidergroup.h"

SliderGroup::SliderGroup(const QString &name, QWidget *parent) : QWidget(parent)
{
    object_name = new QLabel(tr(name));

    slider = new QSlider(Qt::Horizontal);
    slider->setTickPosition(QSlider::TicksBothSides);
    slider->setTickInterval(5);
    slider->setSingleStep(1);
    slider->setMaximum(100);

    spinbox = new QSpinBox;
    spinbox->setRange(0, 100);
    spinbox->setSingleStep(1);

    slash = new QLabel(tr(" / "));

    max_display = new QLineEdit;
    max_display->setMaxLength(4);
    max_display->text(100);

    connect(max_display, SIGNAL(valueChanged(int)), slider, SLOT(setMaximum(int)));
    connect(slider, SIGNAL(valueChanged(int)), spinbox, SLOT(setValue(int)));
    connect(spinbox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
}

void SliderGroup::setMaximum(int value)
{
    slider->setMaximum(value);
}

void SliderGroup::setValue(int value)
{
    slider->setValue(value);
    spinbox->setValue(value);
}
