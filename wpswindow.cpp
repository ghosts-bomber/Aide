#include "wpswindow.h"
#include <QDebug>
#include <QWindow>
using namespace wpsapi;
using namespace kfc;
using namespace wpsapiex;

WPSWindow::WPSWindow(QWidget *parent) : QWidget(parent)
{
   //initWpsWindow();
}

IKRpcClient *WPSWindow::initWPS()
{
    IKRpcClient *pWpsRpcClient = NULL;
        HRESULT hr = createWpsRpcInstance(&pWpsRpcClient);
        if (hr != S_OK)
        {
            qDebug() <<"get WpsRpcClient erro";
            return NULL;
        }
        BSTR StrWpsAddress = SysAllocString(__X("/opt/kingsoft/wps-office/office6/wps"));
        pWpsRpcClient->setProcessPath(StrWpsAddress);
        SysFreeString(StrWpsAddress);

        QVector<BSTR> vArgs;
        vArgs.resize(7);
        vArgs[0] =  SysAllocString(__X("-shield"));
        vArgs[1] =  SysAllocString(__X("-multiply"));
        vArgs[2] =  SysAllocString(__X("-x11embed"));
        vArgs[3] =  SysAllocString(QString::number(winId()).utf16());
        vArgs[4] =  SysAllocString(QString::number(width()).utf16());
        vArgs[5] =  SysAllocString(QString::number(height()).utf16());
        //-hidentp默认隐藏任务窗格
        //vArgs[6] =  SysAllocString(__X("-hidentp"));
        pWpsRpcClient->setProcessArgs(vArgs.size(), vArgs.data());

        for (int i = 0; i < vArgs.size(); i++)
        {
            SysFreeString(vArgs.at(i));
        }

        return pWpsRpcClient;
}

QWidget* WPSWindow::initWpsWindow()
{
    if (!m_spApplication)
    {
        IKRpcClient *pRpcClient = initWPS();
        m_pRpcClient = pRpcClient;
        if (pRpcClient && pRpcClient->getWpsApplication((IUnknown**)&m_spApplication) == S_OK)
        {

            //m_spApplication->get_Documents(&m_spDocs);
            m_spApplication->QueryInterface(IID__WpsApplicationEx, (void**)&m_spApplicationEx);
#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
            if (m_spApplicationEx)
            {
                unsigned long wid = 0;
                m_spApplicationEx->get_EmbedWid(&wid);
                QWidget* container = QWidget::createWindowContainer(QWindow::fromWinId(wid),this);
                return container;
            }
#endif
        }
    }
    return nullptr;
}
