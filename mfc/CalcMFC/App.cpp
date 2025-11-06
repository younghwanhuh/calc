#include "App.h"

#include "MainFrame.h"

BOOL CCalcApp::InitInstance()
{
    CWinApp::InitInstance();

    auto* pFrame = new CCalcMainFrame();
    if (!pFrame->Create(nullptr, _T("계산기 데모")))
    {
        delete pFrame;
        return FALSE;
    }

    m_pMainWnd = pFrame;
    pFrame->ShowWindow(SW_SHOW);
    pFrame->UpdateWindow();
    return TRUE;
}

CCalcApp theApp;
