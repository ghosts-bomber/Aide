#ifndef TASKWINDOW_H
#define TASKWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
class TaskWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TaskWindow(QWidget *parent = nullptr);

signals:

};

#endif // TASKWINDOW_H
