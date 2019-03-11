#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include <windows.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv ) {
    long long t1, t2, freq;
	string str;
	
	//if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}
	
	printf("Opening file a.txt\n"); // << argv[1] << "\n";
	
	FILE* f;

    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// запрашиваем число тиков в 1 сек


	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// смотрим время после окончания цикла
	
	f = fopen("a.txt", "rb");
	char * s = new char[5000000];
	long long lines = 0;
	while (!feof(f)){
		fgets(s, 5000000, f);
		lines++;
	}
	fclose(f);
	
	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// смотрим время после окончания цикла

	printf("\nTime spent: %.3fsec",(t2-t1)/(1.*freq)); 
	printf("\nFile  a.txt has %d",lines);
	printf(" lines.\n");
	return 0;
}