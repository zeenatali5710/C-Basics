/*
 ============================================================================
 Name        : LinkedList.c
 Author      : Zeenat Ali
 Version     :
 Copyright   : Your copyright notice
 Description : Linked List, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*create type LLNode to define struct LLNode*/
typedef struct LLNode {
	char val;
	struct LLNode *next;
} LLNode;

/*makeNode function allocates dynamic memory for node of type LLNode in heap*/
LLNode* makeNode(char val) {
	LLNode *new = malloc(sizeof(LLNode));
	new->val = val;
	new->next = NULL;
	return new;
}

/*printList will print the entire linked list; walker traverse the list*/
void printList(LLNode **head) {
	if (*head == NULL) {
		printf("\nList is empty");
		return;
	}
	LLNode *walker = NULL;
	walker = *head;
	printf("\nLinked List:");
	while (walker != NULL) {
		printf(" %c", walker->val);
		printf("-->");
		walker = walker->next;
	}
}

/*countNodes will count the number of nodes in linked list*/
int countNodes(LLNode **head) {
	int count = 0;
	if (*head == NULL) {
		printf("\nList is empty");
		return 0;
	}
	LLNode *walker = NULL;
	walker = *head;
	while (walker != NULL) {
		count++;
		walker = walker->next;
	}
	return count;
}

/*freeList will free the dynamically allocated memory by linked list */
void freeList(LLNode **head) {
	LLNode *reaper = NULL;
	LLNode *walker = NULL;
	walker = *head;
	while (walker != NULL) {
		reaper = walker;
		walker = walker->next;
		free(reaper);
		reaper = NULL;
	}
	walker = NULL;
	printf("\nList is freed");
}

/*insertNode will insert node at the front of a linked list*/
void insertNode(LLNode **head, LLNode *node) {

	if (node == NULL) {
		*head = node;
	} else {
		node->next = *head;
		*head = node;
	}
	printf("Node %c inserted\n", node->val);
}

/*removeNode will remove node from the front of a linked list*/
void removeNode(LLNode **head) {
	if (*head == NULL) {
		printf("\nList is empty, no nodes to remove");
		return;
	}
	LLNode *walker = *head;
	*head = walker->next;
	printf("\nFront node removed");
}

int main() {
	LLNode *Node1 = makeNode('A');
	LLNode *Node2 = makeNode('B');
	LLNode *Node3 = makeNode('C');
	LLNode *head = NULL;
	insertNode(&head, Node3);
	insertNode(&head, Node2);
	insertNode(&head, Node1);
	printList(&head);
	int count = countNodes(&head);
	printf("\nNo. of nodes:  %d", count);
	removeNode(&head);
	printList(&head);
	removeNode(&head);
	printList(&head);
	removeNode(&head);
	printList(&head);
	removeNode(&head);
	printList(&head);
	freeList(&head);
	head = NULL;
	printList(&head);

}

