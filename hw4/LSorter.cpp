//Isaac Goldman
//EC330 HW4
//
//After researching the problem in the reading and online, I concluded that in order to sort a linked list
// in nlogn time in place, I would need to implement a bottum up merge sort (iterative). 
//  
//I experimented with a variety of different ways to implement this and used the following websites as resources:
// 
//https://leetcode.com/discuss/7429/my-accepted-solution-using-bottom-up-merge-sort-in-c
//https://en.wikipedia.org/wiki/Merge_sort
//http://www.sinbadsoft.com/blog/a-recursive-and-iterative-merge-sort-implementations/
//
//

// 
//



#include <iostream>
#include "LNode.h"
#include "LSorter.h"

using namespace std;

class LNode;

LNode* LSorter::sortList(LNode *head) {
  if(!head || !head -> next) return head;

  LNode * merge (LNode * leftList, LNode * leftTail, LNode * rightList, LNode * rightTail, LNode * &nextTail);
  LNode * findEndNode (int k, LNode * currNode);
  LNode * currNode = head;
  int length = 0;
  while (currNode) length++, currNode = currNode -> next;

  LNode * returnList = new LNode(0); 
  returnList -> next = head;

  for (int  width = 1; width < length; width += width){

    LNode * leftList, *leftTail, *rightList, *rightTail, *Tail;
    Tail = returnList;

    while (Tail -> next) {
      leftList = Tail -> next;
      leftTail = findEndNode(width, leftList);
      if(leftTail) rightList = leftTail; 
      else 
	break;

      rightTail = findEndNode(width, rightList);
      LNode * loopList = rightTail ;
      LNode * nextTail;

      Tail -> next = merge(leftList, leftTail, rightList, rightTail, nextTail);
      Tail = nextTail;
      Tail -> next = loopList;
    }
  }
  return returnList -> next;
}

LNode * findEndNode (int k, LNode * currNode) {
  for (int i = 0; i < k && currNode; i++) currNode = currNode -> next;
  return currNode;
}
LNode * merge (LNode * leftList, LNode * leftTail, LNode * rightList, LNode * rightTail, LNode * &nextTail) {
  if (!leftList) return rightList;
  if (!rightList) return leftList;

  LNode * merge , *head;
  if (leftList -> val < rightList -> val) {
    merge = leftList;
    leftList = leftList -> next;
  } else {
    merge = rightList;
    rightList = rightList -> next;
  }
  head = merge;

  while (leftList != leftTail && rightList != rightTail) {
    if (leftList->val < rightList->val) {
      merge -> next = leftList;
      leftList = leftList -> next;
    } else {
      merge -> next = rightList;
      rightList = rightList -> next;
    }
    merge = merge -> next;
  }
  while (leftList != leftTail) {
    merge -> next = leftList;
    leftList = leftList -> next;
    merge = merge -> next;
  }
  while (rightList != rightTail) {
    merge -> next = rightList;
    rightList = rightList -> next;
    merge = merge -> next;
  }
  nextTail = merge;
  return head;
}










/*

LNode* LSorter::sortList(LNode* head){
  if(!head){
    return NULL;
  }

  int getLength(LNode* currNode);
  LNode * findEndNode (int width, LNode * currNode);
  LNode* merge (int leftSize, int rightSize, LNode* leftList, LNode* rightList, LNode* &end);
  LNode *currList, *endList, *leftList, *rightList, *loopList;
  int leftSize, rightSize;
  LNode* returnList = new LNode(0);
  returnList->next = head;
  endList = head;
  currList = head;
  int fullLength = getLength(endList);
  int subLength = 1;

  

  

  for (int width = 1; width < fullLength; width *= width){

    loopList = returnList;
    leftList = returnList->next;
    leftSize = 0;
    //  currList = NULL;
    // endList = NULL:

      while(loopList->next){  
	
	rightList = leftList;
 
	for (int i = 0; i < width; i++) {
	  leftSize++;
	  rightList = rightList->next;
	  if (!rightList){
	    break;
	  }
	}
	currList = rightList;
	currList = findEndNode(width, currList);

	loopList->next = merge(leftSize, width, leftList, rightList, endList);
	loopList = endList;
	loopList->next = currList;
      }
  }

  return returnList -> next;
}

LNode * findEndNode (int width, LNode * currNode) {
  for (int i = 0; i < width && currNode; i++) {
    currNode = currNode -> next;
  }
  return currNode;
}


int getLength(LNode* currNode){

  int length = 0;
  for(; currNode != NULL; length++){
    currNode = currNode->next;
  }

  return length;
}

LNode* merge (int leftSize, int rightSize, LNode* leftList, LNode* rightList, LNode* &end) {
  if ((!leftList) || (!rightList)){
    return NULL;
  }

 
  LNode * merge , *head;

  if (leftList -> val < rightList -> val) {
    merge = leftList;
    leftList = leftList -> next;
    leftSize--;
  } 

  else {
    merge = rightList;
    rightList = rightList -> next;
    rightSize--;
  }

  head = merge;

  while (leftSize > 0 && rightSize > 0) {
    if (leftList->val < rightList->val) {
      merge->next = leftList;
      leftList = leftList->next;
      leftSize--;
    } 
    else {
      merge -> next = rightList;
      rightList = rightList -> next;
      rightSize--;
    }
    merge = merge -> next;
  }

  while (leftSize > 0 && leftList) {
    merge -> next = leftList;
    leftList = leftList -> next;
    merge = merge -> next;
    leftSize--;
  }

  while (rightSize > 0 && rightList) {
    merge->next = rightList;
    rightList = rightList -> next;
    merge = merge -> next;
    rightSize--;
  }

  end = merge;
  return head;
}


*/
