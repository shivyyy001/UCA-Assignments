/*
 * Program to Remove Nth node from end of Linked list , on Leetcode.
 * Compilation : gcc Remove_Nth_node_end.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 27/8/2021
 * Ques 6. Assignment_6 - Linked List.
 *
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// Function to remove Nth node from end of Linked List.
struct ListNode* removeNthFromEnd(struct ListNode* head , int n)
{
    // Making a dummy node with val = -1 and with its next pointing to head.
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    
    // Making a slow and fast pointer that points to dummy node.
    struct ListNode *slow = dummy;
    struct ListNode *fast = dummy;
    
    /* Making fast pointer cover the distance 'n - 1' from first node so that afterwards slow pointer 
    can cover 'length - n - 1' distance to delete node at nth position from end.  */
    while(n--)
    {
        fast = fast->next;
    }
    
    /* Moving slow and fast pointer by one step till fast's next is not NULL to make sure slow pointer       reaches one node before the nth node from end  */
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    // pointing the slow's next to its next to next node to delete link with Nth node from end.
    if(slow->next != NULL)
    {
        slow->next = slow->next->next;
    }
    
    // returning dummy's next which is head of the updated Linked List.
    return dummy->next;
       
}
