#include <stdio.h>

int prime(long long num){
    if(num == 2) return 1;
    if(num <=1) return 0;
    for(long long i=2;i<num;i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

int palin(long long num){
    long long temp1 = num;
    long long counter = 0;
    while(temp1 != 0){
        temp1 /= 10;
        counter++;
    }
    long long arr[counter];
    for(long long i=0;i<=counter-1;i++){
        arr[i] = num % 10;
        num /= 10;
    }
    for(long long i=0;i<=counter/2-1;i++){
        if(arr[counter-i-1] != arr[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    long long a,b;
    scanf("%lld %lld",&a,&b);
    for(long long i=a;i<=b;i++){
        if(palin(i) && prime(i)){
            printf("%lld\n",i);
        }
    }
}