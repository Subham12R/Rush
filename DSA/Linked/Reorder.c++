#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    public:
        void reorderList(ListNode* head){
            if(!head || !head->next)return;

            ListNode* slow = head;
            ListNode* fast = head;

            while (fast->next && fast->next->next) // tortoise and hare
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* prev = nullptr;
            ListNode* curr = slow->next;
            slow->next = nullptr;

            while(curr){  //reversing the second half
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            ListNode* first = head;
            ListNode* second = prev;


            while(second){ //merging the lists
                ListNode* temp1 = first->next;
                ListNode* temp2 = second->next;

                first->next = second;
                second->next = temp1;

                first = temp1;
                second = temp2;
                
            }

        }

        void printList(ListNode* head){
            while(head){
                cout << head->val << " ";
                head = head->next;
            }
            cout << endl;
        }
};

int main(){
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution s1;
    s1.reorderList(head);
    s1.printList(head);
    return 0;
}

