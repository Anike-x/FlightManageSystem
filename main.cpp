#include <bits/stdc++.h>
#include "user.h"
#include "manager.h"
#include "plane.h"
#include "login.h"

using namespace std;

plane *planelist = nullptr;
user *userist = nullptr;
manager *managerlist = nullptr;

int main() {
    connectAndFillPlaneList();
    int choice;
    while(1){
        cout<<"1.�û�"<<endl;
        cout<<"2.����Ա"<<endl;
        cout<<"3.�˳�"<<endl;
        cout<<"���������ѡ��";
        cin>>choice;
        switch(choice){
            case 1:
                //�û�
                checkUser();
                usermenu();
                break;
            case 2:
                //����Ա
                checkManager();
                managermenu();
                break;
            case 3:
                return 0;
            default:
                cout<<"�����������������"<<endl;
        }
    }
}