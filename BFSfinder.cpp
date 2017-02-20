nclude <iostream>
#include <stdio.h>
#include <string.h>

int map[102][102];
int x[10001],y[10001],z[10001], path_x[10001], path_y[10001]; //z는 방향이랍니다~ 

int main()
{
	int n,m;
	int i,j;
	int h,t; //head와 tail 이예요~
	int p,q;
	int k=0;
	
	freopen("input.txt","r",stdin);
	
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%1d", &map[i][j]);
		}
	}
	
	h = t = 1;
	x[1] = 1;
	y[1] = 1;
	map[1][1] = 0;
	
	while(h<=t){
		p = x[h];
		q = y[h];
		
		if(p == n && q == m) {
			break;
		}
		if(map[p-1][q] == 1) {
			t++;
			x[t] = p-1;
			y[t] = q;
			z[t] = h;
			
			map[p-1][q] = 0;
		}
		
		if(map[p+1][q] == 1) {
			t++;
			x[t] = p+1;
			y[t] = q;
			z[t] = h;
			
			map[p+1][q] = 0;
		}
		
		if(map[p][q-1] == 1) {
			t++;
			x[t] = p;
			y[t] = q-1;
			z[t] = h;
			
			map[p][q-1] = 0;
		}
		
		if(map[p][q+1] == 1) {
			t++;
			x[t] = p;
			y[t] = q+1;
			z[t] = h;
			
			map[p][q+1] = 0;
		}
		
		h++;
	}
	
	int re = 0;
	
	while(h>=1){
		k++;
		path_x[k] = x[h];
		path_y[k] = y[h];
		h = z[h];
		re++;
	}
	
	std::cout<<"2017 LeeYouSup \n"<<"Copyright all rights reserved.\n";
	std::cout<<"--------------------------------\n";
	
	for(i=k;i>=1;i--) {
		std::cout<<"("<<path_x[i]<<","<<path_y[i]<<") ";

	}
	
	std::cout<<"\n"<<re;
	
	return 0;
}
