#include <cstdio>
#include <algorithm>

using namespace std;

int g[40];
int s[6] {0};

int main(){
	
	
	int num;
	scanf("%d",&num);
	
	for(int i=0;i<num;i++){
		
		scanf("%d",&g[i]);
	}
	
	
	sort(g,g+(num+1),greater<int>());
	
	for(int i =0;i<num;i++){
		
		if(g[i] == 100){
			s[0]++; 
			continue;
		}else if(g[i] >=90 && g[i] <=99){
			s[1]++;
			continue;
		}else if(g[i] >= 80 && g[i] <= 89){
			s[2] ++;
			continue;
		}else if(g[i] >= 70 && g[i] <= 79){
			s[3]++;
			continue;
		}else if(g[i] >= 60 && g[i] <=69){
			s[4]++;
			continue;
		}else{
			
			s[5]++;
			continue;
		}
	}
	
	
	
	for(int i=0;i<num;i++){
		printf("%d\n",g[i]);
	}
	
	for(int i=0;i<6;i++){
		
		printf("%d ",s[i]);
		
	}
		
	
	
	return 0;
}
