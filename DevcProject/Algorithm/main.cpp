#include <iostream>
#include <array>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;

int binary( const std::array<int,10>&  _arr,int _left, int _right, int _x){

	while(_left <= _right){

		int mid = _left + (_right-_left)/2;
		
		if( _arr[mid] == _x ){	// If it's equal , return it.
			
			return mid;
			
		}else if( _arr[mid] < _x){	// If '_x' bigger than the middle num, half the arr.
			
			_left = mid + 1 ;
			
		}else{
			
			_right = mid -1;	 // If '_x' smaller than the middle num, half the arr.
		}	
				
	
	}
	
	return -1;

}
int main() {	// Binary search algorithm
	

	int num;
	std::array<int,10> arr;
	int output;
	
	std::cout<<"Input 10 num in order"<<std::endl;
	for(int i =0;i<arr.size();i++){
		
			std::cin>>num;
			arr[i] = num;		
		
	}
	
	cout<<"need search  value: \n"<<endl;
	cin>>num;
	
	output = binary(arr,0,arr.size(),num);
	
	if(output == -1){ 
	
		cout<<"Invalid search "<<endl;
		
	}else{
		
		cout<<"Value: "<<output<<endl;
	}
	
	return 0;
}
