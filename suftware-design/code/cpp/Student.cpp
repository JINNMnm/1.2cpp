#include "../hpp/Student.hpp"
#include <iostream>
using namespace std;


void Student::showchosen(){
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

void Student::addchosen(){
    this->showchosen();
    int numv;
    cout << "请输入要选的课程编号:" << endl;
    cin >> numv;
    chosen[numofchosen++] = numv;
    cout << "选课成功" << endl;
    this->showchosen();
}

void Student::delchosen(){
    if(numofchosen == 0) {cout << "你没得退了兄弟" << endl;return ;}
    this->showchosen();
    numofchosen--;
    int numv,i;
    cout << "请输入要退的课程编号" << endl;
    cin >> numv;
    for(i = 0;i < numofchosen;i++){
        if(chosen[i] == numv){
            for(int j = i;j < numofchosen;j++){
                chosen[j] = chosen[j+1];
            }
            break;
        }
    }
    if(i == numofchosen){
        cout << "你没有选这门课" << endl;
        return ;
    }
    cout << "退课成功" << endl;
    this->showchosen();
}