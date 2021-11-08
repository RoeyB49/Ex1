#include "NumClass.h"
#include <stdio.h>
#include <math.h>
int main() {
  
int n1, n2;
  
scanf ("%d %d", &n1, &n2);
  
int p = n1;
  
int j = n2;
  
printf ("The Armstrong numbers are:");
  
for (int i = p; i <= j; i++)
    {
      
if (isArmstrong (i))
	{
printf (" %d", i);
	
}
    
}
 
printf ("%c", '\n');
  
printf ("The Palindromes are:");
  
for (int i = p; i <= j; i++)
    {
      
if (isPalindrome (i))
	{
	  
printf (" %d", i);
	
}
    
}
  
printf ("%c", '\n');
  
printf ("The Prime numbers are:");

  
for (int i = p; i <= j; i++)
    {
      
if (isPrime (i))
	{
	  
printf (" %d", i);
	
}
    
}
  
printf ("%c", '\n');
  
printf ("The Strong numbers are:");
  
for (int i = p; i <= j; i++)
    {
      
if (isStrong (i))
	{
	  
printf (" %d", i);
	
}
    
}

 printf ("%c", '\n');
 
}
