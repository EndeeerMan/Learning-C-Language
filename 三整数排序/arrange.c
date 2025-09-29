#include<stdio.h>

int main(){
	int a,b,c;
	int i;
	int mem;   //交换数字位置临时存储

	scanf("%d %d %d",&a,&b,&c);

	int arr[3] = {a,b,c};
		flag:for(i=0;i<=1;i++){
				if(arr[i] > arr[i+1]){    //根据我之前看的视频，这个应该是冒泡排序
					mem = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = mem;
					mem = 0;
				}
			}

	if(arr[0] <= arr[1] && arr[1] <= arr[2]){  //判断是否符合排序
		for(i=0;i<=2;i++){
			printf("%d ",arr[i]);   //符合就输出
		}
	}else{
		goto flag;   //不符合打回重新排
	}

	return 0;
}