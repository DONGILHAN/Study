#pragma once


// CConnectDlg ��ȭ �����Դϴ�.

class CConnectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CConnectDlg)

public:
	CConnectDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CConnectDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONNECT_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
public:
	CString m_strAddress;
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
};
