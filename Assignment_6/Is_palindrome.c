/*
 * Program to check if given Singly Linked List is palindrome or not , on Leetcode.
 * Compilation : gcc Is_palindrome.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 25/8/2021
 * Ques 4. Assignment_6 - Linked List.
 *
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// Function to return Middle Node of Linked List.
struct ListNode *find_middle(struct ListNode *head)
{
    // Slow and fast pointers.
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // Moving fast pointer by 2 steps and slow by 1 step forward to reach middle node.
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // returning slow node which is pointing to middle of Linked List.
    return slow;
}


// Function to reverse a Linked List.
struct ListNode *reverse_LL(struct ListNode *head)
{
    // Making current , previous and next nodes.
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    struct ListNode *nxt = head->next;
    
    // Moving till current reaches NULL.
    while(curr != NULL)
    {
        // making current's next point to previous node , to make a node reverse its direction.
        curr->next = prev;
        
        // making prev = curr and curr = nxt to move forward.
        prev = curr;
        curr = nxt;
       
        // if nxt not equals NULL then moving nxt to next node.
        if(nxt != NULL)
        { 
            nxt = nxt->next;
        }
    }
    
    // returning prev node which has head of reversed linked list.
    return prev;    
}


// Function to check if given Singly Linked List is palindrome or not.
bool isPalindrome(struct ListNode* head)
{
    /* base case -> if head is NULL or head's next is NULL then the Linked List is palindrome 
    hence return true  */
    if(head == NULL || head->next == NULL)
    {
        return true;
    }
    
    // Finding the middle Node of Linked list by calling find_middle function made above.
    struct ListNode *mid = find_middle(head);
    
    // making list1 node which has left half of Linked List.
    struct ListNode *list1 = head;
    
    // making list2 node which has right half of Linked List.
    struct ListNode *list2 = mid->next;

    // reversing the right half of Linked List by calling reverse_LL function made above.
    list2 = reverse_LL(list2);
    
    // comparing the two half's till List2 reaches NULL.
    while(list2 != NULL)
    {
        /* if data of both nodes at any point is not equal means Linked List is not
        palindrome , hence return false.   */
        if(list1->val != list2->val)
        {
            return false;
        }
        
        // moving list1 and list2 forward.
        list1 = list1->next;
        list2 = list2->next;
    }
    
    // returing true indicating Linked List is palindrome.
    return true;
    
}
