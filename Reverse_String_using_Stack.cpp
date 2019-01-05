#include <iostream>
#include <stack>	// stack from standard template library (STL)
#include <stdio.h>
#include <string.h>

using namespace std;
void Reverse(char *C, int n)
{
	stack<char> S;
	// loop for push
	for(int i=0; i<n; i++){
		S.push(C[i]);
	}
	// loop for pop
	for(int i=0;i<n;i++){
		C[i] = S.top();		// overwrite the character at index i.
		S.pop();		// perform pop
	}
}


int main(){
	char C[51];
	printf("Enter a string: " );
	gets(C);
	Reverse(C,strlen(C));
	printf("Output = %s",C);
}
