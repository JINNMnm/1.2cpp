#include "../hpp/Manager.hpp"
#include <iostream>
#include <string>
using namespace std;

bool Manager::manageridentity(){
    //����Ա�����֤
    system("cls");
    string num,pw;
    cout << "�����빤��:" << endl;
    cin >> num;
    cout << "(���ִ�Сд)����������:" << endl;
    cin >> pw;
    if(num == this->num && pw == this->pw)
        return true;
    else
        return false;
}