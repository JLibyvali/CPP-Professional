#include <cstdio>


char grap[500][500];
/*
Input: one num, 0<=num<=20;
OutPut:graph


*/

int main() {


	int n;
	scanf("%d",&n);


	int RaC = (4*n) + 5;
	int mid = (RaC +1) /2;	//must be oddnum;

	int x=0,y=0;

	for(int i=0; i<RaC; i++) {

		for(int j=0; j<RaC; j++) {

			grap[i][j] = '.';
		}
	}

	for(int i=0; i<mid; i++) {


		if(i%2==0) {

			if(i == 0) {
				x = i;
				for(int k=2; k<mid; k++) {

					grap[x][k] = '$';
				}
				continue;
			}
			if(i == mid -1){
				
				x = i;
				for(int j=x-2;j<=mid+2;j++){
					
					grap[x][j] = '$';
					
				}
				continue;
				
			}

			x  = i;
			for(int j=0; j<mid; j++) {	//line

				if(j==(i+1)) {
					grap[x][j] ='.';
				} else {
					grap[x][j] = '$';
				}

			}

			y = i;
			for(x=i; x<mid; x++) {	//col

				grap[x][y-2] = '$';
			}


//#######################################
		} else {


			x  = i;

			grap[x][i+1] = '$';

		}



	}



//############################COPY

	for(int i =0; i<mid; i++) {	//line copy

		for(int j=RaC-1; j>mid-1; j--) {
			grap[i][j] = grap[i][((RaC-1) - j)];
		}

	}

	for(int j=RaC-1; j>mid-1; j--) {		//graph copy

		for(int k=0; k<RaC; k++) {

			grap[j][k]  =  grap[RaC - 1 -j][k];
		}
	}


	for(int i=0; i<RaC; i++) {

		for(int j=0; j<RaC; j++) {

			printf("%c",grap[i][j]);
		}
		printf("\n");
	}


	return 0;
}
