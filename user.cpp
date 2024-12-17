//
// Created by 24034 on 24-12-14.
//

#include "user.h"
#include "plane.h"

void usermenu(){
    int choice;
    while(1){
        cout<<"1.��ѯ������Ϣ"<<endl;
        cout<<"2.��Ʊ"<<endl;
        cout<<"3.��Ʊ"<<endl;
        cout<<"4.��ѯ������Ϣ"<<endl;
        cout<<"5.�޸ĸ�����Ϣ"<<endl;
        cout<<"6.�˳�"<<endl;
        cout<<"���������ѡ��";
        cin>>choice;
        switch(choice){
            case 1:
                //��ѯ������Ϣ
                searchMyPlane();
                break;
            case 2:
                //��Ʊ
                orderTicket();
                break;
            case 3:
                //��Ʊ
                returnTicket();
                break;
            case 4:
                //��ѯ������Ϣ
                searchUserInfo();
                break;
            case 5:
                //�޸ĸ�����Ϣ
                changeUserInfo();
                break;
            case 6:
                system("cls");
                return;
            default:
                cout<<"�����������������"<<endl;
        }
        system("pause");
        system("cls");
    }
}

void connectAndFillUserList() {
    userist = new user;
    userist->next = nullptr;
    user* p = userist;
    ifstream fin("D:\\CLion\\projects\\FlightManageSystem\\user.txt");
    if (!fin.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }
    while (true) {
        auto* newUser = new user;
        if (!(fin >> newUser->name
                  >> newUser->passwd
                  >> newUser->card)) {
            delete newUser;  // Release memory
            break;           // Exit loop
        }
        p->next = newUser;
        newUser->next = nullptr;
        p = newUser;
    }
    fin.close();
}

//��ѯ������Ϣ
void searchMyPlane(){
    plane *p;
    p = planeOrder;
    while(p!=NULL){
        cout<<"����ţ�"<<p->id<<endl;
        cout<<"��ɳ��У�"<<p->startCity<<endl;
        cout<<"������У�"<<p->finCity<<endl;
        cout<<"���ʱ�䣺"<<p->takeOffTime<<endl;
        cout<<"����ʱ�䣺"<<p->takeTime<<endl;
        cout<<"��λ����"<<p->site<<endl;
        cout<<"Ʊ�ۣ�"<<p->price<<endl;
        cout<<endl;
        p=p->next;
    }
}

//��Ʊ
void orderTicket(){
    int id;
    cout<<"�����뺽��ţ�";
    cin>>id;
    plane *p;
    p = planelist;
    while(p!=NULL){
        if(p->id==id){
            if(p->site>0){
                p->site--;
                cout<<"��Ʊ�ɹ�"<<endl;
            }else{
                cout<<"��λ����"<<endl;
            }
            return;
        }
        p=p->next;
    }
    cout<<"û���ҵ��ú���"<<endl;
}

//��Ʊ
void returnTicket(){
    int id;
    cout<<"�����뺽��ţ�";
    cin>>id;
    plane *p;
    p = planelist;
    while(p!=NULL){
        if(p->id==id){
            p->site++;
            cout<<"��Ʊ�ɹ�"<<endl;
            return;
        }
        p=p->next;
    }
    cout<<"û���ҵ��ú���"<<endl;
}

//��ѯ������Ϣ
void searchUserInfo(){
    //�����Լ�������������
    string name;
    cout<<"���������������";
    cin>>name;
    user *p;
    p = userist;
    while(p!=NULL){
        if(p->name == name){
            cout<<"������"<<p->name<<endl;
            cout<<"���룺"<<p->passwd<<endl;
            cout<<"���֤�ţ�"<<p->card<<endl;
            return;
        }
        p=p->next;
    }
}

//�޸ĸ�����Ϣ
void changeUserInfo() {
    user *p;
    p = userist;
    string name;
    cout << "���������������";
    cin >> name;
    while (p != NULL) {
        if (p->name == name) {
            cout << "�����������룺";
            cin >> p->passwd;
            cout << "�����������֤�ţ�";
            cin >> p->card;
            cout << "�޸ĳɹ�" << endl;
            return;
        }
        p = p->next;
    }
    cout << "û���ҵ����û�" << endl;
}
