#include "../hpp/Coulist.hpp"
#include "../hpp/Stulist.hpp"
#include "../hpp/Manager.hpp"
#include "../hpp/Student.hpp"
#include "../hpp/Course.hpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void welcome();
void stuidentity();
void manidentity();
void stuwelcome();
void manwelcome();
void howsort();
void howfind();
void bye();

int main()
{

    Stulist stulist;
    Coulist coulist;
    ifstream inStudent("../txt/Student.txt");
    ifstream inCourse("../txt/Course.txt");
    ifstream inManager("../txt/Manager.txt");
    string numv, pwv, collegev, namev, teacherv, catagoryv;
    int bhv, assessmentv, creditv,numofchosenv,chosenv[10];
    while (inStudent >> numv >> pwv >> numofchosenv)
    {
        for(int i = 0;i < numofchosenv;i++) inStudent >> chosenv[i];
        stulist.addstu(numv, pwv,numofchosenv,chosenv);
    }
    inStudent.close(); //学生和课程信息读取完毕
    while (inCourse >> bhv >> namev >> teacherv >> creditv >> catagoryv >> collegev >> assessmentv)
    {
        coulist.addcourse(bhv, namev, teacherv, creditv, catagoryv, collegev, assessmentv);
    }
    inCourse.close();           //学生和课程信息读取完毕
    inManager >> numv >> pwv;   //输入管理员账号密码
    Manager manager(numv, pwv); //创建管理员对象,此项目只有唯一管理员
    inManager.close();          //管理员账号密码输入完毕

    int choice_1, choice_2, wrongtime = 0; //设置用户选项、错误次数

out1:
    welcome();
    while (cin >> choice_1)
    
    {
        switch (choice_1)
        {
            case 1:{
                Student *target = stulist.stuidentity(); //认证并储存身份
                while (target == NULL)
                {
                    cout << "学号或密码错误" << endl
                        << endl;
                    system("pause");
                    target = stulist.stuidentity();
                    wrongtime++;
                    if (wrongtime == 3)
                    {
                        cout << "错误次数过多,请稍后再试" << endl;
                        system("pause");
                        goto out1;
                    }
                }              //学生身份认证
                wrongtime = 0; //错误次数清零
                out2:
                target->del_nonecourse(coulist);
                stuwelcome();
                cin >> choice_2;
                switch (choice_2)
                {
                case 1:
                    //选课
                    target->addchosen(coulist);
                    system("pause");
                    goto out2;
                    break;
                case 2:
                    //退课
                    target->showchosen();
                    if(target->getnumofchosen() == 0)
                    {
                        cout << "您还没有选课,请输入任意值返回上一界面" << endl;
                        system("pause");
                        goto out2;
                    }
                    cout << "请输入要退的课程编号" << endl;
                    cin >> bhv;
                    target->delchosen(bhv);
                    system("pause");
                    goto out2;
                    break;
                case 3:
                    //查询课程
                    howfind();
                    if (!coulist.findcourse())
                    {
                        //查找，如果没找到就执行if，返回上一个界面
                        cout << "输入任意值返回上一界面" << endl;
                        system("pause");
                        goto out2;
                    }
                    system("pause");
                    goto out2;
                    break;
                case 4:
                    //课程评价
                    if (!coulist.find_and_assesscourse())
                    {
                        cout << "评价失败,请输入任意值返回上一界面" << endl;
                        system("pause");
                    }
                    goto out2;
                    break;
                case 5:
                    //查看已选课程
                    target->showchosen();
                    system("pause");
                    goto out2;
                case 6:
                    //重新登陆
                    goto out1;
                default:
                    cout << "输入错误,请重新输入" << endl;
                    break;
                }
                break;
            }
            case 2:{
                while(!manager.manageridentity())
                {
                    cout << "账号或密码错误" << endl;
                    system("pause");
                    wrongtime++;
                    if (wrongtime == 3)
                    {
                        cout << "错误次数过多,请稍后再试" << endl;
                        system("pause");
                        goto out1;
                    }
                }
                wrongtime = 0; //错误次数清零
                out3:
                manwelcome();
                cin >> choice_2;
                switch (choice_2)
                {
                case 1:
                    //添加课程
                    system("cls");
                    cout << "目前已有的课程信息如下,共" << coulist.getsize() << "节：" << endl;
                    coulist.showcourse();
                    cout << "请按以下顺序输入课程信息：课程编号 课程名称 任课教师 学分 课程类别 开课学院 课程评价" << endl;
                    cin >> bhv >> namev >> teacherv >> creditv >> catagoryv >> collegev >> assessmentv;
                    coulist.addcourse(bhv, namev, teacherv, creditv, catagoryv, collegev, assessmentv);
                    cout << endl << "加课成功,共" << coulist.getsize() << "节,以下是加课后的课程信息汇总" << endl << endl;
                    coulist.showcourse();
                    system("pause");
                    goto out3;
                    break;
                case 2:
                    //删除课程
                    system("cls");
                    cout << "目前已有的课程信息如下, 共" << coulist.getsize() << "节：" << endl;
                    coulist.showcourse();
                    cout << "请输入要删除的课程编号" << endl;
                    cin >> bhv;
                    if (!coulist.delcourse(bhv))
                    {
                        cout << "删除失败!因为您提供的课程不存在" << endl;
                        system("pause");
                        goto out3;
                    }
                    cout << endl << "删课成功,共" << coulist.getsize() << "节,以下是删课后的课程信息汇总" << endl << endl;
                    coulist.showcourse();
                    system("pause");
                    goto out3;
                    break;
                case 3:
                    //修改课程
                    system("cls");
                    cout << "目前已有的课程信息如下,共" << coulist.getsize() << "节：" << endl;
                    coulist.showcourse();
                    cout << "请输入要修改的课程编号" << endl;
                    cin >> bhv;
                    if (!coulist.modifycourse(bhv))
                    {
                        cout << "修改失败!因为您提供的课程不存在" << endl;
                        system("pause");
                        goto out3;
                    }
                    cout << endl << "修改成功,共" << coulist.getsize() << "节,以下是修改后的课程信息汇总" << endl << endl;
                    coulist.showcourse();
                    system("pause");
                    goto out3;
                    break;
                case 4:{
                    //查询课程
                    howfind();
                    if (!coulist.findcourse())
                    {
                        //查找，如果没找到就执行if，返回上一个界面
                        cout << "输入任意值返回上一界面" << endl;
                        system("pause");
                        goto out3;
                    }
                    system("pause");
                    goto out3;
                    break;
                }
                case 5:{
                    //排序课程
                    howsort();
                    if (!coulist.sortcourse())
                    {
                        cout << "排序失败,请输入任意值返回上一界面" << endl;
                        system("pause");
                    }
                    system("pause");
                    goto out3;
                }
                case 6:
                    //重新登陆
                    goto out1;
                default:
                    cout << "输入错误,请重新输入" << endl;
                    goto out3;
                    break;
                }
                break;
            }
            case 3:{
                bye();
                system("pause");
                stulist.write();
                coulist.write();
                return 0;
            }
            default:{
                cout << "输入错误,请重新输入" << endl;
                break;
            }
        }
    }
    return 0;
}
void welcome()
{
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
    cout << "                            |           3.关闭系统                               |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                         请选择(1/2/3):" << endl;
}
void stuwelcome()
{
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           欢迎进入学校开课查询系统                 |" << endl;
    cout << "                            |           1.选课                                   |" << endl;
    cout << "                            |           2.退课                                   |" << endl;
    cout << "                            |           3.查寻课程                               |" << endl;
    cout << "                            |           4.课程评价                               |" << endl;
    cout << "                            |           5.查看已选课程编号                       |" << endl;
    cout << "                            |           6.退出登陆                               |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                         请选择(1/2/3/4/5/6):" << endl;
}
void manwelcome()
{
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           欢迎进入学校开课查询系统                 |" << endl;
    cout << "                            |           1.添加课程                               |" << endl;
    cout << "                            |           2.删除课程                               |" << endl;
    cout << "                            |           3.修改课程                               |" << endl;
    cout << "                            |           4.查寻课程                               |" << endl;
    cout << "                            |           5.排序课程                               |" << endl;
    cout << "                            |           6.退出登录                               |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                         请选择(1/2/3/4/5/6):" << endl;
}
void howfind()
{
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           欢迎进入学校开课查询系统                 |" << endl;
    cout << "                            |           1.按课程编号                             |" << endl;
    cout << "                            |           2.按课程名称                             |" << endl;
    cout << "                            |           3.按课程教师                             |" << endl;
    cout << "                            |           4.按课程学院                             |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                         请选择(1/2/3/4):" << endl;
}

void howsort()
{
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           欢迎进入学校开课查询系统                 |" << endl;
    cout << "                            |           1.按课程学分排序                         |" << endl;
    cout << "                            |           2.按课程学院排序                         |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                                请选择(1/2):" << endl;
}

void bye(){
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           感谢使用学校开课查询系统~                  |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
}