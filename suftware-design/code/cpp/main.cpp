#include "Course.hpp"
#include "Student.hpp"
#include "Coulist.hpp"
#include "Stulist.hpp"
#include "Manager.hpp"
#include "Student.hpp"
#include <iostream>
using namespace std;
void welcome();
int main()
{
    welcome();
    Stulist stulist;
    return 0;
}
void welcome(){
    cout << "  W       W        EEEEEEEE       L             CCCCCCCC       OOOOOOOO            M           M    EEEEEEEE" << endl;
    cout << "  W       W        E              L           C               O        O          M M       M  M     E        " << endl;
    cout << "  W       W        E              L          C               O          O        M   M   M    M      E         " << endl;
    cout << "  W   W   W        EEEEEEE        L          C              O            O      M     M      M       EEEEEEE  " << endl;
    cout << "  W  W W  W        E              L          C               O          O      M            M       E           " << endl;
    cout << "  W W   W W        E              L           C               O        O      M            M        E            " << endl;
    cout << "  WW     WW        EEEEEEEE       LLLLLLL      CCCCCCCC        OOOOOOOO      M            M         EEEEEEEE      " << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           ��ӭ����ѧУ���β�ѯϵͳ                 |" << endl;
    cout << "                            |           1.��ѯ������Ϣ                           |" << endl;
    cout << "                            |           2.���ߵ�¼                               |" << endl;
    cout << "                            |           3.����Ա��¼                             |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                         ��ѡ��(1/2/3,-1Ϊ����):";
}