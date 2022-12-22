#include "IntList.h"
#include <iostream> //REMOVE

/* Initializes an empty list.
*/
IntList::IntList() : head(nullptr) {}

/* Inserts a data value to the front of the list.
*/
void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } 
   else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

void IntList::swapHeadAndTail() {
   // TODO: Implement me
   if (head == nullptr || head->next == nullptr) {return;}
   IntNode *tail = head;
   IntNode *beforeTail = nullptr;
   while (tail->next != nullptr)
   {
      if (tail->next->next == nullptr)
      {
         beforeTail = tail;
      }
      if (tail->next == nullptr)
      {
         break;
      }
      tail = tail->next;
   }
   beforeTail->next = head;
   tail->next = head->next;
   head = tail;
   tail = beforeTail->next;
   tail->next = nullptr;
   // cout<<"HEAD IS "<<head->value<<endl;
   // cout<<"next beforeTail IS "<<beforeTail->next->value<<endl;
   // cout<<"TAIL IS "<<tail->value<<endl;

}
