#include "../hpp/Coulist.hpp"
#include "../hpp/Stulist.hpp"
#include "../hpp/Manager.hpp"
#include "../hpp/Student.hpp"
#include "../hpp/People.hpp"
#include "../hpp/Course.hpp"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

void welcome();
void stuidentity();
void manidentity();
void stuwelcome();
void manwelcome();
void ifsort();

int main()
{
    welcome();
    Stulist stulist;
    Coulist coulist;
    ifstream inStudent("../txt/Student.txt");
    ifstream inCourse("../txt/Course.txt");
    ifstream inManager("../txt/Manager.txt");
    string num,pw;
    while(inStudent >> num >> pw){
        stulist.addstu(num,pw);
    }
    inStudent.close();
    while(inCourse >> num >> pw){
        
    }
    int choice_1;
    while(cin >> choice_1 and choice_1 != 0){
        switch(choice_1){
            case 1:
                if(stulist.stuidentity() == true)
                    stuwelcome();
                else
                    cout << "ѧ�Ż��������" << endl;
                break;
            case 2:
                manwelcome();
                break;
        }
    }
    return 0;
}
void welcome(){
    system("cls");
    cout << "  W       W        EEEEEEEE       L             CCCCCCCC       OOOOOOOO            M           M     EEEEEEEE" << endl;
    cout << "  W       W        E              L           C               O        O          M M       M  M     E        " << endl;
    cout << "  W       W        E              L          C               O          O        M   M   M    M      E         " << endl;
    cout << "  W   W   W        EEEEEEE        L          C              O            O      M     M      M       EEEEEEE  " << endl;
    cout << "  W  W W  W        E              L          C               O          O      M            M        E           " << endl;
    cout << "  W W   W W        E              L           C               O        O      M            M         E            " << endl;
    cout << "  WW     WW        EEEEEEEE       LLLLLLL      CCCCCCCC        OOOOOOOO      M            M          EEEEEEEE      " << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           ��ӭ����ѧУ���β�ѯϵͳ                 |" << endl;
    cout << "                            |           1.ѧ����½                               |" << endl;
    cout << "                            |           2.����Ա��¼                             |" << endl;
    cout << "                            |                                                    |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                         ��ѡ��(1/2,-1Ϊ����):" << endl;
}
void stuwelcome(){
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           ��ӭ����ѧУ���β�ѯϵͳ                 |" << endl;
    cout << "                            |           1.ѡ��                                   |" << endl;
    cout << "                            |           2.�˿�                                   |" << endl;
    cout << "                            |           3.��Ѱ�γ�                               |" << endl;
    cout << "                            |           4.�γ�����                               |" << endl;
    cout << "                            |           5.������һ��                             |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
}
void manwelcome(){
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           ��ӭ����ѧУ���β�ѯϵͳ                 |" << endl;
    cout << "                            |           1.��ӿγ�                               |" << endl;
    cout << "                            |           2.ɾ���γ�                               |" << endl;
    cout << "                            |           3.�޸Ŀγ�                               |" << endl;
    cout << "                            |           4.��Ѱ�γ�                               |" << endl;
    cout << "                            |           5.������һ��                             |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
}