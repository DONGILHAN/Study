
// ChatingDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CChatingDlg ��ȭ ����
class CChatingDlg : public CDialogEx
{
private:
	CBrush m_brush;
// �����Դϴ�.
public:
	CChatingDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATING_DIALOG };
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
	afx_msg void OnClickedButtonSend();		//�޼��� ������ ��ư
	CIPAddressCtrl m_IPAddress;
	CString m_strMyIP;
	afx_msg void OnCbnSelchangeCombo1();	//Ư������ �̸�Ƽ��
	afx_msg void OnBnClickedButton1();		//Ư������ ������ ��ư

	afx_msg void OnBnClickedButton2();		//"�ȳ�?" ����Ű��ư
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButtonAlone();	//ȥ�ں��� ��ư
	afx_msg void OnLbnSelchangeList2();		//ȥ�ں��� â
	afx_msg void OnBnClickedButtonMissyou();//"����;�" ����Ű��ư
	afx_msg void OnBnClickedButtonLove();	//"�����" ����Ű��ư
	afx_msg void OnBnClickedButtonWhatdo();	//"����?" ����Ű��ư
	afx_msg void OnBnClickedButtonSleep();	//"��?" ����Ű��ư
	afx_msg void OnBnClickedButtonLaugh();	//"��������" ����Ű��ư
	CButton m_btsend;
	CButton m_bthello;
	CButton b_btmiss;
	CButton m_btlove;
	CButton m_btwhatdo;
	CButton m_btsleep;
	CButton m_btlaugh;
	CButton m_btalone;
	CButton m_btspecial;
};
