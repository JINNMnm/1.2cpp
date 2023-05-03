#include "../hpp/Student.hpp"
#include "../hpp/Coulist.hpp"
#include "../hpp/Course.hpp"
#include <iostream>
#include <algorithm>
using namespace std;


void Student::showchosen(){
    //查看已选课程编号
    sort(chosen,chosen + numofchosen);//排序
    if(numofchosen == 0) 
        cout << "你目前一门课都没选" << endl;
    else{
        cout << "以下是你的已选课程的编号:" << endl;
        for(int i = 0;i < numofchosen;i++){
            cout << chosen[i] << ' ';
        }
        cout << endl;
    }
}

void Student::addchosen(const Coulist& coulist){
    //在已有课程中选课，加入const以防止修改courlist
    if(numofchosen == 10){
        cout << "你已经选了10门课了,不能再选了" << endl;
        return ;
    }
    this->showchosen();
    int bhv;
    cout << "请输入要选的课程编号:" << endl;
    cin >> bhv;
    for(int i = 0;i < numofchosen;i++){
        if(chosen[i] == bhv){
            cout << "你已经选了这门课了" << endl;
            return ;
        }
    }
    if(coulist.findbh(bhv) == NULL){
        return ;
    }
    chosen[numofchosen++] = bhv;
    cout << "选课成功" << endl;
    this->showchosen();
}

void Student::delchosen(int bhv){
    //退出编号为bhv的课
    int i;
    for(i = 0;i < numofchosen;i++){
        if(chosen[i] == bhv){
            for(int j = i;j < numofchosen - 1;j++){
                chosen[j] = chosen[j+1];
            }
            break;
        }
    }
    if(i == numofchosen){
        cout << "你没有选这门课" << endl;
        return ;
    }
    numofchosen--;//退课成功,已选课程数量减一
    cout << "退课成功" << endl;
    this->showchosen();
}

void Student::del_nonecourse(const Coulist& coulist){
    //删除在coulist已经不存在，但是该学生已经选了的课程
    for(int i = 0;i < numofchosen;i++){
        if(coulist.findbh(chosen[i]) == NULL){
            delchosen(chosen[i]);
        }
    }
    return;
}