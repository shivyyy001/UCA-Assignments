/*
 * Program to rotate a linked list to right by K places , on Leetcode.
 * Compilation : gcc Rotate_by_K.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 27/8/2021
 * Ques 9. Assignment_6 - Linked List.
 *
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// Function to return length of Linked List.
int length(struct ListNode *head)
{
    int count = 0;
    
    // Traversing the Linked list till head is not NULL to count nodes.
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    
    return count;
}


// Function to rotate a linked list to right by K places.
struct ListNode* rotateRight(struct ListNode* head, int k)
{
    // base case -> if head is NULL or head's next is NULL , return head.
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    // calculate length of linked list.
    int len = length(head);
    
    // make k = k % len because k can even be greater than length of linked list.
    k = k % len;
    
    // making a temporary node to traverse the linked list.
    struct ListNode *temp = head;
    
    // traversing till we reach last node.
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    // making last node connect with head.
    temp->next = head;
    
    // making count = len - k - 1 to traverse till length - rotations needed.
    int count = len - k - 1;
    
    // traversing till count is greater than 0.
    while(count > 0)
    {
        head = head->next;
        count--;
    }
    
    // storing the head's next in temp to store updated head after rotation.
    temp = head->next;
    
    // breaking the link to delete cycle.
    head->next = NULL;
    
    // returning temp , which has head of the updated rotated Linked list.
    return temp;
    
}
