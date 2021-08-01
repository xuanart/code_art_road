#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

void test(char *start, char *end, char*res)
{
	int i = 0;
	int j = 0;
	if (start[0] == '\0') {
		res[0] = '/';
		for (i = 0; i < 100; i++) {
			if (end[i] != '/') {
				strcpy(res + 1, end + i);
				return;
			}
		}
	}

	if (end[0] == '\0') {
		res[0] = '/';
		for (i = 1; i < 100; i++) {
			if (start[i] != '/') {
				strcpy(res + 1, start + i);	
				return;
			}
		}
	}

	res[0] = '/';
	for (i = 0; i < 100; i++) {
		if (start[i] != '/') {
			strcpy(res + 1, start + i);	
			break;
		}
	}
	int len = strlen(start + i);
	for (j = 0; j < 100; j++) {
		if (end[j] != '/') {
			res[len + 1] = '/';
			strcpy(res + len +2, end + j);
			return;
		}
	}
}

void removedh(char *res)
{
	int i = 0;
	for (i = 0; i < 200; i++) {
		if (res[i] == ',') {
			strcpy(res + i, res + i + 1);
			return;
		}
	}
}

int main()
{
	char start[100] = {0};
	char end[100] = {0};
	char res[200] = {0};

	scanf("%s%s",start, end);
	test(start, end, res);
	removedh(res);
	cout<<res<<endl;

	return 0;
}