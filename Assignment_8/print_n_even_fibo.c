/**
 * Program to print n numbers in fibonacci series that are even.
 * Compilation : gcc print_n_even_fibo.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 19/8/2021
 * Ques 1 Assignment_8 - Algorithm .
 *
 */
 

#include<stdio.h>

/* Important Observation -> Observation is based upon fact that every third number in fibonacci
series is an even number , so we just need to print every 3rd number in fibonacci series. */

// Function to print the nth even number in fibonacci series.
long long int print_n_even_fibo(long long int n)
{
    // base case 1 ->
    if(n == 0)
    {
        return 0;
    }
    
    // base case 2 ->
    if(n == 1)
    {
        return 2;
    }

    // base case 3 ->
    if(n == 2)
    {
        return 8;
    }
    
    
    /* We know F(n) = F(n-1) + F(n-2) which can also be written as -> 
    F(n) = (4 * F(n-3)) + F(n-6) , now we want every third number of fibonacci
    series to be printed hence the equation becomes ->
    
    F(3) = (4 * F(2)) + F(1) , where F(2) is 8 and F(1) is 2 , thus more generally ->
    F(n) = (4 * F(n - 1)) + F(n - 2) .   */
    
    long long int answer = (4 * print_n_even_fibo(n - 1)) + print_n_even_fibo(n - 2);
    return answer;

}




int main()
{
    long long int n = 0;
    
    // scanning n.
    // max limit is taken as 30 to avoid overflow.
    printf("Enter any value of n from 1 to 30 \n");
    scanf("%lld" , &n);
    
    printf("Printing %lld numbers in fibonacci series that are even : \n" , n);
    
    int i = 1;
    while(i <= n)
    {
        // calling function to print n even numbers in fibonacci series.
        long long int num = print_n_even_fibo(i);
        printf("%lld \n" , num);
        
        i++;
    }
    
    return 0;
}


