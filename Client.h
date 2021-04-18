
#include <iostream>
#include <WinSock2.h>
using namespace std;
class Client {
private:
	string username;
	char special_char;
	SOCKET sock;
	int Field_num;
public:
	void Set_user(string _user) {
		username = _user;
	}
	void Set_char(char _spc) {
		special_char = _spc;
	}
	void Set_sock(SOCKET _sock) {
		sock = _sock;
	}
	string Get_user() {
		return username;
	}
	char Get_char() {
		return special_char;
	}
	SOCKET Get_sock() {
		return sock;
	}
	int Get_num() { return Field_num; }
	void Set_num(int _num) { Field_num = _num; }
	Client(SOCKET _sock) {
		Set_sock(_sock);
	}
};
