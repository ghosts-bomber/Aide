#include "tabwidget.h"
#include <QDebug>
TabWidget::TabWidget(QWidget *parent) : QWidget(parent)
{
   m_pHLayout = new QHBoxLayout;
   m_pWpsWindow = new WPSWindow();
   m_pTaskWindow = new TaskWindow();
   QWidget* wpsWindow = m_pWpsWindow->initWpsWindow();
   if(wpsWindow)
   {
       m_pHLayout->addWidget(wpsWindow);
   }
   else
   {
       qDebug()<<"create wps window failed";
   }
   m_pHLayout->addWidget(m_pTaskWindow);
   m_pHLayout->setMargin(0);
   m_pHLayout->setSpacing(0);
   m_pHLayout->setStretchFactor(wpsWindow,8);
   m_pHLayout->setStretchFactor(m_pTaskWindow,2);
   this->setLayout(m_pHLayout);
}
