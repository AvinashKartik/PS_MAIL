#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include<time.h>
#include<windowsx.h>
#include<conio.h>
#include<string>
#include<sstream>
#include <iomanip>


using namespace std;

#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")

const char g_szClassName[] = "myWindowClass";


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class User_ID;
class Email_Box;
int check_userloginbinfile(User_ID x);
int no_of_records();
void write_userbinfile();
void displayall_userbinfile();
void displayaone_userbinfile(int x);

int check_forgpassbinfile(User_ID x);
void change_passbinfile(User_ID x);
int check_usernamebinfile(const char* x);

class User_ID
{
private:
    char name[40];
    char phno[11];
    int age;
    char pass1[30];
    char pass2[30];
    int uno;

public:
    User_ID()
    {
        name[0]='0';
        pass1[0]=pass2[0]='0';
        age=uno=0;
        phno[0]=0;
    }
    void accept_signup()
    {

        cout<<"Enter your username(max40): ";
        for(int l=5; l!=4;)
        {
            cin.sync();
            int i=0;
            char b;

            for(;;)
            {
                if(i<=38)
                {
                    b=_getch();

                    if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
                    {
                        name[i]=b;
                        i++;
                        cout<<b;
                    }
                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }
                    if(b=='\r')
                    {
                        name[i]='\0';
                        l=4;
                        break;
                    }
                }
                else
                {
                    b=_getch();


                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }

                    if(b=='\r')
                    {
                        name[i]='\0';
                        l=4;
                        break;
                    }

                }
            }

        }

        cout<<endl;


        for(int i=0; i!=1; )
        {
            const char* p=name;
            if(check_usernamebinfile(p)==0&&strlen(p)>=6)
            {
                cout<<"Username already exists. Enter again!"<<endl;
                cout<<"Enter your username(max 40): ";

                for(int l=5; l!=4;)
                {

                    cin.sync();
                    int i=0;
                    char b;

                    for(;;)
                    {
                        if(i<=38)
                        {
                            b=_getch();
                            if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
                            {
                                name[i]=b;
                                i++;
                                cout<<b;
                            }
                            if(b=='\b'&&i>=1)
                            {
                                cout<<"\b \b";
                                i--;
                            }
                            if(b=='\r')
                            {

                                name[i]='\0';
                                l=4;

                                break;
                            }
                        }
                        else
                        {
                            b=_getch();


                            if(b=='\b'&&i>=1)
                            {
                                cout<<"\b \b";
                                i--;
                            }

                            if(b=='\r')
                            {
                                name[i]='\0';
                                l=4;
                                break;
                            }

                        }

                    }
                }
            }
            else if(strlen(p)<6)
            {
                cout<<endl;
                cout<<"Username should atleast be 6 characters long. Enter again!"<<endl;
                cout<<"Enter your username(max 40): ";
                for(int l=5; l!=4;)
                {
                    cin.sync();
                    int i=0;
                    char b;
                    for(;;)
                    {
                        if(i<=38)
                        {
                            b=_getch();
                            if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
                            {
                                name[i]=b;
                                i++;
                                cout<<b;
                            }
                            if(b=='\b'&&i>=1)
                            {
                                cout<<"\b \b";
                                i--;
                            }
                            if(b=='\r')
                            {

                                name[i]='\0';
                                l=4;

                                break;
                            }
                        }
                        else
                        {
                            b=_getch();


                            if(b=='\b'&&i>=1)
                            {
                                cout<<"\b \b";
                                i--;
                            }

                            if(b=='\r')
                            {
                                name[i]='\0';
                                l=4;
                                break;
                            }
                        }

                    }
                }

            }
            else
            {
                i=1;
            }
        }
        cout<<endl;

        cout<<"Enter your phone number: ";
        for(int l=5; l!=4;)
        {
            cin.sync();
            int i=0;
            char b;
            for(;;)
            {
                if(i<=9)
                {
                    b=_getch();
                    if(b>='0'&&b<='9')
                    {
                        phno[i]=b;
                        i++;
                        cout<<b;

                    }
                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }
                    if(b=='\r')
                    {
                        if(i>=6)
                        {
                            phno[i]='\0';

                            l=4;
                        }
                        else
                        {
                            cout<<endl;
                            cout<<i;
                            cout<<"PhoneNumber should be 10 digits. Enter again: ";

                        }
                        break;
                    }
                }
                else
                {
                    b=_getch();


                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }

                    if(b=='\r')
                    {
                        name[i]='\0';
                        l=4;
                        break;
                    }


                }
            }
        }
        cout<<endl;

        cout<<"Enter your age(15-150): ";
        cin>>age;
        for(int i=0; i!=5;)
        {
            if(age<15||age>150)
            {
                cout<<"Invalid age entered. Enter again: ";
                cin>>age;
            }
            else
            {
                i=5;
            }
        }

        cin.sync();
        cout<<"Enter your password(max 30): ";
        for(int l=5; l!=4;)
        {
            cin.sync();
            int i=0;
            char b;
            for(;;)
            {
                if(i<=29)
                {
                    b=_getch();
                    if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
                    {
                        pass1[i]=b;
                        i++;
                        cout<<"*";
                    }
                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }
                    if(b=='\r')
                    {
                        if(i>=6)
                        {
                            pass1[i]='\0';

                            l=4;
                        }
                        else
                        {
                            cout<<endl;

                            cout<<"Password should at least be 6 characters long. Enter again: ";

                        }
                        break;
                    }
                }
                else
                {

                    b=_getch();


                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }

                    if(b=='\r')
                    {
                        name[i]='\0';
                        l=4;
                        break;
                    }
                }
            }
        }

        cout<<endl;

        cin.sync();
        for(int l=0; l!=4;)
        {
            cin.sync();
            cout<<"Re-Enter your password: ";
            int i=0;

            char b;
            for(;;)
            {
                if(i<=29)
                {
                    b=_getch();
                    if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
                    {
                        pass2[i]=b;
                        i++;
                        cout<<"*";
                    }
                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }
                    if(b=='\r')
                    {
                        if(i>=6)
                        {
                            pass2[i]='\0';
                            l=4;
                        }
                        else
                        {
                            cout<<endl;

                            cout<<"Password should at least be 6 characters long. Enter again: ";

                        }
                        break;
                    }
                }
                else
                {
                    b=_getch();


                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }

                    if(b=='\r')
                    {
                        name[i]='\0';
                        l=4;
                        break;
                    }

                }
            }
        }


        cout<<endl;

        for(int i=0; i<3; i++ )
        {
            if(strcmp(pass1,pass2)!=0&&i!=2)
            {

                cout<<"Your passwords do not match!"<<endl<<endl;

                cout<<"Enter your password(max 30): ";
                for(int l=5; l!=4;)
                {
                    cin.sync();
                    int i=0;
                    char b;
                    for(;;)
                    {
                        if(i<=29)
                        {
                            b=_getch();
                            if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
                            {
                                pass1[i]=b;
                                i++;
                                cout<<"*";
                            }
                            if(b=='\b'&&i>=1)
                            {
                                cout<<"\b \b";
                                i--;
                            }
                            if(b=='\r')
                            {
                                if(i>=6)
                                {
                                    pass1[i]='\0';

                                    l=4;
                                }
                                else
                                {
                                    cout<<endl;

                                    cout<<"Password should at least be 6 characters long. Enter again: ";

                                }
                                break;
                            }
                        }

                        else
                        {
                            b=_getch();


                            if(b=='\b'&&i>=1)
                            {
                                cout<<"\b \b";
                                i--;
                            }

                            if(b=='\r')
                            {
                                name[i]='\0';
                                l=4;
                                break;
                            }
                        }
                    }


                    cout<<endl;
                }

                for(int l=0; l!=4;)
                {
                    cin.sync();
                    cout<<"Re-Enter your password: ";
                    int i=0;

                    char b;
                    for(;;)
                    {
                        if(i<=29)
                        {
                            b=_getch();
                            if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
                            {
                                pass2[i]=b;
                                i++;
                                cout<<"*";
                            }
                            if(b=='\b'&&i>=1)
                            {
                                cout<<"\b \b";
                                i--;
                            }
                            if(b=='\r')
                            {
                                if(i>=6)
                                {
                                    pass2[i]='\0';
                                    l=4;
                                }
                                else
                                {
                                    cout<<endl;

                                    cout<<"Password should at least be 6 characters long. Enter again: ";

                                }
                                break;
                            }

                        }
                        else
                        {
                            b=_getch();


                            if(b=='\b'&&i>=1)
                            {
                                cout<<"\b \b";
                                i--;
                            }

                            if(b=='\r')
                            {
                                name[i]='\0';
                                l=4;
                                break;
                            }
                        }
                    }


                    cout<<endl;
                }
            }
            else if(strcmp(pass1,pass2)!=0&&i==2)
            {

                cout<<"Your passwords do not match!"<<endl<<endl;
                cin.sync();
                cout<<"Invalid password entered THREE times for signup. program terminates!"<<endl;
                exit(0);
            }
            else
            {
                i=4;
            }
        }

    }

    void accept_login()
    {
        cout<<"Enter your username: ";
        for(int l=5; l!=4;)
        {
            cin.sync();
            int i=0;
            char b;

            for(;;)
            {
                if(i<=39)
                {
                    b=_getch();
                    if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
                    {
                        name[i]=b;
                        i++;
                        cout<<b;
                    }
                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }
                    if(b=='\r')
                    {
                        name[i]='\0';
                        l=4;
                        break;
                    }
                }

                else
                {
                    b=_getch();


                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }

                    if(b=='\r')
                    {
                        name[i]='\0';
                        l=4;
                        break;
                    }
                }
            }
        }

        cout<<endl;

        cout<<"Enter your password: ";
        for(int l=5; l!=4;)
        {
            cin.sync();
            int i=0;
            char b;
            for(;;)
            {
                if(i<=29)
                {
                    b=_getch();
                    if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
                    {
                        pass1[i]=b;
                        i++;
                        cout<<"*";
                    }
                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }
                    if(b=='\r')
                    {
                        pass1[i]='\0';
                        l=4;
                        break;
                    }
                }

                else
                {
                    b=_getch();


                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }

                    if(b=='\r')
                    {
                        name[i]='\0';
                        l=4;
                        break;
                    }
                }
            }
        }
        cout<<endl;

    }


    void accept_forgotpass()
    {


        cout<<"Enter your username: ";
        for(int l=5; l!=4;)
        {
            cin.sync();
            int i=0;
            char b;
            for(;;)
            {
                if(i<=39)
                {
                    b=_getch();
                    if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
                    {
                        name[i]=b;
                        i++;
                        cout<<b;
                    }
                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }
                    if(b=='\r')
                    {

                        name[i]='\0';

                        l=4;



                        break;
                    }
                }

                else
                {
                    b=_getch();


                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }

                    if(b=='\r')
                    {
                        name[i]='\0';
                        l=4;
                        break;
                    }
                }
            }
        }

        cout<<endl;

        cout<<"Enter your phone number: ";
        for(int l=5; l!=4;)
        {
            cin.sync();
            int i=0;
            char b;
            for(;;)
            {
                if(i<=9)
                {
                    b=_getch();
                    if(b>='0'&&b<='9')
                    {
                        phno[i]=b;
                        i++;
                        cout<<b;


                    }
                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }
                    if(b=='\r')
                    {
                        if(i>=6)
                        {
                            phno[i]='\0';

                            l=4;
                        }
                        else
                        {
                            cout<<endl;

                            cout<<"PhoneNumber should be 10 digits. Enter again: ";

                        }
                        break;
                    }
                }
                else
                {
                    b=_getch();


                    if(b=='\b'&&i>=1)
                    {
                        cout<<"\b \b";
                        i--;
                    }

                    if(b=='\r')
                    {
                        name[i]='\0';
                        l=4;
                        break;
                    }
                }
            }


            cout<<endl;
        }


    }

    void display()
    {
        cout<<"The username is: ";
        puts(name);

        cout<<"The phone number is: ";
        puts(phno);

        cout<<"The age is: "<<age<<endl;

        cout<<"The password is: ";
        puts(pass1);
    }

    void set_uno(int x)
    {
        uno=x;
    }

    int get_uno()
    {
        return uno;
    }

    const char* get_name()
    {
        const char *p=name;
        return p;
    }

    const char* get_pass1()
    {
        const char *p=pass1;
        return p;
    }

    const char* get_phno()
    {
        const char*p= phno;
        return p;
    }

    void set_pass(const char *p)
    {
        strcpy(pass1, p);
        strcpy(pass2, p);
    }

    void set_username(const char *p)
    {
        strcpy(name, p);

    }


};

