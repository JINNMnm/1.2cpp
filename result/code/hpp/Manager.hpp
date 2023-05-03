#ifndef MANAGER_HPP
#define MANAGER_HPP
#include <string>
using namespace std;
class Manager{
    public:
        Manager(string numv = "",string pwv = ""):num(numv),pw(pwv){};//构造函数
        bool manageridentity();//管理员身份认证
        string getnum(){return num;}//获取工号
        string getpw(){return pw;}//获取密码
    private:
        string num;//工号
        string pw;//密码
};
#endif