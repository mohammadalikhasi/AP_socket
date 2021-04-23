#pragma once
#pragma once
#include <string>
#include <iostream>
using namespace std;
class Field3 {
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
	char da = 'O';
	char db = 'O';
	char dc = 'O';
	char dd = 'O';
	char de = 'O';
	char df = 'O';
	char ea = 'O';
	char eb = 'O';
	char fa = 'O';
	char fb = 'O';
	char ga = 'O';
	char gb = 'O';
	char A;
	char B;
	int score_A = 0;
	int score_B = 0;
	string user_A;
	string user_B;
	SOCKET socka;
public:
	void Set_aa(char a) {
		aa = a;
	}
	void Set_ab(char a) {
		ab = a;
	}
	int Win() {
		if (aa != 'O' && ab != 'O' && ac != 'O' && ba != 'O' && bb != 'O' &&
			bc != 'O' && ca != 'O' && cb != 'O' && cc != 'O'
			&& da != 'O' && db != 'O' && dc != 'O' && dd != 'O' && de != 'O' && df != 'O'\
			&& ea != 'O' && eb != 'O' && fa != 'O' && fb != 'O' && ga != 'O' && gb != 'O') {
			show();
			if (score_A > score_B)
			{
				cout << endl << endl << "player " << user_A << " wins";
				Send_string(send(), socka);
				exit(0);
			}
			if (score_A < score_B)
			{
				cout << endl << endl << "player " << user_B << " wins";
				Send_string(send(), socka);
				exit(0);
			}
			if (score_A == score_B)
			{
				cout << endl << endl << "nobody won";
				Send_string(send(), socka);
				exit(0);
			}
			return 0;
		}
		return 1;
	}

