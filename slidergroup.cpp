#include "slidergroup.h"

SliderGroup::SliderGroup(const QString &name, QWidget *parent) : QWidget(parent)
{
    object_name = new QLabel;
    object_name->setText(name);

    slider = new QSlider(Qt::Horizontal);
    slider->setTickPosition(QSlider::TicksBothSides);
    slider->setTickInterval(5);
    slider->setSingleStep(1);
    slider->setMaximum(100);

    spinbox = new QSpinBox;
    spinbox->setRange(0, 100);
    spinbox->setSingleStep(1);

    slash = new QLabel(tr("/100"));

    connect(slider, SIGNAL(valueChanged(int)), spinbox, SLOT(setValue(int)));
    connect(spinbox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

    sliderLayout = new QGridLayout(this);
    sliderLayout->setSizeConstraint(QLayout::SetFixedSize);
    sliderLayout->addWidget(slider, 0, 1);
    sliderLayout->addWidget(spinbox, 0, 2);
    sliderLayout->addWidget(object_name, 0, 0);
}

void SliderGroup::setValue(int value)
{
    slider->setValue(value);
    spinbox->setValue(value);
    emit valueHasChanged(value);
}

QString SliderGroup::getObjectName()
{
    QString name = object_name->text();
    return name;
}
