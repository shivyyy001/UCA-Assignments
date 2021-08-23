/*
 * Program to implement Stack using Linked List in C.
 * Compilation : gcc Stack_using_LL.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 23/8/2021
 * Ques 1. Assignment_6 - Linked List.
 *
 */


/*

Runtime Complexities of created Functions :
push()         -> O(1).
pop()          -> O(1).
peek()         -> O(1).
is_empty()     -> O(1).
get_size()     -> O(1).
free_stack()   -> O(size). as we need to traverse the Linked List to free all Nodes.

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


// Creating head of Linked List and current size variable.
struct Node *head;
int size;


// Function to initialize stack by making head = NULL and size = 0.
void initialize_stack()
{
    head = NULL;
    size = 0;
}


// Function to push an element into stack using Linked List Node.
void push(int val)
{
    // creating a new linked list node and assigning val to its data and NULL to its next.
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;   

    // if head is NULL ,means size is 0 so just point head to newNode and head's next to NULL.
    if(head == NULL)
    {
        head = newNode;
        head->next = NULL;
    }
    
    // else attach newNode at front of linked list and make head point to that newNode.
    else
    {
        newNode->next = head;
        head = newNode;
    }
    
    printf("Added %d at top of stack \n" , val);
    
    // increase size.
    size++;
}

// Function to pop an element from top of stack , which is also the element at head of Linked List.
int pop()
{
    if(size == 0)
    {
        printf("Nothing to remove , stack is empty\n");
        return INT_MIN;
    }
    
    // Store node at top in temp and make head point to next node.
    struct Node *temp = head;
    int data = head->data;
    head = head->next;
    
    // decrease the size and free the top node.
    size--;
    free(temp);
    
    // return data of top node which was popped out.
    return data;
}

// Function to check is stack is empty or not.
bool is_empty()
{
    if(size == 0)
    {
        return 1;
    }
    
    return 0;
}


// Function to return top element of stack , without removing it.
int peek()
{
    if(size == 0)
    {
        printf("Stack is empty , no element at top \n");
        return INT_MIN;
    }
    
    int temp = head->data;
    return temp;
}


// Function to return current size of stack.
int get_size()
{
    return size;
}


// Function to free the stack after use.
void free_stack()
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

    printf("Stack freed \n");
}


// Main function to show working of this stack.
int main() 
{
    initialize_stack();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
	
    printf("Current size = %d\n" , get_size());
	
    int popped_out = pop();
    if(popped_out != INT_MIN)
    {
        printf("Popped out element = %d\n" , popped_out);
    }
	
    printf("Peek element = %d\n" , peek());
	
    popped_out = pop();
    if(popped_out != INT_MIN)
    {
        printf("Popped out element = %d\n" , popped_out);
    }
	
    printf("Current size = %d\n" , get_size());
    printf("Is stack empty ? : %d\n" , is_empty());
	
    printf("Peek element = %d\n" , peek());
	
    free_stack();
	
    printf("Is stack empty ? : %d\n" , is_empty());
	
    return 0;

}