class Email_Box
{
private:
    char sender[40];
    char receiver[40];
    char subject[50];
    char content[500];
    int eno;
    char dt[1500];
    int read;
    int sent;

public:
    Email_Box()
    {
        sender[0]='0';
        receiver[0]='0';
        content[0]='0';
        subject[0]='0';
        read=0;
        sent=0;

    }

    Email_Box(const char*s, const char*r, const char* sub, const char* c)
    {
        strcpy(sender, s);
        strcpy(receiver, r);
        strcpy(subject, sub);
        strcpy(content, c);

        r=0;

        time_t now = time(0);
        strcpy(dt, ctime(&now));



    }

    const char* get_sender()
    {
        const char*p=sender;
        return p;
    }

    const char* get_receiver()
    {
        const char*p=receiver;
        return p;
    }

    const char* get_subject()
    {
        const char*p=subject;
        return p;
    }

    const char* get_content()
    {
        const char*p=content;
        return p;
    }

    char* get_total_inbox1()
    {
        char*c=content;
        char*s=sender;
        char*sub=subject;
        char total[1000];
        total[0]='\0';
        //time_t now = time(0);
        //dt = ctime(&now);

        strcat(total, s);
        strcat(total, "  |  ");
        strcat(total, sub);
        strcat(total, " | ");
        strcat(total, dt);

        char *b=&total[0];
        return b;
    }

    char* get_total_sentmail1()
    {
        char*c=content;
        char*r=receiver;
        char*sub=subject;
        char total[1000];
        total[0]='\0';


        strcat(total, r);
        strcat(total, "  |  ");
        strcat(total, sub);
        strcat(total, " | ");
        strcat(total, dt);
        char *b=&total[0];
        return b;


    }

    char* get_total_inbox()
    {
        char*c=content;
        char*s=sender;
        char*sub=subject;
        char total[1000];
        total[0]='\0';

        strcat(total, "SENDER: ");
        strcat(total, s);
        strcat(total, "\r\nSUBJECT: ");
        strcat(total, sub);
        strcat(total, "\r\nDATE: ");
        strcat(total, dt);
        strcat(total, "\r\nCONTENT: \r\n");
        strcat(total, c);
        strcat(total, "\r\n");

        char *b=&total[0];
        return b;
    }


    char* get_total_sent()
    {
        char*c=content;
        char*s=receiver;
        char*sub=subject;
        char total[1000];
        total[0]='\0';

        strcat(total, "TO: ");
        strcat(total, s);
        strcat(total, "\r\nSUBJECT: ");
        strcat(total, sub);
        strcat(total, "\r\nDATE: ");

        strcat(total, dt);
        strcat(total, "\r\nCONTENT: \r\n");
        strcat(total, c);

        strcat(total, "\r\n");

        char *b=&total[0];
        return b;
    }

    void set_eno(int x)
    {
        eno=x;
    }

    void display()
    {

        cout<<"FROM: ";
        puts(sender);
        cout<<endl<<endl;
        cout<<"SUBJECT: ";
        puts(subject);
        cout<<endl<<endl<<endl;
        cout<<"CONTENT: ";
        puts(content);
        cout<<endl;


    }

    int get_eno()
    {
        return eno;
    }

    void set_read()
    {
        read=1;
    }

    void set_sent(int x)
    {
        sent=x;
    }

    int get_read()
    {
        return read;
    }

    int get_sent()
    {
        return sent;
    }



};


int no_of_records_U()
{
    User_ID u;
    fstream binfile("USER_DETAILS.dat", ios::binary|ios::out);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.seekg(0L, ios::end);
        long lastbyte=binfile.tellg();
        binfile.close();

        return int(lastbyte/sizeof(u));
    }
    return 0;
}

void write_userbinfile()
{
    User_ID u;


    fstream binfile("USER_DETAILS.dat", ios::binary|ios::out| ios::app);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.seekg(0L, ios::end);
        long lastbyte=binfile.tellg();
        u.accept_signup();
        u.set_uno(lastbyte/sizeof(u)+1);
        binfile.write((char*)&u, sizeof(u));
    }
    binfile.close();

}

void write_Mailboxbinfile(Email_Box e)
{
    fstream binfile("EMAILS-SENT.dat", ios::binary|ios::out| ios::app);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.seekg(0L, ios::end);
        long lastbyte=binfile.tellg();

        e.set_eno(lastbyte/sizeof(e)+1);
        e.set_sent(1);
        binfile.write((char*)&e, sizeof(e));

    }
    binfile.close();

}

void write_Mailboxbinfile1(Email_Box e)
{
    fstream binfile("EMAILS-SENT.dat", ios::binary|ios::out| ios::app);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.seekg(0L, ios::end);
        long lastbyte=binfile.tellg();

        e.set_eno(lastbyte/sizeof(e)+1);
        e.set_sent(0);
        binfile.write((char*)&e, sizeof(e));

    }
    binfile.close();

}

void displayall_userbinfile()
{
    User_ID u;
    fstream binfile("USER_DETAILS.dat", ios::binary|ios::in);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.read((char*)&u, sizeof(u));
        while(!binfile.eof())
        {
            u.display();
            binfile.read((char*)&u, sizeof(u));
        }
    }
    binfile.close();
}

void displayall_Mailboxbinfile()
{
    Email_Box e;
    fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.read((char*)&e, sizeof(e));
        while(!binfile.eof())
        {
            e.display();
            binfile.read((char*)&e, sizeof(e));
        }
    }
    binfile.close();
}

void displayallofone_Mailboxbinfile(const char* x)
{
    Email_Box e;
    const char *p;
    const char *q;

    fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.read((char*)&e, sizeof(e));
        while(!binfile.eof())
        {
            p=x;
            q=e.get_receiver();
            if(strcmp(p,q)==0)
            {
                e.display();

            }
            binfile.read((char*)&e, sizeof(e));
        }
    }
    binfile.close();
}

