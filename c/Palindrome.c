/*
A palindrome number is a number that is same after reverse. 
For example 121, 34543, 343, 131, 48984 are the palindrome numbers.
*/
#include <stdio.h>
int main()
{
    int n, m, rem, rev=0;
    printf("Enter a Number:");
    scanf("%d",&n); //Take Input
    m=n;  // assigning value for backup
  
    while(m > 0)
    {
        rem = m % 10;
        rev = rev * 10 +rem;
        m = m / 10;
    }
    if(n == rev)
    {
        printf("%d is a Palindrome",n);
    }
    else
    {
        printf("%d is not a Palindrome",n);
    }
    return 0;
}
