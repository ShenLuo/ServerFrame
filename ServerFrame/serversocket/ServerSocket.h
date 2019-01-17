/*
	������socket�߼�
*/

#ifndef _SERVER_SOCKET_H_
#define _SERVER_SOCKET_H_

#include <WinSock2.h>
#include <thread>
#include "ServerSocketDefine.h"
#include "../ServerBase/ServerBase.h"

class ServerSocket
{
public:
	ServerSocket(){}
	~ServerSocket(){}

	// ����socket
	int RunServerSocket(ServerBase* server, SocketConfig* param);

private:

	// socket�߳�
	void ThreadServerSocket(SocketConfig* param);

	// ��ʼ��socket
	SOCKET InitSocket(const char* sIP, int nPort);

	// ��ʼsocket
	bool StartSocket(SOCKET socket);

private:
	// socket�߳�
	std::thread m_stThread;

	// ����������
	ServerBase* m_stServer;
};

#endif // _SERVER_SOCKET_H_