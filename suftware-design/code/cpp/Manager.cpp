#include "../hpp/Manager.hpp"
#include <iostream>
#include <string>
using namespace std;

bool Manager::manageridentity(){
    //管理员身份认证
    system("cls");
    string num,pw;
    cout << "请输入工号:" << endl;
    cin >> num;
    cout << "(区分大小写)请输入密码:" << endl;
    cin >> pw;
    if(num == this->num && pw == this->pw)
        return true;
    else
        return false;
}