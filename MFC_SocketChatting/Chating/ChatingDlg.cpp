
// ChatingDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Chating.h"
#include "ChatingDlg.h"
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


// CChatingDlg 대화 상자



CChatingDlg::CChatingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHATING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS_SERVER, m_IPAddress);
	DDX_Control(pDX, IDC_BUTTON_SEND, m_btsend);
	DDX_Control(pDX, IDC_BUTTON2, m_bthello);
	DDX_Control(pDX, IDC_BUTTON_MISSYOU, b_btmiss);
	DDX_Control(pDX, IDC_BUTTON_LOVE, m_btlove);
	DDX_Control(pDX, IDC_BUTTON_WHATDO, m_btwhatdo);
	DDX_Control(pDX, IDC_BUTTON_SLEEP, m_btsleep);
	DDX_Control(pDX, IDC_BUTTON_LAUGH, m_btlaugh);
	DDX_Control(pDX, IDC_BUTTON_ALONE, m_btalone);
	DDX_Control(pDX, IDC_BUTTON1, m_btspecial);
}

BEGIN_MESSAGE_MAP(CChatingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON_SEND, &CChatingDlg::OnClickedButtonSend)
ON_CBN_SELCHANGE(IDC_COMBO1, &CChatingDlg::OnCbnSelchangeCombo1)
ON_BN_CLICKED(IDC_BUTTON1, &CChatingDlg::OnBnClickedButton1)

ON_BN_CLICKED(IDC_BUTTON2, &CChatingDlg::OnBnClickedButton2)

ON_WM_CTLCOLOR()
ON_BN_CLICKED(IDC_BUTTON_ALONE, &CChatingDlg::OnBnClickedButtonAlone)
ON_LBN_SELCHANGE(IDC_LIST2, &CChatingDlg::OnLbnSelchangeList2)
ON_BN_CLICKED(IDC_BUTTON_MISSYOU, &CChatingDlg::OnBnClickedButtonMissyou)
ON_BN_CLICKED(IDC_BUTTON_LOVE, &CChatingDlg::OnBnClickedButtonLove)
ON_BN_CLICKED(IDC_BUTTON_WHATDO, &CChatingDlg::OnBnClickedButtonWhatdo)
ON_BN_CLICKED(IDC_BUTTON_SLEEP, &CChatingDlg::OnBnClickedButtonSleep)
ON_BN_CLICKED(IDC_BUTTON_LAUGH, &CChatingDlg::OnBnClickedButtonLaugh)
END_MESSAGE_MAP()


// CChatingDlg 메시지 처리기

BOOL CChatingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.
	m_btsend.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1)));		//전송 비트맵
	m_bthello.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2)));		//안녕 비트맵
	b_btmiss.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3)));		//보고싶다 비트맵
	m_btlove.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP4)));		//사랑해비트맵
	m_btwhatdo.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP5)));		//뭐해비트맵
	m_btsleep.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP6)));		//잘자비트맵
	m_btlaugh.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP7)));		//ㅋㅋㅋㅋ비트맵
	m_btalone.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP8)));		//나만보기비트맵
	m_btspecial.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP9)));		//나만보기비트맵

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


	SetIcon(m_hIcon, TRUE);			//
	SetIcon(m_hIcon, FALSE);		//

	m_brush.CreateSolidBrush(RGB(0, 200, 255));

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	//IP주소 가져오기
	char name[255];
	PHOSTENT hostinfo;
	if (gethostname(name, sizeof(name)) == 0)
	{
		if ((hostinfo = gethostbyname(name)) != NULL)
		{
			m_strMyIP = inet_ntoa(*(struct in_addr *)*hostinfo->h_addr_list);
		}
	}
	m_IPAddress.SetWindowText(m_strMyIP);
	m_IPAddress.EnableWindow(FALSE);

	((CChatingApp*)AfxGetApp())->InitServer();
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChatingDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChatingDlg::OnPaint()
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
HCURSOR CChatingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CChatingDlg::OnClickedButtonSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	GetDlgItemText(IDC_DATA, strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
	SetDlgItemText(IDC_DATA, _T(""));
}


void CChatingDlg::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

}


void CChatingDlg::OnBnClickedButton1() // 이모티콘버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	GetDlgItemText(IDC_COMBO1, strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
	SetDlgItemText(IDC_COMBO1, _T(""));
}

void CChatingDlg::OnBnClickedButton2() //단축키버튼
{
	CString strData;
	strData.Format(_T("안녕?"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

HBRUSH CChatingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (nCtlColor == CTLCOLOR_DLG) return m_brush;

	else if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(0, 200, 255));
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void CChatingDlg::OnBnClickedButtonAlone()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	GetDlgItemText(IDC_DATA, strData);
	((CChatingApp*)AfxGetApp())->ReceiveData1(strData);
	SetDlgItemText(IDC_DATA, _T(""));
}


void CChatingDlg::OnLbnSelchangeList2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CChatingDlg::OnBnClickedButtonMissyou()
{
	CString strData;
	strData.Format(_T("보고싶다"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CChatingDlg::OnBnClickedButtonLove()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	strData.Format(_T("사랑해"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
}


void CChatingDlg::OnBnClickedButtonWhatdo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	strData.Format(_T("뭐해?"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
}


void CChatingDlg::OnBnClickedButtonSleep()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	strData.Format(_T("잘자"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
}


void CChatingDlg::OnBnClickedButtonLaugh()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strData;
	strData.Format(_T("ㅋㅋㅋㅋ"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
}
