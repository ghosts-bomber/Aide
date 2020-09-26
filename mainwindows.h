#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QWidget>
#include <QHBoxLayout>
#include "tabwidget.h"
class MainWindows : public QWidget
{
    Q_OBJECT

public:
    MainWindows(QWidget *parent = nullptr);
    ~MainWindows();
private:
    TabWidget* m_pTabWidget;
    QHBoxLayout* m_pHLayout;
};
#endif // MAINWINDOWS_H
