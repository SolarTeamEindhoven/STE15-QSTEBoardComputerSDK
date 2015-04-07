#ifndef CONTROLBARBUTTON_H
#define CONTROLBARBUTTON_H

#include <QQuickItem>

class ControlBarButton : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(ControlBarButton)

public:
    explicit ControlBarButton(QQuickItem *parent = 0);
    virtual ~ControlBarButton();

signals:

public slots:

private:
};

#endif // CONTROLBARBUTTON_H
