#ifndef BCCONTROLBAR_H
#define BCCONTROLBAR_H

#include <QQuickItem>

class ControlBarButton;
class ControlBarScrollWheel;

class BCControlBar : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(BCControlBar)

    Q_PROPERTY(ControlBarButton* leftButton READ getLeftButton WRITE setLeftButton NOTIFY leftButtonChanged)
    Q_PROPERTY(ControlBarButton* middleButton READ getMiddleButton WRITE setMiddleButton NOTIFY middleButtonChanged)
    Q_PROPERTY(ControlBarButton* rightButton READ getRightButton WRITE setRightButton NOTIFY rightButtonChanged)

    Q_PROPERTY(ControlBarScrollWheel* leftScrollWheel READ getLeftScrollWheel WRITE setLeftScrollWheel NOTIFY leftScrollWheelChanged)
    Q_PROPERTY(ControlBarScrollWheel* rightScrollWheel READ getRightScrollWheel WRITE setRightScrollWheel NOTIFY rightScrollWheelChanged)

    Q_CLASSINFO("DefaultProperty", "null")

public:
    static constexpr double ButtonRadius_mm = 20;
    static constexpr double LeftButtonLocationX_mm = 30;
    static constexpr double MiddleButtonLocationX_mm = 70;
    static constexpr double RightButtonLocationX_mm = 110;

    static constexpr double ScrollWheelRadius_mm = 35;
    static constexpr double ScrollWheelLocationY_mm = -20;
    static constexpr double LeftScrollWheelLocationX_mm = -10;
    static constexpr double RightScrollWheelLocationX_mm = 100;

    explicit BCControlBar(QQuickItem *parent = 0);
    ~BCControlBar();

    ControlBarButton* getLeftButton();
    ControlBarButton* getMiddleButton();
    ControlBarButton* getRightButton();

    ControlBarScrollWheel* getLeftScrollWheel();
    ControlBarScrollWheel* getRightScrollWheel();

    void setLeftButton(ControlBarButton* newLeftButton);
    void setMiddleButton(ControlBarButton* newMiddleButton);
    void setRightButton(ControlBarButton* newRightButton);

    void setLeftScrollWheel(ControlBarScrollWheel* newLeftScrollWheel);
    void setRightScrollWheel(ControlBarScrollWheel* newRightScrollWheel);

signals:
    void leftButtonChanged(ControlBarButton* newLeftButton);
    void middleButtonChanged(ControlBarButton* newMiddleButton);
    void rightButtonChanged(ControlBarButton* newRightButton);

    void leftScrollWheelChanged(ControlBarScrollWheel* newLeftScrollWheel);
    void rightScrollWheelChanged(ControlBarScrollWheel* newRightScrollWheel);

public slots:

private slots:
    void handleWindowChanged(QQuickWindow*);

private:
    ControlBarButton* leftButton;
    ControlBarButton* middleButton;
    ControlBarButton* rightButton;

    ControlBarScrollWheel* leftScrollWheel;
    ControlBarScrollWheel* rightScrollWheel;

    void setParentToThis(QQuickItem* item);

    void updateButtonDpiProperties(ControlBarButton* button, double location);
    void updateScrollWheelDpiProperties(ControlBarScrollWheel* scrollWheel, double location);

    void updateDPIProperty(QObject* obj, const char* name, double value);
};

#endif // BCCONTROLBAR_H
