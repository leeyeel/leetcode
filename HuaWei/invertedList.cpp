//逆序链表题目，输入一个单向链表，将链表逆序后输出各结点的值。
//leetcode: 206. Reverse Linked List.  Difficulty: Easy
#include<iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if(head==0||head->next==0) return head;
            ListNode *pre = head;
            ListNode *p = head->next;
            head->next=0;
            ListNode *nxt=0;
            while(p){
                nxt=p->next;
                p->next=pre;
                pre=p;
                p=nxt;
            }
            return pre;

        }

};

ListNode* addNode(ListNode* l0,int input){
    ListNode *newNode = new ListNode(input);
    ListNode *p=0;
    p=l0;
    if(l0==0)
        l0=newNode;
    else{
        while(p->next!=0)
            p=p->next;
        p->next=newNode;
    }
    return l0;
}

bool OutputNode(ListNode *head){
    ListNode* pNode=head;  
    if(head==NULL)  
        return false;  
    else  
    {  
        std::cout<<pNode->val;  
        while(pNode->next!=NULL)  
        {  
            pNode=pNode->next;   
            std::cout<<","<<pNode->val;
        }  
    }  

    std::cout<<std::endl;
}


int main(){
    //std::cout<<"type your input number..\n";
    int tmp=0;
    ListNode *ll=0;

    do{
        std::cin>>tmp;
        //std::cout<<tmp<<" ";
        ll = addNode(ll,tmp);
    }
    while(std::cin.get()==',');

    Solution *sol = new Solution();
    ListNode *l2 = sol->reverseList(ll);
    OutputNode(l2);


}