	void Set_ac(char a) {
		ac = a;
	}void Set_ba(char a) {
		ba = a;
	}void Set_bb(char a) {
		bb = a;
	}void Set_bc(char a) {
		bc = a;
	}void Set_ca(char a) {
		ca = a;
	}void Set_cb(char a) {
		cb = a;
	}void Set_cc(char a) {
		cc = a;
	}void Set_da(char a) {
		da = a;
	}void Set_db(char a) {
		db = a;
	}void Set_dc(char a) {
		dc = a;
	}void Set_dd(char a) {
		dd = a;
	}void Set_de(char a) {
		de = a;
	}void Set_df(char a) {
		df = a;
	}void Set_ea(char a) {
		ea = a;
	}void Set_eb(char a) {
		eb = a;
	}
	void Set_fa(char a) {
		fa = a;
	}void Set_fb(char a) {
		fb = a;
	}
	void Set_ga(char a) {
		ga = a;
	}void Set_gb(char a) {
		gb = a;
	}
	void Set_A(char a) {
		A = a;
	}
	void Set_B(char a) {
		B = a;
	}
	void Set_user_A(string a) {
		user_A = a;
	}
	void Set_user_B(string a) {
		user_B = a;
	}
	void Set_score_A(int a) {
		score_A = a;
	}
	void Set_score_B(int a) {
		score_B = a;
	}
	int Get_score_A() {
		return score_A;
	}
	int Get_score_B() {
		return score_B;
	}
	char Get_aa() {
		return aa;
	}
	char Get_ab() {
		return ab;
	}
	char Get_ac() {
		return ac;
	}
	char Get_ba() {
		return ba;
	}
	char Get_bb() {
		return bb;
	}
	char Get_bc() {
		return bc;
	}
	char Get_ca() {
		return ca;
	}
	char Get_cb() {
		return cb;
	}
	char Get_cc() {
		return cc;
	}
	char Get_da() {
		return da;
	}
	char Get_db() {
		return db;
	}
	char Get_dc() {
		return dc;
	}
	char Get_dd() {
		return dd;
	}
	char Get_de() {
		return de;
	}
	char Get_df() {
		return df;
	}
	char Get_ea() {
		return ea;
	}
	char Get_eb() {
		return eb;
	}
	char Get_fa() {
		return fa;
	}
	char Get_fb() {
		return fb;
	}
	char Get_ga() {
		return ga;
	}
	char Get_gb() {
		return gb;
	}
	string Get_user_A() {
		return user_A;
	}
	string Get_user_B() {
		return user_B;
	}
	Field3(char a, char b) {
		A = a;
		B = b;
	}
	void Set_score_B() {
		int score = 0;
		if (aa == ac && ac == ab && ab == B)
			score++;
		if (ba == bb && B == bc && bc == bb)
			score++;
		if (ca == cb && B == cb && cb == cc)
			score++;
		if (da == db && db == dc && dc == B)
			score++;
		if (dd == de && de == df && df == B)
			score++;
		if (ab == bb && bb == cb && cb == B)
			score++;
		if (ca == dc && dc == ea && ea == B)
			score++;
		if (cc == dd && dd == eb && eb == B)
			score++;
		if (ea == fa && fa == ga && ga == B)
			score++;
		if (eb == fb && fb == gb && gb == B)
			score++;
		score_B = score;
	}
	void Set_score_A() {
		int score = 0;
		if (aa == ac && ac == ab && ab == A)
			score++;
		if (ba == bb && A == bc && bc == bb)
			score++;
		if (ca == cb && A == cb && cb == cc)
			score++;
		if (da == db && db == dc && dc == A)
			score++;
		if (dd == de && de == df && df == A)
			score++;
		if (ab == bb && bb == cb && cb == A)
			score++;
		if (ca == dc && dc == ea && ea == A)
			score++;
		if (cc == dd && dd == eb && eb == A)
			score++;
		if (ea == fa && fa == ga && ga == A)
			score++;
		if (eb == fb && fb == gb && gb == A)
			score++;
		score_A = score;
	}
	void show() {
		system("cls");
		Set_score_A();
		Set_score_B();
		cout << endl << user_A << ":" << score_A << "\t\t\t\t"
			<< user_B << ":" << score_B << endl << endl << endl;
		cout << aa << "-----" << ab << "-----" << ac << "\t\t\t\t" << "1" << "-----" << "2" << "-----" << "3" << endl;
		cout << "|     " << "|" << "   " << "  |" << "\t\t\t\t|     " << "|" << "   " << "  |" << endl;
		cout << "|-" << ba << "---" << bb << "---" << bc << "-" << "|" << "\t\t\t\t" << "|-" << "4" << "---" << "5" << "---" << "6" << "-" << "|" << endl;
		cout << "| |   " << "|" << "   | |" << "\t\t\t\t" << "| |   " << "|" << "   | |" << endl;
		cout << "| | " << ca << "-" << cb << "-" << cc << " | |" << "\t\t\t\t" << "| | " << "7" << "-" << "8" << "-" << "9" << " | |" << endl;
		cout << "| | |   | | |" << "\t\t\t\t" << "| | |   | | |" << endl;
		cout << da << "-" << db << "-" << dc << "   " << dd << "-" << de << "-" << df << "\t\t\t   " << "   10" << "-" << "11" << "-" << "12" << " " << "13" << "-" << "14" << "-" << "15" << endl;
		cout << "| | |   | | |" << "\t\t\t\t" << "| | |   | | |" << endl;
		cout << "| | " << ea << "---" << eb << " | |" << "\t\t\t\t| | " << "16" << "-" << "17" << " | |" << endl;
		cout << "| |/     \\| |" << "\t\t\t\t| |/     \\| |" << endl;
		cout << "| " << fa << "-------" << fb << " |" << "\t\t\t\t" << "| " << "18" << "-----" << "19" << " |" << endl;
		cout << "|/         \\|" << "\t\t\t\t" << "|/         \\|" << endl;
		cout << ga << "-----------" << gb << "\t\t\t\t" << "20" << "---------" << "21" << endl;
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
		a.push_back(da);
		a.push_back(db);
		a.push_back(dc);
		a.push_back(dd);
		a.push_back(de);
		a.push_back(df);
		a.push_back(ea);
		a.push_back(eb);
		a.push_back(fa);
		a.push_back(fb);
		a.push_back(ga);
		a.push_back(gb);
		return a;
	}
	void set_map(string a) {
		aa = a[0];
		ab = a[1];
		ac = a[2];
		ba = a[3];
		bb = a[4];
		bc = a[5];
		ca = a[6];
		cb = a[7];
		cc = a[8];
		da = a[9];
		db = a[10];
		dc = a[11];
		dd = a[12];
		de = a[13];
		df = a[14];
		ea = a[15];
		eb = a[16];
		fa = a[17];
		fb = a[18];
		ga = a[19];
		gb = a[20];
	}
	void Fill() {
		Win();
		show();
		cout << endl << "please enter number of place";
		int d;
		cin >> d;
		if (d == 1 && aa == 'O')
			aa = A;
		if (d == 2 && ab == 'O')
			ab = A;
		if (d == 3 && ac == 'O')
			ac = A;
		if (d == 4 && ba == 'O')
			ba = A;
		if (d == 5 && bb == 'O')
			bb = A;
		if (d == 6 && bc == 'O')
			bc = A;
		if (d == 7 && ca == 'O')
			ca = A;
		if (d == 8 && cb == 'O')
			cb = A;
		if (d == 9 && cc == 'O')
			cc = A;
		if (d == 10 && da == 'O')
			da = A;
		if (d == 11 && db == 'O')
			db = A;
		if (d == 12 && dc == 'O')
			dc = A;
		if (d == 13 && dd == 'O')
			dd = A;
		if (d == 14 && de == 'O')
			de = A;
		if (d == 15 && df == 'O')
			df = A;
		if (d == 16 && ea == 'O')
			ea = A;
		if (d == 17 && eb == 'O')
			eb = A;
		if (d == 18 && fa == 'O')
			fa = A;
		if (d == 19 && fb == 'O')
			fb = A;
		if (d == 20 && ga == 'O')
			ga = A;
		if (d == 21 && gb == 'O')
			gb = A;
		show();
		Win();
	}
	void Set_sock(SOCKET _sock) {
		socka = _sock;
	}
};
