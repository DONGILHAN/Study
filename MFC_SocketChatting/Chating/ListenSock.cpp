// ListenSock.cpp : ���� �����Դϴ�.
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


// CListenSock ��� �Լ�


void CListenSock::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	((CChatingApp*)AfxGetApp())->Accept(); //��������� ���� ȣ��
	CAsyncSocket::OnAccept(nErrorCode);
}
