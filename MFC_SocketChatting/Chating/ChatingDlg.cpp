
// ChatingDlg.cpp : 姥薄 督析
//

#include "stdafx.h"
#include "Chating.h"
#include "ChatingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 誓遂 覗稽益轡 舛左拭 紫遂鞠澗 CAboutDlg 企鉢 雌切脊艦陥.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 企鉢 雌切 汽戚斗脊艦陥.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 走据脊艦陥.

// 姥薄脊艦陥.
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


// CChatingDlg 企鉢 雌切



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


// CChatingDlg 五獣走 坦軒奄

BOOL CChatingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 獣什奴 五敢拭 "舛左..." 五敢 牌鯉聖 蓄亜杯艦陥.
	m_btsend.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1)));		//穿勺 搾闘己
	m_bthello.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2)));		//照括 搾闘己
	b_btmiss.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3)));		//左壱粛陥 搾闘己
	m_btlove.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP4)));		//紫櫛背搾闘己
	m_btwhatdo.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP5)));		//更背搾闘己
	m_btsleep.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP6)));		//設切搾闘己
	m_btlaugh.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP7)));		//せせせせ搾闘己
	m_btalone.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP8)));		//蟹幻左奄搾闘己
	m_btspecial.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP9)));		//蟹幻左奄搾闘己

	// IDM_ABOUTBOX澗 獣什奴 誤敬 骨是拭 赤嬢醤 杯艦陥.
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

	// TODO: 食奄拭 蓄亜 段奄鉢 拙穣聖 蓄亜杯艦陥.
	//IP爽社 亜閃神奄
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
	return TRUE;  // 匂朕什研 珍闘継拭 竺舛馬走 省生檎 TRUE研 鋼発杯艦陥.
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

// 企鉢 雌切拭 置社鉢 舘蓄研 蓄亜拝 井酔 焼戚嬬聖 益軒形檎
//  焼掘 坪球亜 琶推杯艦陥.  庚辞/坂 乞季聖 紫遂馬澗 MFC 誓遂 覗稽益轡税 井酔拭澗
//  覗傾績趨滴拭辞 戚 拙穣聖 切疑生稽 呪楳杯艦陥.

void CChatingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 益軒奄研 是廃 巨郊戚什 珍努什闘脊艦陥.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 適虞戚情闘 紫唖莫拭辞 焼戚嬬聖 亜錘汽拭 限嫡艦陥.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 焼戚嬬聖 益験艦陥.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 紫遂切亜 置社鉢吉 但聖 塊澗 疑照拭 朕辞亜 妊獣鞠亀系 獣什奴拭辞
//  戚 敗呪研 硲窒杯艦陥.
HCURSOR CChatingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CChatingDlg::OnClickedButtonSend()
{
	// TODO: 食奄拭 珍闘継 硝顕 坦軒奄 坪球研 蓄亜杯艦陥.
	CString strData;
	GetDlgItemText(IDC_DATA, strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
	SetDlgItemText(IDC_DATA, _T(""));
}


void CChatingDlg::OnCbnSelchangeCombo1()
{
	// TODO: 食奄拭 珍闘継 硝顕 坦軒奄 坪球研 蓄亜杯艦陥.

}


void CChatingDlg::OnBnClickedButton1() // 戚乞銅嬬獄動
{
	// TODO: 食奄拭 珍闘継 硝顕 坦軒奄 坪球研 蓄亜杯艦陥.
	CString strData;
	GetDlgItemText(IDC_COMBO1, strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
	SetDlgItemText(IDC_COMBO1, _T(""));
}

void CChatingDlg::OnBnClickedButton2() //舘逐徹獄動
{
	CString strData;
	strData.Format(_T("照括?"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
	// TODO: 食奄拭 珍闘継 硝顕 坦軒奄 坪球研 蓄亜杯艦陥.
}

HBRUSH CChatingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  食奄辞 DC税 働失聖 痕井杯艦陥.
	if (nCtlColor == CTLCOLOR_DLG) return m_brush;

	else if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(0, 200, 255));
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  奄沙葵戚 旋雁馬走 省生檎 陥献 崎君獣研 鋼発杯艦陥.
	return hbr;
}


void CChatingDlg::OnBnClickedButtonAlone()
{
	// TODO: 食奄拭 珍闘継 硝顕 坦軒奄 坪球研 蓄亜杯艦陥.
	CString strData;
	GetDlgItemText(IDC_DATA, strData);
	((CChatingApp*)AfxGetApp())->ReceiveData1(strData);
	SetDlgItemText(IDC_DATA, _T(""));
}


void CChatingDlg::OnLbnSelchangeList2()
{
	// TODO: 食奄拭 珍闘継 硝顕 坦軒奄 坪球研 蓄亜杯艦陥.
}


void CChatingDlg::OnBnClickedButtonMissyou()
{
	CString strData;
	strData.Format(_T("左壱粛陥"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
	// TODO: 食奄拭 珍闘継 硝顕 坦軒奄 坪球研 蓄亜杯艦陥.
}


void CChatingDlg::OnBnClickedButtonLove()
{
	// TODO: 食奄拭 珍闘継 硝顕 坦軒奄 坪球研 蓄亜杯艦陥.
	CString strData;
	strData.Format(_T("紫櫛背"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
}


void CChatingDlg::OnBnClickedButtonWhatdo()
{
	// TODO: 食奄拭 珍闘継 硝顕 坦軒奄 坪球研 蓄亜杯艦陥.
	CString strData;
	strData.Format(_T("更背?"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
}


void CChatingDlg::OnBnClickedButtonSleep()
{
	// TODO: 食奄拭 珍闘継 硝顕 坦軒奄 坪球研 蓄亜杯艦陥.
	CString strData;
	strData.Format(_T("設切"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
}


void CChatingDlg::OnBnClickedButtonLaugh()
{
	// TODO: 食奄拭 珍闘継 硝顕 坦軒奄 坪球研 蓄亜杯艦陥.
	CString strData;
	strData.Format(_T("せせせせ"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
}