void delete_Mailboxbinfile()
{
    Email_Box e;
    fstream binfile("EMAILS-SENT.dat", ios::binary|ios::out);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        int x;
        long recPos;
        cout<<"Enter the email number you would want to delete: ";
        cin>>x;
        recPos=(long)(x-1)*sizeof(e);
        binfile.seekg(recPos);
        e.set_eno(-1);
        binfile.write((char*)&e, sizeof(e));
    }
    binfile.close();


}

void displayaone_Mailboxbinfile(int x)
{
    Email_Box e;
    fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        long recPos=(long)(x-1)*sizeof(e);
        binfile.seekg(recPos);
        binfile.read((char*)&e, sizeof(e));
        if(!binfile.eof())
        {
            e.display();
        }
    }
    binfile.close();

}

void displayaone_userbinfile(int x)
{
    User_ID u;
    fstream binfile("USER_DETAILS.dat", ios::binary|ios::in);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        long recPos=(long)(x-1)*sizeof(u);
        binfile.seekg(recPos);
        binfile.read((char*)&u, sizeof(u));
        if(!binfile.eof())
        {
            u.display();
        }
    }
    binfile.close();

}

int check_userloginbinfile(User_ID x)
{
    User_ID u;
    int a=0;
    const char *p;
    const char *q;
    const char *c;
    const char *d;

    fstream binfile("USER_DETAILS.dat", ios::binary|ios::in);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.read((char*)&u, sizeof(u));
        while(!binfile.eof())
        {
            p=x.get_name();
            q=u.get_name();
            if(strcmp(p,q)==0)
            {
                c=x.get_pass1();
                d=u.get_pass1();
                if(strcmp(c,d)==0)
                {
                    a=1;
                }
            }

            binfile.read((char*)&u, sizeof(u));
        }
    }
    binfile.close();

    return a;
}

int check_forgpassbinfile(User_ID x)
{
    User_ID u;
    int a=0;
    const char *p;
    const char *q;


    fstream binfile("USER_DETAILS.dat", ios::binary|ios::in);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.read((char*)&u, sizeof(u));
        while(!binfile.eof())
        {
            p=x.get_name();
            q=u.get_name();
            if(strcmp(p,q)==0)
            {
                if(strcmp(p,q)==0)
                {
                    a=1;
                }
            }

            binfile.read((char*)&u, sizeof(u));
        }
    }
    binfile.close();

    return a;
}

void change_passbinfile(User_ID x)
{
    User_ID u;

    const char *p;
    const char *q;


    fstream binfile("USER_DETAILS.dat", ios::binary|ios::in|ios::out);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.read((char*)&u, sizeof(u));
        while(!binfile.eof())
        {
            p=x.get_name();
            q=u.get_name();
            if(strcmp(p,q)==0)
            {
                u.set_pass(x.get_pass1());
                binfile.seekp((long)-sizeof(u), ios::cur);
                binfile.write((char*)&u, sizeof(u));

            }

            binfile.read((char*)&u, sizeof(u));
        }
    }
    binfile.close();


}

int check_usernamebinfile(const char* x)
{
    User_ID u;
    int a=1;
    const char *p;
    const char *q;

    fstream binfile("USER_DETAILS.dat", ios::binary|ios::in);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.read((char*)&u, sizeof(u));
        while(!binfile.eof())
        {
            p=x;
            q=u.get_name();
            if(strcmp(p,q)==0)
            {
                a=0;
            }
            binfile.read((char*)&u, sizeof(u));
        }


    }

    binfile.close();

    return a;
}

HWND hWndEdit1;
HWND hWndEdit2;
HWND hWndEdit3;
HWND hWndEdit4;
HWND hWndEdit5;
HWND hWndEdit6;
HWND hWndStatic1;
HWND hWndStatic2;
HWND hWndStatic3;
HWND hWndButton1;
HWND hWndButton2;
HWND hWndButton3;
HWND hWndButton4;
HWND hWndButton5;
HWND hWndStatic4;
HWND hWndButton6;
HWND hWndButton7;
HWND hWndButton8;
HWND hWndButton9;
HWND hWndButton10;
HWND hWndButton11;
HWND hWndButton12;
HWND hWndListbox1;
HWND hWndListbox2;
HWND hWndListbox3;
HWND hWndListbox_Search1;
HWND hWndListbox_Search2;

void fullscreen()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

//------------------------------------------------------------------START OF WIN MAIN
User_ID uu;  //this is to store the username of the user alone and use it after he has logged in
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR nCmdLine, int nCmdShow)




{

    //system("color %");
    system("color 80");
    //fullscreen();




    char a[7];
    strcpy(a,"WinApp");
    LPTSTR windowClass = TEXT(a);
    char b[20];
    strcpy(b,"Windows Application");
    LPTSTR windowTitle = TEXT(b);
    WNDCLASSEX wcex;

    wcex.cbClsExtra = 0;



    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.cbWndExtra = 0;
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);

    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hInstance = hInstance;
    wcex.lpfnWndProc = WndProc;
    wcex.lpszClassName = windowClass;
    wcex.lpszMenuName = NULL;
    wcex.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL, TEXT("RegisterClassEx Failed!"), TEXT("Error"), MB_ICONERROR);
        return EXIT_FAILURE;
    }

    HWND hWnd;

    char var_1;
    char var_2;
    char var_3;
    char temp_check1[100];
    char temp_check2[100];
    char temp_check3[100];



    cout<<"            Welcome to PS MAIL              "<<endl<<endl;
    cout<<"1 - User"<<endl;
    cout<<"2 - Exit "<<endl<<endl;
    cout<<"____________________________________________________________________"<<endl;
    cout<<"Enter your choice (1-2): ";
    cin.sync();
    cin.getline(temp_check1,100);
    var_1=temp_check1[0];

    cout<<"____________________________________________________________________"<<endl<<endl<<endl;


    for(int h=0; h!=10; )
    {


        if(var_1=='1'&&strlen(temp_check1)==1)
        {
            cout<<"            SIGN IN        "<<endl<<endl;
            cout<<"1 - Login"<<endl;
            cout<<"2 - SignUp"<<endl;
            cout<<"3 - Exit "<<endl<<endl;
            cout<<"____________________________________________________________________"<<endl;
            cout<<"Enter your choice (1-3): ";
            cin.getline(temp_check2, 100);
            var_2=temp_check2[0];
            cout<<"____________________________________________________________________"<<endl<<endl<<endl;

            for(int i=0; var_2!=4; )
            {
                if(var_2=='1'&&strlen(temp_check2)==1)
                {
                    User_ID u;
                    u.accept_login();
                    for(int j=0; j<4; j++)
                    {

                        if(j==3)
                        {
                            system("cls");
                            MessageBox(NULL, TEXT("Invalid credentials entered THREE times!!"), TEXT("X"), MB_ICONEXCLAMATION);
                            cout<<"            Choose from the below options              "<<endl<<endl;
                            cout<<"1 - Forgot Password!?"<<endl;
                            cout<<"2 - Exit "<<endl<<endl;
                            cout<<"____________________________________________________________________"<<endl;
                            cout<<"Enter your choice (1-2): ";

                            cin.getline(temp_check3, 100);
                            var_3=temp_check3[0];

                            cout<<"____________________________________________________________________"<<endl<<endl<<endl;
                            User_ID u1;

                            for(int m=0 ; m!=10 ; )
                            {
                                if(var_3=='1'&&strlen(temp_check3)==1)
                                {
                                    double tempno;
                                    cout<<"To change your password:(Only one try. Carefully enter credentials)"<<endl;

                                    u1.accept_forgotpass();
                                    if(check_forgpassbinfile(u1)==0)
                                    {
                                        MessageBox(NULL, TEXT("Invalid credentials again. Program will terminate!! Press any key after 'ok'"), TEXT("X"), MB_ICONEXCLAMATION);
                                        exit(0);
                                    }
                                    else
                                    {
                                        char pass1[30];
                                        cout<<"Enter new password: ";
                                        cin.sync();


                                        for(int l=5; l!=4;)
                                        {
                                            cin.sync();
                                            int i=0;
                                            char b;
                                            for(;;)
                                            {
                                                b=_getch();
                                                if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
                                                {
                                                    pass1[i]=b;
                                                    i++;
                                                    cout<<"*";
                                                }
                                                if(b=='\b'&&i>=1)
                                                {
                                                    cout<<"\b \b";
                                                    i--;
                                                }
                                                if(b=='\r')
                                                {
                                                    //if(i>=6){
                                                    pass1[i]='\0';

                                                    l=4;
                                                    //}
                                                    //else{
                                                    //   cout<<endl;
                                                    //   cout<<i;
                                                    //  cout<<"Password should at least be 6 characters long. Enter again: ";

                                                    //}
                                                    break;
                                                }
                                            }
                                        }

                                        cout<<endl;

                                        const char* a=pass1;
                                        u1.set_pass(a);
                                        change_passbinfile(u1);
                                        system("cls");
                                        MessageBox(0, TEXT("You have successfully changed your password!!"), TEXT("Success"), 0);

                                        cout<<"            SIGN IN            "<<endl<<endl;
                                        cout<<"1 - Login"<<endl;
                                        cout<<"2 - SignUp"<<endl;
                                        cout<<"3 - Exit "<<endl<<endl;
                                        cout<<"____________________________________________________________________"<<endl;
                                        cout<<"Enter your choice (1-3): ";
                                        cin>>var_2;
                                        cin.get();
                                        cout<<"____________________________________________________________________"<<endl<<endl<<endl;



                                        m=10;
                                    }


                                }
                                else if(var_3=='2'&&strlen(temp_check2)==1)
                                {
                                    m=10;
                                    exit(0);

                                }
                                else
                                {

                                    cout<<"Please enter a valid number (1-2): ";
                                    cin.sync();
                                    cin.getline(temp_check3, 100);
                                    var_3=temp_check3[0];

                                    cout<<endl;

                                }
                            }
                        }
                        else
                        {
                            if(check_userloginbinfile(u)==0 && j!=2)
                            {

                                cout<<"Invalid credentials! Enter again!"<<endl;
                                u.accept_login();
                            }
                            else if(check_userloginbinfile(u)==0 && j==2)
                            {

                            }
                            else
                            {
                                j=4;
                                uu.set_username(u.get_name());
                                system("cls");
                                MessageBox(0, TEXT("You have successfully logged in"), TEXT("Success"), 0);
                                var_2=4;

                            }
                        }
                    }

                }

                else if(var_2=='2'&&strlen(temp_check2)==1)
                {
                    User_ID u;
                    write_userbinfile();

                    system("cls");
                    MessageBox(0, TEXT("You have successfully Signed up!!"), TEXT("Success"), 0);
                    cout<<"            SIGN IN        "<<endl<<endl;
                    cout<<"1 - Login"<<endl;
                    cout<<"2 - SignUp"<<endl;
                    cout<<"3 - Exit "<<endl<<endl;
                    cout<<"____________________________________________________________________"<<endl;
                    cout<<"Enter your choice (1-3): ";
                    cin>>var_2;
                    cout<<"____________________________________________________________________"<<endl<<endl<<endl;






                }

                else if(var_2=='3'&&strlen(temp_check2)==1)
                {
                    exit(0);

                }
                else
                {

                    cout<<"Please enter a valid number (1-3): ";
                    cin.sync();
                    cin.getline(temp_check2, 100);
                    var_2=temp_check2[0];



                    cout<<endl;
                }

            }
            h=10;

        }
        else if(var_1=='2'&&strlen(temp_check1)==1)
        {
            exit(0);
        }
        else
        {
            temp_check1[0]='\0';
            cout<<"Please enter a valid number (1-2): ";
            cin.sync();
            cin.getline(temp_check1, 100);

            var_1=temp_check1[0];
            cout<<endl;

        }
    }                                          //major if condition ends here. Beyond this point, it is safe to assume we are writing code for when e te user is logged in




