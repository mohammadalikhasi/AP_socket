#include<stdio.h>
#include<winsock2.h>
#include <sstream>
#include <iostream>
#include "Client.h"
#include "Field1.h"
#include "Field3.h"
#pragma comment(lib,"ws2_32.lib") //Winsock Library
using namespace std;
void Get_info2(SOCKET sock, Client& A);
int string_to_int(string s);
void Client_to_Client(SOCKET sock1, SOCKET sock2);
void Send_string(string s, SOCKET sock);
void Send_char(char* a, int len, SOCKET sock);
char* convert_string_to_char(string s);
string convert_char_to_string(char* msg, int size);
void Get_info(SOCKET sock, Client& A);
string recive_char(SOCKET sock);
void Send_schar(char a, SOCKET sock);
int main(int argc, char* argv[])
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}
	SOCKET s;
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	//Bind
	if (bind(s, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
	}
	listen(s, 3);
	struct sockaddr_in client;
	int c = sizeof(struct sockaddr_in);
	SOCKET new_socket, new_socket2;
	int Flag1 = 1, Flag2 = 1;
	while (1)
	{
		if (Flag1) {
			new_socket = accept(s, (struct sockaddr*)&client, &c);
		}
		Client A(new_socket);
		if (Flag2)
		new_socket2 = accept(s, (struct sockaddr*)&client, &c);
		Send_string(to_string(1), new_socket);
		Send_string(to_string(2), new_socket2);
		Get_info(new_socket, A);
		Client B(new_socket2);
		cout << A.Get_char() << A.Get_user() << A.Get_num();
		Send_schar(A.Get_char(), new_socket2);
		Send_string(A.Get_user(), new_socket2);
		Send_string(to_string(A.Get_num()), new_socket2);
		Get_info2(new_socket2, B);
		cout << B.Get_char();
		Send_schar(B.Get_char(), new_socket);
		Send_string(B.Get_user(), new_socket);
		if (A.Get_num()==1)
		{
			for (int i = 0; i < 4; i++)
			{
				Client_to_Client(new_socket, new_socket2);
				Client_to_Client(new_socket2, new_socket);
			}
			Client_to_Client(new_socket, new_socket2);
			string smg;
			smg = recive_char(new_socket2);
		}
		if (A.Get_num() == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				Client_to_Client(new_socket, new_socket2);
				Client_to_Client(new_socket2, new_socket);
			}
			string smg = recive_char(new_socket);
			
		}
		if (A.Get_num() == 3)
		{
			for (int i = 0; i < 10; i++)
			{
				Client_to_Client(new_socket, new_socket2);
				Client_to_Client(new_socket2, new_socket);
			}
			Client_to_Client(new_socket, new_socket2);
			string msg = recive_char(new_socket2);
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
void Get_info(SOCKET sock, Client& A) {
	string user;
	user=recive_char(sock);
	A.Set_user(user);
	string c;
	c = recive_char(sock);
	A.Set_char(c[0]);
	int a = string_to_int(recive_char(sock));
	A.Set_num(a);
	cout << user << c[0] << a;
}
void Get_info2(SOCKET sock, Client& A) {
	string usser;
	usser = recive_char(sock);
	string a;
	a = recive_char(sock);
	A.Set_user(usser);
	A.Set_char(a[0]);
}

string recive_char(SOCKET sock) {
	char a[200];
	int recv_size;
	recv_size = recv(sock, a, sizeof(a), 0);
	a[recv_size] = '\0';
	string msg;
	msg = convert_char_to_string(a, strlen(a));
	return msg;
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
	ss >>a;
	return a;
}
void Client_to_Client(SOCKET sock1, SOCKET sock2) {
	string msg;
	msg=recive_char(sock1);
	Send_string(msg, sock2);
}