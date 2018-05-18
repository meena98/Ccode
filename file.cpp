
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"

struct student
{
	int id;
	const char *name;
	int m1, m2, m3, m4;
	float avg;
	float cgpa;
	int flag;
};


student * input = (student*)malloc(1*sizeof(student));
int k = 0,s=1;


struct studentinfo
{
	int rollno;
	const char *pno;
	const char* add;
	const char* city;
	int pin;
	int flag1;
};


studentinfo * input1 = (studentinfo*)malloc(1*sizeof(studentinfo));
int k1 = 0;

char* getfield(char* line, int num)
{
	char* tok;
	for (tok = strtok(line, ",");
		tok && *tok;
		tok = strtok(NULL, ",\n"))
	{
		if (!--num)
			return tok;
	}
	return NULL;
}
int size = 2;

int compare(char* tmp)
{
	int c = 0;
	int temp = 0, temp1 = 0;
	temp = atoi(getfield(tmp, 1));
	if ((temp == input[0].id))
	{
		printf("1.replace\n2.ignore");
		scanf("%d",&c);
		if (c == 1)
		{
			k = 0;
			size = 2;
			return 0;
		}
		else if (c == 2)
		{
			return 1;
		}
	}
	else
	{
		k = 0;
		return 0;
	}
}
void load()
{
	//file = fopen("C:\\Users\\lenovo\\Downloads\\", "r");
	int flag=0;
	int i = 0;
	//char *path = (char*)malloc(sizeof(char) * 100);
	//strcpy(path, "C:\\Users\\lenovo\\Downloads\\");
	char fname[50];
	printf("enter file name");
	scanf("%s", &fname);
	//strcat(fname, fname);
	FILE *file;
	file = fopen(fname,"r");
	//k = 0;
	char line[100];
	fgets(line, sizeof(student), file);
	while (fgets(line, sizeof(student)*sizeof(student), file))
	{
		char* tmp = strdup(line); 
		if (flag == 0)
		{
			if (compare(tmp) == 1)
			{
				return;
			}
			flag = 1;
		}
		input[k].id = atoi(getfield(strdup(line), 1));
		input[k].name = getfield(strdup(line), 2);
		input[k].m1 = atoi(getfield(strdup(line), 3));
		input[k].m2 = atoi(getfield(strdup(line), 4));
		input[k].m3 = atoi(getfield(strdup(line), 5));
		input[k].m4 = atoi(getfield(strdup(line), 6));
		input[k].flag = 1;
		free(tmp);
		student * newip = (student*)realloc(input,sizeof(student) * size);
		input = newip;
		size++;
		k++;
	}
	getchar();
}
void show()
{
	int loop1 = 0,i=0;
	for (i; i <=k;i++)
	{
		if (input[i].flag == 1)
		{
			printf("%d\t", input[i].id);
			printf("%s\t", input[i].name);
			printf("%d\t", input[i].m1);
			printf("%d\t", input[i].m2);
			printf("%d\t", input[i].m3);
			printf("%d\t", input[i].m4);
			if (input[i].avg > 0)
			{
				printf("%f\t", input[i].avg);
			}
			else
			{
				printf("NA\t");
			}
			if (input[i].cgpa > 0)
			{
				printf("%f\n", input[i].cgpa);
			}
			else
			{
				printf("NA\n");
			}
		}
	}
}
void showinfo()
{
	int i = 0;
	for (i; i <=k; i++)
	{
		if (input1[i].flag1 == 1)
		{
			printf("%d\t", input1[i].rollno);
			printf("%s\t", input1[i].pno);
			printf("%s\t", input1[i].add);
			printf("%s\t", input1[i].city);
			printf("%d\n", input1[i].pin);
		}
	}
}
void average()
{
	int i = 0;
	for (i = 0; i < k; i++)
	{
		input[i].avg = (input[i].m1 + input[i].m2 + input[i].m3 + input[i].m4) / 4;
	}
	for (i = 0; i < k; i++)
	{
		printf("%d\t", input[i].id);
		printf("%s\t\t", input[i].name);
		printf("%d\t", input[i].m1);
		printf("%d\t", input[i].m2);
		printf("%d\t", input[i].m3);
		printf("%d\t", input[i].m4);
		printf("%f\n", input[i].avg);
	}

}