//    int var_11, var_12, var_13;
//
//
//
//    cout<<"            Welcome to EMAIL MENU 1              "<<endl<<endl;
//    cout<<"1 - For inbox"<<endl;
//    cout<<"2 - To compose an email"<<endl;
//    cout<<"3 - Log out"<<endl<<endl;
//    cout<<"____________________________________________________________________"<<endl;
//    cout<<"Enter your choice from EmailMenu1: ";
//    cin>>var_11;
//    cin.get();
//
//    cout<<"____________________________________________________________________"<<endl<<endl<<endl;
//
//    if(var_11==2){





    if (!(hWnd = CreateWindow(windowClass,  "INBOX", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 1000, NULL, NULL, hInstance, NULL)))
    {
        MessageBox(NULL, TEXT("CreateWindow Failed!"), TEXT("Error"), MB_ICONERROR);
        return EXIT_FAILURE;
    }

    HICON hIcon, hIconSm;

    hIcon = (HICON) LoadImage(NULL, "psmail.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE);
    //hIcon = (HICON) LoadImage(NULL, "mmm.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
    if (hIcon)
    {
        SendMessage(hWnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    }
    else
    {
        //MessageBox(hWnd, "Could not load large icon!", "Error", MB_OK | MB_ICONERROR);
        hIconSm = (HICON) LoadImage(NULL, "psmail_small.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE);
        SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIconSm);
    }


    HBRUSH brush = CreateSolidBrush(RGB(169,169,169));
    SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND,(LONG) brush );


    //char a[10];
    //SetWindowText(HWND hWnd,a, )
    ShowWindow(hWnd, nCmdShow);
    //ShowWindow(hWnd, SW_HIDE);
    ShowWindow(hWnd, SW_MAXIMIZE);

    UpdateWindow(hWnd);

    SetTimer(hWnd, 37, 5000, (TIMERPROC) NULL);

    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return EXIT_SUCCESS;




}

void func1(HWND hWnd);
void func2(HWND hWnd);
void func_composemail(HWND hWnd);
void func_inbox(HWND hWnd);


