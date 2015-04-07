#include "controlbarscrollwheel.h"

ControlBarScrollWheel::ControlBarScrollWheel(QQuickItem *parent)
    : QQuickItem(parent)
{
    setZ(200);
}

ControlBarScrollWheel::~ControlBarScrollWheel()
{
    ;
}

void ControlBarScrollWheel::rotateUp()
{
    emit rotation(singleTickRotationAngle);
}

void ControlBarScrollWheel::rotateDown()
{
    emit rotation(-singleTickRotationAngle);
}

