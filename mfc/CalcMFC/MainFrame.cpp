#include "MainFrame.h"

#include "Calculator.h"
#include "LimitedCalculator.h"

BEGIN_MESSAGE_MAP(CCalcMainFrame, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_PAINT()
END_MESSAGE_MAP()

CCalcMainFrame::CCalcMainFrame() = default;

int CCalcMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
    {
        return -1;
    }

    BuildSummary();
    return 0;
}

void CCalcMainFrame::OnPaint()
{
    CPaintDC dc(this);
    const int kLineHeight = 24;
    int y = 12;

    if (lines_.empty())
    {
        dc.TextOutW(12, y, _T("계산 결과를 준비하지 못했습니다."));
        return;
    }

    for (const auto& line : lines_)
    {
        dc.TextOutW(12, y, line);
        y += kLineHeight;
    }
}

void CCalcMainFrame::BuildSummary()
{
    lines_.clear();

    Calculator calc(10.0);
    const double after_add = calc.add(5.0);
    const double after_multiply = calc.multiply(2.0);
    const double static_sum = Calculator::add_three(1.0, 2.0, 3.0);

    LimitedCalculator limited(-10.0, 10.0);
    limited.set_value(9.0);
    const double limited_after_add = limited.add(5.0);
    const double limited_after_multiply = limited.multiply(3.0);

    lines_.emplace_back(_T("MFC 계산기 데모"));

    CString line;

    line.Format(_T("기본 계산기: 초기값 10 + 5 = %.2f"), after_add);
    lines_.push_back(line);

    line.Format(_T("기본 계산기: 위 결과 × 2 = %.2f"), after_multiply);
    lines_.push_back(line);

    line.Format(_T("정적 합산: 1 + 2 + 3 = %.2f"), static_sum);
    lines_.push_back(line);

    lines_.emplace_back(_T("제한 계산기: 범위 [-10, 10]"));

    line.Format(_T("현재 값 9 + 5 (상한 적용) = %.2f"), limited_after_add);
    lines_.push_back(line);

    line.Format(_T("현재 값 × 3 (상·하한 적용) = %.2f"), limited_after_multiply);
    lines_.push_back(line);

//     line.Format(_T("최종 값은 한계 내에 있는가? %s"), limited.within_limits(limited.value()) ? _T("예") : _T("아니오"));
//     lines_.push_back(line);
}
