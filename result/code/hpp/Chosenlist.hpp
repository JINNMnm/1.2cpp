#ifndef CHOSENLIST_HPP
#define CHOSENLIST_HPP
#include "Chosen.hpp"

class Chosenlist{
    public:
        Chosenlist();//构造函数
        bool addchosen(int bhv);//添加课程
        bool delchosen(int bhv);//按照课程编号删除课程

        int getsize(){return size;}//获取已选课程数量
        int getmaxsize(){return maxsize;}//获取最大选课数量
        Chosen* gethead(){return head;}//获取头指针
    private:
        int maxsize;
        Chosen* head;
        int size;
};
#endif