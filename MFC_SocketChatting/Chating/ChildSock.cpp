// ChildSock.cpp : ���� �����Դϴ�.
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


// CChildSock ��� �Լ�


void CChildSock::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	((CChatingApp*)AfxGetApp())->CloseChild();
	CAsyncSocket::OnClose(nErrorCode);
}


void CChildSock::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	((CChatingApp*)AfxGetApp())->ReceiveData();
	CAsyncSocket::OnReceive(nErrorCode);
}
