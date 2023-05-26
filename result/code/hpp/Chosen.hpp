#ifndef CHOSEN_HPP
#define CHOSEN_HPP

class Chosen{
    public:
        Chosen* next;
        Chosen();//构造函数
        Chosen(int bhv):bh(bhv){}//带参数的构造函数

        int getbh(){return bh;}//获取课程编号
    private:
        int bh;
};
#endif