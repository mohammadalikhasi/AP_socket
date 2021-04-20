#pragma once

#include <iostream>
#include <string>
#include <WinSock2.h>

using namespace std;

void Send_string(string msg, SOCKET sock);

class Field2
{
private:
    char aa = 'o';
    char ab = 'o';
    char ac = 'o';
    char ba = 'o';
    char bb = 'o';
    char bc = 'o';
    char ca = 'o';
    char cb = 'o';
    char cc = 'o';
    char cd = 'o';
    char da = 'o';
    char db = 'o';
    char dc = 'o';
    char ea = 'o';
    char eb = 'o';
    char ec = 'o';

    int score_A = 0;
    int score_B = 0;

    char a;
    char b;

    SOCKET socka;
    SOCKET sockb;

    string A_user;
    string B_user;

public:
    void Set_sock(SOCKET sock)
    {
        socka = sock;
    }
    void Set_A_user(string _A)
    {
        A_user = _A;
    }
    void Set_B_user(string _B)
    {
        B_user = _B;
    }

    string Get_A_user() { return A_user; }
    string Get_B_user() { return B_user; }

    void Set_aa(char new_char)
    {
        aa = new_char;
    }
    void Set_ab(char new_char)
    {
        ab = new_char;
    }
    void Set_ac(char new_char)
    {
        ac = new_char;
    }
    void Set_ba(char new_char)
    {
        ba = new_char;
    }
    void Set_bb(char new_char)
    {
        bb = new_char;
    }
    void Set_bc(char new_char)
    {
        bc = new_char;
    }
    void Set_ca(char new_char)
    {
        ca = new_char;
    }
    void Set_cb(char new_char)
    {
        cb = new_char;
    }
    void Set_cc(char new_char)
    {
        cc = new_char;
    }
    void Set_cd(char new_char)
    {
        cd = new_char;
    }
    void Set_da(char new_char)
    {
        da = new_char;
    }
    void Set_db(char new_char)
    {
        db = new_char;
    }
    void Set_dc(char new_char)
    {
        dc = new_char;
    }
    void Set_ea(char new_char)
    {
        ea = new_char;
    }
    void Set_eb(char new_char)
    {
        eb = new_char;
    }
    void Set_ec(char new_char)
    {
        ec = new_char;
    }

