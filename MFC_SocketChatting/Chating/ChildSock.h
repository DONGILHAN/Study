#pragma once

// CChildSock ��� ����Դϴ�.

class CChildSock : public CAsyncSocket
{
public:
	CChildSock();
	virtual ~CChildSock();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};


