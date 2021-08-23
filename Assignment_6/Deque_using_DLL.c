/*
 * Program to implement Deque using Doubly Linked List in C.
 * Compilation : gcc Deque_using_DLL.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 23/8/2021
 * Ques 3. Assignment_6 - Linked List.
 *
 */


/*

Runtime Complexities of created Functions :

enqueue_front()     -> O(1).
enqueue_rear()      -> O(1).
dequeue_front()     -> O(1).
dequeue_rear()      -> O(1).
peek_front()        -> O(1).
peek_rear()         -> O(1).
is_empty()          -> O(1).
get_size()          -> O(1).
is_present()        -> O(size) as we need to traverse the Linked List to check.
free_deque()        -> O(size) as we need to traverse the Linked List to free all Nodes.

*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


/* Creating a structure node (Doubly Linked List Node) to contain next node address , previous node address 
and data of its node.  */
struct Node
{
    struct Node *next;
    struct Node *prev;
    int data;
};


// Creating head , tail of Doubly Linked List and current size variable.
struct Node *head;
struct Node *tail;
int size;


// Function to initialize deque by making head = NULL , tail = NULL and size = 0.
void initialize_deque()
{
    head = NULL;
    tail = NULL;
    size = 0;
}


// Function to enqueue an element at front of deque using Doubly Linked List Node.
void enqueue_front(int val)
{
    // creating a new Doubly linked list node and assigning val to its data and NULL to its next and prev.
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    // if head is NULL ,means size is 0 so just point head and tail to newNode and head's next and prev to NULL.
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        head->next = NULL;
        head->prev = NULL;
    }
    
    // else attach head of present Doubly Linked list to newNode and point head to newNode to add a node at front.
    else
    {
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = NULL;
        
        head = newNode;
    }
    
    printf("Added %d at front of deque \n" , val);
    
    // increase size.
    size++;
}


// Function to enqueue an element at rear of deque using Doubly Linked List Node.
void enqueue_rear(int val)
{
    // creating a new Doubly linked list node and assigning val to its data and NULL to its next and prev.
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    // if head is NULL ,means size is 0 so just point head and tail to newNode and head's next and prev to NULL.
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        head->next = NULL;
        head->prev = NULL;
    }
    
    // else attach newNode to tail of current Doubly Linked List and move tail one place ahead.
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = NULL;
        
        tail = tail->next;
    }
    
    printf("Added %d at rear of deque \n" , val);
    
    // increase size.
    size++;
}


// Function to dequeue an element from front of deque , which is also the element at head of Doubly Linked List.
int dequeue_front()
{
    if(size == 0)
    {
        printf("Nothing to remove from front, deque is empty\n");
        return INT_MIN;
    }
    
    // Store node at front in temp and make head point to next node and also break the link with prev node.
    struct Node *temp = head;
    int data = head->data;
    head = head->next;
    head->prev = NULL;
    
    // decrease the size and free the front node.
    size--;
    free(temp);
    
    // return data of front node which was dequeued out.
    return data;
}


// Function to dequeue an element from rear of deque , which is also the element at tail of Doubly Linked List.
int dequeue_rear()
{
    if(size == 0)
    {
        printf("Nothing to remove from rear, deque is empty\n");
        return INT_MIN;
    }
    
    // Store node at tail in temp and make tail point to prev node and also break link with next node.
    struct Node *temp = tail;
    int data = tail->data;
    tail = tail->prev;
    tail->next = NULL;
    
    // decrease the size and free the rear node.
    size--;
    free(temp);
    
    // return data of rear node which was dequeued out.
    return data;
}


// Function to return front node data of deque , without removing it.
int peek_front()
{
    if(size == 0)
    {
        printf("Deque is empty , no element at front \n");
        return INT_MIN;
    }
    
    int temp = head->data;
    return temp;
}


// Function to return rear node data of deque , without removing it.
int peek_rear()
{
    if(size == 0)
    {
        printf("Deque is empty , no element at rear \n");
        return INT_MIN;
    }
    
    int temp = tail->data;
    return temp;
}


// Function to check if a particular element is present in deque or not.
bool is_present(int key)
{
    if(size == 0)
    {
        return 0;
    }
    
    // Node to traverse the Doubly Linked List.
    struct Node *traverse = head;
    
    while(traverse != NULL)
    {
        // if key found , return 1.
        if(traverse->data == key)
        {
            return 1;
        }
        
        traverse = traverse->next;
    }
    
    // if key not found , return 0.
    return 0;
}


// Function to check is deque is empty or not.
bool is_empty()
{
    if(size == 0)
    {
        return 1;
    }
    
    return 0;
}


// Function to return current size of deque
int get_size()
{
    return size;
}


// Function to free the deque after use.
void free_deque()
{
    while(head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        
        printf("Node %d freed \n" , temp->data);
        free(temp);
    }
    
    size = 0;
    head = NULL;
    tail = NULL;    

    printf("Deque freed \n");
}


// Main function to show working of this deque.
int main() 
{
    initialize_deque();
    
    enqueue_front(10);
    enqueue_front(20);
    enqueue_rear(30);
    enqueue_front(40);
    enqueue_rear(50);
	
    printf("\nTraversing Deque from front -> \n");
    struct Node *travforward=head;
    while(travforward != NULL)
    {
        printf("%d " , travforward->data);
        travforward = travforward->next;
    }
    printf("\n");
	
    printf("\nTraversing Deque from rear -> \n");
    struct Node *travreverse = tail;
    while(travreverse != NULL)
    {
        printf("%d " , travreverse->data);
        travreverse = travreverse->prev;
    }
    printf("\n\n");
	
    printf("Current size = %d\n" , get_size());
	
    int dequeued_out_rear = dequeue_rear();
    if(dequeued_out_rear != INT_MIN)
    {
        printf("Dequeued out element from rear = %d\n" , dequeued_out_rear);
    }
	
    printf("Is %d present in deque ? : %d \n" , dequeued_out_rear , is_present(dequeued_out_rear));
	
    printf("Peek element from rear = %d\n" , peek_rear());
	
    int dequeued_out_front = dequeue_front();
    if(dequeued_out_front != INT_MIN)
    {
        printf("Dequeued out element from front = %d\n" , dequeued_out_front);
    }
	
    printf("Current size = %d\n" , get_size());
    printf("Is deque empty ? : %d\n" , is_empty());
	
    printf("Peek element from front = %d\n" , peek_front());
	
    printf("Is %d present in deque ? : %d \n" , 30 , is_present(30));
	
    free_deque();
	
    printf("Is deque empty ? : %d\n" , is_empty());

    return 0;

}
