#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <ctime>
#include <iomanip>
using namespace std;

class Wallet
{
    public:

        float amt;

        Wallet();
        bool transact(string no, int n);
        void transfer(string no);
        void recharge(string no);
        void cashout(string no);
        void viewWallet(string no);
        void payment(string no);
        void salami(string no);
        void message(string no);
        void transactHistory(string no);

};

Wallet::Wallet()
{
    amt=0.0;
}



bool Wallet :: transact(string no, int n)
{
    stringstream ss;
    stringstream ss1;
    fstream f;

    string line;

    ss << no << ".txt";

    f.open(ss.str());

    int len = 2;
    while(getline(f,line))
    {
        if(line.find("BALANCE : RS. ") != string::npos)
        {
            string bal;
            float balance;

            bal = line.substr(14,line.length());

            balance = stof(bal);

            if(amt < 0)
            {
                cout << endl << "INVALID ENTRY !!!" << endl;
                return false;
            }

            if(n == 1)
            {
                balance += amt;

                ss1 << "T " << no << ".txt";

                ofstream f1;

                f1.open(ss1.str(),ios::app);

                time_t now = time(0);
                char* dateTime = ctime(&now);

                f1 << "RS.   " << setw(10) << amt << " - " << dateTime << endl;

                f1.close();
            }
            else if(n == 0)
            {
                if(amt <= balance)
                {
                    balance -= amt;

                    ss1 << "T " << no << ".txt";

                    ofstream f1;

                    f1.open(ss1.str(),ios::app);

                    time_t now = time(0);
                    char* dateTime = ctime(&now);

                    f1 << "RS. - " << setw(10) << amt << " - " << dateTime << endl;

                    f1.close();
                }
                else
                {
                    return false;
                }
            }

            f.seekg(len);

            int len1 = line.length();
            int i = 1;
            while(i != len1)
            {
                f << "!";
                i++;
            }

            f << endl;
            f << "BALANCE : RS. " << balance << endl << endl;

            return true;
        }

        len += (line.length() + 1);
    }

    f.close();

    return false;
}

void Wallet :: transfer(string no)
{
    string no1;
    ifstream f;
    string line;

    bool chk;
    int i = 0;

    fflush(stdin);
    cout << "ENTER ACCOUNT NUMBER TO TRANSFER : ";
    getline(cin,no1);

    f.open("USER.txt",ios::in);

    if(!f)
    {
        cout << endl << "ACCOUNT NOT FOUND" << endl;
    }
    else
    {
        while(getline(f,line))
        {
            if(line == no1)
            {
                f.close();


                cout << "ENTER AMOUNT TO TRANSFER         : RS. ";
                cin >> amt;

                chk = transact(no,0);
                if(chk)
                {
                    transact(no1,1);
                    cout << endl << "TRANSFER SUCCESSFUL" << endl;
                }
                else
                {
                    cout << endl << "NO ENOUGH BALANCE TO TRANSFER !!!" << endl;
                    cout << "TRANSFER FAILED" << endl;
                }

                i = 1;

                break;
            }
        }
    }

    if(i == 0)
        cout << endl << "TRANSFER FAILED" << endl;
}

void Wallet :: recharge(string no)
{
    string no1;
    ifstream f;
    string line;

    bool chk;
    int i = 0;
     cout<<"select operator"<<endl;
            cout<<"1.GrameenPhone"<<endl;
            cout<<"2.Banglalink"<<endl;
            cout<<"3.Airtel"<<endl;
            cout<<"4.Robi"<<endl;
            cout<<"5.Teletalk"<<endl;
            int n; cin>>n;
            if(n>=1&&n<=5) system("cls");
            else {
                cout<<"invalid choice"<<endl;
                return;
            }
    fflush(stdin);
                cout << "ENTER THE NUMBER                 :";
                string phnnum;
                fflush(stdin);
                cin>>phnnum;
                if(phnnum.length()!=11){
                    cout<<"INVALID NUMBER"<<endl;
                    return;
                }
                cout<<endl;
                cout << "ENTER AMOUNT TO RECHARGE         : RS. ";
                cin >> amt;

                chk = transact(no,0);
                if(chk)
                {
                    //transact(no1,1);
                    cout << endl << "RECHARGE SUCCESSFUL" << endl;
                }
                else
                {
                    cout << endl << "NO ENOUGH BALANCE TO RECHARGE !!!" << endl;
                    cout << "RECHARGE FAILED" << endl;
                }

                i = 1;






    if(i == 0)
        cout << endl << "RECHARGE FAILED" << endl;
}

