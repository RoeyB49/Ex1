#include "NumClass.h"
#include <stdio.h>
#include <math.h>
int isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int Factorial(int n){
    int counter=1;
    for(int i=1;i<=n;i++){
        counter*=i;
    }
    return counter;
}
int isStrong(int n){
   int counter=0;
   int p=0;
   int original=n;
   while(n!=0){
       p=n%10;
       counter+=Factorial(p);
       n=n/10;
   }
   if(counter==original){
       return 1;
   }
   else{
       return 0;
   }
}
