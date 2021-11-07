#include <stdio.h>
#include <math.h>
#include "NumClass.h"
int isArmstrong(int n)
{
   double power=0,p=0,counter=0;
   double original=n;
   while(n!=0){
       n=n/10;
       power++;
   }
   n=original;
   while(n!=0){
       p=n%10;
       counter+=pow(p,power);
       n=n/10;
   }
   if(counter==original){
   return 1;
   }
   else{
   return 0;
   }
   
}
int isPalindrome(int n){
    int original=n;
    int counter=0;
    while(n!=0){
        n=n/10;
        counter++;
    }
    n=original;
    int arr[counter];
    for(int i=counter-1;i>=0;i--){
        arr[i]=n%10;
        n=n/10;
    }
    for(int i=0,j=counter-1;i<j;i++,j--){
        if(arr[i]!=arr[j]){
            return 0;
        }
    }
    return 1;
}
