#include <iostream>
#include <string>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

/*
Input:2
Output:
  A
 BBB 
*/
//	int num;
//	cin>>num;
//	
//	for(int i =0;i<num;i++){
//		
//		string space = string( num - i , ' ');
//		string  ch = string(2*i+1,'A'+i);
//		cout<<space + ch<<endl;
//	}
//	
/*
Input:C
Output:
   A
  ABA
 ABCBA
 --------------
 Input:3
 Output:
   1
  121
 12321
*/


	char c;
	cin>>c;	//If 'F', F - A =5
	
	if(c >= 'A' && c<= 'Z'){
		
		for(int i=0;i<= c - 'A' ; i++){	// line num
			
			// space
			for(int j=0;j<= c - 'A' - i;j++ ){ 
				cout<<" ";
			}
			
			// left char
			for(int k=0; k<=i;k++ ){
				cout<<(char)('A' + k );
			}
			//right char
			for(int k= i-1;k>=0;k--){
				cout<<(char)('A' + k );
			}
			cout<<endl;
			
		}
		
	}else{
			
		for(int i=0;i<= c - '1'  ; i++){	// line num
			
			// space
			for(int j=0;j<= c - '1' - i;j++ ){ 
				cout<<" ";
			}
			
			// left char
			for(int k=0; k<=i;k++ ){
				cout<<(char)('1' + k );
			}
			//right char
			for(int k= i-1;k>=0;k--){
				cout<<(char)('1' + k );
			}
			cout<<endl; 
			
		}	
		
	}

	return 0;
}
