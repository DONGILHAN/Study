
// Client.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"
#include "ConnectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientApp

BEGIN_MESSAGE_MAP(CClientApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CClientApp ����

CClientApp::CClientApp()
{
	// �ٽ� ���� ������ ����
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
	m_pClient = NULL;
}


// ������ CClientApp ��ü�Դϴ�.

CClientApp theApp;


// CClientApp �ʱ�ȭ

BOOL CClientApp::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControlsEx()�� �ʿ��մϴ�.
	// InitCommonControlsEx()�� ������� ������ â�� ���� �� �����ϴ�.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���� ���α׷����� ����� ��� ���� ��Ʈ�� Ŭ������ �����ϵ���
	// �� �׸��� �����Ͻʽÿ�.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}


	AfxEnableControlContainer();

	// ��ȭ ���ڿ� �� Ʈ�� �� �Ǵ�
	// �� ��� �� ��Ʈ���� ���ԵǾ� �ִ� ��� �� �����ڸ� ����ϴ�.
	CShellManager *pShellManager = new CShellManager;

	// MFC ��Ʈ���� �׸��� ����ϱ� ���� "Windows ����" ���־� ������ Ȱ��ȭ
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));

	CClientDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ���⿡ [Ȯ��]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ���⿡ [���]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "���: ��ȭ ���ڸ� ������ �������Ƿ� ���� ���α׷��� ����ġ �ʰ� ����˴ϴ�.\n");
		TRACE(traceAppMsg, 0, "���: ��ȭ ���ڿ��� MFC ��Ʈ���� ����ϴ� ��� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS�� ������ �� �����ϴ�.\n");
	}

	// ������ ���� �� �����ڸ� �����մϴ�.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// ��ȭ ���ڰ� �������Ƿ� ���� ���α׷��� �޽��� ������ �������� �ʰ�  ���� ���α׷��� ���� �� �ֵ��� FALSE��
	// ��ȯ�մϴ�.
	return FALSE;
}

void CClientApp::Connect()
{
	CConnectDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_pClient = new CClientSock;
		m_pClient->Create();
		m_pClient->Connect(dlg.m_strAddress, 7000);
		m_pMainWnd->GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
		m_pMainWnd->GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(FALSE);
	}
}

void CClientApp::SendData(CString& strData)
{
	CTime time;
	time = CTime::GetCurrentTime(); //����ð����� �޾ƿ���
	m_pClient->Send((LPCTSTR)strData, sizeof(TCHAR)*(strData.GetLength() + 1));
	CString strText;
	UINT nPort;

	m_pClient->GetSockName(strText, nPort);
	strText.Format(_T("[%s]: %s                              ( %d �� %d �� %d �� )"), strText, strData, time.GetHour(), time.GetMinute(), time.GetSecond());
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);
}

void CClientApp::ReceiveData()
{
	CTime time;
	time = CTime::GetCurrentTime(); //����ð����� �޾ƿ���
	char temp[1000];
	m_pClient->Receive(temp, sizeof(temp));
	CString strText;
	UINT nPort;

	m_pClient->GetPeerName(strText, nPort);
	strText.Format(_T("[%s]: %s                              ( %d �� %d �� %d �� ) "), strText, temp, time.GetHour(), time.GetMinute(), time.GetSecond());
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);
	AfxMessageBox(_T("�޼����� �����߽��ϴ�!"), MB_ICONINFORMATION);
}

void CClientApp::ReceiveData1(CString &strData) //�������� �����͹޴°�
{
	CString strText;
	strText.Format(_T("%s"), strData);
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST2))->InsertString(-1, strText);
}

void CClientApp::CleanUp()
{
	if (m_pClient)
		delete m_pClient;
}

void CClientApp::CloseChild()
{
	AfxMessageBox(_T("��ȭ�� ����Ǿ����ϴ�."));
	m_pMainWnd->GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(TRUE);
}