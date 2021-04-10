
// Chating.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "Chating.h"
#include "ChatingDlg.h"
#include "afxsock.h" //mfc 소켓확장

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChatingApp

BEGIN_MESSAGE_MAP(CChatingApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CChatingApp 생성

CChatingApp::CChatingApp()
{
	// 다시 시작 관리자 지원
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
	m_pServer = NULL;
	m_pChild = NULL;
}


// 유일한 CChatingApp 개체입니다.

CChatingApp theApp;


// CChatingApp 초기화

BOOL CChatingApp::InitInstance()
{
	// 응용 프로그램 매니페스트가 ComCtl32.dll 버전 6 이상을 사용하여 비주얼 스타일을
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControlsEx()가 필요합니다.
	// InitCommonControlsEx()를 사용하지 않으면 창을 만들 수 없습니다.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 응용 프로그램에서 사용할 모든 공용 컨트롤 클래스를 포함하도록
	// 이 항목을 설정하십시오.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}


	AfxEnableControlContainer();

	// 대화 상자에 셸 트리 뷰 또는
	// 셸 목록 뷰 컨트롤이 포함되어 있는 경우 셸 관리자를 만듭니다.
	CShellManager *pShellManager = new CShellManager;

	// MFC 컨트롤의 테마를 사용하기 위해 "Windows 원형" 비주얼 관리자 활성화
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 응용 프로그램 마법사에서 생성된 응용 프로그램"));

	CChatingDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 여기에 [확인]을 클릭하여 대화 상자가 없어질 때 처리할
		//  코드를 배치합니다.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 여기에 [취소]를 클릭하여 대화 상자가 없어질 때 처리할
		//  코드를 배치합니다.
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "경고: 대화 상자를 만들지 못했으므로 응용 프로그램이 예기치 않게 종료됩니다.\n");
		TRACE(traceAppMsg, 0, "경고: 대화 상자에서 MFC 컨트롤을 사용하는 경우 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS를 수행할 수 없습니다.\n");
	}

	// 위에서 만든 셸 관리자를 삭제합니다.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// 대화 상자가 닫혔으므로 응용 프로그램의 메시지 펌프를 시작하지 않고  응용 프로그램을 끝낼 수 있도록 FALSE를
	// 반환합니다.
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
	AfxMessageBox(_T("상대방이 접속했습니다!"));
	m_pChild = new CChildSock;
	m_pServer->Accept(*m_pChild);//클라이언트 접속을 허용
	m_pMainWnd->GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
}

void CChatingApp::SendData(CString &strData)
{
	CTime time;
	time = CTime::GetCurrentTime();//현재시간정보 받아오기
	m_pChild->Send((LPCTSTR)strData, sizeof(TCHAR)*(strData.GetLength() + 1));
	CString strText;
	UINT nPort;
	//자신의 IP 주소와 포트 번호를 얻음
	m_pChild->GetSockName(strText, nPort);

	strText.Format(_T("[나]: %s                             		( %d 시 %d 분 %d 초 )"), strData, time.GetHour(), time.GetMinute(), time.GetSecond());
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);
}

void CChatingApp::ReceiveData()
{

	CTime time;
	time = CTime::GetCurrentTime(); //현재시간정보 받아오기
	char temp[1000];
	m_pChild->Receive(temp, sizeof(temp));
	CString strText;
	UINT nPort;
	//상대방의 IP 주소와 포트 번호를 얻음
	m_pChild->GetSockName(strText, nPort);

	strText.Format(_T("[상대방]: %s                              ( %d 시 %d 분 %d 초 )"), temp, time.GetHour(), time.GetMinute(), time.GetSecond());
	((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);
	AfxMessageBox(_T("메세지가 도착했습니다!"), MB_ICONINFORMATION);
}

void CChatingApp::ReceiveData1(CString &strData) //나만보기 데이터받는곳
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
	AfxMessageBox(_T("대화가 종료되었습니다."));
	delete m_pChild;
	//보내기 버튼 비 활성화
	m_pMainWnd->GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
}