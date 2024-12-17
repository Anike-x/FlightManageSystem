//
// Created by 24034 on 24-12-14.
//

#ifndef FLIGHTMANAGESYSTEM_PLANE_H
#define FLIGHTMANAGESYSTEM_PLANE_H

#include <bits/stdc++.h>
using namespace std;

typedef struct plane
{
    int id; // �����
    string startCity; // ��ɳ���
    string finCity; // �������
    string takeOffTime; // ���ʱ��
    string takeTime; // ����ʱ��
    int site; // ��λ��
    int price; // Ʊ��
    struct plane* next; // ����ָ����
}plane;

extern plane *planelist;

//��ȡ�ļ�
void connectAndFillPlaneList();

#endif //FLIGHTMANAGESYSTEM_PLANE_H
