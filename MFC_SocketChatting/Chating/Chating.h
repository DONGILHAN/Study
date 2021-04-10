
// Chating.h : PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"		// 주 기호입니다.
#include "ListenSock.h"
#include "ChildSock.h"

// CChatingApp:
// 이 클래스의 구현에 대해서는 Chating.cpp을 참조하십시오.
//

class CChatingApp : public CWinApp
{
public:
	CChatingApp();

// 재정의입니다.
public:
	virtual BOOL InitInstance();
	void InitServer();						//서버 소켓 초기화
	void Accept();							//연결
	void SendData(CString& strData);		//데이터 전송 
	void ReceiveData();						//데이터 수신
	void ReceiveData1(CString& strData);	//혼자말하기 데이터 들어갈곳
	void CloseChild();						//연결된 소켓이 닫히면 호출
	void CleanUp();							//생성된 소켓을 닫고 메모리를 해제한다
	CListenSock* m_pServer;
	CChildSock* m_pChild;
// 구현입니다.

	DECLARE_MESSAGE_MAP()
};

extern CChatingApp theApp;