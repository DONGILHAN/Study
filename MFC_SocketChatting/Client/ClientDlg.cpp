
// ClientDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CClientDlg 대화 상자



CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CClientDlg::OnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CClientDlg::OnClickedButtonSend)
	ON_LBN_SELCHANGE(IDC_LIST1, &CClientDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON_HELLO, &CClientDlg::OnBnClickedButtonHello)
	ON_BN_CLICKED(IDC_BUTTON_MISSYOU, &CClientDlg::OnBnClickedButtonMissyou)
	ON_BN_CLICKED(IDC_BUTTON_LOVE, &CClientDlg::OnBnClickedButtonLove)
	ON_BN_CLICKED(IDC_BUTTON_WHATDO, &CClientDlg::OnBnClickedButtonWhatdo)
	ON_BN_CLICKED(IDC_BUTTON_SLEEP, &CClientDlg::OnBnClickedButtonSleep)
	ON_BN_CLICKED(IDC_BUTTON_LAUGH, &CClientDlg::OnBnClickedButtonLaugh)
	ON_BN_CLICKED(IDC_BUTTON_ALONE, &CClientDlg::OnBnClickedButtonAlone)
	ON_BN_CLICKED(IDC_BUTTON_IMOTI, &CClientDlg::OnBnClickedButtonImoti)
END_MESSAGE_MAP()


// CClientDlg 메시지 처리기

BOOL CClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CClientDlg::OnClickedButtonConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CClientApp*)AfxGetApp())->Connect();
}


void CClientDlg::OnClickedButtonSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	GetDlgItemText(IDC_EDIT_DATA, strData);
	((CClientApp*)AfxGetApp())->SendData(strData);
	SetDlgItemText(IDC_EDIT_DATA, _T(" "));
}


void CClientDlg::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CClientDlg::OnBnClickedButtonHello()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	strData.Format(_T("안녕?"), strData);
	((CClientApp*)AfxGetApp())->SendData(strData);
}


void CClientDlg::OnBnClickedButtonMissyou()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	strData.Format(_T("보고싶다"), strData);
	((CClientApp*)AfxGetApp())->SendData(strData);
}


void CClientDlg::OnBnClickedButtonLove()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	strData.Format(_T("사랑해"), strData);
	((CClientApp*)AfxGetApp())->SendData(strData);
}


void CClientDlg::OnBnClickedButtonWhatdo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	strData.Format(_T("뭐해?"), strData);
	((CClientApp*)AfxGetApp())->SendData(strData);
}


void CClientDlg::OnBnClickedButtonSleep()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	strData.Format(_T("자?"), strData);
	((CClientApp*)AfxGetApp())->SendData(strData);
}


void CClientDlg::OnBnClickedButtonLaugh()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	strData.Format(_T("ㅋㅋㅋㅋ"), strData);
	((CClientApp*)AfxGetApp())->SendData(strData);
}


void CClientDlg::OnBnClickedButtonAlone()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	GetDlgItemText(IDC_EDIT_DATA, strData);
	((CClientApp*)AfxGetApp())->ReceiveData1(strData);
	SetDlgItemText(IDC_EDIT_DATA, _T(""));
}


void CClientDlg::OnBnClickedButtonImoti()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	GetDlgItemText(IDC_COMBO1, strData);
	((CClientApp*)AfxGetApp())->SendData(strData);
	SetDlgItemText(IDC_COMBO1, _T(""));
}
