#ifndef CONTROLBARSCROLLWHEEL_H
#define CONTROLBARSCROLLWHEEL_H

#include <QQuickItem>

class ControlBarScrollWheel : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(ControlBarScrollWheel)

public:
    static constexpr double singleTickRotationAngle = 20;

    explicit ControlBarScrollWheel(QQuickItem *parent = 0);
    ~ControlBarScrollWheel();

signals:
    void rotation(double angle);

public slots:
    void rotateUp();
    void rotateDown();
};

#endif // CONTROLBARSCROLLWHEEL_H
