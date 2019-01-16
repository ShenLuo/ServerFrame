/*
	·þÎñÆ÷socketÂß¼­
*/

#ifndef _SERVER_SOCKET_DEFINE_H_
#define _SERVER_SOCKET_DEFINE_H_

#define BOOL_CHECK_NULL(arg) if (nullptr == arg)\
						{ \
							return false;\
						}\
						return true\
						

struct SocketConfig
{
	std::string sIp;
	int nPort;
};

#endif // _SERVER_SOCKET_DEFINE_H_

