#pragma once

// CListenSock ��� ����Դϴ�.

class CListenSock : public CAsyncSocket
{
public:
	CListenSock();
	virtual ~CListenSock();
	virtual void OnAccept(int nErrorCode);
};


