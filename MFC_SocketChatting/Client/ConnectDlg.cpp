// ConnectDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Client.h"
#include "ConnectDlg.h"
#include "afxdialogex.h"


// CConnectDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CConnectDlg, CDialogEx)

CConnectDlg::CConnectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CONNECT_DLG, pParent)
{

}

CConnectDlg::~CConnectDlg()
{
}

void CConnectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConnectDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CConnectDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CConnectDlg �޽��� ó�����Դϴ�.


void CConnectDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	GetDlgItemText(IDC_IPADDRESS1, m_strAddress);
	CDialogEx::OnOK();
}
