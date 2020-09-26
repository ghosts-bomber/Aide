#ifndef WPSWINDOW_H
#define WPSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "wpsapi.h"
#include "kfc/comsptr.h"
#include "wpsapiex.h"
class WPSWindow : public QWidget
{
    Q_OBJECT
public:
    explicit WPSWindow(QWidget *parent = nullptr);

signals:

public:
   IKRpcClient* initWPS();
   QWidget* initWpsWindow();
private:
    IKRpcClient* m_pRpcClient = nullptr;
    kfc::ks_stdptr<wpsapi::_Application> m_spApplication;
    kfc::ks_stdptr<wpsapiex::_ApplicationEx> m_spApplicationEx;
    kfc::ks_stdptr<wpsapi::Documents> m_spDocs;
};

#endif // WPSWINDOW_H