int store_eno[1000];
int store_eno1[1000];
int store_eno2[1000];
int store_eno3[1000];
int store_eno4[1000];


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    char s[40],r[40],c[500], sub[50];
    int dummy=0;

    // for(int i=0; i<1000; i++){
    //    store_eno[i]=0;
    //}

    switch (msg)
    {

    case WM_CREATE:
        hWndStatic1 = CreateWindow("Static",
                                   "TO           : ",
                                   WS_CHILD,
                                   25, 50, 70, 20,
                                   hWnd, NULL, NULL, NULL);



        hWndStatic2 = CreateWindow("Static",
                                   TEXT("SUBJECT: "),
                                   WS_CHILD,
                                   25,90, 70, 20,
                                   hWnd, NULL, NULL, NULL);



        hWndEdit1 = CreateWindow("Edit",
                                 TEXT(""),
                                 WS_CHILD | WS_BORDER | ES_MULTILINE | WS_VSCROLL,
                                 100, 50, 1000, 20,
                                 hWnd, NULL, NULL, NULL);



        hWndEdit2 = CreateWindow("Edit",
                                 TEXT(""),
                                 WS_CHILD |  WS_BORDER | ES_MULTILINE |  WS_VSCROLL,
                                 100, 90, 1000, 20,
                                 hWnd, NULL, NULL, NULL);

        //ShowWindow(hWndEdit2, SW_HIDE);

        hWndStatic3 = CreateWindow("Static",
                                   TEXT("CONTENT: "),
                                   WS_CHILD,
                                   25, 140, 70, 20,
                                   hWnd, NULL, NULL, NULL);


        hWndEdit3 = CreateWindow("Edit",
                                 TEXT(""),
                                 WS_CHILD |  WS_BORDER | ES_MULTILINE |  WS_VSCROLL,
                                 25, 170, 1075, 350,
                                 hWnd, NULL, NULL, NULL);


        hWndEdit4 = CreateWindow("Edit",
                                 TEXT(""),
                                 WS_CHILD | ES_MULTILINE |WS_BORDER | WS_VSCROLL|ES_READONLY,
                                 25, 270, 1075, 260,
                                 hWnd, NULL, NULL, NULL);

        hWndEdit5 = CreateWindow("Edit",
                                 TEXT(""),
                                 WS_CHILD | ES_MULTILINE | WS_VISIBLE | WS_BORDER | WS_VSCROLL| ES_READONLY,
                                 25, 240, 1075, 300,
                                 hWnd, NULL, NULL, NULL);

        hWndEdit6 = CreateWindow("Edit",
                                 TEXT(""),
                                 WS_CHILD | WS_BORDER | ES_READONLY| WS_VISIBLE,
                                 300, 543, 650, 25,
                                 hWnd, NULL, NULL, NULL);




        hWndButton1 = CreateWindow("Button",
                                   TEXT("SEND"),
                                   WS_CHILD |  BS_PUSHBUTTON,
                                   1125, 450, 125, 30,
                                   hWnd, (HMENU) 1,  NULL, NULL);


        hWndButton2 = CreateWindow("Button",
                                   TEXT("SEARCH"),
                                   WS_CHILD |WS_VISIBLE | BS_PUSHBUTTON,
                                   1125, 50, 125, 30,
                                   hWnd, (HMENU) 2,  NULL, NULL);

        hWndButton3 = CreateWindow("Button",
                                   TEXT("CLEAR"),
                                   WS_CHILD | BS_PUSHBUTTON,
                                   1125, 420, 125, 30,
                                   hWnd, (HMENU) 3,  NULL, NULL);

        hWndButton4 = CreateWindow("Button",
                                   TEXT("DRAFTS"),
                                   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                   1125, 110, 125, 30,
                                   hWnd, (HMENU) 4,  NULL, NULL);

        hWndButton5 = CreateWindow("Button",
                                   TEXT("COMPOSE MAIL"),
                                   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                   1125, 140, 125, 30,
                                   hWnd, (HMENU) 5,  NULL, NULL);

        hWndButton6 = CreateWindow("Button",
                                   TEXT("INBOX"),
                                   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                   1125, 80, 125, 30,
                                   hWnd, (HMENU) 6,  NULL, NULL);

        hWndButton7 = CreateWindow("Button",
                                   TEXT("SENT MAIL"),
                                   WS_CHILD  |WS_VISIBLE| BS_PUSHBUTTON,
                                   1125, 170, 125, 30,
                                   hWnd, (HMENU) 7,  NULL, NULL);

        hWndButton8 = CreateWindow("Button",
                                   TEXT("EXIT"),
                                   WS_CHILD  |WS_VISIBLE| BS_PUSHBUTTON,
                                   1125, 540, 140, 30,
                                   hWnd, (HMENU) 8,  NULL, NULL);

        hWndButton9 = CreateWindow("Button",
                                   TEXT("SAVE TO DRAFTS"),
                                   WS_CHILD | BS_PUSHBUTTON,
                                   1125, 390, 125, 30,
                                   hWnd, (HMENU) 9,  NULL, NULL);

        hWndButton10 = CreateWindow("Button",
                                    TEXT("REPLY"),
                                    WS_CHILD | BS_PUSHBUTTON,
                                    1125, 450, 125, 30,
                                    hWnd, (HMENU) 100,  NULL, NULL);

        hWndButton11 = CreateWindow("Button",
                                    TEXT("FORWARD"),
                                    WS_CHILD | BS_PUSHBUTTON,
                                    1125, 420, 125, 30,
                                    hWnd, (HMENU) 101,  NULL, NULL);

        hWndButton12 = CreateWindow("Button",
                                    TEXT("MODIFY"),
                                    WS_CHILD | BS_PUSHBUTTON,
                                    1125, 450, 125, 30,
                                    hWnd, (HMENU) 102,  NULL, NULL);



        //hWndButton9 = CreateWindow("Button",
        //                              TEXT("CHAT"),
        //                            WS_CHILD  |WS_VISIBLE| BS_PUSHBUTTON ,
        //                          1125, 370, 125, 30,
        //                        hWnd, (HMENU) 8,  NULL, NULL);


        hWndListbox1 = CreateWindow("LISTBOX",
                                    "",
                                    WS_CHILD | WS_BORDER | WS_VISIBLE | WS_VSCROLL | LBS_NOTIFY,
                                    25, 50, 1075, 175,
                                    hWnd, (HMENU) 20, NULL, NULL);

        hWndListbox2 = CreateWindow("LISTBOX",
                                    "",
                                    WS_CHILD | WS_BORDER | WS_VSCROLL | LBS_NOTIFY,
                                    25, 50, 1075, 175,
                                    hWnd, (HMENU) 21, NULL, NULL);

        hWndListbox_Search1 = CreateWindow("LISTBOX",
                                           "",
                                           WS_CHILD | WS_BORDER | WS_VSCROLL | LBS_NOTIFY,
                                           25, 50, 1075, 40,
                                           hWnd, (HMENU) 29, NULL, NULL);

        hWndListbox_Search2 = CreateWindow("LISTBOX",
                                           "",
                                           WS_CHILD | WS_BORDER | WS_VSCROLL | LBS_NOTIFY,
                                           25, 85, 1075, 160,
                                           hWnd, (HMENU) 78, NULL, NULL);

        hWndListbox3 = CreateWindow("LISTBOX",
                                    "",
                                    WS_CHILD | WS_BORDER | WS_VSCROLL | LBS_NOTIFY,
                                    25, 50, 1075, 175,
                                    hWnd, (HMENU) 79, NULL, NULL);


        func_inbox(hWnd);


        break;

    case WM_COMMAND:
//        HBRUSH brush = CreateSolidBrush(RGB(169,169,169));
//        SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND,(LONG) brush );
//
//        SetClassLongPtr(hWndStatic1, GCLP_HBRBACKGROUND,(LONG) brush );
//
//
//        SetClassLongPtr(hWndStatic2, GCLP_HBRBACKGROUND,(LONG) brush );
//
//
//        SetClassLongPtr(hWndStatic3, GCLP_HBRBACKGROUND,(LONG) brush );
//
//        SetClassLongPtr(hWndStatic4, GCLP_HBRBACKGROUND,(LONG) brush );

        dummy=GetWindowText(hWndEdit1, r, 40);

//        cout << "here";
//        cout << LBN_DBLCLK;
//        cout << HIWORD(wParam);
//        cout << LOWORD(wParam);

        if (LOWORD(wParam)==1)
        {

            if(check_usernamebinfile(r)==0 && r[0]!='\0')
            {
                dummy=GetWindowText(hWndEdit2, sub, 50);
                dummy=GetWindowText(hWndEdit3, c, 500);
                if(sub[0]=='\0'&& c[0]=='\0')
                {
                    const int result = MessageBox(NULL, TEXT("Are you sure you want to send email? \n 1. No Subject! \n 2. No Content! "), TEXT("Error"), MB_ICONERROR| MB_YESNOCANCEL);
                    switch (result)
                    {
                    case IDYES:


                        Email_Box e(uu.get_name(), r, sub, c);
                        write_Mailboxbinfile(e);

                        MessageBox(0, TEXT("You have successfully sent the email!!"), TEXT("Success"), 0);
                        e.set_sent(1);
                        func1(hWnd);
                        SetWindowText(hWndEdit1, "");
                        SetWindowText(hWndEdit2, "");
                        SetWindowText(hWndEdit3, "");

                        break;


                    }


                }
                else if(sub[0]=='\0'&& c[0]!='\0')
                {
                    const int result = MessageBox(NULL, TEXT("Are you sure you want to send email? \n 1. No Subject! \n"), TEXT("Error"), MB_ICONERROR | MB_YESNOCANCEL);
                    switch (result)
                    {
                    case IDYES:


                        Email_Box e(uu.get_name(), r, sub, c);
                        write_Mailboxbinfile(e);
                        MessageBox(0, TEXT("You have successfully sent the email!!"), TEXT("Success"), 0);
                        e.set_sent(1);
                        func1(hWnd);
                        SetWindowText(hWndEdit1, "");
                        SetWindowText(hWndEdit2, "");
                        SetWindowText(hWndEdit3, "");

                        break;


                    }
                }
                else if(sub[0]!='\0'&& c[0]=='\0')
                {
                    const int result = MessageBox(NULL, TEXT("Are you sure you want to send email? \n 1. No Content! \n"), TEXT("Error"), MB_ICONERROR | MB_YESNOCANCEL);
                    switch (result)
                    {
                    case IDYES:


                        Email_Box e(uu.get_name(), r, sub, c);
                        write_Mailboxbinfile(e);
                        MessageBox(0, TEXT("You have successfully Sent the email!!"), TEXT("Success"), 0);
                        e.set_sent(1);
                        func1(hWnd);
                        SetWindowText(hWndEdit1, "");
                        SetWindowText(hWndEdit2, "");
                        SetWindowText(hWndEdit3, "");

                        break;


                    }
                }
                else
                {

                    Email_Box e(uu.get_name(), r, sub, c);
                    write_Mailboxbinfile(e);
                    MessageBox(0, TEXT("You have successfully Sent the email!!"), TEXT("Success"), 0);
                    e.set_sent(1);
                    func1(hWnd);
                    SetWindowText(hWndEdit1, "");
                    SetWindowText(hWndEdit2, "");
                    SetWindowText(hWndEdit3, "");

                }

            }
            else
            {
                MessageBox(NULL, TEXT("Invalid Username entered!! Enter again"), TEXT("Error"), MB_ICONERROR);
            }

        }

        else if (LOWORD(wParam)==9)
        {

            if(check_usernamebinfile(r)==0 && r[0]!='\0')
            {
                dummy=GetWindowText(hWndEdit2, sub, 50);
                dummy=GetWindowText(hWndEdit3, c, 500);
                if(sub[0]=='\0'&& c[0]=='\0')
                {
                    const int result = MessageBox(NULL, TEXT("Are you sure you want to save to drafts? \n 1. No Subject! \n 2. No Content! "), TEXT("Error"), MB_ICONERROR| MB_YESNOCANCEL);
                    switch (result)
                    {
                    case IDYES:


                        Email_Box e(uu.get_name(), r, sub, c);
                        write_Mailboxbinfile1(e);
                        MessageBox(0, TEXT("You have successfully saved your email to drafts!!"), TEXT("Success"), 0);
                        e.set_sent(0);

                        func2(hWnd);
                        SetWindowText(hWndEdit1, "");
                        SetWindowText(hWndEdit2, "");
                        SetWindowText(hWndEdit3, "");

                        break;


                    }


                }
                else if(sub[0]=='\0'&& c[0]!='\0')
                {
                    const int result = MessageBox(NULL, TEXT("Are you sure you want to save to drafts? \n 1. No Subject! \n"), TEXT("Error"), MB_ICONERROR | MB_YESNOCANCEL);
                    switch (result)
                    {
                    case IDYES:


                        Email_Box e(uu.get_name(), r, sub, c);
                        write_Mailboxbinfile1(e);
                        MessageBox(0, TEXT("You have successfully saved your email to drafts!!"), TEXT("Success"), 0);
                        e.set_sent(0);

                        func2(hWnd);
                        SetWindowText(hWndEdit1, "");
                        SetWindowText(hWndEdit2, "");
                        SetWindowText(hWndEdit3, "");

                        break;


                    }
                }
                else if(sub[0]!='\0'&& c[0]=='\0')
                {
                    const int result = MessageBox(NULL, TEXT("Are you sure you want to save to drafts? \n 1. No Content! \n"), TEXT("Error"), MB_ICONERROR | MB_YESNOCANCEL);
                    switch (result)
                    {
                    case IDYES:


                        Email_Box e(uu.get_name(), r, sub, c);
                        write_Mailboxbinfile1(e);
                        MessageBox(0, TEXT("You have successfully saved your email to drafts!!"), TEXT("Success"), 0);
                        e.set_sent(0);

                        func2(hWnd);
                        SetWindowText(hWndEdit1, "");
                        SetWindowText(hWndEdit2, "");
                        SetWindowText(hWndEdit3, "");

                        break;


                    }
                }
                else
                {

                    Email_Box e(uu.get_name(), r, sub, c);
                    write_Mailboxbinfile1(e);
                    MessageBox(0, TEXT("You have successfully saved your email to drafts!!"), TEXT("Success"), 0);
                    e.set_sent(0);

                    func2(hWnd);
                    SetWindowText(hWndEdit1, "");
                    SetWindowText(hWndEdit2, "");
                    SetWindowText(hWndEdit3, "");

                }

            }
            else
            {
                MessageBox(NULL, TEXT("Invalid Username entered!! Enter again"), TEXT("Error"), MB_ICONERROR);
            }

        }


        else if(LOWORD(wParam)==2)
        {
            SetWindowTextA(hWnd, "SEARCH");
            ShowWindow(hWndEdit1, SW_HIDE);
            ShowWindow(hWndEdit2, SW_HIDE);
            ShowWindow(hWndEdit3, SW_HIDE);
            ShowWindow(hWndStatic1, SW_HIDE);
            ShowWindow(hWndStatic2, SW_HIDE);
            ShowWindow(hWndStatic3, SW_HIDE);
            ShowWindow(hWndEdit4, SW_SHOW);
            ShowWindow(hWndButton1, SW_HIDE);
            ShowWindow(hWndButton3, SW_HIDE);
            ShowWindow(hWndButton9, SW_HIDE);
            ShowWindow(hWndButton10, SW_HIDE);
            ShowWindow(hWndButton11, SW_HIDE);
            ShowWindow(hWndButton12, SW_HIDE);
            ShowWindow(hWndEdit5, SW_HIDE);
            ShowWindow(hWndListbox1, SW_HIDE);
            ShowWindow(hWndListbox2, SW_HIDE);
            ShowWindow(hWndListbox3, SW_HIDE);
            ShowWindow(hWndListbox_Search1, SW_SHOW);
            ShowWindow(hWndListbox_Search2, SW_SHOW);
            SetWindowText(hWndEdit1, "");
            SetWindowText(hWndEdit2, "");
            SetWindowText(hWndEdit3, "");




            //SendMessage(hWndListbox_Search2, LB_RESETCONTENT, 0, 0);
            SetWindowText(hWndEdit5, "");

            User_ID u;

            char here[100];
            here[0]='\0';

            //cout<<store_eno2[0]<<" "<<store_eno2[1]<<endl;
            fstream binfile("USER_DETAILS.dat", ios::binary|ios::in);

            if (!binfile)
            {

                MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);

            }
            else
            {

                //binfile.seekg((long)-(sizeof(u)), ios::cur);

                binfile.read((char*)&u, sizeof(u));



                int k=0;


                while(!binfile.eof())
                {

                    strcpy(here, u.get_name());


                    SendMessage(hWndListbox_Search1, LB_ADDSTRING, 0, (LPARAM)here);
                    store_eno2[k]=u.get_uno();
                    //cout<<store_eno2[k]<<" ";
                    //binfile.seekg((long)-(2*(sizeof(u))), ios::cur);
                    binfile.read((char*)&u, sizeof(u));
                    k++;
                }



            }


            binfile.close();

        }

        else if(LOWORD((wParam)==5))
        {
            //COMPOSE MAIL
            func_composemail(hWnd);

        }
        else if(LOWORD(wParam)==3)
        {
            SetWindowText(hWndEdit1, "");
            SetWindowText(hWndEdit2, "");
            SetWindowText(hWndEdit3, "");
        }
