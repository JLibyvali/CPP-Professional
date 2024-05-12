#include <bits/stdc++.h>

using  namespace  std;

string num1,num2;
vector<int> n1(10010),n2(10010);
vector<int> num(10000);
void bigNumPlus(string a,string b,int length){

    // reverse all, simulate the vertical
    for(int i=0,tmp1 = a.length()-1,tmp2 = b.length()-1;i<length;i++){
        n1[i] = a[tmp1] - '0';
        n2[i] = b[tmp2] - '0';
        tmp1--;
        tmp2--;
    }

    for(int i=0,up=0,tmp=0;i<length;i++){  // answer storaged in n1[],from low to high.
        tmp = n1[i] + n2[i] + up;
        n1[i] = tmp % 10;
        up = tmp / 10;
    }

    // print
    for(int i = length;i>=0;i--){
        if(n1[i] != 0){
            for(i;i>=0;i--){
                cout<<n1[i];
            }
        }
    }
    cout<<endl;

}


void factorial(int n){

    num[0] = 1;

    for(int i=2;i<=n;i++){
        for(int tmp=0,up=0,j=0;j<=10000;j++){
            tmp = num[j] * i + up;
            num[j] = tmp % 10;
            up = tmp / 10;
        }
    }

    // print
    for(int i=10000;i>=0;i--){
        if(num[i] != 0){
            for(i;i>=0;i--){
                cout<<num[i];
            }
        }
    }
    cout<<endl;

}
int main(){

    cin>>num1>>num2;
    int len = max(num1.length(),num2.length());
    cout<<"Huge num plus:"<<endl;
    bigNumPlus(num1,num2,len);

    cout<<"Factorial:"<<endl;
    int n;
    cin>>n;

    factorial(n);

    return 0;
}