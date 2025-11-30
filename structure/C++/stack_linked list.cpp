#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class LinkedListStack {
    private:
        ListNode *stackTop;
        int stkSize;

         //释放链表内存函数（用于析构函数）
        void freeMemoryLinkedList(ListNode *node) {
            while (node != nullptr) {
                ListNode *tmp = node;
                node = node->next;
                delete tmp; //用 new 分配的内存必须用 delete 释放。  如果用C,malloc() 分配的内存必须用 free() 释放，但 free() 仅释放内存块，不会调用析构函数。
            }
        }
    public:
        LinkedListStack() {
            stackTop = nullptr;
            stkSize = 0;
        }
        ~LinkedListStack() {
            freeMemoryLinkedList(stackTop);
        }
        int size() {
            return stkSize;
        }

        bool isEmpty() {
            return size() == 0;
        }
        /*入栈 */
        void push(int num) {
            ListNode *node = new ListNode(num);
            node->next = stackTop;
            stackTop = node;
            stkSize++;
        }
        /*出栈 */
        int pop() {
            int num = top();
            ListNode *tmp = stackTop;
            stackTop = stackTop->next;
            delete tmp;
            stkSize--;
            return num;
        }
        /*访问栈顶元素 */
        int top() {
            if(isEmpty()){
                throw out_of_range("栈为空");
            }
            return stackTop->val;
        }
        /*将链表转化为 Vector 用于打印 */
        vector<int> toVector() {
            vector<int> vec;
            ListNode *node = stackTop;
            while (node != nullptr) {
                vec.push_back(node->val);
                node = node->next;
            }
            reverse(vec.begin(), vec.end());
            return vec;
        }
};