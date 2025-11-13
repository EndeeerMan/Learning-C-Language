#include <stdio.h>

int main(){
    unsigned long long n,r;
    while(scanf("%llu %llu",&n,&r) != EOF){
        unsigned long long sum = 1;
        if(n-r <= r){
            for(unsigned long long i=r+1;i<=n;i++){
                sum *= i;
            }
            for(unsigned long long i=1;i<=n-r;i++){
                sum /= i;
            }
        }else{
            for(unsigned long long i=n-r+1;i<=n;i++){
                sum *= i;
            }
            for(unsigned long long i=1;i<=r;i++){
                sum /= i;
            }
        }
        printf("%llu\n",sum);
    }
}