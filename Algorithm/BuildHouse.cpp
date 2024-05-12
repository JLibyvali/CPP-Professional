#include <iostream>
#include <string>

using  namespace std;



/*
Input: 3 4
OutPut:
+-+-+-+-+
|*|*|*|*|
+-+-+-+-+
|*|*|*|*|
+-+-+-+-+
|*|*|*|*|
+-+-+-+-+

*/

int main(){
	
   int row,col;
   cin>>row>>col;
   
   for(int k=0;k<row;k++){	// lines
   
   for(int i=0;i<col;i++){	// wall
   		cout<<"+-";
   }
   cout<<"+"<<endl;
   
   for(int j = 0 ; j<col;j++){
   	cout<<"|*";
   }
   cout<<"|"<<endl;
}

	 for(int i=0;i<col;i++){	// last line
   		cout<<"+-";
   }
   cout<<"+"<<endl;
	
	
	return 0;
}
