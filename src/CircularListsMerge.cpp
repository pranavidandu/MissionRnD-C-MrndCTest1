/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if (*head1 == NULL || *head2 == NULL)
		return -1;
	struct node *ptr1 = *head1;
	struct node *ptr2 = *head1;
	int len = 0;
	while (ptr2->next != ptr1){
		ptr2 = ptr2->next;
		len++;
	}
	len++;
	ptr2->next = NULL;
	ptr1 = *head2;
	ptr2 = *head2;
	while (ptr2->next != ptr1){
		ptr2 = ptr2->next;
		len++;
	}
	len++;
	ptr2->next = NULL;
	ptr1 = *head1;
	ptr2 = *head2;
	if (ptr1->data < ptr2->data){// if the condition head1 is the main pointer
		while (ptr1->next != NULL){
			if (ptr1->data <= ptr2->data && ptr1->next->data >= ptr2->data){
				*head2 = ptr2->next;
				ptr2->next = ptr1->next;
				ptr1->next = ptr2;
				ptr1 = ptr1->next->next;
				ptr2 = *head2;
			}
			else if (ptr1->data >= ptr2->data && ptr2->next->data <= ptr1->data){
				*head2 = ptr2->next;
				ptr2->next = ptr1->next->next;
				ptr1->next->next = ptr2;
				ptr2 = ptr1->next->next;
				ptr2 = *head2;

			}
			else{
				ptr1 = ptr1->next;
			}
		}
		if (ptr1->next == NULL){
			ptr1->next = *head2;
		}
		ptr1 = *head1, ptr2 = *head1;
		while (ptr2->next != NULL){
			ptr2 = ptr2->next;
		}
		ptr2->next = *head1;
		return len;
	}
	else{
		while (ptr2->next != NULL){
			if (ptr2->data <= ptr1->data && ptr2->next->data >= ptr1->data){
				*head1 = ptr1->next;
				ptr1->next = ptr2->next;
				ptr2->next = ptr1;
				ptr2 = ptr2->next->next;
				ptr1 = *head1;
			}
			else if (ptr2->data >= ptr1->data && ptr1->next->data <= ptr2->data){
				*head1 = ptr1->next;
				ptr1->next = ptr2->next->next;
				ptr2->next->next = ptr1;
				ptr1 = ptr2->next->next;
				ptr1 = *head1;

			}
			else{
				ptr2 = ptr2->next;
			}
		}
		if (ptr2->next == NULL){
			ptr2->next = *head1;
		}
		ptr1 = *head2, ptr2 = *head2;
		while (ptr2->next != NULL){
			ptr2 = ptr2->next;
		}
		ptr2->next = *head2;
		return len;
	}
}