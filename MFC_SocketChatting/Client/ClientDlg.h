
// ClientDlg.h : ��� ����
//

#pragma once


// CClientDlg ��ȭ ����
class CClientDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CClientDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
