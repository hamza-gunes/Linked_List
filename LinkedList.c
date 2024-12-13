#include <stdio.h>
#include <stdlib.h>

// Hamza Gunes - 05/12/2024 - Linked List.

struct list {
    int key;
    struct list *next;
};

struct list* CreateNode(int key) {
	
    struct list *NewNode = (struct list*)malloc(sizeof(struct list));

    if (NewNode == NULL) {
        printf("Node Creation Error");
        exit(1);
    }

    NewNode->key = key;
    NewNode->next = NULL;

    return NewNode;
}

void PrintLinkedList(struct list *root) {
	
    struct list *iter = root;

    while (iter != NULL) {
        printf("%d\n", iter->key);
        iter = iter->next;
    }
}

void AddToEnd(struct list **root, int key) {
	
    struct list *iter = *root;

    while (iter->next != NULL) {
        iter = iter->next;
    }

    iter->next = CreateNode(key);
}

void AddToHead(struct list **root, int key){
			
	struct list *NewNode = CreateNode(key);
	
	NewNode->next = *root;
	*root = NewNode;	
}

void DeleteFromEnd(struct list **root){
		
	struct list *iter = *root;
	
	if (iter->next == NULL){
		printf("You Can't Delete Root...\n");
		exit(1);
	}
	
	struct list *temp = iter;
	
	while (iter->next != NULL){
		
		temp = iter;
		iter = iter->next;
			
	}
	
	free(iter);
	temp->next = NULL;
}

void DeleteFromHead(struct list **root){
	
	struct list *temp = *root;
	
	if (temp->next == NULL){
		printf("You Can't Delete Root...\n");
		exit(1);
	}
	
	*root = temp->next;
	free(temp);
}

void AddNodeAfterKey(struct list **root, int key, int key2){
	
	struct list *iter = *root;
	
	while(iter != NULL && iter->key != key){
		
		iter = iter->next;		
	}
	
	if(iter == NULL){
		
		printf("Key not found\n");
		exit(1);
	}
	
	struct list *NewNode = CreateNode(key2);
	NewNode->next = iter->next;
	iter->next = NewNode;		
}

void DeleteNodeWithKey(struct list **root, int key){
	
	struct list *iter = *root;
	
	if(iter->next == NULL && iter->key == key){
		printf("You Can't Delete Node...\n");
		exit(1);
	}
	
	struct list *temp = iter;
	
	while(iter != NULL && iter->key != key){
		
		temp = iter;
		iter = iter->next;
	}
	
	if(iter == NULL){
		printf("Key not found...\n");
		exit(1);
	}
	
	temp->next = iter->next;
	free(iter);
}

void ReverseLinkedList(struct list **root){
	
	struct list *back = NULL;
	struct list *iter = *root;
	struct list *forward = NULL;
	
	while (iter != NULL){
		
		forward = iter->next;
		iter->next = back;
		back = iter;
		iter = forward;
		
	}
	*root = back;
}

int main() {
	
    struct list *root = CreateNode(10);

	AddToHead(&root, 0);
    AddToEnd(&root, 20);
    AddToEnd(&root, 30);
    AddToEnd(&root, 40);
    AddToEnd(&root, 50);
    AddToEnd(&root, 60);
    AddToEnd(&root, 70);
    AddToEnd(&root, 80);
    AddToEnd(&root, 90);
    AddToEnd(&root, 100);
    
    
    printf("------List------\n");
    PrintLinkedList(root);
    
    printf("\n------New List------\n");
   	DeleteFromEnd(&root);
   	DeleteFromHead(&root);
   	AddNodeAfterKey(&root, 50, 55);
   	DeleteNodeWithKey(&root, 70);
   	PrintLinkedList(root);
   	
   	printf("\n------Reversed List------\n");
   	ReverseLinkedList(&root); 	  
    PrintLinkedList(root);

    return 0;
}