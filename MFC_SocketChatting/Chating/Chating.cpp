
// Chating.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "Chating.h"
#include "ChatingDlg.h"
#include "afxsock.h" //mfc ����Ȯ��

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChatingApp

BEGIN_MESSAGE_MAP(CChatingApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CChatingApp ����

CChatingApp::CChatingApp()
{
	// �ٽ� ���� ������ ����
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
	m_pServer = NULL;
	m_pChild = NULL;
}


// ������ CChatingApp ��ü�Դϴ�.

CChatingApp theApp;


// CChatingApp �ʱ�ȭ

BOOL CChatingApp::InitInstance()
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

	CChatingDlg dlg;
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

void CChatingApp::InitServer()
{
	m_pServer = new CListenSock;
	m_pServer->Create(7000);
	m_pServer->Listen();
}

void CChatingApp::Accept()
{
	AfxMessageBox(_T("������ �����߽��ϴ�!"));
	m_pChild = new CChildSock;
	m_pServer->Accept(*m_pChild);//Ŭ���̾�Ʈ ������ ���
	m_pMainWnd->GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
}

void CChatingApp::SendData(CString &strData)
{
	CTime time;
	time = CTime::GetCurrentTime();//����ð����� �޾ƿ���
	m_pChild->Send((LPCTSTR)strData, sizeof(TCHAR)*(strData.GetLength() + 1));
	CString strText;
	UINT nPort;
	//�ڽ��� IP �ּҿ� ��Ʈ ��ȣ�� ����
	m_pChild->GetSockName(strText, nPort);

	strText.Format(_T("[��]: %s                             		( %d �� %d �� %d �� )"), strData, time.GetHour(), time.GetMinute(), time.GetSecond());
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);
}

void CChatingApp::ReceiveData()
{

	CTime time;
	time = CTime::GetCurrentTime(); //����ð����� �޾ƿ���
	char temp[1000];
	m_pChild->Receive(temp, sizeof(temp));
	CString strText;
	UINT nPort;
	//������ IP �ּҿ� ��Ʈ ��ȣ�� ����
	m_pChild->GetSockName(strText, nPort);

	strText.Format(_T("[����]: %s                              ( %d �� %d �� %d �� )"), temp, time.GetHour(), time.GetMinute(), time.GetSecond());
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);
	AfxMessageBox(_T("�޼����� �����߽��ϴ�!"), MB_ICONINFORMATION);
}

void CChatingApp::ReceiveData1(CString &strData) //�������� �����͹޴°�
{
	CString strText;
	strText.Format(_T("%s"), strData);
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST2))->InsertString(-1, strText);
}

void CChatingApp::CleanUp()
{
	if (m_pServer)
		delete m_pServer;
	if (m_pChild)
		delete m_pChild;
}

void CChatingApp::CloseChild()
{
	AfxMessageBox(_T("��ȭ�� ����Ǿ����ϴ�."));
	delete m_pChild;
	//������ ��ư �� Ȱ��ȭ
	m_pMainWnd->GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
}