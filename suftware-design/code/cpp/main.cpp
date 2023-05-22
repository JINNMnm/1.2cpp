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
    inStudent.close(); //ѧ���Ϳγ���Ϣ��ȡ���
    while (inCourse >> bhv >> namev >> teacherv >> creditv >> catagoryv >> collegev >> assessmentv)
    {
        coulist.addcourse(bhv, namev, teacherv, creditv, catagoryv, collegev, assessmentv);
    }
    inCourse.close();           //ѧ���Ϳγ���Ϣ��ȡ���
    inManager >> numv >> pwv;   //�������Ա�˺�����
    Manager manager(numv, pwv); //��������Ա����,����Ŀֻ��Ψһ����Ա
    inManager.close();          //����Ա�˺������������

    int choice_1, choice_2, wrongtime = 0; //�����û�ѡ��������

out1:
    welcome();
    while (cin >> choice_1)
    
    {
        switch (choice_1)
        {
            case 1:{
                Student *target = stulist.stuidentity(); //��֤���������
                while (target == NULL)
                {
                    cout << "ѧ�Ż��������" << endl
                        << endl;
                    system("pause");
                    target = stulist.stuidentity();
                    wrongtime++;
                    if (wrongtime == 3)
                    {
                        cout << "�����������,���Ժ�����" << endl;
                        system("pause");
                        goto out1;
                    }
                }              //ѧ�������֤
                wrongtime = 0; //�����������
                out2:
                target->del_nonecourse(coulist);
                stuwelcome();
                cin >> choice_2;
                switch (choice_2)
                {
                case 1:
                    //ѡ��
                    target->addchosen(coulist);
                    system("pause");
                    goto out2;
                    break;
                case 2:
                    //�˿�
                    target->showchosen();
                    if(target->getnumofchosen() == 0)
                    {
                        cout << "����û��ѡ��,����������ֵ������һ����" << endl;
                        system("pause");
                        goto out2;
                    }
                    cout << "������Ҫ�˵Ŀγ̱��" << endl;
                    cin >> bhv;
                    target->delchosen(bhv);
                    system("pause");
                    goto out2;
                    break;
                case 3:
                    //��ѯ�γ�
                    howfind();
                    if (!coulist.findcourse())
                    {
                        //���ң����û�ҵ���ִ��if��������һ������
                        cout << "��������ֵ������һ����" << endl;
                        system("pause");
                        goto out2;
                    }
                    system("pause");
                    goto out2;
                    break;
                case 4:
                    //�γ�����
                    if (!coulist.find_and_assesscourse())
                    {
                        cout << "����ʧ��,����������ֵ������һ����" << endl;
                        system("pause");
                    }
                    goto out2;
                    break;
                case 5:
                    //�鿴��ѡ�γ�
                    target->showchosen();
                    system("pause");
                    goto out2;
                case 6:
                    //���µ�½
                    goto out1;
                default:
                    cout << "�������,����������" << endl;
                    break;
                }
                break;
            }
            case 2:{
                while(!manager.manageridentity())
                {
                    cout << "�˺Ż��������" << endl;
                    system("pause");
                    wrongtime++;
                    if (wrongtime == 3)
                    {
                        cout << "�����������,���Ժ�����" << endl;
                        system("pause");
                        goto out1;
                    }
                }
                wrongtime = 0; //�����������
                out3:
                manwelcome();
                cin >> choice_2;
                switch (choice_2)
                {
                case 1:
                    //��ӿγ�
                    system("cls");
                    cout << "Ŀǰ���еĿγ���Ϣ����,��" << coulist.getsize() << "�ڣ�" << endl;
                    coulist.showcourse();
                    cout << "�밴����˳������γ���Ϣ���γ̱�� �γ����� �ον�ʦ ѧ�� �γ���� ����ѧԺ �γ�����" << endl;
                    cin >> bhv >> namev >> teacherv >> creditv >> catagoryv >> collegev >> assessmentv;
                    coulist.addcourse(bhv, namev, teacherv, creditv, catagoryv, collegev, assessmentv);
                    cout << endl << "�ӿγɹ�,��" << coulist.getsize() << "��,�����Ǽӿκ�Ŀγ���Ϣ����" << endl << endl;
                    coulist.showcourse();
                    system("pause");
                    goto out3;
                    break;
                case 2:
                    //ɾ���γ�
                    system("cls");
                    cout << "Ŀǰ���еĿγ���Ϣ����, ��" << coulist.getsize() << "�ڣ�" << endl;
                    coulist.showcourse();
                    cout << "������Ҫɾ���Ŀγ̱��" << endl;
                    cin >> bhv;
                    if (!coulist.delcourse(bhv))
                    {
                        cout << "ɾ��ʧ��!��Ϊ���ṩ�Ŀγ̲�����" << endl;
                        system("pause");
                        goto out3;
                    }
                    cout << endl << "ɾ�γɹ�,��" << coulist.getsize() << "��,������ɾ�κ�Ŀγ���Ϣ����" << endl << endl;
                    coulist.showcourse();
                    system("pause");
                    goto out3;
                    break;
                case 3:
                    //�޸Ŀγ�
                    system("cls");
                    cout << "Ŀǰ���еĿγ���Ϣ����,��" << coulist.getsize() << "�ڣ�" << endl;
                    coulist.showcourse();
                    cout << "������Ҫ�޸ĵĿγ̱��" << endl;
                    cin >> bhv;
                    if (!coulist.modifycourse(bhv))
                    {
                        cout << "�޸�ʧ��!��Ϊ���ṩ�Ŀγ̲�����" << endl;
                        system("pause");
                        goto out3;
                    }
                    cout << endl << "�޸ĳɹ�,��" << coulist.getsize() << "��,�������޸ĺ�Ŀγ���Ϣ����" << endl << endl;
                    coulist.showcourse();
                    system("pause");
                    goto out3;
                    break;
                case 4:{
                    //��ѯ�γ�
                    howfind();
                    if (!coulist.findcourse())
                    {
                        //���ң����û�ҵ���ִ��if��������һ������
                        cout << "��������ֵ������һ����" << endl;
                        system("pause");
                        goto out3;
                    }
                    system("pause");
                    goto out3;
                    break;
                }
                case 5:{
                    //����γ�
                    howsort();
                    if (!coulist.sortcourse())
                    {
                        cout << "����ʧ��,����������ֵ������һ����" << endl;
                        system("pause");
                    }
                    system("pause");
                    goto out3;
                }
                case 6:
                    //���µ�½
                    goto out1;
                default:
                    cout << "�������,����������" << endl;
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
                cout << "�������,����������" << endl;
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
    cout << "                            |           ��ӭ����ѧУ���β�ѯϵͳ                 |" << endl;
    cout << "                            |           1.ѧ����½                               |" << endl;
    cout << "                            |           2.����Ա��¼                             |" << endl;
    cout << "                            |           3.�ر�ϵͳ                               |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                         ��ѡ��(1/2/3):" << endl;
}
void stuwelcome()
{
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           ��ӭ����ѧУ���β�ѯϵͳ                 |" << endl;
    cout << "                            |           1.ѡ��                                   |" << endl;
    cout << "                            |           2.�˿�                                   |" << endl;
    cout << "                            |           3.��Ѱ�γ�                               |" << endl;
    cout << "                            |           4.�γ�����                               |" << endl;
    cout << "                            |           5.�鿴��ѡ�γ̱��                       |" << endl;
    cout << "                            |           6.�˳���½                               |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                         ��ѡ��(1/2/3/4/5/6):" << endl;
}
void manwelcome()
{
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           ��ӭ����ѧУ���β�ѯϵͳ                 |" << endl;
    cout << "                            |           1.��ӿγ�                               |" << endl;
    cout << "                            |           2.ɾ���γ�                               |" << endl;
    cout << "                            |           3.�޸Ŀγ�                               |" << endl;
    cout << "                            |           4.��Ѱ�γ�                               |" << endl;
    cout << "                            |           5.����γ�                               |" << endl;
    cout << "                            |           6.�˳���¼                               |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                         ��ѡ��(1/2/3/4/5/6):" << endl;
}
void howfind()
{
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           ��ӭ����ѧУ���β�ѯϵͳ                 |" << endl;
    cout << "                            |           1.���γ̱��                             |" << endl;
    cout << "                            |           2.���γ�����                             |" << endl;
    cout << "                            |           3.���γ̽�ʦ                             |" << endl;
    cout << "                            |           4.���γ�ѧԺ                             |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                         ��ѡ��(1/2/3/4):" << endl;
}

void howsort()
{
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           ��ӭ����ѧУ���β�ѯϵͳ                 |" << endl;
    cout << "                            |           1.���γ�ѧ������                         |" << endl;
    cout << "                            |           2.���γ�ѧԺ����                         |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                                                ��ѡ��(1/2):" << endl;
}

void bye(){
    system("cls");
    cout << "                            ------------------------------------------------------" << endl;
    cout << "                            |           ��лʹ��ѧУ���β�ѯϵͳ~                  |" << endl;
    cout << "                            ------------------------------------------------------" << endl;
}