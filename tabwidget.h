#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "wpswindow.h"
#include "taskwindow.h"
class TabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TabWidget(QWidget *parent = nullptr);
private:
    WPSWindow* m_pWpsWindow;
    TaskWindow* m_pTaskWindow;
    QHBoxLayout* m_pHLayout;
signals:

};

#endif // TABWIDGET_H
