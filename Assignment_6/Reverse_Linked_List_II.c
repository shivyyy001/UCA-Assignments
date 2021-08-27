/*
 * Program to reverse a linked list from left to right , on Leetcode.
 * Compilation : gcc Reverse_Linked_List_II.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 27/8/2021
 * Ques 7. Assignment_6 - Linked List.
 *
 */



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// Function to reverse a linked list from left to right.
struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    // base case => if head is NULL or head's next is NULL or left == right then return head.  
    if(head == NULL || head->next == NULL || left == right)
    {
        return head;
    }
    
    // Making current and previous nodes.
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    
    // moving to left's position node.
    while(left > 1)
    {
        prev = curr;
        curr = curr->next;
        left--;
        
        /* doing right-- as well so as to store right-left+1 in right , which is size of that part of 
        Linked list which is to be reversed.  */
        right--;
    }
    
    // before node to store left half of that part of linked list which is going to be reversed.
    struct ListNode *before = prev;
    
    // end_of_reversed node to store end of reversed linked list.
    struct ListNode *end_of_reversed = curr;
    
    // additional node to help reverse the Linked list
    struct ListNode *nxtt = curr->next;
    
    // traverse rill right is not 0.
    while(right > 0)
    {
        // reversing the linked list part which was from left to right.
        curr->next = prev;
        prev = curr;
        curr = nxtt;
        if(nxtt != NULL)
        {
            nxtt = nxtt->next;
        }
        
        right--;
    }
    
    // if we are not asked to reverse the Linked list from head , then put prev in before's next.
    if(before != NULL)
    {
        before->next = prev;
    }
    
    // else just make head = prev.
    else
    {
        head = prev;
    }
    
    // put curr in end_of_reversed's next to attach right remaining part of list.
    end_of_reversed->next = curr;
    
    // returning head.
    return head;
    
}