    void Win()
    {
        if (aa != 'O' && ab != 'O' && ac != 'O' && ba != 'O' && bb != 'O' &&
            bc != 'O' && ca != 'O' && cb != 'O' && cc != 'O' && cd != 'O' && 
            da != 'O' && db != 'O' && dc != 'O' && ea != 'O' && eb != 'O' && ec != 'O')
        {
            show();

            if (score_A > score_B)
            {
                cout << endl
                     << endl
                     << "player " << A_user << " wins";
                Send_string(send(), socka);
                exit(0);
            }
            if (score_A < score_B)
            {
                cout << endl
                     << endl
                     << "player " << B_user << " wins";
                Send_string(send(), socka);
                exit(0);
            }
            if (score_A == score_B)
            {
                cout << endl
                     << endl
                     << "nobody won";
                Send_string(send(), socka);
                exit(0);
            }
        }
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
    char Get_cd() { return cd; }
    char Get_da() { return da; }
    char Get_db() { return db; }
    char Get_dc() { return dc; }
    char Get_ea() { return ea; }
    char Get_eb() { return eb; }
    char Get_ec() { return ec; }

    void Set_score_A()
    {
        int score = 0;
        if (aa == ca && aa == ea && aa == a)
            score++;
        if (aa == ab && aa == ac && aa == a)
            score++;
        if (ac == cd && ac == ec && ac == a)
            score++;
        if (ba == bb && ba == bc && ba == a)
            score++;
        if (ba == cb && ba == da && ba == a)
            score++;
        if (bc == cc && bc == dc && bc == a)
            score++;
        if (da == db && da == dc && da == a)
            score++;
        if (ea == eb && ea == ec && ea == a)
            score++;

        score_A = score;
    }
    void Set_score_B()
    {
        int score = 0;
        if (aa == ca && aa == ea && aa == b)
            score++;
        if (aa == ab && aa == ac && aa == b)
            score++;
        if (ac == cd && ac == ec && ac == b)
            score++;
        if (ba == bb && ba == bc && ba == b)
            score++;
        if (ba == cb && ba == da && ba == b)
            score++;
        if (bc == cc && bc == dc && bc == b)
            score++;
        if (da == db && da == dc && da == b)
            score++;
        if (ea == eb && ea == ec && ea == b)
            score++;

        score_B = score;
    }

    int Get_score_A() { return score_A; }
    int Get_score_B() { return score_B; }

    void Set_a(char new_char) { a = new_char; }
    void Set_b(char new_char) { b = new_char; }

    void show()
    {
        system("cls");
        
        Set_score_A();
		Set_score_B();
		cout << A_user << ":" << score_A << "\t\t\t" 
             <<	B_user << ":" << score_B;

        cout << endl
             << endl
             << endl
             << endl;
        cout << aa << "_____" << ab << "_____" << ac << endl
             << "|     |     |" << endl
             << "|  " << ba << "__" << bb << "__" << bc << "  |"
             << endl
             << "|  |     |  |"
             << endl
             << ca << "__" << cb << "     " << cc << "__" << cd
             << endl
             << "|  |     |  |"
             << endl
             << "|  " << da << "__" << db << "__" << dc << "  |"
             << endl
             << "|     |     |" << endl
             << ea << "_____" << eb << "_____" << ec << endl;
    }
    string send()
    {
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
        a.push_back(cd);
        a.push_back(da);
        a.push_back(db);
        a.push_back(dc);
        a.push_back(ea);
        a.push_back(eb);
        a.push_back(ec);
        return a;
    }
    Field2(char A, char B)
    {
        Set_a(A), Set_b(B);
    }
    Field2(char *a)
    {
        aa = a[0];
        ab = a[1];
        ac = a[2];
        ba = a[3];
        bb = a[4];
        bc = a[5];
        ca = a[6];
        cb = a[7];
        cc = a[8];
        cd = a[9];
        da = a[10];
        db = a[11];
        dc = a[12];
        ea = a[13];
        eb = a[14];
        ec = a[15];
    }

    void Set_map(string a)
    {
        aa = a[0];
        ab = a[1];
        ac = a[2];
        ba = a[3];
        bb = a[4];
        bc = a[5];
        ca = a[6];
        cb = a[7];
        cc = a[8];
        cd = a[9];
        da = a[10];
        db = a[11];
        dc = a[12];
        ea = a[13];
        eb = a[14];
        ec = a[15];
    }

    void Fill()
    {
        Win();
        show();
        
        cout << endl
             << "please enter number of place";

        int d;
        cin >> d;

        string mg = send();

        if (d == 1 && aa == 'o')
            aa = a;
        if (d == 2 && ab == 'o')
            ab = a;
        if (d == 3 && ac == 'o')
            ac = a;
        if (d == 4 && ba == 'o')
            ba = a;
        if (d == 5 && bb == 'o')
            bb = a;
        if (d == 6 && bc == 'o')
            bc = a;
        if (d == 7 && ca == 'o')
            ca = a;
        if (d == 8 && cb == 'o')
            cb = a;
        if (d == 9 && cc == 'o')
            cc = a;
        if (d == 10 && cc == 'o')
            cd = a;
        if (d == 11 && aa == 'o')
            da = a;
        if (d == 12 && ab == 'o')
            db = a;
        if (d == 13 && ac == 'o')
            dc = a;
        if (d == 14 && ba == 'o')
            ea = a;
        if (d == 15 && bb == 'o')
            eb = a;
        if (d == 16 && bc == 'o')
            ec = a;

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