//
//            SetWindowTextA(hWnd, "SENTMAIL-1");
//            ShowWindow(hWndEdit1, SW_HIDE);
//            ShowWindow(hWndEdit2, SW_HIDE);
//            ShowWindow(hWndEdit3, SW_HIDE);
//            ShowWindow(hWndStatic1, SW_HIDE);
//            ShowWindow(hWndStatic2, SW_HIDE);
//            ShowWindow(hWndStatic3, SW_HIDE);
//            ShowWindow(hWndEdit4, SW_SHOW);
//            ShowWindow(hWndButton1, SW_HIDE);
//            ShowWindow(hWndListbox1, SW_HIDE);
//            ShowWindow(hWndEdit5, SW_HIDE);
//            ShowWindow(hWndListbox2, SW_HIDE);
//            ShowWindow(hWndListbox_Search1, SW_HIDE);
//            ShowWindow(hWndListbox_Search2, SW_HIDE);
//            SetWindowText(hWndEdit5, "" );
//
//            Email_Box e;
//
//
//            char here[100000];
//            here[0]='\0';
//            //const char* temp;
//
//
//            fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in|ios::ate);
//
//            if (!binfile){
//                MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
//            }
//            else{
//
//                binfile.seekg((long)-(sizeof(e)), ios::cur);
//
//                binfile.read((char*)&e, sizeof(e));
//
//                const char *p;
//                const char *q;
//
//
//                while(binfile.tellg()>0L){
//                    p=uu.get_name();
//                    q=e.get_sender();
//                    if(strcmp(p,q)==0){
//                        strcat(here, e.get_total_sent());
//                    }
//                    binfile.seekg((long)-(2*(sizeof(e))), ios::cur);
//
//                    binfile.read((char*)&e, sizeof(e));
//
//
//                }
//
//            }
//            binfile.close();
//            const char *sho = here;
//            SetWindowText(hWndEdit4, sho);
//
//        }
        else if(LOWORD(wParam)==6)
        {
            //INBOX

            func_inbox(hWnd);

        }
        //else if(HIWORD(wParam) == LBN_DBLCLK){
        else if(HIWORD(wParam) == LBN_SELCHANGE)
        {


            char temp[1000];
            temp[0]='\0';

            if (LOWORD(wParam) == 20)
            {

                int SelIndex = SendMessage(hWndListbox1, LB_GETCURSEL, 0, 0L);

//              long int len = SendMessage(hWndListbox1, LB_GETTEXT, (WPARAM)(int)(SelIndex), (LPARAM)(LPCTSTR)(temp));

                for(int i=0; i<1000; i++)
                {

                    if(i==SelIndex)
                    {
                        Email_Box e;




                        //SetWindowText(hWndEdit5, "\0");


                        char here[100000];
                        here[0]='\0';
//                        for(int i=0; i<1000; i++){
//                                            cout<<store_eno[i];
//                        }

                        fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in|ios::out);

                        if (!binfile)
                        {
                            MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
                        }
                        else
                        {

                            binfile.read((char*)&e, sizeof(e));


                            while(!binfile.eof())
                            {


                                if(e.get_eno()==store_eno[i])
                                {

                                    if(e.get_read()!=1)
                                    {
                                        e.set_read();
                                        strcpy(here, e.get_total_inbox1());

                                        SendMessage(hWndListbox1, LB_DELETESTRING,(WPARAM) SelIndex, 0);

                                        SendMessage(hWndListbox1, LB_INSERTSTRING, (WPARAM) SelIndex, (LPARAM)here);

                                        //SendMessage(hWndListbox1, LB_DELETESTRING,(WPARAM) SelIndex+1, 0);

                                    }
                                    here[0]='\0';
                                    strcpy(here, e.get_total_inbox());
                                    e.set_read();
                                    binfile.seekp((long)-sizeof(e), ios::cur);
                                    binfile.write((char*)&e, sizeof(e));
                                    binfile.seekg((long)sizeof(e), ios::cur);


                                }
                                binfile.read((char*)&e, sizeof(e));
                            }

                        }
                        binfile.close();
                        const char *sho = here;
                        SetWindowText(hWndEdit5, sho);
                    }
                }


            }

            else if(LOWORD(wParam)==21)
            {

                int SelIndex = SendMessage(hWndListbox2, LB_GETCURSEL, 0, 0L);


//              long int len = SendMessage(hWndListbox1, LB_GETTEXT, (WPARAM)(int)(SelIndex), (LPARAM)(LPCTSTR)(temp));

                for(int i=0; i<1000; i++)
                {

                    if(i==SelIndex)
                    {
                        Email_Box e;
                        char here[100000];
                        here[0]='\0';

                        fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in);

                        if (!binfile)
                        {
                            MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
                        }
                        else
                        {

                            binfile.read((char*)&e, sizeof(e));


                            while(!binfile.eof())
                            {


                                if(e.get_eno()==store_eno1[i])
                                {
                                    strcat(here, e.get_total_sent());
                                }
                                binfile.read((char*)&e, sizeof(e));
                            }


                        }
                        binfile.close();
                        const char *sho = here;
                        SetWindowText(hWndEdit5, sho);
                    }
                }
            }
            else if(LOWORD(wParam)==79)
            {


                int SelIndex = SendMessage(hWndListbox3, LB_GETCURSEL, 0, 0L);


//              long int len = SendMessage(hWndListbox1, LB_GETTEXT, (WPARAM)(int)(SelIndex), (LPARAM)(LPCTSTR)(temp));

                for(int i=0; i<1000; i++)
                {

                    if(i==SelIndex)
                    {

                        Email_Box e;
                        char here[100000];
                        here[0]='\0';

                        fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in);

                        if (!binfile)
                        {
                            MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
                        }
                        else
                        {

                            binfile.read((char*)&e, sizeof(e));


                            while(!binfile.eof())
                            {


                                if(e.get_eno()==store_eno4[i])
                                {
                                    strcat(here, e.get_total_sent());
                                }
                                binfile.read((char*)&e, sizeof(e));

                            }

                        }
                        binfile.close();
                        const char *sho = here;
                        SetWindowText(hWndEdit5, sho);
                    }
                }
            }

            else if(LOWORD(wParam)==29)
            {
                SendMessage(hWndListbox_Search2, LB_RESETCONTENT, 0, 0);
                int SelIndex = SendMessage(hWndListbox_Search1, LB_GETCURSEL, 0, 0L);


//              long int len = SendMessage(hWndListbox1, LB_GETTEXT, (WPARAM)(int)(SelIndex), (LPARAM)(LPCTSTR)(temp));

                for(int i=0; i<1000; i++)
                {
                    if(i==SelIndex)
                    {
                        User_ID u;
                        char here[100000];
                        here[0]='\0';

                        fstream binfile1("USER_DETAILS.dat", ios::binary|ios::in);
                        if (!binfile1)
                        {
                            MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
                        }
                        else
                        {

                            binfile1.read((char*)&u, sizeof(u));


                            while(!binfile1.eof())
                            {


                                if(u.get_uno()==store_eno2[i])
                                {

                                    Email_Box e;

                                    char here[100000];
                                    here[0]='\0';

                                    fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in|ios::ate);

                                    if (!binfile)
                                    {
                                        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
                                    }
                                    else
                                    {
                                        binfile.seekg((long)-(sizeof(e)), ios::cur);

                                        binfile.read((char*)&e, sizeof(e));


                                        const char *p;
                                        const char *q;
                                        int m=0;


                                        while(binfile.tellg()>0L)
                                        {

                                            p=e.get_sender();
                                            // Get length of text in listbox
                                            int textLen = (int) SendMessage(hWndListbox_Search1, LB_GETTEXTLEN, i, 0);

                                            // Allocate buffer to store text (consider +1 for end of string)
                                            TCHAR * textBuffer = new TCHAR[textLen + 1];

                                            // Get actual text in buffer
                                            SendMessage(hWndListbox_Search1, LB_GETTEXT, i, (LPARAM) textBuffer );


                                            if(strcmp(p,textBuffer)==0)
                                            {
                                                if(strcmp(e.get_receiver(),uu.get_name())==0)
                                                {
                                                    strcpy(here, e.get_total_inbox1());
                                                    SendMessage(hWndListbox_Search2, LB_ADDSTRING, 0, (LPARAM)here);
                                                    store_eno3[m]=e.get_eno();
                                                    m++;
                                                }
                                            }
                                            binfile.seekg((long)-(2*(sizeof(e))), ios::cur);

                                            binfile.read((char*)&e, sizeof(e));
                                        }

                                    }
                                    binfile.close();

                                }


                                binfile1.read((char*)&u, sizeof(u));
                            }

                        }
                        binfile1.close();

                    }


                }
            }
            else if(LOWORD(wParam)==78)
            {

                int SelIndex = SendMessage(hWndListbox_Search2, LB_GETCURSEL, 0, 0L);


//              long int len = SendMessage(hWndListbox1, LB_GETTEXT, (WPARAM)(int)(SelIndex), (LPARAM)(LPCTSTR)(temp));

                for(int i=0; i<1000; i++)
                {

                    if(i==SelIndex)
                    {
                        Email_Box e;
                        char here[100000];
                        here[0]='\0';

                        fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in);

                        if (!binfile)
                        {
                            MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
                        }
                        else
                        {

                            binfile.read((char*)&e, sizeof(e));


                            while(!binfile.eof())
                            {


                                if(e.get_eno()==store_eno3[i])
                                {


                                    strcat(here, e.get_total_sent());
                                }
                                binfile.read((char*)&e, sizeof(e));
                            }

                        }
                        binfile.close();
                        const char *sho = here;
                        SetWindowText(hWndEdit4, sho);
                    }
                }
            }

            else
            {

            }


        }
        else if(LOWORD(wParam)==7)
        {
            //SENTMAIL
            func1(hWnd);
        }
        else if(LOWORD(wParam)==8)
        {
            exit(0);
            SetWindowText(hWndEdit1, "");
            SetWindowText(hWndEdit2, "");
            SetWindowText(hWndEdit3, "");
        }
        else if(LOWORD(wParam)==4)
        {
            //DRAFTS
            func2(hWnd);

        }
        else if(LOWORD(wParam)==102)
        {
            //DRAFTS-MODIFY-COMPOSE MAIL

            int SelIndex = SendMessage(hWndListbox3, LB_GETCURSEL, 0, 0L);


            int v=store_eno4[SelIndex];


            func_composemail(hWnd);

            const char *a;
            const char *b;
            const char *c;

            Email_Box e;

            fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in);

            if (!binfile)
            {
                MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
            }
            else
            {


                long recPos=(long)(v-1)*sizeof(e);
                binfile.seekg(recPos);
                binfile.read((char*)&e, sizeof(e));

                a=e.get_receiver();
                b=e.get_subject();
                c=e.get_content();



            }

            binfile.close();

            SetWindowText(hWndEdit1, a);
            SetWindowText(hWndEdit2, b);
            SetWindowText(hWndEdit3, c);


        }
        else if(LOWORD(wParam)==100)
        {
            //INBOX-REPLY-COMPOSE MAIL

            int SelIndex = SendMessage(hWndListbox1, LB_GETCURSEL, 0, 0L);


            int v=store_eno[SelIndex];


            func_composemail(hWnd);

            const char *a;
            char b[1000];
            b[0]='\0';
            strcat(b,"RE: ");

            char c[10000];
            c[0]='\0';
            strcat(c,"\r\n\r\n\r\n\r\n---------------------------Previous email-----------------------------------\r\n");
            Email_Box e;

            fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in);

            if (!binfile)
            {
                MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
            }
            else
            {


                long recPos=(long)(v-1)*sizeof(e);
                binfile.seekg(recPos);
                binfile.read((char*)&e, sizeof(e));

                a=e.get_sender();
                strcat(b,e.get_subject());
                strcat(c,e.get_content());



            }

            binfile.close();

            SetWindowText(hWndEdit1, a);
            SetWindowText(hWndEdit2, b);
            SetWindowText(hWndEdit3, c);


        }
        else if(LOWORD(wParam)==101)
        {
            //INBOX-REPLY-COMPOSE MAIL

            int SelIndex = SendMessage(hWndListbox1, LB_GETCURSEL, 0, 0L);


            int v=store_eno[SelIndex];


            func_composemail(hWnd);

            const char *a;
            char b[1000];
            b[0]='\0';
            strcat(b,"FWD: ");

            char c[10000];
            c[0]='\0';
            strcat(c,"\r\n");
            Email_Box e;

            fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in);

            if (!binfile)
            {
                MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
            }
            else
            {


                long recPos=(long)(v-1)*sizeof(e);
                binfile.seekg(recPos);
                binfile.read((char*)&e, sizeof(e));


                strcat(b,e.get_subject());
                strcat(c,e.get_content());




            }

            binfile.close();


            SetWindowText(hWndEdit2, b);
            SetWindowText(hWndEdit3, c);
            MessageBox(0, TEXT("Enter Username to forward to"), TEXT("Success"), 0);


        }



        else
        {

        }
        break;

    case WM_TIMER:

        if(LOWORD(wParam)==37)
        {

            SetWindowText(hWndEdit6," ");
            Email_Box e;

            fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in);

            if (!binfile)
            {
                MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
            }
            else
            {

                binfile.read((char*)&e, sizeof(e));


                int k=0;
                while(!binfile.eof())
                {


                    if(e.get_read()==0&&strcmp(e.get_receiver(),uu.get_name())==0&&e.get_sent()==1)
                    {
                        k++;

                    }
                    binfile.read((char*)&e, sizeof(e));
                }

                string Result;//string which will contain the result

                std::stringstream convert; // stringstream used for the conversion

                convert << k;//add the value of Number to the characters in the stream

                Result = convert.str();//set Result to the content of the stream


                char here[100];
                here[0]='\0';
                strcat(here,"You have ");
                strcat(here,Result.c_str());
                strcat(here," unread emails ");
                const char *sho = here;
                SetWindowText(hWndEdit6,"");
                SetWindowText(hWndEdit6,sho );
            }
            binfile.close();

        }



        break;
    case WM_DESTROY:
        PostQuitMessage(EXIT_SUCCESS);
        break;
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);

        return FALSE;
    }

}

