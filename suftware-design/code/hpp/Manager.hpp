#ifndef MANAGER_HPP
#define MANAGER_HPP
#include <string>
using namespace std;
class Manager{
    public:
        Manager(string numv = "",string pwv = ""):num(numv),pw(pwv){};
        bool manageridentity();//管理员身份认证
        string getnum(){return num;}
        string getpw(){return pw;}
    private:
        string num;//工号
        string pw;//密码
};
#endif