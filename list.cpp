//
// Created by Administrator on 2017/6/4.
//

#include <iostream>

using namespace std;

/*如果是c++的话可以歇歇构造函数初始化*/
struct ListNode{
    ListNode*  next;
    int        data;
};

void addToTail(ListNode** header, int value) {
    if (!header)
        return;

    ListNode* node = new ListNode();
    node->data = value;
    node->next = NULL;

    /*说明头不存在*/
    if (!*header) {
        *header = node;
        return;
    } else {
        ListNode* nodeTmp = *header;
        while (nodeTmp->next) {
            nodeTmp = nodeTmp->next;
        }
        nodeTmp->next = node;
    }
    return;
}

void RemoveNode(ListNode** header, int value) {
    if (!(header && *header))
        return;

    /*需要移除的指针*/
    ListNode* deleteNode = NULL;

    /*需要需要删除头的话，这个分支比较简单，直接删掉即可*/
    if ((*header)->data == value) {
        deleteNode = (*header);
        /*现在（*header）可能为空*/
        (*header) = (*header)->next;
    }
    /*如果是中间节点的话，只需要把后面的指针交给前一个节点即可*/
    else {
        ListNode* nodeTmp = (*header);
        while (nodeTmp->next ) {
            if (nodeTmp->next->data == value) {
                deleteNode = nodeTmp->next;
                nodeTmp->next = nodeTmp->next->next;
                break;
            }
            nodeTmp = nodeTmp->next;
        }
    }

    /*释放空间*/
    if (deleteNode)
        delete deleteNode;
    deleteNode = NULL;
    return ;
}

void showList(ListNode** header) {
    if (!(header && *header))
        return;
    ListNode* node = *header;
    while (node) {
        std::cout << node->data << std::endl;
        node = node->next;
    }
    return;
}

//题目1，反向打印链表值

//思路1，顺序遍历，然后放入栈中，然后再打印

//思路2,递归   风险，如果链表非常长，栈空间可能不够用

//注意这里的是地址，不是二级地址
void reverseList(ListNode* header) {
    if (!header)
        return;
    if (header->next)
        reverseList(header->next);
    std::cout << header->data << std::endl;
}


int main(){
    ListNode* header = new ListNode();
    header->data = 100;
    for(int i = 0; i < 3; ++i) {
        addToTail(&header, i);
    }

//    RemoveNode(&header, 2);
//    showList(&header);
    reverseList(header);
    return 0;
}