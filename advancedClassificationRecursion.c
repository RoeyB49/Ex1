#include <stdio.h>
#include <math.h>
#include "NumClass.h"
//find the power of each element
int PowerCheck(int n){
    if(n==0){
        return 0;
    }
    return 1+PowerCheck(n/10);
}
int ArmHelper(int n, int counter,int power,int original){
    if(n==0){
        return counter;
    }
    counter+=pow(n%10,power);
    n=n/10;
    return ArmHelper(n,counter,power,original);
}

int isArmstrong(int n){
    int power=PowerCheck(n);
    int original=n;
    return ArmHelper(n, 0,power,original)==original;
}
int PalindromeHelper(int n){
     if(n == 0){
        return 0;
    }
    return ((n%10*pow(10, PowerCheck(n)-1)) + PalindromeHelper(n/10));
}
int isPalindrome(int n){
    if(n == PalindromeHelper(n))
    {
        return 1;
    }else{
        return 0; 
    }
    }