void Wallet :: cashout(string no)
{
    string no1;
    ifstream f;
    string line;

    bool chk;
    int i = 0;

    fflush(stdin);
    cout << "ENTER AGENT NUMBER TO CASHOUT : ";
    getline(cin,no1);

    f.open("AGENT.txt",ios::in);

    if(!f)
    {
        cout << endl << "AGENT NOT FOUND" << endl;
    }
    else
    {
        while(getline(f,line))
        {
            if(line == no1)
            {
                f.close();


                cout << "ENTER AMOUNT TO CASH OUT         : RS. ";
                cin >> amt;

                chk = transact(no,0);
                if(chk)
                {
                   // transact(no1,1);
                    cout << endl << "CASH OUT SUCCESSFUL" << endl;
                }
                else
                {
                    cout << endl << "NO ENOUGH BALANCE FOR CASH OUT !!!" << endl;
                    cout << "CASH OUT FAILED" << endl;
                }

                i = 1;

                break;
            }
        }
    }

    if(i == 0)
        cout << endl << "CASH OUT FAILED" << endl;
}

void Wallet :: payment(string no)
{
    string no1;
    ifstream f;
    string line;

    bool chk;
    int i = 0;

    fflush(stdin);
    cout << "ENTER MERCHANT NUMBER TO TRANSFER : ";
    getline(cin,no1);

    f.open("MERCHANT.txt",ios::in);

    if(!f)
    {
        cout << endl << "INVALID MERCHANT ACCOUNT" << endl;
    }
    else
    {
        while(getline(f,line))
        {
            if(line == no1)
            {
                f.close();


                cout << "ENTER AMOUNT FOR PAYMENT         : RS. ";
                cin >> amt;

                chk = transact(no,0);
                if(chk)
                {
                   // transact(no1,1);
                    cout << endl << "PAYMENT SUCCESSFUL" << endl;
                }
                else
                {
                    cout << endl << "NO ENOUGH BALANCE FOR PAYMENT !!!" << endl;
                    cout << "PAYMENT FAILED" << endl;
                }

                i = 1;

                break;
            }
        }
    }

    if(i == 0)
        cout << endl << "PAYMENT FAILED" << endl;
}
void Wallet :: salami(string no)
{
    string no1;
    ifstream f;
    string line;
    ofstream f2;

    bool chk;
    int i = 0;

    fflush(stdin);
    cout << "ENTER ACCOUNT NUMBER TO TRANSFER : ";
    getline(cin,no1);

    f.open("USER.txt",ios::in);
   f2.open("MESSAGE "+no1+".txt",ios::app);
    if(!f2){
    f2.close();
        f2.open("MESSAGE "+no1+".txt",ios::out);}
//    cout<<"press ENTER & choose 1 to send"<<endl;
//    int n; cin>>n;
   string s;
//    while(getline(cin,s)&&n!=1){
//        f2<<s;
//    }
//    f2.close();

    if(!f)
    {
        cout << endl << "ACCOUNT NOT FOUND" << endl;
    }
    else
    {
        while(getline(f,line))
        {
            if(line == no1)
            {
                f.close();


                cout << "ENTER AMOUNT TO TRANSFER         : RS. ";
                cin >> amt;
                f2<<endl;
                fflush(stdin);
                cout<<  "WRITE YOUR MESSAGE               :";
                f2<<"MESSAGE:"<<endl;
               // cout<<""<<endl;
   // int n; cin>>n;
   // string s;
    getline(cin,s);
        f2<<s<<endl<<endl;
        time_t now = time(0);
        char* dateTime = ctime(&now);
        f2<<dateTime<<endl<<endl;

    f2.close();

                chk = transact(no,0);
                if(chk)
                {
                    transact(no1,1);
                     cout << endl << "MESSAGE SENT!!" << endl;
                    cout << endl << "TRANSFER SUCCESSFUL" << endl;
                }
                else
                {
                    cout << endl << "NO ENOUGH BALANCE TO TRANSFER !!!" << endl;
                    cout << "TRANSFER & MESSAGE SENT FAILED" << endl;
                }

                i = 1;

                break;
            }
        }
    }

    if(i == 0)
        cout << endl << "TRANSFER & MESSAGE SENT FAILED" << endl;
}


