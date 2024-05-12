#include <cstdio>
#include <string>

/*
January 1, 1 AD is Monday, so can deduce any-day's  is which of one week through loop.
Leap year: can be divisible by four or  four hundred.

One formula:For calculating which the day of week by the Date.
If 'w' means week, 'y' means year, 'm' means month , 'd' means day.

w = (d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400)%7	[NOTICE]:The January and the Feburary had be 13-th month and 14-th month in last year.
Then the result equals with  'w + 1'.

*/

using namespace std;


/*
Input: year month day
1 1 1
Output : which day of week
Monday

*/
int Targetday=0;	// Offset with '1 1 1' day .
int main(){
	
//	array<string,7> week {"Monday","Tuesday","Wednesday","Thursday","Friday","Satarday","Sunday"};
//	
//	int y,m,d;
//	
//	cin>>y>>m>>d;
//	
//	
//	for(int i =1;i<y;i++){	// Years
//		
//		if((i % 4==0 && i % 100 !=0) || i%400==0){
//			
//			Targetday += 366%7;
//			Targetday %= 7; 
//			
//		}else{
//			
//			Targetday += 365%7;
//			Targetday %= 7;
//		}
//		
//	}
//	
//	for(int i=1;i<m;i++){	// Months
//		
//	
//		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
//			
//			Targetday += 31 %7;
//			Targetday %= 7;
//			
//		}else if(i==4 || i==6 || i==9 || i==11){
//			
//			Targetday += 30 % 7;
//			Targetday %=7;
//		}else if ((y % 4 ==0 && y % 100 !=0) || y % 400 ==0){
//			
//			Targetday += 29%7;
//			Targetday %= 7;
//		
//		}else{
//			Targetday += 28%7;
//			Targetday %= 7;
//		}
//		
//	}
//	
//		
//	Targetday += (d -1) % 7; 	//days
//	Targetday %= 7;
//	
//	cout<<week[Targetday]<<endl;


// #######################################
/*
Inpute: date, yyyy mm dd k
2016 10 1 100
Outpute: the date after k days.
2017-01-09
*/

	
	int y,m,d,k;
	scanf("%d%d%d%d",&y,&m,&d,&k);
	
	int day[] {0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	for(int i=0; i<k;i++){	// Traverse day by day.
		
		if((y % 4 ==0 && y%100 !=0) || y %400 == 0){
			day[2] = 29;
		}else{
			day[2] = 28;
		}
		d++;
		
		if(d == day[m] + 1){
			
			d =1;
			m++;
		}
		if(m == 13){
			m=1;
			y++;
	}	
		
}
	
	
	printf("%04d-%02d-%02d\n",y,m,d);
	
	return 0;
}
