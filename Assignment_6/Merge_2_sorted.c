/*
 * Program to Merge two sorted Linked lists , on Leetcode.
 * Compilation : gcc Merge_2_sorted.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 27/8/2021
 * Ques 8. Assignment_6 - Linked List.
 *
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// Function to merge two sorted Linked lists.
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    // if both l1 and l2 are NULL return NULL.
    if(l1 == NULL && l2 == NULL)
        return NULL;
    
    // else if l2 is not NULL return l2.
    else if(l1 == NULL && l2 != NULL)
        return l2;
    
    // else if l1 is not NULL return l1.
    else if(l1 != NULL && l2 == NULL)
        return l1;
    
    // Making a temp node.
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    
    // Making an extra node t that points to temp node.
    struct ListNode *t = temp;
    
    // Traversing till l1 is not NULL and l2 is not NULL.
    while(l1 != NULL && l2 != NULL)
    {
        // if value of l1 is less than that of l2 then point t's next to l1 and move both t and l1 ahead.
        if(l1->val < l2->val)
        {
            t->next = l1;
            l1 = l1->next;
            t = t->next;
        }
        
        // else if value of l2 is less than that of l1 then point t's next to l2 and move both t and l2 ahead. 
        else
        {
            t->next = l2;
            l2 = l2->next;
            t = t->next;  
        }
    }
        
    /* if l1 is not NULL then put l1 at t's next to attach remaining l1 linked list
    with the sorted Linked list.  */
    if(l1 != NULL)
    {
        t->next = l1;
    }
    
    /* else if l2 is not NULL then put l2 at t's next to attach remaining l2 linked list 
    with the sorted Linked list.  */
    else if(l2 != NULL)
    {
        t->next = l2;
    }
     
    // returning temp's next which is head of the final sorted Linked List. 
    return temp->next;
}

