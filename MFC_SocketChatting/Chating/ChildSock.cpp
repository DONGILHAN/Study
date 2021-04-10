// ChildSock.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Chating.h"
#include "ChildSock.h"


// CChildSock

CChildSock::CChildSock()
{
}

CChildSock::~CChildSock()
{
}


// CChildSock 멤버 함수


void CChildSock::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	((CChatingApp*)AfxGetApp())->CloseChild();
	CAsyncSocket::OnClose(nErrorCode);
}


void CChildSock::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	((CChatingApp*)AfxGetApp())->ReceiveData();
	CAsyncSocket::OnReceive(nErrorCode);
}
