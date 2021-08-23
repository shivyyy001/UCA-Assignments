/*
 * Program to implement Queue using Linked List in C.
 * Compilation : gcc Queue_using_LL.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 23/8/2021
 * Ques 2. Assignment_6 - Linked List.
 *
 */


/*

Runtime Complexities of created Functions :
enqueue()      -> O(1).
dequeue()      -> O(1).
peek()         -> O(1).
is_empty()     -> O(1).
get_size()     -> O(1).
free_queue()   -> O(size). as we need to traverse the Linked List to free all Nodes.

*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Creating a structure node (Linked List Node) to contain next node address and data of its node.
struct Node
{
    struct Node *next;
    int data;
};


// Creating head , tail of Linked List and current size variable.
struct Node *head;
struct Node *tail;
int size;


// Function to initialize queue by making head = NULL , tail = NULL and size = 0.
void initialize_queue()
{
    head = NULL;
    tail = NULL;
    size = 0;
}


// Function to enqueue an element into queue using Linked List Node.
void enqueue(int val)
{
    // creating a new linked list node and assigning val to its data and NULL to its next.
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    
    // if head is NULL ,means size is 0 so just point head and tail to newNode and head's next to NULL.
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        head->next = NULL;
    }
    
    // else attach newNode to tail of linked list and make tail move forward.
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
    
    printf("Added %d at tail of queue \n" , val);
    
    // increase size.
    size++;
}

// Function to dequeue an element from front of queue , which is also the element at head of Linked List.
int dequeue()
{
    if(size == 0)
    {
        printf("Nothing to remove , queue is empty\n");
        return INT_MIN;
    }
    
    // Store node at front in temp and make head point to next node.
    struct Node *temp = head;
    int data = head->data;
    head = head->next;
    
    // decrease the size and free the front node.
    size--;
    free(temp);
    
    // return data of front node which was popped out.
    return data;
}

// Function to check is queue is empty or not.
bool is_empty()
{
    if(size == 0)
    {
        return 1;
    }
    
    return 0;
}


// Function to return front element of queue , without removing it.
int peek()
{
    if(size == 0)
    {
        printf("Queue is empty , no element at front \n");
        return INT_MIN;
    }
    
    int temp = head->data;
    return temp;
}


// Function to return current size of queue.
int get_size()
{
    return size;
}


// Function to free the queue after use.
void free_queue()
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

    printf("Queue freed \n");
}


// Main function to show working of this queue.
int main() 
{
    initialize_queue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
	
    printf("Current size = %d\n" , get_size());
	
    int dequeued_out = dequeue();
    if(dequeued_out != INT_MIN)
    {
        printf("Dequeued out element = %d\n" , dequeued_out);
    }
	
    printf("Peek element = %d\n" , peek());
	
    dequeued_out = dequeue();
    if(dequeued_out != INT_MIN)
    {
        printf("Dequeued out element = %d\n" , dequeued_out);
    }
	
    printf("Current size = %d\n" , get_size());
    printf("Is queue empty ? : %d\n" , is_empty());
	
    printf("Peek element = %d\n" , peek());
	
    free_queue();
	
    printf("Is queue empty ? : %d\n" , is_empty());

    return 0;

}
