#include <stdio.h>
#include <stdlib.h>


int main() {
    int i,x,n,y;
	int a[500000];	
	while(scanf("%d",&x)!=EOF){
		for(n=0;;n++){
			scanf("%d",&a[n]);
			if(getchar()=='\n')
			break;
		}
		y=a[0]*n;
		for(i=1;i<n;i++){
		   y=y*x+a[i]*(n-i);
		} 
		printf("%d\n",y);
	}
	return 0;
}