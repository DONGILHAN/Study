// ListenSock.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Chating.h"
#include "ListenSock.h"


// CListenSock

CListenSock::CListenSock()
{
}

CListenSock::~CListenSock()
{
}


// CListenSock 멤버 함수


void CListenSock::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	((CChatingApp*)AfxGetApp())->Accept(); //접속허용을 위해 호출
	CAsyncSocket::OnAccept(nErrorCode);
}
