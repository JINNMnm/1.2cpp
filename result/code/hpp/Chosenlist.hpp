#ifndef CHOSENLIST_HPP
#define CHOSENLIST_HPP
#include "Chosen.hpp"

class Chosenlist{
    public:
        Chosenlist();//���캯��
        bool addchosen(int bhv);//��ӿγ�
        bool delchosen(int bhv);//���տγ̱��ɾ���γ�

        int getsize(){return size;}//��ȡ��ѡ�γ�����
        int getmaxsize(){return maxsize;}//��ȡ���ѡ������
        Chosen* gethead(){return head;}//��ȡͷָ��
    private:
        int maxsize;
        Chosen* head;
        int size;
};
#endif