/*
 * Program to Remove Duplicates from sorted linked list , on Leetcode.
 * Compilation : gcc Remove_duplicates.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 23/8/2021
 * Ques 5. Assignment_6 - Linked List.
 *
 */
 
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// Function to Remove Duplicates from sorted linked list.
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    /* base case -> if head is NULL or head's next is NULL then there are no duplicates , 
    hence return head.  */
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    // creating a dummy node with val = -1 and who's next is pointing to head currently. 
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    dummy->val = -1;
    
    // creating current node which points to dummy node.
    struct ListNode *curr = dummy;
    
    // Traversing till head is not NULL.
    while(head != NULL)
    {
        // if head's next is not NULL and if there are consecutive nodes equal.
        if(head->next != NULL && head->val == head->next->val)
        {
            // keep moving forward until we reach a point where consecutive nodes are not equal.
            while(head->next!=NULL && head->val == head->next->val)
            {
                head=head->next;
            }
            
            /* point current's next to head's next indicating that head's next might be a node 
            which is'nt repeated.   */
            curr->next = head->next;
        }
        
        else
        {
            // moving current forward indicating that current's next node is not repeated so move to next node.
            curr = curr->next;
        }
        
        // moving head forward.
        head = head->next;
        
    }
    
    // returning dummy's next which will have only those nodes of Linked list which are'nt repeated.
    return dummy->next;
    
}

