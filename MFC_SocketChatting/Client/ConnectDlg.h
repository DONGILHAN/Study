#pragma once


// CConnectDlg 대화 상자입니다.

class CConnectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CConnectDlg)

public:
	CConnectDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CConnectDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONNECT_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
public:
	CString m_strAddress;
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
};
