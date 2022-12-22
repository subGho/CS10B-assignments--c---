#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
   return;
}

ostream & operator<<(ostream &o, const IntList &oIntList)
{
   IntNode *tempNode =oIntList.head;
   o<<tempNode;
   return o;
}

ostream & operator<<(ostream &o, IntNode *tempNode)
{
   if (tempNode == nullptr)
   {
      return o;
   }
   if (tempNode->next == nullptr)
   {
      o<<tempNode->value;
      return o;
   }
   o<<tempNode->value<<" ";
   tempNode = tempNode->next;
   operator<<(o, tempNode);
   return o;
}

bool IntList::exists(int value) const
{
   IntNode *currNode = head;
   if (exists(currNode, value))
   {
      return true;
   }
   return false;
}

bool IntList::exists(IntNode *currNode, int value) const
{
   if (currNode == nullptr)
   {
      return false;
   }
   if (currNode->value == value)
   {
      return true;
   }
   currNode = currNode->next;
   if (exists(currNode, value))
   {
      return true;
   }
   return false;
}