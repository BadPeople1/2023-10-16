#include <iostream>
using namespace std;

typedef struct listnode
{
    int data; //������
    struct listnode* next; //�쵲���
}NODE;

void ListTraverse(listnode* head)
{
    listnode* p = head;
    p = p->next;
    while (p != NULL)
    {
        cout << p->data << " "; //�L�X�`�I���
        p = p->next;
    }
    cout << endl;
}

bool InsertAfter(listnode* p, int value)
{
    listnode* NewNode;
    NewNode = new listnode;
    if (NewNode == NULL)
        return false;
    NewNode->data = value;
    NewNode->next = p->next;
    p->next = NewNode;
    return true;
}

listnode* GetPreNode(listnode* head, listnode* OldNode)
{
    listnode* p, * q;
    p = head;
    q = head->next;
    while ((q != NULL) && (q != OldNode))
    {
        p = q;
        q = q->next;
    }
    if (q != NULL)
        return p;
    else
        return NULL;
}

bool DeleteNode(listnode* head, listnode* OldNode)
{
    listnode* PreNode;
    if (head == OldNode)
        return false;
    PreNode = GetPreNode(head, OldNode);
    if (PreNode == NULL)
        return false;
    PreNode->next = OldNode->next;
    delete OldNode;
    return true;
}

int main()
{
    NODE* listA;
    listA = new NODE;
    listA->data = 20;
    listA->next = NULL;
    cout << "";

    NODE* listB;
    listB = new NODE;
    listB->data = 0;
    listB->next = new NODE;
    listB->next->data = 10;
    listB->next->next = new NODE;
    listB->next->next->data = 20;
    listB->next->next->next = new NODE;
    listB->next->next->next->data = 30;
    listB->next->next->next->next = new NODE;
    listB->next->next->next->next->data = 40;
    listB->next->next->next->next->next = NULL;
    ListTraverse(listB);

    InsertAfter(listB->next->next, 25);
    ListTraverse(listB);

    DeleteNode(listB, listB->next->next->next);
}

// ����{��: Ctrl + F5 �� [����] > [�Ұʦ�������] �\���
// �����{��: F5 �� [����] > [�Ұʰ���] �\���

// �}�l�ϥΪ�����: 
//   1. �ϥ� [����`��] �����A�s�W/�޲z�ɮ�
//   2. �ϥ� [Team Explorer] �����A�s�u���l�ɱ���
//   3. �ϥ� [��X] �����A�Ѿ\�իؿ�X�P��L�T��
//   4. �ϥ� [���~�M��] �����A�˵����~
//   5. �e�� [�M��] > [�s�W����]�A�إ߷s���{���X�ɮסA�άO�e�� [�M��] > [�s�W�{������]�A�N�{���{���X�ɮ׷s�W�ܱM��
//   6. ����n�A���}�Ҧ��M�׮ɡA�Ыe�� [�ɮ�] > [�}��] > [�M��]�A�M���� .sln �ɮ�
//   7. DanielFeng