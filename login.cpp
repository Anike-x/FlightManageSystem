//
// Created by 24034 on 24-12-16.
//

#include "login.h"

void init(){
    connectAndFillUserList();
    connectAndFillPlaneList();
}

void checkUser(){
    char name[10];
    char passwd[20];
    cout<<"�������û�����";
    cin>>name;
    cout<<"���������룺";
    cin>>passwd;
    user *p;
    p = userist;
    while(p!=NULL){
        if(p->name == name && p->passwd == passwd){
            cout<<"��¼�ɹ�"<<endl;
            usermenu();
            return;
        }
        p=p->next;
    }
    cout<<"�û������������"<<endl;
}

void checkManager(){
    char name[10];
    char passwd[20];
    cout<<"�������û�����";
    cin>>name;
    cout<<"���������룺";
    cin>>passwd;
    manager *p;
    p = managerlist;
    while(p!=NULL){
        if(p->name == name && p->passwd == passwd){
            cout<<"��¼�ɹ�"<<endl;
            managermenu();
            return;
        }
        p=p->next;
    }
    cout<<"�û������������"<<endl;
    system("cls");
}
