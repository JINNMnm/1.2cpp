#ifndef MANAGER_HPP
#define MANAGER_HPP
#include <string>
using namespace std;
class Manager{
    public:
        Manager(string numv = "",string pwv = ""):num(numv),pw(pwv){};
        bool manageridentity();//����Ա�����֤
        string getnum(){return num;}
        string getpw(){return pw;}
    private:
        string num;//����
        string pw;//����
};
#endif