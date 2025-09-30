#include <stdio.h>
#include <math.h>

int main(){
	int x = 1100;
	int y = 11;
	int z[10] = {0,1,2,3,4,5,6,7,8,9};
	int mem = 0;
	for(int i1=1;i1<=9;i1++){
		mem = x*z[i1];
		for(int i2=0;i2<=9;i2++){
			mem+=y*z[i2];
			int root = (sqrt(mem));
			if(root * root == mem){
				printf("%d",mem);
			}else{
				mem-=y*z[i2];
			}
		}
	}
	return 0;
}