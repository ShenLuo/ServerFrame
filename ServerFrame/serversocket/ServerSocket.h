/*
	服务器socket逻辑
*/

#ifndef _SERVER_SOCKET_H_
#define _SERVER_SOCKET_H_

#include <WinSock2.h>
#include <thread>
#include "ServerSocketDefine.h"

class ServerSocket
{
public:
	ServerSocket(){}
	~ServerSocket(){}

	// 运行socket
	int RunServerSocket(SocketConfig* param);

private:

	// socket线程
	void ThreadServerSocket(SocketConfig* param);

	// 初始化socket
	SOCKET InitSocket(const char* sIP, int nPort);

	// 开始socket
	bool StartSocket(SOCKET& socket);

private:
	// socket线程
	std::thread m_stThread;
};

#endif // _SERVER_SOCKET_H_