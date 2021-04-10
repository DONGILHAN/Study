
// ChatingDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CChatingDlg 대화 상자
class CChatingDlg : public CDialogEx
{
private:
	CBrush m_brush;
// 생성입니다.
public:
	CChatingDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATING_DIALOG };
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
	afx_msg void OnClickedButtonSend();		//메세지 보내기 버튼
	CIPAddressCtrl m_IPAddress;
	CString m_strMyIP;
	afx_msg void OnCbnSelchangeCombo1();	//특무순자 이모티콘
	afx_msg void OnBnClickedButton1();		//특수문자 보내기 버튼

	afx_msg void OnBnClickedButton2();		//"안녕?" 단축키버튼
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButtonAlone();	//혼자보기 버튼
	afx_msg void OnLbnSelchangeList2();		//혼자보기 창
	afx_msg void OnBnClickedButtonMissyou();//"보고싶어" 단축키버튼
	afx_msg void OnBnClickedButtonLove();	//"사랑해" 단축키버튼
	afx_msg void OnBnClickedButtonWhatdo();	//"뭐해?" 단축키버튼
	afx_msg void OnBnClickedButtonSleep();	//"자?" 단축키버튼
	afx_msg void OnBnClickedButtonLaugh();	//"ㅋㅋㅋㅋ" 단축키버튼
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
