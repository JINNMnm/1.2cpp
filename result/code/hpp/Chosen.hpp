#ifndef CHOSEN_HPP
#define CHOSEN_HPP

class Chosen{
    public:
        Chosen* next;
        Chosen();//���캯��
        Chosen(int bhv):bh(bhv){}//�������Ĺ��캯��

        int getbh(){return bh;}//��ȡ�γ̱��
    private:
        int bh;
};
#endif