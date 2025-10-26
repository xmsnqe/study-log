#include <iostream>

struct ListNode {
    int val; //节点值
    ListNode* next; //指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {} //构造函数
};

void insert(ListNode *n0, ListNode *p){
    if(n0 -> next == nullptr){
        return;
    }
    ListNode *n1 = n0 -> next;
    p -> next = n1;
    n0 -> next = p;
}

//调用此函数时必须保证n0确实是p的前驱节点，否则会破坏链表结构
void remove1(ListNode *n0, ListNode *p){
    if(n0 -> next == nullptr){
        return;
    }
    ListNode *n1 = p -> next;
    n0 -> next = n1;
    delete p;
}

void remove2(ListNode *n0){
    if(n0 -> next == nullptr){
        return;
    }
    ListNode *p  = n0 -> next;
    ListNode *n1 = p  -> next;
    n0 -> next = n1;
    delete p;
}

//链表访问节点的效率有点低，因为需要遍历链表直到找到要访问的节点
//时间复杂度O(n)
ListNode *access(ListNode *head, int index){
    for(int i = 0; i < index; i++){
        if(head == nullptr){
            return nullptr;
        }
        head = head -> next;
    }
    return head;
}
/*ListNode *不建议改为void*，因为void*无法确定指针所指的类型，无法调用其成员函数
必须强制类型转换为ListNode*才能调用其成员函数*/


int find(ListNode *head, int target){
    int index = 0;
    while(head!= nullptr){
        if(head -> val == target){
            return index;
        }
        head = head -> next;
        index++;
    }
    return -1;
}





int main() {
    return 0;
}