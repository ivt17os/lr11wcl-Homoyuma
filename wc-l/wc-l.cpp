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
	
	cout << "Opening file a.txt\n"; // << argv[1] << "\n";
	
	ifstream f("a.txt");
	
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// ����������� ����� ����� � 1 ���


	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// ������� ����� ����� ��������� �����
	
	long long lines = 0;
	while (!f.eof()){
		getline(f, str);
		lines++;
	}
	
	
	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// ������� ����� ����� ��������� �����

	cout << str << "\n Time spent:" << (t2-t1)/(1.*freq) 
		 << "\n File  a.txt has " << lines << " lines.";
	return 0;
}