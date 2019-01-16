/*
	服务器socket逻辑
*/

#include "ServerSocket.h"

// 运送socket
int ServerSocket::RunServerSocket(SocketConfig* param)
{
	m_stThread = std::thread(&ServerSocket::ThreadServerSocket, this, param);
	m_stThread.detach();
}

// socket线程
void ServerSocket::ThreadServerSocket(SocketConfig* param)
{
	SOCKET temp = InitSocket(param->sIp.c_str(), param->nPort);

	return;
}

// 初始化socket
SOCKET ServerSocket::InitSocket(const char* sIP, int nPort)
{
	// 获取WSADATA信息
	WSADATA wsData;
	int nResult = WSAStartup(MAKEWORD(2,2), &wsData);
	if (NO_ERROR != nResult)
	{
		return INVALID_SOCKET;
	}

	// 创建Socket对象
	SOCKET soListen = INVALID_SOCKET;
	soListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (soListen == INVALID_SOCKET)
	{
		return INVALID_SOCKET;
	}

	sockaddr_in stAddress;
	stAddress.sin_family = AF_INET;
	stAddress.sin_addr.S_un.S_addr = inet_addr(sIP);
	stAddress.sin_port = htons(nPort);

	// 绑定Socket
	int nResultB = bind(soListen, (SOCKADDR *)&stAddress, sizeof(stAddress));
	if (nResultB == SOCKET_ERROR)
	{
		int nError = WSAGetLastError();
		return INVALID_SOCKET;
	}

	return soListen;
}

// 开始socket
bool ServerSocket::StartSocket(SOCKET& socket)
{
	WSAEVENT temp = WSACreateEvent();
	BOOL_CHECK_NULL(temp);
	
	WSAEventSelect(socket, temp, 1);

}