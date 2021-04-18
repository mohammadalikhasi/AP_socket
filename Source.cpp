#include<stdio.h>
#include<winsock2.h>
#include <sstream>
#include <iostream>
#include "Client.h"
#include "Field1.h"
#include "Field3.h"
#pragma comment(lib,"ws2_32.lib") //Winsock Library
using namespace std;
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
	new_socket = accept(s, (struct sockaddr*)&client, &c);
	new_socket2 = accept(s, (struct sockaddr*)&client, &c);
	Send_string(to_string(1), new_socket);
	Send_string(to_string(2), new_socket2);
	Client A(new_socket);
	Get_info(new_socket, A);
	Client B(new_socket2);
	Get_info(new_socket2, B);
	Send_schar(B.Get_char(), new_socket);
	Send_schar(A.Get_char(), new_socket2);
	Send_string(B.Get_user(), new_socket);
	Send_string(A.Get_user(), new_socket2);
	if (A.Get_num()==B.Get_num()==1)
	{
		Field1 f(A.Get_char(), B.Get_char());
		for (int i = 0; i < 5; i++)
		{
			Client_to_Client(new_socket, new_socket2);
			Client_to_Client(new_socket2, new_socket);
		}
		closesocket(new_socket);
		closesocket(new_socket2);
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
	char user[40];
	int user_len;
	string usser;
	user_len = recv(sock, user, 40, 0);
	user[user_len] = '\0';
	usser = convert_char_to_string(user, strlen(user));
	char a[2];
	recv(sock, a, 1, 0);
	int Fieald;
	string f;
	f=recive_char(sock);
	Fieald = string_to_int(f);
	cout << usser << a[0] << Fieald;
	A.Set_num(Fieald);
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