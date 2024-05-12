#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Prac 2-3
int Htoi(const char *s, const int len);

// Prac 2-6
char *setbits(int x, int p, int n, int y);

// Prac 2-7
char *invert(int x, int p, int n);

// Prac 2-8
char *rightrot(int x, int n);

int Htoi(const char *s, const int len) {

    int i, j;
    double n = 0;

    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        if (s[i] == 'x' || s[i] == 'X')
            break;
        if (isdigit(s[i]))
            n += pow(16, j) * (s[i] - '0');
        if (isalpha(s[i]))
            n += pow(16, j) * (((isupper(s[i])) ? s[i] - 'A' : s[i] - 'a') + 10);
    }
    return (int) n;
}

char *setbits(int x, int p, int n, int y) {

    int i, j;
    static char bitsx[32], bitsy[32];
    for (i = 0; i < 32; i++) {
        bitsx[i] = (x & 1) ? '1' : '0';
        x >>= 1;
    }

    for (i = 0; i < 32; i++) {
        bitsy[i] = (y & 1) ? '1' : '0';
        y >>= 1;
    }

    for (i = p, j = 0; j < n; i++, j++) {
        bitsx[i] = bitsy[j];
    }

    return bitsx;
}

char *invert(int x, int p, int n){

    int i,j;
    static char bitsx[32];
    for (i = 0; i < 32; i++) {
        bitsx[i] = (x & 1) ? '1' : '0';
        x >>= 1;
    }

    for(i=p,j=0;j<n;i++,j++){
       bitsx[i] = ((bitsx[i] - '0') & 1) ? '0' : '1';
    }

    return bitsx;
}

char *rightrot(int x, int n){

    int i,j,len=0;
    static char bitsx[32];
    static char res[32];

    for (i = 0; i < 32; i++) {
        bitsx[i] = (x & 1) ? '1' : '0';
        x >>= 1;
        len++;
    }

    for(i=0,j=len;i<n;i++,j++){
      bitsx[j] = bitsx[i];
    }

    for(i=0,j=n;i<len;i++,j++){
        res[i] = bitsx[j];
    }

    return res;
}
