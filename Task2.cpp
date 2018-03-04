#include<stdio.h>
#include<string.h>
#include<Windows.h>

void reverseR(int length, char *str){
	if(length <= 1){
	}else if(length > 1){

		//we firstly change the first and the last char
		char temp = str[0];
		str[0] = str[length - 1];
		str[length - 1] = temp;

		//then we move the pointer, let it make a[1] to be the new first char
		str++;
		
		//same reason, we need to make sure the last char also has move
		length = length - 2;

		//then we do it again
		reverseR(length, str);
	}
}
int main(){
	//simple IO
	char str[50];
	
	scanf("%s", str);

	reverseR(strlen(str), str);

	printf("%s\n", str);

	system("pause");
	return 0;
}