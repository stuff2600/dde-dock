#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QScreen>
#include <QDebug>
#include "Widgets/dockconstants.h"
#include "Panel/panel.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

public slots:
    void slotDockModeChanged(DockConstants::DockMode newMode,DockConstants::DockMode oldMode);

private:
    Panel *mainPanel = NULL;
};

#endif // MAINWIDGET_H
