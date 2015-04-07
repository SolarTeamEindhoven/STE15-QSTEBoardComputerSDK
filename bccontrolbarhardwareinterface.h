/**************************************************************************
 **
 ** Copyright 2015 Solar Team Eindhoven. All rights reserved.
 **
 ** Licensed under the Apache License, Version 2.0 (the "License");
 ** you may not use this file except in compliance with the License.
 ** You may obtain a copy of the License at
 **
 **   http://www.apache.org/licenses/LICENSE-2.0
 **
 ** Unless required by applicable law or agreed to in writing, software
 ** distributed under the License is distributed on an "AS IS" BASIS,
 ** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 ** See the License for the specific language governing permissions and
 ** limitations under the License.
 **
 **************************************************************************/

#ifndef BCCONTROLBARHARDWAREINTERFACE_H
#define BCCONTROLBARHARDWAREINTERFACE_H

#include <functional>

#include <QQuickItem>
#include <QVector>

class QQuickWindow;

class BCControlBarHardwareInterface : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(BCControlBarHardwareInterface)

    Q_PROPERTY(double position READ getPosition NOTIFY positionChanged)
    Q_PROPERTY(double topPosition READ getTopPosition WRITE setTopPosition NOTIFY topPositionChanged)
    Q_PROPERTY(double bottomPosition READ getBottomPosition WRITE setBottomPosition NOTIFY bottomPositionChanged)
    Q_PROPERTY(QList<double> feedbackPositions READ getFeedbackPositions WRITE setFeedbackPositions NOTIFY feedbackPositionsChanged)

public:
    static constexpr double barHeight_mm = 20;

    explicit BCControlBarHardwareInterface(QQuickItem* parent = NULL);
    virtual ~BCControlBarHardwareInterface();

    const QList<double>& getFeedbackPositions() const;
    void setFeedbackPositions(const QList<double>& newFeedbackPositions);

    double getTopPosition() const;
    void setTopPosition(double newTopPosition);

    double getBottomPosition() const;
    void setBottomPosition(double newBottomPosition);

    static void setPosition(double position);
    static std::function<void(const QList<double>&)> feedbackPositionsChangedCallback;

signals:
    void positionChanged(double position);
    void topPositionChanged(double topPosition);
    void bottomPositionChanged(double bottomPosition);
    void feedbackPositionsChanged(const QList<double>& feedbackPositions);

public slots:

private slots:
    void handleWindowChanged(QQuickWindow* window);
    void updateY();

protected:
    static double position;
    static double topPosition;
    static double bottomPosition;
    static QList<double> feedbackPositions;

private:
    double getPosition() const;

    static QVector<BCControlBarHardwareInterface*> bccontrolBarHardwareInterfaceList;
};

#endif // BCCONTROLBARHARDWAREINTERFACE_H
