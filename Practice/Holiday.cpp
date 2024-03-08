#include <cstdio>

using namespace std;


/*

Calculate total holiday days  in one year.

YangLi Festival:
Januray 1st,1-holiday
May 1st,1-holiday
October 1st,3-holidays
December 25th,1-holiday

YingLi Festival:
Sping Festival: YingLi's 1m1d,3-holidays.
QingMing Festival:YangLi's  some day between 4m4d-4m6d.
Duanwu Festival: YingLi's 5m5d, 1-holiday.
ZhongQiu Festival: YingLi's 8m15d,1-holiday

Input:
year;
Spring Festival date;
Qingming Festival date;
DuanWu Festival date;
ZhongQiu Festival date;

w:This year 's Januray 1st  is which day of one week, e.g.Monday:1,Tuesday:2...

Output:
total holidays.
*/

int mm[10] {1,5,10,10,10,12};	//All festivals' YangLi date.
int dd[10] {1,1,1,2,3,25}; 


int days[]{0,31,28,31,30,31,30,31,31,30,31,30,31};


void nextday(int& _y,int& _m,int& _d){
	
	_d++;
	
	if(_d == days[_m]+1){
		
		_d = 1;
		_m++;
	}
		
}

int main(){
	
	int y,w,Mcurrent,Dcurrent,SpringF,result;;
	scanf("%d",&y);
	
	for(int i=6;i<10;i++){
		scanf("%d%d",&mm[i],&dd[i]);	// Spring Festival,QingMing Festival,DuanWu Festival,ZhongQiu Festival;
	}
	
	scanf("%d",&w);
	
	if((y %4==0 && y%100 !=0) || y %400 ==0){
		days[2]++;
	}
	 
	
	Mcurrent = Dcurrent = 1; // Current date.
	SpringF = 0;	// IS in Spring festival or not.
	result = 0;
	
	while(Mcurrent < 13 ){
		
		
		if(Mcurrent == mm[6] && Dcurrent == dd[6]){	// If Spring Festival.
			
			result++;
			SpringF = 2;
				//Spring Festival remaining 2 days.
		}else if (SpringF){
			
			result++;
			SpringF--;
			
		}else if ( w ==6 || w==7){
			
			result ++;
			
		}else {
			for(int i=0;i<10;i++){
				
				if(Mcurrent==mm[i] && Dcurrent==dd[i]){
					result++;
					break; 
				} 
				
			}
		}
		nextday(y,Mcurrent,Dcurrent);	// rolling to nextday.
		w++;
		
		if(w==8){
			w=1;	
		}
	}	
	
	printf("%d\n",result);
	
	return 0;
}
