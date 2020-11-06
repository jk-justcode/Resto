/********************************************
**
** Copyright 2020 JustCode Justyna Kulinska
**
** This file is part of Resto.
**
** Resto is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** any later version.
**
** Resto is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Resto; if not, write to the Free Software
** Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
**
********************************************/

#ifndef CYCLESCONTROLLER_H
#define CYCLESCONTROLLER_H

#include <QObject>

#include "settingscontroller.h"

class CyclesController final : public QObject
{
    Q_OBJECT
    Q_ENUMS(State)

    Q_PROPERTY(int maxCyclesNumber READ maxCyclesNumber CONSTANT)
    Q_PROPERTY(int currentIteration READ currentIteration WRITE setCurrentIteration NOTIFY currentIterationChanged)
    Q_PROPERTY(bool isCycleFinished READ isCycleFinished NOTIFY isCycleFinishedChanged)

public:
    CyclesController(SettingsController &settingsController, QObject *parent = 0);

    int maxCyclesNumber() const;

    int currentIteration() const;
    bool isCycleFinished() const;

signals:
    void currentIterationChanged(int currentIteration) const;
    void isCycleFinishedChanged(bool isCycleFinished) const;

public slots:
    void setCurrentIteration(int iteration);
    void resetCurrentIteration();
    void incrementCurrentIteration();

private:
    static const int sc_maxCyclesNumber = 3;
    SettingsController &m_settingsController;

    int m_currentIteration = 0;
};

#endif // CYCLESCONTROLLER_H
