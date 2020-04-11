#include"stdio.h"
#include"winsock.h"
#include"string.h"
#include"iostream"
using namespace std;
#pragma comment(lib,"wsock32.lib")
int main(int argc, TCHAR* argv[])
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "WSAStartup  �޷���ʼ����" << endl;
		return 0;
	}
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	while(true)
	{
		char dest_ip[100];
		cout <<"please input dest ip: ";
		cin >> dest_ip;
		cout << endl;
		addr.sin_addr.S_un.S_addr = inet_addr(dest_ip);
		int s_port,e_port;
		cout << "please input start port: ";
		cin >> s_port;
		cout << endl;
		cout << "please input end port: ";
		cin >> e_port;
		cout << endl;
		for (int i = s_port; i <= e_port; i++)
		{
			SOCKET s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if(s == INVALID_SOCKET)
			{
				printf("Failed\n");
			}
			addr.sin_port = htons(i);
			int ret = connect(s, (LPSOCKADDR)&addr,sizeof(addr));
			if(ret == 0)
			{
				printf("%s:%d port is open\n",dest_ip,i);
			}
			else
			{
				printf("%s:%d port is close\n",dest_ip,i);
			}
			::closesocket(s);
		}
		cout << endl;
	}
}