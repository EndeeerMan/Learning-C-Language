#include <stdio.h>

int main(){
    int n,r;
    while(scanf("%d %d",&n,&r) != EOF){
        long long sum = 1;
        if(n-r <= r){
            for(int i=r+1;i<=n;i++){
                sum *= i;
            }
            for(int i=1;i<=n-r;i++){
                sum /= i;
            }
        }else{
            for(int i=n-r+1;i<=n;i++){
                sum *= i;
            }
            for(int i=1;i<=r;i++){
                sum /= i;
            }
        }
        printf("%lld\n",sum);
    }
}