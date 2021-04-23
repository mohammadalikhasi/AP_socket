#include<stdio.h>
#include<winsock2.h>
#include <sstream>
#include <iostream>
#include "Client.h"
#include "Field1.h"
#include "Field3.h"
#include "Field2.h"
#pragma comment(lib,"ws2_32.lib") //Winsock Library
#pragma warning(disable:4996) 
using namespace std;
void Get_info2(SOCKET sock, Client& A, char b, string user1, int Field);
void FILL2(Field2& f, SOCKET sock);
void FILL3(Field3& f, SOCKET sock);
void FILL1(Field1& f, SOCKET sock);
int string_to_int(string s);
void Send_string(string s, SOCKET sock);
void Send_char(char* a, int len, SOCKET sock);
char* convert_string_to_char(string s);
string convert_char_to_string(char* msg, int size);
void Get_info(SOCKET sock, Client& A);
string recive_char(SOCKET sock);
void Send_schar(char a, SOCKET sock);
int main() {

	WSADATA wsa;
	SOCKET s;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}
	struct sockaddr_in server;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);
	if (connect(s, (struct sockaddr*)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}
	while (1) {
		int number, num_Field;
		string msg, c;
		Client A(s);
		system("cls");
		number = string_to_int(recive_char(s));
		if (number == 1)
		{
			Get_info(s, A);
		}
		else
		{
			c = recive_char(s);
			msg = recive_char(s);
			num_Field = string_to_int(recive_char(s));
			Get_info2(s, A, c[0], msg, num_Field);
		}
		if (A.Get_num() == 1 && number == 1)
		{
			c = recive_char(s);
			msg = recive_char(s);
			Field1 f(A.Get_char(), c[0]);
			f.Set_A_user(A.Get_user());
			f.Set_B_user(msg);
			f.Set_sock(s);
			f.Fill();
			Send_string(f.send(), s);
			for (int i = 0; i < 4; i++)
			{
				FILL1(f, s);
			}
		}
		if (A.Get_num() == 1 && number == 2)
		{
			Field1 f(A.Get_char(), c[0]);
			f.Set_A_user(A.Get_user());
			f.Set_B_user(msg);
			f.Set_sock(s);
			for (int i = 0; i < 4; i++)
			{
				FILL1(f, s);
			}
			msg = recive_char(s);
			f.Set_map(msg);
			f.Win();
		}
		if (A.Get_num() == 2 && number == 1)
		{
			c = recive_char(s);
			msg = recive_char(s);
			Field2 f(A.Get_char(), c[0]);
			f.Set_A_user(A.Get_user());
			f.Set_B_user(msg);
			f.Set_sock(s);
			f.Fill();
			Send_string(f.send(), s);
			for (int i = 0; i < 8; i++)
			{
				FILL2(f, s);
				f.Win();
			}
		}
		if (A.Get_num() == 2 && number == 2)
		{
			Field2 f(A.Get_char(), c[0]);
			f.Set_A_user(A.Get_user());
			f.Set_B_user(msg);
			f.Set_sock(s);
			for (int i = 0; i < 8; i++)
			{
				FILL2(f, s);
			}
		}
		if (A.Get_num() == 3 && number == 1)
		{
			c = recive_char(s);
			msg = recive_char(s);
			Field3 f(A.Get_char(), c[0]);
			f.Set_user_A(A.Get_user());
			f.Set_user_B(msg);
			f.Set_sock(s);
			f.Fill();
			Send_string(f.send(), s);
			for (int i = 0; i < 10; i++)
			{
				FILL3(f, s);
			}
		}
		if (A.Get_num() == 3 && number == 2)
		{
			Field3 f(A.Get_char(), c[0]);
			f.Set_user_A(A.Get_user());
			f.Set_user_B(msg);
			f.Set_sock(s);
			for (int i = 0; i < 10; i++)
			{
				FILL3(f, s);
			}
			string smg;
			smg = recive_char(s);
			f.set_map(smg);
			f.Fill();
		}
	}
}
void Send_string(string s, SOCKET sock) {
	char a[200];
	for (int i = 0; i < s.size(); i++)
	{
		a[i] = s[i];
	}
	send(sock, a, s.size(), 0);
}
void Send_char(char* a, int len, SOCKET sock) {
	send(sock, a, len - 1, 0);
}
char* convert_string_to_char(string s) {
	char a[200];
	for (int i = 0; i < s.size(); i++)
	{
		a[i] = s[i];
	}
	return a;
}
string convert_char_to_string(char* msg, int size) {
	int i;
	string msg1;
	for (i = 0; i < size; i++)
	{
		msg1.push_back(msg[i]);
	}
	return msg1;
}
void Get_info2(SOCKET sock, Client& A, char b, string user1, int Field)
{
	string user;
	cout << "please enter your username" << endl;
	cin >> user;
	while (user == user1)
	{
		cout << "the username is already used.please enter again.";
		cin >> user;
	}
	Send_string(user, sock);
	cout << "please choose your char(except O and " << b << ")" << endl;
	char a;
	cin >> a;
	while (a == 'O' || a == b)
	{
		cout << "enter again";
		cin >> a;
	}
	Send_schar(a, sock);
	A.Set_num(Field);
	A.Set_char(a);
	A.Set_user(user);
}
void Get_info(SOCKET sock, Client& A) {
	string user;
	cout << "please enter your username" << endl;
	cin >> user;
	Send_string(user, sock);
	cout << "please choose your char(except O)" << endl;
	char a;
	cin >> a;
	while (a == 'O')
	{
		cout << "enter again";
		cin >> a;
	}
	Send_schar(a, sock);
	int f;
	cout << "please enter your field" << endl;
	cin >> f;
	string fi;
	fi = to_string(f);
	Send_string(fi, sock);
	A.Set_char(a);
	A.Set_num(f);
	A.Set_user(user);
}string recive_char(SOCKET sock) {
	char a[200];
	int recv_size;
	recv_size = recv(sock, a, sizeof(a), 0);
	a[recv_size] = '\0';
	string s;
	s = convert_char_to_string(a, strlen(a));
	return s;
}
void Send_schar(char a, SOCKET sock) {
	char b[1];
	b[0] = a;
	send(sock, b, 1, 0);
}
int string_to_int(string s) {
	stringstream ss;
	int a;
	ss << s;
	ss >> a;
	return a;
}
void FILL1(Field1& f, SOCKET sock) {
	string msg;
	msg = recive_char(sock);
	f.Set_map(msg);
	f.Fill();
	Send_string(f.send(), sock);
}
void FILL3(Field3& f, SOCKET sock) {
	string msg;
	msg = recive_char(sock);
	f.set_map(msg);
	f.Fill();
	Send_string(f.send(), sock);
}
void FILL2(Field2& f, SOCKET sock) {
	string msg;
	msg = recive_char(sock);
	f.Set_map(msg);
	f.Fill();
	Send_string(f.send(), sock);
}