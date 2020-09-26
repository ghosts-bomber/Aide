#include "mainwindows.h"

MainWindows::MainWindows(QWidget *parent)
    : QWidget(parent)
{
    m_pHLayout = new QHBoxLayout();
    m_pTabWidget = new TabWidget();
    m_pHLayout->addWidget(m_pTabWidget);
    m_pHLayout->setMargin(0);
    this->setLayout(m_pHLayout);
}

MainWindows::~MainWindows()
{
}

