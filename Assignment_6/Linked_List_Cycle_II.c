/*
 * Program to return the node from where cycle begins, if cycle exists, in the singly linked list 
 * , on Leetcode.
 *
 * Compilation : gcc Linked_List_Cycle_II.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 27/8/2021
 * Ques 10. Assignment_6 - Linked List.
 *
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// Function to return the node from where cycle begins, if cycle exists, in the singly linked list.
struct ListNode *detectCycle(struct ListNode *head) 
{
    // base case , if head is NULL return NULL.
    if(head == NULL)
    {
        return NULL;
    }
    
    // Make fast and slow nodes that points to head.
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    // traversing till fast or fast's next has'nt reached NULL.
    while(fast!=NULL && fast->next!=NULL)
    {
        // Moving slow pointer by 1 step and fast by 2 step (Floyd's Cycle-Finding Algorithm).
        slow = slow->next;
        fast = fast->next->next;
        
        // if at any point slow and fast are equal means we have found a cycle thus break.
        if(slow == fast)
        {
            break;
        }
    }
    
    // thus if fast is NULL or fast's next is NULL means there is no cycle , return NULL.
    if(fast == NULL || fast->next == NULL)
    {
        return NULL;
    }
    
    // point slow to head.
    slow = head;
    
    // move till fast and slow dont meet. Where they meet that will be the starting point of Cycle.
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    // return that starting point of cycle.
    return slow;
}
