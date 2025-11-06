#pragma once

#include <afxwin.h>
#include <vector>

// Main window that renders calculator summaries using device context output.
class CCalcMainFrame : public CFrameWnd
{
public:
    CCalcMainFrame();

protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnPaint();

    DECLARE_MESSAGE_MAP()

private:
    std::vector<CString> lines_;
    void BuildSummary();
};
