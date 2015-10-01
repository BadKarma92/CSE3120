//	Author:		Bradley Bunk,	BBunk2011@my.fit.edu
//	Course:		CSE 3120
//	Project:	Assign02

#include <stdio.h>

#define ARRAY_SIZE 10

#define STUDENT_NAME "Bradley Bunk"

int compare(int *first, int *second, int s){
	_asm {
		mov ecx, s  				//ecx is our size counter
		mov eax, 0					//eax serves as our counter of discrepancies in the two arrays
		mov ebx, first
		mov edx, second

	TOP:
		mov edi, DWORD PTR[edx]		//Dword 32 bit, Sword 16 bit, and byte 8 bit
		cmp edi, DWORD PTR[ebx]		//Dword pointer d
		jne DIFFERENT				//if not equal we jump out of the loop to update the not equal counter.

	UPDATE:
		add edx, TYPE first
		add ebx, TYPE second
		sub ecx, 1
		cmp ecx, 0					//if we are at the end of the array we can safely exit the loop
		je DONE
		jmp TOP

	DIFFERENT:
		add eax,1
		jmp UPDATE

	DONE:
	}
}

int main(int argc, char* argv[]){

	int array1[ARRAY_SIZE] = { 32, 71, 29, 43, 50, 84, 19, 38, 65, 46 };
	int array2[ARRAY_SIZE] = { 32, 75, 29, 43, 51, 84, 14, 38, 65, 42 };
	int count = 0;
	int a;

	printf("\n\nCSE 3120 - Assignment # 2 - %s", STUDENT_NAME);

	count = compare(array1, array2, ARRAY_SIZE);

	printf("\n\n\tThe arrays have %d elements that are not equal.\n\n", count);

	scanf("%s", a);

  return 0;
}