void Wallet :: viewWallet(string no)
{
    stringstream ss;
    ifstream f;

    string line;

    ss << no << ".txt";

    f.open(ss.str());

    while(getline(f,line))
    {
        if(line.find("BALANCE : RS. ") != string::npos)
        {
            cout << "AVAILABLE " << line << endl;

            break;
        }
    }

    f.close();
}

void Wallet :: message(string no)
{
    stringstream ss;
    ifstream f;

    string line;

    ss <<"MESSAGE "<< no << ".txt";

    f.open(ss.str());
   // cout<<endl;
    while(f.good())
    {
       string s;
       getline(f,s);
       cout<<s<<endl;
    }
    cout<<endl;

    f.close();
}

void Wallet :: transactHistory(string no)
{
    stringstream ss;
    ifstream f;

    string line;

    ss << "T " << no << ".txt";

    f.open(ss.str());

    while(getline(f,line))
    {
        cout << line << endl;
    }

    f.close();

}


//******************************************************************
//******************************************************************
//******************************************************************
//******************************************************************

class User
{
    public:
        Wallet w;

        string name;
        string mobile;
        float balance;
        int pin;

        User();
        void signup();
        bool check();
        static bool login(string no);
        void display(string no);

    protected:

    private:
};

User::User()
{
    name = "";
    mobile = "";
    balance = 0.0;
    pin = 0;
}

void User :: signup()
{
    bool chk;

    stringstream ss;

    fflush(stdin);
    cout << "ENTER YOUR NAME          : ";
    getline(cin,name);
    fflush(stdin);
    cout << "ENTER YOUR MOBILE NUMBER : ";
    getline(cin,mobile);
    cout << "ENTER INITIAL BALANCE    : RS. ";
    cin >> balance;
    cout << "ENTER A 4 DIGIT PIN      : ";
    cin >> pin;

    chk = check();

    if(chk)
    {
        ofstream f;

        ss << mobile << ".txt";

        f.open(ss.str(),ios::out);

        f << pin << endl;
        f << "NAME    : " << name << endl;
        f << "MOBILE  : " << mobile << endl;
        f << "BALANCE : RS. " << balance << endl << endl;

        f.close();

        stringstream ss1;
        ss1 << "T " << mobile << ".txt";

        ofstream f1;

        f1.open(ss1.str(),ios::app);

        time_t now = time(0);
        char* dateTime = ctime(&now);

        f1 << "RS.   " << setw(10) << balance << " - " << dateTime << endl;

        f1.close();

        cout << endl << "ACCOUNT CREATED SUCCESSFULLY" << endl;
        cout << "NOTE : ACCOUNT NUMBER IS SAME AS MOBILE NUMBER" << endl;
    }
    else
    {
        cout << endl << "ACCOUNT NOT CREATED" << endl;
        cout << "INVALID ENTRY FOUND OR ACCOUNT ALREADY EXISTS !!!" << endl;
    }
}

bool User :: check()
{
    string line;
    fstream f;

    f.open("USER.txt",ios::in);

    if(mobile.length() != 11)
        return false;

    if(!f)
    {
        f.close();

        f.open("USER.txt",ios::out);
    }
    else
    {
        while(getline(f,line))
        {
            if(line == mobile)
            {
                f.close();
                return false;
            }
        }
    }

    if(balance <= 0)
        return false;

    if(pin < 1000 || pin >= 10000)
        return false;

    f.close();

    f.open("USER.txt",ios::app);
    f << mobile << endl;
    f.close();

    return true;
}

bool User :: login(string no)
{
    string line;
    fstream f;
    stringstream ss;

    int cpin;

    f.open("USER.txt",ios::in);

    if(!f)
    {
        return false;
    }
    else
    {
        while(getline(f,line))
        {
            if(line == no)
            {
                ss << no << ".txt";
                f.close();

                f.open(ss.str(),ios::in);

                getline(f,line);

                cout << "ENTER YOUR PIN            : ";
                cin >> cpin;

                if(cpin == stoi(line))
                {
                    f.close();
                    return true;
                }
            }
        }
    }

    f.close();

    return false;
}

