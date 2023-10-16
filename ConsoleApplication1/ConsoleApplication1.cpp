#include <iostream>
using namespace std;

typedef struct listnode
{
    int data; //資料欄位
    struct listnode* next; //鏈結欄位
}NODE;

void ListTraverse(listnode* head)
{
    listnode* p = head;
    p = p->next;
    while (p != NULL)
    {
        cout << p->data << " "; //印出節點資料
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
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
//   7. DanielFeng