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
                    cout << "学号或密码错误" << endl;
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
    cout << "                            |           欢迎进入学校开课查询系统                 |" << endl;
    cout << "                            |           1.学生登陆                               |" << endl;
    cout << "                            |           2.管理员登录                             |" << endl;
    cout << "                            |                                                    |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                         请选择(1/2,-1为结束):" << endl;
}
void stuwelcome(){
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           欢迎进入学校开课查询系统                 |" << endl;
    cout << "                            |           1.选课                                   |" << endl;
    cout << "                            |           2.退课                                   |" << endl;
    cout << "                            |           3.查寻课程                               |" << endl;
    cout << "                            |           4.课程评价                               |" << endl;
    cout << "                            |           5.返回上一级                             |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
}
void manwelcome(){
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           欢迎进入学校开课查询系统                 |" << endl;
    cout << "                            |           1.添加课程                               |" << endl;
    cout << "                            |           2.删除课程                               |" << endl;
    cout << "                            |           3.修改课程                               |" << endl;
    cout << "                            |           4.查寻课程                               |" << endl;
    cout << "                            |           5.返回上一级                             |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
}