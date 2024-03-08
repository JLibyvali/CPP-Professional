/*
## 'Newline character'  in linux is one char,but in windows is two.##

IN C:
scanf("%s",&str), will  be end with 'space', 'newline character' ,'\0'.  Delimiter is still in buffer.

gets(char* str),fgets(char* str,sizeof(str),stdin):
"gets()" delimiter was 'newline character', wouldn't put the 'newline character' into str and refresh the buffer!
"fgets()" delimiter was 'newline character',will put the 'newline character' into str and  refresh buffer!


IN CPP:

cin>>str, will be stopped  with 'space', 'newline character' ,'\0'. Delimiter is still in iostream.

cin.getline(char* str,num) :could  from iostream and writing into 'type char*' in a line,until the delimiter or num-limited, and throw delimiter away
add '\0' in the end.
cin.get(char* str,num)  :could read from iostream one by one, util the num limited or delimiter, but it will keep the delimiter in iostream,
	   and add '\0' in the end

getline(any-stream,str,'delim'):
Read form 'any-stream' and  stored in 'str' , util the delimiter:default delimiter were 'newline character' , 'getline()' will throw the delimiter away.


##SO IMPORTANT:  After using the 'cin' , if then using the getline(),'getline()' will only read one 'newline character' into 'str' .##

*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

//char res[5000000];	// the c-style string end with '\0'
char s1[1100],s2[1100];

int main() {

	/*

	Input: 1,2,3,4
	Output:
	1:A,1
	2:ABA,3
	3:ABACABA,7
	4:ABACABADABACABA,15
	5:ABACABADABACABAEABACABADABACABA,31

	*/
//-----------------------------------------------
//	int num;
//	scanf("%d",&num);
//
//	int len =0;
//	for(int i = 0; i<num;i++){
//
//		strcat(res + len + 1,res);	// 'strcat(s1,s2)' ,connect 's2' to the end of 's1'.
//		res[len] = 'A' + i ;
//
//		len =  strlen(res);
//
//	}
//	printf("%s\n",res);
//
//	return 0;


//#######################################################################
/*
Input:str1 and str2, find the 'str2' appeared times in 'str1'
str1:ossosso
str2:osso

Output: num;
2

*/

	gets(s1);
	gets(s2);

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	int ans =0;
	
	for(int i=0; i+len2 -1 < len1; i++ ) {	// compared one by one. 'i + len2 -1' means don't need that end.

		bool match = true;
		
		for(int j=0; j<len2; j++) {

			if(s1[i+j] != s2[j]) {
				match = false;
				break;
			}

		}

		if(match) {
			ans++;
		}

	}

	printf("%d\n",ans);


	return 0;

}
