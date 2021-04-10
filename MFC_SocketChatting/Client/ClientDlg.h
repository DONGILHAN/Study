
// ClientDlg.h : 헤더 파일
//

#pragma once


// CClientDlg 대화 상자
class CClientDlg : public CDialogEx
{
// 생성입니다.
public:
	CClientDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnClickedButtonConnect();
	afx_msg void OnClickedButtonSend();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButtonHello();
	afx_msg void OnBnClickedButtonMissyou();
	afx_msg void OnBnClickedButtonLove();
	afx_msg void OnBnClickedButtonWhatdo();
	afx_msg void OnBnClickedButtonSleep();
	afx_msg void OnBnClickedButtonLaugh();
	afx_msg void OnBnClickedButtonAlone();
	afx_msg void OnBnClickedButtonImoti();
};
