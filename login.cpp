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
    cout<<"请输入用户名：";
    cin>>name;
    cout<<"请输入密码：";
    cin>>passwd;
    user *p;
    p = userist;
    while(p!=NULL){
        if(p->name == name && p->passwd == passwd){
            cout<<"登录成功"<<endl;
            usermenu();
            return;
        }
        p=p->next;
    }
    cout<<"用户名或密码错误"<<endl;
}

void checkManager(){
    char name[10];
    char passwd[20];
    cout<<"请输入用户名：";
    cin>>name;
    cout<<"请输入密码：";
    cin>>passwd;
    manager *p;
    p = managerlist;
    while(p!=NULL){
        if(p->name == name && p->passwd == passwd){
            cout<<"登录成功"<<endl;
            managermenu();
            return;
        }
        p=p->next;
    }
    cout<<"用户名或密码错误"<<endl;
    system("cls");
}
