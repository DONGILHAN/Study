#include "resource.h"
#include "ClientSock.h"
// Client.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CClientApp:
// �� Ŭ������ ������ ���ؼ��� Client.cpp�� �����Ͻʽÿ�.
//

class CClientApp : public CWinApp
{
public:
	CClientApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	void Connect();
	void SendData(CString &strData);
	void ReceiveData();
	void ReceiveData1(CString& strData);
	void CloseChild();
	void CleanUp();
	CClientSock* m_pClient;
// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CClientApp theApp;