void User :: display(string no)
{
    int choice;
    bool chk;

    while(1)
    {
       system("cls");
        cout << "1. DEPOSIT" << endl;
        cout << "2. TRANSFER" << endl;
        cout << "3. VIEW WALLET" << endl;
        cout << "4. TRANSACTION HISTORY" << endl;
        cout << "5. MOBILE RECHARGE " << endl;
        cout << "6. CASH OUT " << endl;
        cout << "7. ONLINE PAYMENT" << endl;
        cout << "8. GIFT/SALAMI " << endl;
        cout << "9. VIEW MESSAGE " <<endl;
        cout << "10.LOG OUT" << endl << endl;

        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            system("cls");
            cout << "ENTER AMOUNT TO DEPOSIT : RS. ";
            cin >> w.amt;
            chk = w.transact(no,1);
            if(chk)
                cout << endl << "DEPOSIT SUCCESSFUL" << endl;
            else
                cout << "DEPOSIT FAILED" << endl;
            break;
        }
        case 2:
        {
            system("cls");
            w.transfer(no);
            break;
        }
        case 3:
        {
            system("cls");
            w.viewWallet(no);
            break;
        }
        case 4:
        {
            system("cls");
            w.transactHistory(no);
            break;
        }
        case 5:
        {
            system("cls");
            w.recharge(no);
            break;
        }
        case 6:
        {
            system("cls");
            w.cashout(no);
            break;
        }
        case 7:
        {
            system("cls");
            w.payment(no);
            break;
        }
        case 8:
        {
            system("cls");

            w.salami(no);
            break;
        }
        case 9:
        {
            system("cls");

            w.message(no);
            break;
        }
        case 10:
            system("cls");
            cout << "LOGOUT SUCCESSFUL" << endl;
            return;
        default:
            cout << "INVALID CHOICE !!!" << endl;
        }

        cout << endl;
        system("pause");
    }
}

class Menu
{
public:
    int choice;
    void menuProg()
    {
      while(1)
    {
        system("cls");

        cout << "1. SIGN UP" << endl;
        cout << "2. LOGIN" << endl;
        cout << "3. DELETE ACCOUNT" << endl;
        cout << "4. EXIT" << endl << endl;

        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            system("cls");
            cout << "SIGNUP" << endl << endl;
            User obj;
            obj.signup();
            break;
        }
        case 2:
        {
            system("cls");
            User obj;
            string no;
            bool chk;
            cout << "LOGIN" << endl << endl;
            fflush(stdin);
            cout << "ENTER YOUR ACCOUNT NUMBER : ";
            getline(cin,no);
            chk = User :: login(no);
            if(chk)
            {
                obj.display(no);
            }
            else
            {
                cout << endl << "ACCOUNT NOT FOUND OR INVALID PIN!!!" << endl << endl;
            }
            break;
        }

         case 3:
        {
            system("cls");
            User obj;
            string no;
            bool chk;
            cout << "DELETE ACCOUNT" << endl << endl;
            fflush(stdin);
            cout << "ENTER YOUR ACCOUNT NUMBER : ";
            getline(cin,no);

            chk=User :: login(no);
            if(!chk){cout<<"ACCOUNT NOT FOUND!"<<endl;}
            else{
            string sp=no+".txt";
            remove(sp.c_str());
            sp="T "+no+".txt";
            remove(sp.c_str());
            sp="MESSAGE "+no+".txt";
            remove(sp.c_str());

            ifstream f;
            f.open("USER.txt");
            int k;
            vector<string>v;
            vector<int>vint;
            int count=1;
            while(f>>sp){
                if(no!=sp){
                    v.push_back(sp);
                }
            }

            ofstream f2;
            f2.open("NEWUSER.txt");
            for(int i=0;i<v.size();i++){
                f2<<v[i]<<endl;
            }
            f.close();f2.close();
            if(remove("USER.txt")==0) cout<<"ACCOUNT DELETE SUCCESSFULL"<<endl;
            rename("NEWUSER.txt","USER.txt");

            }
            break;
        }

        case 4:
            exit(0);
        default:
            cout << endl << "INVALID CHOICE !!!" << endl;
        }

        cout << endl;
        system("pause");
    }

    }
};
int main()
{
    Menu p1;
    p1.menuProg();
    return 0;
}
