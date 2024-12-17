//
// Created by 24034 on 24-12-14.
//

#ifndef FLIGHTMANAGESYSTEM_USER_H
#define FLIGHTMANAGESYSTEM_USER_H

#include <bits/stdc++.h>
#include "plane.h"
using namespace std;

typedef struct user
{
    string name;
    string passwd;
    string card;
    plane *order;
    struct user *next;//����ָ����
}user;//�˿���Ϣ

extern user *userist;


void usermenu();
void searchPlane();
void orderTicket();
void returnTicket();
void searchUserInfo();
void changeUserInfo();

#endif //FLIGHTMANAGESYSTEM_USER_H