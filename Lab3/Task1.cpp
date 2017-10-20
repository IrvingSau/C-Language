#include<stdio.h>
int main()
{
	int x=30, y=30, z=40;
	int temp1, temp2;

	temp1= x/++y +z / y;
	printf("temp1= %3d\t%y= %d\n", temp1 ,y);

	y=30;
	temp2 = x/y++ +z /y;
	printf("temp2= %3d\t%y= %d\n", temp2, y);
	return 0;

	/*result: 
	 *if temp1 = 1, y = 31
	 *temp2 = 2, y = 31
	 *%3d is the minimum field width, means leave 3 characters space.
	 */
}