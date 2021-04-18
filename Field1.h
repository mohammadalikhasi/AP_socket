#pragma once
#pragma once
#pragma once
#include <iostream>
#include <string>
#include <WinSock2.h>
using namespace std;
void Send_string(string msg, SOCKET sock);
class Field1 {
private:
	char aa = 'O';
	char ab = 'O';
	char ac = 'O';
	char ba = 'O';
	char bb = 'O';
	char bc = 'O';
	char ca = 'O';
	char cb = 'O';
	char cc = 'O';
	int score_A = 0;
	int score_B = 0;
	char a;
	char b;
	SOCKET socka;
	SOCKET sockb;
	string A_user;
	string B_user;
public:
	void Set_sock(SOCKET sock) {
		socka = sock;
	}
	void Set_A_user(string _A) {
		A_user = _A;
	}
	void Set_B_user(string _B) {
		B_user = _B;
	}
	string Get_A_user() { return A_user; }
	string Get_B_user() { return B_user; }
	void Set_aa(char new_char) {
		aa = new_char;
	}
	void Win() {
		if (aa != 'O' && ab != 'O' && ac != 'O' && ba != 'O' && bb != 'O' &&
			bc != 'O' && ca != 'O' && cb != 'O' && cc != 'O') {
			show();
			if (score_A > score_B)
			{
				cout << endl << endl << "player " << A_user << " wins";
				Send_string(send(), socka);
				exit(0);
			}
			if (score_A < score_B)
			{
				cout << endl << endl << "player " << B_user << " wins";
				Send_string(send(), socka);
				exit(0);
			}
			if (score_A == score_B)
			{
				cout << endl << endl << "nobody won";
				Send_string(send(), socka);
				exit(0);
			}

		}
	}

	void Set_ab(char new_char) {
		ab = new_char;
	}void Set_ac(char new_char) {
		ac = new_char;
	}void Set_ba(char new_char) {
		ba = new_char;
	}void Set_bb(char new_char) {
		bb = new_char;
	}void Set_bc(char new_char) {
		bc = new_char;
	}
	void Set_ca(char new_char) {
		ca = new_char;
	}void Set_cb(char new_char) {
		cb = new_char;
	}void Set_cc(char new_char) {
		cc = new_char;
	}
	char Get_aa() { return aa; }
	char Get_ab() { return ab; }
	char Get_ac() { return ac; }
	char Get_ba() { return ba; }
	char Get_bb() { return bb; }
	char Get_bc() { return bc; }
	char Get_ca() { return ca; }
	char Get_cb() { return cb; }
	char Get_cc() { return cc; }
	void Set_score_A() {
		int score = 0;
		if (aa == bb && aa == cc && aa == a)
			score++;
		if (aa == ab && ab == ac && aa == a)
			score++;
		if (ba == bb && bb == bc && ba == a)
			score++;
		if (ca == cb && cb == cc && ca == a)
			score++;
		if (aa == ba && ba == ca && aa == a)
			score++;
		if (ab == bb && bb == cb && ab == a)
			score++;
		if (ac == bc && bc == cc && ac == a)
			score++;
		if (ac == bb && bb == ca && bb == a)
			score++;
		score_A = score;
	}
	void Set_score_B() {
		int score = 0;
		if (aa == bb && aa == cc && aa == b)
			score++;
		if (aa == ab && ab == ac && aa == b)
			score++;
		if (ba == bb && bb == bc && ba == b)
			score++;
		if (ca == cb && cb == cc && ca == b)
			score++;
		if (aa == ba && ba == ca && aa == b)
			score++;
		if (ab == bb && bb == cb && ab == b)
			score++;
		if (ac == bc && bc == cc && ac == b)
			score++;
		if (ac == bb && bb == ca && bb == b)
			score++;
		score_B = score;
	}
	int Get_score_A() { return score_A; }
	int Get_score_B() { return score_B; }
	void Set_a(char new_char) { a = new_char; }
	void Set_b(char new_char) { b = new_char; }
	void show() {
		system("cls");
		Set_score_A();
		Set_score_B();
		cout << A_user << ":" << score_A << "\t\t\t" <<
			B_user << ":" << score_B;
		cout << endl << endl << endl << endl;
		cout << aa << "__" << ab << "__" << ac << endl << "|  |  |"
			<< endl << ba << "__" << bb << "__" << bc << endl << "|  |  |" <<
			endl << ca << "__" << cb << "__" << cc << endl;
	}
	string send() {
		string a;
		a.push_back(aa);
		a.push_back(ab);
		a.push_back(ac);
		a.push_back(ba);
		a.push_back(bb);
		a.push_back(bc);
		a.push_back(ca);
		a.push_back(cb);
		a.push_back(cc);
		return a;
	}
	Field1(char A, char B) {
		Set_a(A), Set_b(B);
	}
	Field1(char* a) {
		aa = a[0];
		ab = a[1];
		ac = a[2];
		ba = a[3];
		bb = a[4];
		bc = a[5];
		ca = a[6];
		cb = a[7];
		cc = a[8];
	}
	void Set_map(string a) {
		aa = a[0];
		ab = a[1];
		ac = a[2];
		ba = a[3];
		bb = a[4];
		bc = a[5];
		ca = a[6];
		cb = a[7];
		cc = a[8];
	}
	void Fill() {
		Win();
		show();
		cout << endl << "please enter number of place";
		int d, st = 1;
		cin >> d;
		string mg = send();

		if (d == 1 && aa == 'O')
			aa = a;
		if (d == 2 && ab == 'O')
			ab = a;
		if (d == 3 && ac == 'O')
			ac = a;
		if (d == 4 && ba == 'O')
			ba = a;
		if (d == 5 && bb == 'O')
			bb = a;
		if (d == 6 && bc == 'O')
			bc = a;
		if (d == 7 && ca == 'O')
			ca = a;
		if (d == 8 && cb == 'O')
			cb = a;
		if (d == 9 && cc == 'O')
			cc = a;
		if (send() == mg)
		{
			cout << "the place " << d << " is full";
			getchar();
			Fill();
		}
		show();
		Win();
	}
};