int check(int i)
{
	if (i > 90)
	{
		return 10;
	}
	else if (i > 80 && i < 90)
	{
		return 9;
	}
	else if (i > 70 && i < 80)
	{
		return 9;
	}
	else if (i > 60 && i < 70)
	{
		return 9;
	}
	else if (i > 50 && i < 60)
	{
		return 9;
	}
	else if (i > 40 && i < 50)
	{
		return 9;
	}
	else if (i>30&&i<40)
	{
		return 4;
	}
	else if (i>20 && i < 30)
	{
		return 3;
	}
	else if (i>10 && i < 20)
	{
		return 2;
	}
	else if (i>0 && i < 10)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void cgpa()
{
	int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
	int i = 0;
	{
		for (i = 0; i < k; i++)
		{
			r1 = check(input[i].m1);
			r2 = check(input[i].m2);
			r3 = check(input[i].m3);
			r4 = check(input[i].m4);
			input[i].cgpa = (r1 + r2 + r3 + r4) / 4;
			printf("%d\t", input[i].id);
			printf("%s\t", input[i].name);
			printf("%d\t", input[i].m1);
			printf("%d\t", input[i].m2);
			printf("%d\t", input[i].m3);
			printf("%d\t", input[i].m4);
			printf("%f\n", input[i].cgpa);
		}
	}
}

void save()
{
	int i = 0;
	FILE *output;
	output = fopen("output.txt", "w");
	for (i = 1; i < k; i++)
	{
		if (input[i].flag == 1) {
			fprintf(output, "%d,", input[i].id);
			fprintf(output, "%s,", input[i].name);
			fprintf(output, "%d,", input[i].m1);
			fprintf(output, "%d,", input[i].m2);
			fprintf(output, "%d,", input[i].m3);
			fprintf(output, "%d,", input[i].m4);
			if (input[i].avg > 0)
			{
				fprintf(output, "%f,", input[i].avg);
			}
			if (input[i].cgpa > 0)
			{
				fprintf(output, "%f\n", input[i].cgpa);
			}
		}
	}
	fclose(output);
}
int size1 = 2;
int compare1(char *tmp)
{
	int c = 0;
	int temp = 0, temp1 = 0;
	temp = atoi(getfield(tmp, 1));
	//temp1 = atoi(getfield(tmp, 3));
	if ((temp == input1[0].rollno)) //&& (temp1 == input[0].m1))
	{
		printf("1.replace\n2.ignore");
		scanf("%d", &c);
		if (c == 1)
		{
			k = 0;
			size1 = 2;
			return 0;
		}
		else if (c == 2)
		{
			return 1;
		}
	}
	else
	{
		k = 0;
		return 0;
	}
}
void loadinfo()
{
	//k = 0;
	int i = 0;
	int flag1 = 0;
	//char *path1 = (char*)malloc(sizeof(char) * 100);
	//strcpy(path1, "C:\\Users\\lenovo\\Downloads\\");
	char fname1[50];
	printf("enter file2 name");
	scanf("%s", &fname1);
	//strcat(path1, fname1);
	FILE *file1;
	file1 = fopen(fname1, "r");
	char line[100];
	fgets(line, sizeof(studentinfo)*sizeof(studentinfo), file1);

	while (fgets(line, sizeof(studentinfo)*sizeof(studentinfo), file1))
	{
		char* tmp = strdup(line);
		if (flag1 == 0)
		{
			if (compare1(tmp) == 1)
			{
				return;
			}
			flag1 = 1;
		}
		input1[k].rollno = atoi(getfield(strdup(line), 1));
		input1[k].pno = (getfield(strdup(line), 2));
		input1[k].add = (getfield(strdup(line), 3));
		input1[k].city = (getfield(strdup(line), 4));
		input1[k].pin = atoi(getfield(strdup(line), 5));
		input1[k].flag1 = 1;
		free(tmp);
		studentinfo * newip1 = (studentinfo*)realloc(input1, sizeof(studentinfo) * size1);
		input1 = newip1;
		size1++;
		k++;
	}
	getchar();
}
void merge()
{
	int c = 0, count1 = 0;
	int count = 0;
	//FILE *file1 = fopen("C:\\Users\\lenovo\\Downloads\\studentinfolist.csv", "r");
	//FILE *file = fopen("C:\\Users\\lenovo\\Downloads\\studentmarkslist.csv", "r");
    //load();
	//loadinfo();
	char line[100];
	char line1[100];
	int i = 1, temp = 0, temp1 = 0;
	char fnamem[50];
	printf("enter file1 name");
	scanf("%s", &fnamem);
	FILE *filem;
	filem = fopen(fnamem, "r");
	char fnamem1[50];
	printf("enter file2 name");
	scanf("%s", &fnamem1);
	FILE *filem1;
	filem1 = fopen(fnamem1, "r");
	for (c = getc(filem); c != EOF; c = getc(filem))
		if (c == '\n') {
			count1 = count1 + 1;
		}
	rewind(filem);
	fgets(line1, sizeof(student)*sizeof(student), filem);
	fgets(line, sizeof(studentinfo)*sizeof(studentinfo), filem1);
	for (i = 1; i <= count1; i++)
	{
		count = 0;
		fgets(line1, sizeof(student)*sizeof(student), filem);
		temp = atoi(getfield(strdup(line1), 1));
		while (temp!=temp1)
		{
			if (count > count1)
			{
				break;
			}
			fgets(line, sizeof(studentinfo)*sizeof(studentinfo), filem1);
			char* tmp = strdup(line);
			temp1 = atoi(getfield(strdup(line), 1));
			count++;
		}
		if (temp == temp1)
		{
			printf("%d %s %d %d %d %d", atoi(getfield(strdup(line1), 1)), (getfield(strdup(line1), 2)), atoi(getfield(strdup(line1), 3)), atoi(getfield(strdup(line1), 4)), atoi(getfield(strdup(line1), 5)), atoi(getfield(strdup(line1), 6)));
			printf("%s %s %s %d\n", (getfield(strdup(line), 2)), (getfield(strdup(line), 3)), (getfield(strdup(line), 4)), atoi(getfield(strdup(line), 5)));
			rewind(filem1);
		}
		rewind(filem1);
	}
}

void show10()
{
	int count = 1;
	for (s; count <= 10; s++)
	{
		if (input[s].flag == 1)
		{
			printf("%d\t", input[s].id);
			printf("%s\t", input[s].name);
			printf("%d\t", input[s].m1);
			printf("%d\t", input[s].m2);
			printf("%d\t", input[s].m3);
			printf("%d\n", input[s].m4);
			count++;
		}
	}
}
void printMarksList(struct student* input, int i){
	printf("%d\t", input[i].id);
	printf("%s\t\t", input[i].name);
	printf("%d\t", input[i].m1);
	printf("%d\t", input[i].m2);
	printf("%d\t", input[i].m3);
	printf("%d\t", input[i].m4);
	printf("\n");
}
void filterbyName(char* op, char* val)
{
	int i;
	for (i = 0; i < k; i++)
	{
		if (strcmp(op, "BW") == 0)
		{
		}
	}
}
void filterbyM1(char* op, char* val)
{
	int i;
	for (i = 0; i < k; i++) {
		if (strcmp(op, "LT") == 0) {
			if (input[i].m1 < atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "LE") == 0) {
			if (input[i].m1 <= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GE") == 0) {
			if (input[i].m1 >= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GT") == 0) {
			if (input[i].m1 > atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "EQ") == 0) {
			if (input[i].m1 = atoi(val)) {
				printMarksList(input, i);
			}
		}
	}
}
void filterbyM2(char* op, char* val)
{
	int i;
	for (i = 0; i < k; i++) {
		if (strcmp(op, "LT") == 0) {
			if (input[i].m2 < atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "LE") == 0) {
			if (input[i].m2 <= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GE") == 0) {
			if (input[i].m2 >= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GT") == 0) {
			if (input[i].m2 > atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "EQ") == 0) {
			if (input[i].m2 = atoi(val)) {
				printMarksList(input, i);
			}
		}
	}
}
void filterbyM3(char* op, char* val)
{
	int i;
	for (i = 0; i < k; i++) {
		if (strcmp(op, "LT") == 0) {
			if (input[i].m2 < atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "LE") == 0) {
			if (input[i].m3 <= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GE") == 0) {
			if (input[i].m3 >= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GT") == 0) {
			if (input[i].m3 > atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "EQ") == 0) {
			if (input[i].m3 = atoi(val)) {
				printMarksList(input, i);
			}
		}
	}
}
void filterbyM4(char* op, char* val)
{
	int i;
	for (i = 0; i < k; i++) {
		if (strcmp(op, "LT") == 0) {
			if (input[i].m4 < atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "LE") == 0) {
			if (input[i].m4 <= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GE") == 0) {
			if (input[i].m4 >= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GT") == 0) {
			if (input[i].m4 > atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "EQ") == 0) {
			if (input[i].m4 = atoi(val)) {
				printMarksList(input, i);
			}
		}
	}
}
void filterbyavg(char* op, char* val)
{
	int i;
	for (i = 0; i < k; i++) {
		if (strcmp(op, "LT") == 0) {
			if (input[i].avg < atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "LE") == 0) {
			if (input[i].avg <= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GE") == 0) {
			if (input[i].avg >= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GT") == 0) {
			if (input[i].avg >atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "EQ") == 0) {
			if (input[i].avg = atoi(val)) {
				printMarksList(input, i);
			}
		}
	}
}
void filterbygpa(char* op, char* val)
{
	int i;
	for (i = 0; i < k; i++) {
		if (strcmp(op, "LT") == 0) {
			if (input[i].cgpa < atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "LE") == 0) {
			if (input[i].cgpa <= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GE") == 0) {
			if (input[i].cgpa >= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GT") == 0) {
			if (input[i].cgpa > atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "EQ") == 0) {
			if (input[i].cgpa = atoi(val)) {
				printMarksList(input, i);
			}
		}
	}
}
void filterbyRollno(char* op, char* val)
{
	int i;
	for (i = 0; i < k; i++) {
		if (strcmp(op, "LT") == 0) {
			if (input[i].id < atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "LE") == 0) {
			if (input[i].id <= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GE") == 0) {
			if (input[i].id >= atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "GT") == 0) {
			if (input[i].id > atoi(val)) {
				printMarksList(input, i);
			}
		}
		else if (strcmp(op, "EQ") == 0) {
			if (input[i].id = atoi(val)) {
				printMarksList(input, i);
			}
		}
	}
}
void filter(char* col, char* op, char* val)
{
	if (strcmp(col, "rollno") == 0) {
		filterbyRollno(op, val);
	}
	else if (strcmp(col, "name") == 0) {
		filterbyName(op, val);
	}
	else if (strcmp(col, "m1") == 0) {
		filterbyM1(op, val);
	}
	else if (strcmp(col, "m2") == 0) {
		filterbyM2(op, val);
	}
	else if (strcmp(col, "m3") == 0) {
		filterbyM3(op, val);
	}
	else if (strcmp(col, "m4") == 0) {
		filterbyM4(op, val);
	}
	else if (strcmp(col, "avg") == 0) {
		filterbyavg(op, (val));
	}
	else if (strcmp(col, "gpa") == 0) {
		filterbygpa(op, val);
	}
	else {
		printf("Invalid column name\n");
	}
}
void printinfo(struct studentinfo* input1, int i)
{
	printf("%d\t", input1[i].rollno);
	printf("%s\t\t", input1[i].pno);
	printf("%s\t", input1[i].add);
	printf("%s\t", input1[i].city);
	printf("%d\t", input1[i].pin);
	printf("\n");
}
void filteradd(char* op, char* val)
{
	int i, j = 0, flag = 0,len1=0,len2=0;
	len1 = strlen(val);
	for (i = 0; i < k; i++) {
		len2 = strlen(input1[i].add);
		if (strcmp(op, "BW") == 0) {
			for (j = 0; val[j] != '\0';j++)
			{
				if (input1[i].add[j] == val[j])
				{
					flag = 1;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				printinfo(input1, i);
			}
		}
		if (strcmp(op, "EW") == 0)
		{
			for (j = len1 - 1; val[j] >= 0; j--)
			{
				if (input1[i].add[len2-1] == val[j])
				{
					flag = 1;
					len2--;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				printinfo(input1, i);
			}
		}
	}
}
void filtercity(char* op, char* val)
{
	int i, j = 0, flag = 0, len1 = 0, len2 = 0;
	len1 = strlen(val);
	for (i = 0; i < k; i++) {
		len2 = strlen(input1[i].city);
		if (strcmp(op, "BW") == 0) {
			for (j = 0; val[j] != '\0'; j++)
			{
				if (input1[i].city[j] == val[j])
				{
					flag = 1;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				printinfo(input1, i);
			}
		}
		if (strcmp(op, "EW") == 0)
		{
			for (j = len1 - 1; val[j] >= 0; j--)
			{
				if (input1[i].city[len2 - 1] == val[j])
				{
					flag = 1;
					len2--;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				printinfo(input1, i);
			}
		}
	}
}
void filterpno(char* op, char* val)
{
	int i, j = 0, flag = 0, len1 = 0, len2 = 0;
	len1 = strlen(val);
	for (i = 0; i < k; i++) {
		len2 = strlen(input1[i].pno);
		if (strcmp(op, "BW") == 0) {
			for (j = 0; val[j] != '\0'; j++)
			{
				if (input1[i].pno[j] == val[j])
				{
					flag = 1;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				printinfo(input1, i);
			}
		}
		if (strcmp(op, "EW") == 0)
		{
			for (j = len1 - 1; val[j] >= 0; j--)
			{
				if (input1[i].pno[len2 - 1] == val[j])
				{
					flag = 1;
					len2--;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				printinfo(input1, i);
			}
		}
	}
}
void filterrollnoinfo(char* op, char* val)
{
	int i;
	for (i = 0; i < k; i++) {
		if (strcmp(op, "LT") == 0) {
			if (input1[i].rollno < atoi(val)) {
				printinfo(input1, i);
			}
		}
		else if (strcmp(op, "LE") == 0) {
			if (input1[i].rollno <= atoi(val)) {
				printinfo(input1, i);
			}
		}
		else if (strcmp(op, "GE") == 0) {
			if (input1[i].rollno >= atoi(val)) {
				printinfo(input1, i);
			}
		}
		else if (strcmp(op, "GT") == 0) {
			if (input1[i].rollno > atoi(val)) {
				printinfo(input1, i);
			}
		}
		else if (strcmp(op, "EQ") == 0) {
			if (input1[i].rollno = atoi(val)) {
				printinfo(input1, i);
			}
		}
	}
}
void filterpin(char* op, char* val)
{
	int i;
	for (i = 0; i < k; i++) {
		if (strcmp(op, "LT") == 0) {
			if (input1[i].pin < atoi(val)) {
				printinfo(input1, i);
			}
		}
		else if (strcmp(op, "LE") == 0) {
			if (input1[i].pin <= atoi(val)) {
				printinfo(input1, i);
			}
		}
		else if (strcmp(op, "GE") == 0) {
			if (input1[i].pin >= atoi(val)) {
				printinfo(input1, i);
			}
		}
		else if (strcmp(op, "GT") == 0) {
			if (input1[i].pin > atoi(val)) {
				printinfo(input1, i);
			}
		}
		else if (strcmp(op, "EQ") == 0) {
			if (input1[i].pin = atoi(val)) {
				printinfo(input1, i);
			}
		}
	}
}
void filterinfo(char* col, char* op, char* val)
{
	if (strcmp(col, "rollno") == 0) {
		filterrollnoinfo(op, val);
	}
	else if (strcmp(col, "pin") == 0) {
		filterpin(op, val);
	}
	else if (strcmp(col, "city") == 0) {
		filtercity(op, val);
	}
	else if (strcmp(col, "pno") == 0) {
		filterpno(op, val);
	}
	else if (strcmp(col, "add") == 0) {
		filteradd(op, val);
	}
}

int main()
{
	int count = 0, i = 0, ch = 0;
	int ch1;
	while (1)
	{
		printf("enter the option");
		printf("\n1.load\n2.show\n3.average\n4.gpa\n5.save\n6.merge\n7.exit\n8.show10\n9.filter\n10.hash");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
		{
			printf("1.marks 2.info");
			scanf("%d", &ch1);
			if (ch1 == 1)
			{
				load();
			}
			else
			{
				loadinfo();
			}
		}
		break;
		case 2:
		{
			if (input[0].flag == 1)
			{
				show();
			}
			if (input1[0].flag1 == 1)
			{
				showinfo();
			}
		}
		break;
		case 3:
		{
			average();
		}
		break;
		case 4:
		{
			cgpa();
		}
		break;
		case 5:
		{
			save();
		}
		break;
		case 6:
		{
			merge();
		}
		break;
		case 7:
		{
			exit(0);			
		}
		break;
		case 8:
		{
			show10();
		}
		break;
		case 9:
		{
			int ch = 0;
			char col[10], op[10], val[10];
			char query[10];// = (char*)malloc(sizeof(char) * 10);
			printf("1.marks\n2.info");
			scanf("%d", &ch);
			printf("Enter the column,Operation,Value\n");
			scanf("%s", query);
			strcpy(col, strtok(query, ","));
			strcpy(op, strtok(NULL, ","));
			strcpy(val, strtok(NULL, ","));
			if (ch == 1)
			{
				filter(col, op, val);
			}
			else
			{
				filterinfo(col, op, val);
			}
		}
		break;
		case 10:
		{
			int c = 0, size = 10;
			char k[10], v[10];
			char a[10], b[10];
			printf("1.insert,2.get");
			scanf("%d", &c);
			if (c == 1)
			{
				printf("enter key and value");
				scanf("%s %s", &k, &v);
				insert(k, v, size);
			}
			else if (c == 2)
			{
				printf("enter key");
				scanf("%d", &k);
				get(k, size);
			}
		}
		break;
		}
		getchar();
	}
}