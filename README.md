    远程IP：百度ip：220.181.38.150:443
    端口范围：433-444
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
    输入远程IP地址以及要扫描的端口号范围
    SOCKET s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //创建套接字
    int ret = connect(s, (LPSOCKADDR)&addr,sizeof(addr));
    //connect函数  使用系统提供的conect()函数来连接目标端口，如果端口开启则返回0 否则返回-1
    尝试连接端口，并返回端口开启状态。
