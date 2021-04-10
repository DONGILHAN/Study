
// ChatingDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Chating.h"
#include "ChatingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CChatingDlg ��ȭ ����



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


// CChatingDlg �޽��� ó����

BOOL CChatingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.
	m_btsend.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1)));		//���� ��Ʈ��
	m_bthello.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2)));		//�ȳ� ��Ʈ��
	b_btmiss.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3)));		//����ʹ� ��Ʈ��
	m_btlove.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP4)));		//����غ�Ʈ��
	m_btwhatdo.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP5)));		//���غ�Ʈ��
	m_btsleep.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP6)));		//���ں�Ʈ��
	m_btlaugh.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP7)));		//����������Ʈ��
	m_btalone.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP8)));		//���������Ʈ��
	m_btspecial.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP9)));		//���������Ʈ��

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//IP�ּ� ��������
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
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CChatingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CChatingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CChatingDlg::OnClickedButtonSend()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strData;
	GetDlgItemText(IDC_DATA, strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
	SetDlgItemText(IDC_DATA, _T(""));
}


void CChatingDlg::OnCbnSelchangeCombo1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}


void CChatingDlg::OnBnClickedButton1() // �̸�Ƽ�ܹ�ư
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strData;
	GetDlgItemText(IDC_COMBO1, strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
	SetDlgItemText(IDC_COMBO1, _T(""));
}

void CChatingDlg::OnBnClickedButton2() //����Ű��ư
{
	CString strData;
	strData.Format(_T("�ȳ�?"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

HBRUSH CChatingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.
	if (nCtlColor == CTLCOLOR_DLG) return m_brush;

	else if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(0, 200, 255));
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}


void CChatingDlg::OnBnClickedButtonAlone()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strData;
	GetDlgItemText(IDC_DATA, strData);
	((CChatingApp*)AfxGetApp())->ReceiveData1(strData);
	SetDlgItemText(IDC_DATA, _T(""));
}


void CChatingDlg::OnLbnSelchangeList2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CChatingDlg::OnBnClickedButtonMissyou()
{
	CString strData;
	strData.Format(_T("����ʹ�"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CChatingDlg::OnBnClickedButtonLove()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strData;
	strData.Format(_T("�����"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
}


void CChatingDlg::OnBnClickedButtonWhatdo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strData;
	strData.Format(_T("����?"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
}


void CChatingDlg::OnBnClickedButtonSleep()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strData;
	strData.Format(_T("����"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
}


void CChatingDlg::OnBnClickedButtonLaugh()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strData;
	strData.Format(_T("��������"), strData);
	((CChatingApp*)AfxGetApp())->SendData(strData);
}
