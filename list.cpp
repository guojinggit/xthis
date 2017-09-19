//
// Created by Administrator on 2017/6/4.
//

#include <iostream>

using namespace std;
//
///*如果是c++的话可以写写构造函数初始化*/
//struct ListNode{
//    ListNode*  next;
//    int        data;
//};
//
//void addToTail(ListNode** header, int value) {
//    if (!header)
//        return;
//
//    ListNode* node = new ListNode();
//    node->data = value;
//    node->next = NULL;
//
//    /*说明头不存在*/
//    if (!*header) {
//        *header = node;
//        return;
//    } else {
//        ListNode* nodeTmp = *header;
//        while (nodeTmp->next) {
//            nodeTmp = nodeTmp->next;
//        }
//        nodeTmp->next = node;
//    }
//    return;
//}
//
///*只适用于删除一个节点*/
//void RemoveNode(ListNode** header, int value) {
//    if (!(header && *header))
//        return;
//
//    /*需要移除的指针*/
//    ListNode* deleteNode = NULL;
//
//    /*需要需要删除头的话，这个分支比较简单，直接删掉即可*/
//    if ((*header)->data == value) {
//        deleteNode = (*header);
//        /*现在（*header）可能为空*/
//        (*header) = (*header)->next;
//    }
//    /*如果是中间节点的话，只需要把后面的指针交给前一个节点即可*/
//    else {
//        ListNode* nodeTmp = (*header);
//        while (nodeTmp->next ) {
//            if (nodeTmp->next->data == value) {
//                deleteNode = nodeTmp->next;
//                nodeTmp->next = nodeTmp->next->next;
//                break;
//            }
//            nodeTmp = nodeTmp->next;
//        }
//    }
//
//    /*释放空间*/
//    if (deleteNode)
//        delete deleteNode;
//    deleteNode = NULL;
//    return ;
//}
//
////remonv multi
//void removeMultiNode(ListNode** header, int value) {
////    if (!header || !*header)
////        return;
////
////    ListNode* node = (*header);
////    while (node->next) {
////        if (node->data == value) {
////
////        } else if (node->next->data == value){
////            ListNode* nodeTmp = node->next->next;
////            delete node->next;
////            node->next = nodeTmp;
////            node = node->next;
////            if (!node)
////                break;
////        }
////    }
////    return;
//}
//void showList(ListNode** header) {
//    if (!(header && *header))
//        return;
//    ListNode* node = *header;
//    while (node) {
//        std::cout << node->data << std::endl;
//        node = node->next;
//    }
//    return;
//}
//
////题目1，反向打印链表值  这是打印
//
////思路1，顺序遍历，然后放入栈中，然后再打印
//
////思路2,递归   风险，如果链表非常长，栈空间可能不够用
//
////注意这里的是地址，不是二级地址
//void reversePrintList(ListNode* header) {
//    if (!header)
//        return;
//    if (header->next)
//        reversePrintList(header->next);
//    std::cout << header->data << std::endl;
//}
//
////反转链表
//
//
//
////反转链表
//
//ListNode* reverseList(ListNode* header) {
//
//    ListNode* pRevHeader = NULL;
//    ListNode* pNode = header;
//    ListNode* pPreNode = NULL;
//
//    while (pNode != NULL) {
//        ListNode* pNext = pNode->next;
//        if (pNext != NULL)
//            pRevHeader = pNext;
//
//        pNode->next = pPreNode;
//
//        pPreNode = pNode;
//        pNode = pNext;
//    }
//    return pRevHeader;
//}
//
//
////listMerge
//
//ListNode* mergeList(ListNode* header1,ListNode* header2){
//    if (header1 == NULL)
//        return header2;
//    else if (header2 == NULL)
//        return header1;
//
//    ListNode* pMergeHeader = NULL;
//    if (header1->data < header2->data) {
//        pMergeHeader = header1;
//        pMergeHeader->next = mergeList(header1->next, header2);
//    } else {
//        pMergeHeader = header2;
//        pMergeHeader->next = mergeList(header1, header2->next);
//    }
//    return pMergeHeader;
//}



//链表操作
//1.基本数据结构

struct ListNode{
    ListNode* pNext;
    int        data;
};

//2.链表的插入

void addToTail(ListNode** head, int data) {
    if (!head)
        return;

    ListNode* node = new ListNode();
    node->pNext = NULL;
    node->data = data;

    if (*head == NULL) {
        *head = node;
        return;
    } else {
        ListNode* nodeTmp = *head;
        while (nodeTmp->pNext) {
            nodeTmp = nodeTmp->pNext;
        }
        nodeTmp->pNext = node;
    }
}

void showList(ListNode* head) {

    while (head) {
        std::cout << head->data << std::endl;
        head = head->pNext;
    }
}

void removeNode(ListNode** head, int value) {
    if (head == NULL || *head == NULL)
        return;
    ListNode* delNode = NULL;
    //如果想删除head节点
    if ((*head)->data == value) {
        delNode = *head;
        *head = (*head)->pNext;
    } else {
        ListNode* tmpNode = *head;
        while (tmpNode->pNext != NULL && tmpNode->pNext->data != value)
            tmpNode = tmpNode->pNext;

        if (tmpNode->pNext && tmpNode->pNext->data == value) {
            delNode = tmpNode->pNext;
            tmpNode->pNext = tmpNode->pNext->pNext;
        }

    }
    if (delNode) {
        delete delNode;
        delNode = NULL;
    }
}

//链表反序打印,递归实现
void reversePrintList(ListNode* head) {
    if (!head)
        return;
    if (head->pNext != NULL)
        reversePrintList(head->pNext);
    std::cout << (head->data) << std::endl;
}

//链表反序

//ListNode* reverseList(ListNode* head) {
//
//    // 三个变量 1.头节点的保存 2.新的头节点 3.之前的节点
//    ListNode* nodeTmp = head;
//    ListNode* nodePre = NULL;
//    ListNode* nodeRev = NULL;
//
//    //还需要新增一个下一个节点
//    while (nodeTmp != NULL) {
//        ListNode* nodeNext = nodeTmp->pNext;
//        if (nodeNext != NULL)
//            nodeRev = nodeNext;
//
//        nodeTmp->pNext = nodePre;
//        nodePre = nodeTmp;
//        nodeTmp = nodeNext;
//    }
//    return nodeRev;
//}



ListNode* reserverList(ListNode* head) {

    //4个变量，首先由三个
    ListNode* nodeTmp = head;
    ListNode* nodePre = NULL;
    ListNode* nodeNew = NULL;

    //
    while (nodeTmp != NULL) {
        ListNode* nodeNext = nodeTmp->pNext;

        if (nodeNext != NULL)
            nodeNew = nodeNext;

        nodeTmp->pNext = nodePre;
        nodePre = nodeTmp;
        nodeTmp = nodeTmp->pNext;
    }
}











int main(){
    ListNode* header = new ListNode();
    header->data = 100;
    for(int i = 0; i < 3; ++i)
        addToTail(&header, i);

    removeNode(&header, 2);
//    removeMultiNode(&header, 2);
    showList(header);
    reversePrintList(header);
//    ListNode* l = reverseList(header);
//    showList(NULL);
    return 0;
}