/*
BOOL WINAPI EnableWindow(HWND  hWndEdit1, BOOL=1);

const int result = MessageBox(NULL, TEXT("You have successfully Sent the email!!"), TEXT("Error"), MB_ICONERROR| MB_YESNOCANCEL);

                switch (result)
                {
                case IDYES:
                // Do something
                break;
                case IDNO:
                // Do something
                break;
                case IDCANCEL:
                // Do something
                break;
                }

*/

void func1(HWND hWnd)
{
    SetWindowTextA(hWnd, "SENTMAIL");
    ShowWindow(hWndEdit1, SW_HIDE);
    ShowWindow(hWndEdit2, SW_HIDE);
    ShowWindow(hWndEdit3, SW_HIDE);
    ShowWindow(hWndStatic1, SW_HIDE);
    ShowWindow(hWndStatic2, SW_HIDE);
    ShowWindow(hWndStatic3, SW_HIDE);
    ShowWindow(hWndEdit4, SW_HIDE);
    ShowWindow(hWndButton1, SW_HIDE);
    ShowWindow(hWndButton3, SW_HIDE);
    ShowWindow(hWndButton9, SW_HIDE);
    ShowWindow(hWndButton10, SW_HIDE);
    ShowWindow(hWndButton11, SW_HIDE);
    ShowWindow(hWndButton12, SW_HIDE);
    ShowWindow(hWndEdit5, SW_SHOW);
    ShowWindow(hWndListbox3, SW_HIDE);
    ShowWindow(hWndListbox1, SW_HIDE);
    ShowWindow(hWndListbox2, SW_SHOW);
    ShowWindow(hWndListbox_Search1, SW_HIDE);
    ShowWindow(hWndListbox_Search2, SW_HIDE);
    SetWindowText(hWndEdit1, "");
    SetWindowText(hWndEdit2, "");
    SetWindowText(hWndEdit3, "");

    SendMessage(hWndListbox2, LB_RESETCONTENT, 0, 0);
    SetWindowText( hWndEdit5, "");

    Email_Box e;

    char here[100000];
    here[0]='\0';

    fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in|ios::ate);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.seekg((long)-(sizeof(e)), ios::cur);

        binfile.read((char*)&e, sizeof(e));


        const char *p;
        const char *q;
        int i=0;


        while(binfile.tellg()>0L)
        {

            p=uu.get_name();
            q=e.get_sender();

            if(strcmp(p,q)==0)
            {
                if(e.get_sent()==1)
                {
                    strcpy(here, e.get_total_sentmail1());
                    SendMessage(hWndListbox2, LB_ADDSTRING, 0, (LPARAM)here);
                    store_eno1[i]=e.get_eno();

                    i++;
                }
            }
            binfile.seekg((long)-(2*(sizeof(e))), ios::cur);

            binfile.read((char*)&e, sizeof(e));
        }

    }
    binfile.close();


}

