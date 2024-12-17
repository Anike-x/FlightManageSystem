//
// Created by 24034 on 24-12-14.
//

#ifndef FLIGHTMANAGESYSTEM_MANAGER_H
#define FLIGHTMANAGESYSTEM_MANAGER_H

#include <bits/stdc++.h>
using namespace std;

typedef struct manager
{
    string name;
    string passwd;
    string card;
    struct manager *next;
}manager;//³Ë¿ÍÐÅÏ¢

extern manager *managerlist;

void managermenu();
void addPlane();
void deletePlane();
void changePlane();
void searchAllUserInfo();

#endif //FLIGHTMANAGESYSTEM_MANAGER_H
