#include "bccontrolbar.h"

#include <QVariant>
#include <QQuickWindow>
#include <QScreen>

#include <ControlBarButton>
#include <ControlBarScrollWheel>

static constexpr double inch2mmh = 25.4;

BCControlBar::BCControlBar(QQuickItem *parent)
    : QQuickItem(parent)
    , leftButton(NULL)
    , middleButton(NULL)
    , rightButton(NULL)
    , leftScrollWheel(NULL)
    , rightScrollWheel(NULL)
{
    connect(this, &QQuickItem::windowChanged, this, &BCControlBar::handleWindowChanged);
}

BCControlBar::~BCControlBar()
{
    ;
}

ControlBarButton* BCControlBar::getLeftButton()
{
    return leftButton;
}

ControlBarButton* BCControlBar::getMiddleButton()
{
    return middleButton;
}

ControlBarButton* BCControlBar::getRightButton()
{
    return rightButton;
}

ControlBarScrollWheel* BCControlBar::getLeftScrollWheel()
{
    return leftScrollWheel;
}

ControlBarScrollWheel* BCControlBar::getRightScrollWheel()
{
    return rightScrollWheel;
}

void BCControlBar::setLeftButton(ControlBarButton* newLeftButton)
{
    setParentToThis(newLeftButton);

    QObject* anchors = newLeftButton->property("anchors").value<QObject*>();
    anchors->setProperty("verticalCenter", this->property("top"));
    anchors->setProperty("horizontalCenter", this->property("left"));

    updateButtonDpiProperties(newLeftButton, LeftButtonLocationX_mm);

    leftButton = newLeftButton;
    emit leftButtonChanged(newLeftButton);
}

void BCControlBar::setMiddleButton(ControlBarButton* newMiddleButton)
{
    setParentToThis(newMiddleButton);

    QObject* anchors = newMiddleButton->property("anchors").value<QObject*>();
    anchors->setProperty("verticalCenter", this->property("top"));
    anchors->setProperty("horizontalCenter", this->property("left"));

    updateButtonDpiProperties(newMiddleButton, LeftButtonLocationX_mm);

    middleButton = newMiddleButton;
    emit middleButtonChanged(newMiddleButton);
}

void BCControlBar::setRightButton(ControlBarButton* newRightButton)
{
    setParentToThis(newRightButton);

    QObject* anchors = newRightButton->property("anchors").value<QObject*>();
    anchors->setProperty("verticalCenter", this->property("top"));
    anchors->setProperty("horizontalCenter", this->property("left"));

    updateButtonDpiProperties(newRightButton, LeftButtonLocationX_mm);

    rightButton = newRightButton;
    emit rightButtonChanged(newRightButton);
}

void BCControlBar::setLeftScrollWheel(ControlBarScrollWheel* newLeftScrollWheel)
{
    setParentToThis(newLeftScrollWheel);

    QObject* anchors = newLeftScrollWheel->property("anchors").value<QObject*>();
    anchors->setProperty("verticalCenter", this->property("top"));
    anchors->setProperty("horizontalCenter", this->property("left"));

    updateScrollWheelDpiProperties(newLeftScrollWheel, LeftScrollWheelLocationX_mm);

    leftScrollWheel = newLeftScrollWheel;
    emit leftScrollWheelChanged(newLeftScrollWheel);
}

void BCControlBar::setRightScrollWheel(ControlBarScrollWheel* newRightScrollWheel)
{
    setParentToThis(newRightScrollWheel);

    QObject* anchors = newRightScrollWheel->property("anchors").value<QObject*>();
    anchors->setProperty("verticalCenter", this->property("top"));
    anchors->setProperty("horizontalCenter", this->property("left"));

    updateScrollWheelDpiProperties(newRightScrollWheel, RightScrollWheelLocationX_mm);

    rightScrollWheel = newRightScrollWheel;
    emit rightScrollWheelChanged(newRightScrollWheel);
}

void BCControlBar::handleWindowChanged(QQuickWindow*)
{
    updateButtonDpiProperties(leftButton, LeftButtonLocationX_mm);
    updateButtonDpiProperties(middleButton, MiddleButtonLocationX_mm);
    updateButtonDpiProperties(rightButton, RightButtonLocationX_mm);

    updateScrollWheelDpiProperties(leftScrollWheel, LeftScrollWheelLocationX_mm);
    updateScrollWheelDpiProperties(rightScrollWheel, RightScrollWheelLocationX_mm);
}

void BCControlBar::setParentToThis(QQuickItem* item)
{
    QVariant link = QVariant::fromValue<BCControlBar*>(this);
    item->setProperty("parent", link);
}

void BCControlBar::updateButtonDpiProperties(ControlBarButton* button, double location)
{
    if(button == NULL)
        return;

    QObject* anchors = button->property("anchors").value<QObject*>();
    updateDPIProperty(anchors, "horizontalCenterOffset", location);
    updateDPIProperty(button, "width", ButtonRadius_mm);
    updateDPIProperty(button, "height", ButtonRadius_mm);
}

void BCControlBar::updateScrollWheelDpiProperties(ControlBarScrollWheel* scrollWheel, double location)
{
    if(scrollWheel == NULL)
        return;

    QObject* anchors = scrollWheel->property("anchors").value<QObject*>();
    updateDPIProperty(anchors, "horizontalCenterOffset", location);
    updateDPIProperty(anchors, "verticalCenterOffset", ScrollWheelLocationY_mm);
    updateDPIProperty(scrollWheel, "width", ScrollWheelRadius_mm);
    updateDPIProperty(scrollWheel, "height", ScrollWheelRadius_mm);
}

void BCControlBar::updateDPIProperty(QObject* obj, const char* name, double value)
{
    if(obj == NULL)
        return;

    QQuickWindow* window = this->window();
    if(window == NULL)
        return;

    double dpmm = window->screen()->physicalDotsPerInchY() / inch2mmh; // Dots Per MiliMeter
    obj->setProperty(name, value * dpmm);
}