void func2(HWND hWnd)
{
    SetWindowTextA(hWnd, "DRAFTS");
    ShowWindow(hWndEdit1, SW_HIDE);
    ShowWindow(hWndEdit2, SW_HIDE);
    ShowWindow(hWndEdit3, SW_HIDE);
    ShowWindow(hWndStatic1, SW_HIDE);
    ShowWindow(hWndStatic2, SW_HIDE);
    ShowWindow(hWndStatic3, SW_HIDE);
    ShowWindow(hWndEdit4, SW_HIDE);
    ShowWindow(hWndButton1, SW_HIDE);
    ShowWindow(hWndButton3, SW_HIDE);
    ShowWindow(hWndButton9, SW_HIDE);
    ShowWindow(hWndButton10, SW_HIDE);
    ShowWindow(hWndButton11, SW_HIDE);
    ShowWindow(hWndButton12, SW_SHOW);
    ShowWindow(hWndListbox1, SW_HIDE);
    ShowWindow(hWndEdit5, SW_SHOW);
    ShowWindow(hWndListbox2, SW_HIDE);
    ShowWindow(hWndListbox3, SW_SHOW);
    ShowWindow(hWndListbox_Search1, SW_HIDE);
    ShowWindow(hWndListbox_Search2, SW_HIDE);
    SetWindowText(hWndEdit1, "");
    SetWindowText(hWndEdit2, "");
    SetWindowText(hWndEdit3, "");

    SendMessage(hWndListbox3, LB_RESETCONTENT, 0, 0);
    SetWindowText( hWndEdit5, "");

    Email_Box e;

    char here[100000];
    here[0]='\0';

    fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in|ios::ate);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.seekg((long)-(sizeof(e)), ios::cur);

        binfile.read((char*)&e, sizeof(e));


        const char *p;
        const char *q;
        int i=0;


        while(binfile.tellg()>0L)
        {

            p=uu.get_name();
            q=e.get_sender();

            if(strcmp(p,q)==0)
            {
                if(e.get_sent()==0)
                {
                    strcpy(here, e.get_total_sentmail1());
                    SendMessage(hWndListbox3, LB_ADDSTRING, 0, (LPARAM)here);
                    store_eno4[i]=e.get_eno();

                    i++;
                }
            }
            binfile.seekg((long)-(2*(sizeof(e))), ios::cur);

            binfile.read((char*)&e, sizeof(e));
        }

    }
    binfile.close();


}

void func_composemail(HWND hWnd)
{
    SetWindowTextA(hWnd, "COMPOSE MAIL");
    ShowWindow(hWndEdit1, SW_SHOW);
    ShowWindow(hWndEdit2, SW_SHOW);
    ShowWindow(hWndEdit3, SW_SHOW);
    ShowWindow(hWndStatic1, SW_SHOW);
    ShowWindow(hWndStatic2, SW_SHOW);
    ShowWindow(hWndStatic3, SW_SHOW);
    ShowWindow(hWndEdit4, SW_HIDE);
    ShowWindow(hWndButton1, SW_SHOW);
    ShowWindow(hWndButton3, SW_SHOW);
    ShowWindow(hWndButton9, SW_SHOW);
    ShowWindow(hWndButton10, SW_HIDE);
    ShowWindow(hWndButton11, SW_HIDE);
    ShowWindow(hWndButton12, SW_HIDE);
    ShowWindow(hWndListbox1, SW_HIDE);
    ShowWindow(hWndEdit5, SW_HIDE);
    ShowWindow(hWndListbox2, SW_HIDE);
    ShowWindow(hWndListbox3, SW_HIDE);
    ShowWindow(hWndListbox_Search1, SW_HIDE);
    ShowWindow(hWndListbox_Search2, SW_HIDE);
    SetWindowText( hWndEdit5, "" );
    SetWindowText(hWndEdit1, "");
    SetWindowText(hWndEdit2, "");
    SetWindowText(hWndEdit3, "");


}

void func_inbox(HWND hWnd)
{
    SetWindowTextA(hWnd, "INBOX");
    ShowWindow(hWndEdit1, SW_HIDE);
    ShowWindow(hWndEdit2, SW_HIDE);
    ShowWindow(hWndEdit3, SW_HIDE);
    ShowWindow(hWndStatic1, SW_HIDE);
    ShowWindow(hWndStatic2, SW_HIDE);
    ShowWindow(hWndStatic3, SW_HIDE);
    ShowWindow(hWndEdit4, SW_HIDE);
    ShowWindow(hWndButton1, SW_HIDE);
    ShowWindow(hWndButton3, SW_HIDE);
    ShowWindow(hWndButton9, SW_HIDE);
    ShowWindow(hWndButton10, SW_SHOW);
    ShowWindow(hWndButton11, SW_SHOW);
    ShowWindow(hWndButton12, SW_HIDE);
    ShowWindow(hWndListbox1, SW_SHOW);
    ShowWindow(hWndEdit5, SW_SHOW);
    ShowWindow(hWndListbox2, SW_HIDE);
    ShowWindow(hWndListbox3, SW_HIDE);
    ShowWindow(hWndListbox_Search1, SW_HIDE);
    ShowWindow(hWndListbox_Search2, SW_HIDE);
    SetWindowText(hWndEdit1, "");
    SetWindowText(hWndEdit2, "");
    SetWindowText(hWndEdit3, "");


    SendMessage(hWndListbox1, LB_RESETCONTENT, 0, 0);
    SetWindowText( hWndEdit5, "" );

    Email_Box e;

    char here[100000];
    here[0]='\0';

    fstream binfile("EMAILS-SENT.dat", ios::binary|ios::in|ios::ate);

    if (!binfile)
    {
        MessageBox(0, TEXT("Error attempting to open file"), TEXT("Success"), 0);
    }
    else
    {
        binfile.seekg((long)-(sizeof(e)), ios::cur);

        binfile.read((char*)&e, sizeof(e));


        const char *p;
        const char *q;
        int i=0;


        while(binfile.tellg()>0L)
        {

            p=uu.get_name();
            q=e.get_receiver();

            if(strcmp(p,q)==0)
            {
                if(e.get_sent()==1)
                {
                    if(e.get_read()==1)
                    {
                        strcpy(here, e.get_total_inbox1());
                        SendMessage(hWndListbox1, LB_ADDSTRING, 0, (LPARAM)here);
                        store_eno[i]=e.get_eno();
                    }
                    else
                    {
                        strcpy(here, e.get_total_inbox1());
                        strcat(here, "  **");
                        SendMessage(hWndListbox1, LB_ADDSTRING, 0, (LPARAM)here);
                        store_eno[i]=e.get_eno();

                    }
                    i++;
                }
            }
            binfile.seekg((long)-(2*(sizeof(e))), ios::cur);

            binfile.read((char*)&e, sizeof(e));
        }

    }
    binfile.close();
}









































