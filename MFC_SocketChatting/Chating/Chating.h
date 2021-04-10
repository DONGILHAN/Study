
// Chating.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.
#include "ListenSock.h"
#include "ChildSock.h"

// CChatingApp:
// �� Ŭ������ ������ ���ؼ��� Chating.cpp�� �����Ͻʽÿ�.
//

class CChatingApp : public CWinApp
{
public:
	CChatingApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	void InitServer();						//���� ���� �ʱ�ȭ
	void Accept();							//����
	void SendData(CString& strData);		//������ ���� 
	void ReceiveData();						//������ ����
	void ReceiveData1(CString& strData);	//ȥ�ڸ��ϱ� ������ ����
	void CloseChild();						//����� ������ ������ ȣ��
	void CleanUp();							//������ ������ �ݰ� �޸𸮸� �����Ѵ�
	CListenSock* m_pServer;
	CChildSock* m_pChild;
// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CChatingApp theApp;