#ifndef MANAGER_HPP
#define MANAGER_HPP
#include <string>
using namespace std;
class Manager{
    public:
        Manager(string numv = "",string pwv = ""):num(numv),pw(pwv){};//���캯��
        bool manageridentity();//����Ա�����֤
        string getnum(){return num;}//��ȡ����
        string getpw(){return pw;}//��ȡ����
    private:
        string num;//����
        string pw;//����
};
#endif