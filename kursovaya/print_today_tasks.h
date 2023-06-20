#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include"date_detection.h"

//переменные
char* mname_ptt[10];
char* mdate_ptt[10];
//переменные

void print_today_tasks_main() {
	int counter_ptt = 0;
	char* today_dates[10];
	char* today_heads[10];
	FILE* file_head;
	FILE* file_date;
	file_head = fopen("tasks.txt", "r");
	file_date = fopen("dates.txt", "r");

/*
	while (!feof(file_date)&& !ferror(file_date))
	{
		if (fgetc(file_date) == '\n') {
			counter_ptt++;
			printf("%d", counter);
		}
	}
	*/
	while (!feof(file_date) && !ferror(file_date))
	{
		if (fgetc(file_date) == '\n') {
			counter_ptt++;
		}
	}

	/*
	while (!feof(file_date))
	{
		fscanf(file_date, "%*[^\n]%*c");
		counter_ptt++;
		printf("%d", counter_ptt);
		
	}
	*/
	fclose(file_date);
	file_date = fopen("dates.txt", "r");
	int i = 0;
	while (!feof(file_date))
	{
		mdate_ptt[i] = (char*)malloc(sizeof(char) * 10);
		fscanf(file_date, "%s", mdate_ptt[i]);
		i++;
	}

	i = 0;
	while (!feof(file_head))
	{
		mname_ptt[i] = (char*)malloc(sizeof(char) * 10);
		fscanf(file_head, "%s", mname_ptt[i]);
		i++;
	}
	fclose(file_head);
	fclose(file_date);
	int len_mass = 0;
	for (int i = 0; i < counter_ptt; i++) {
		if (CheckDate(mdate_ptt[i]) == (1)) {
			today_dates[len_mass] = (char*)malloc(sizeof(char) * 10);
			today_heads[len_mass] = (char*)malloc(sizeof(char) * 10);
			memcpy(today_dates[len_mass], mdate_ptt[i], 12);
			memcpy(today_heads[len_mass], mname_ptt[i], 10);
			len_mass++;
		}
	}
	if (len_mass == 0) {
		printf("Задач нет");
	}
	else {
		printf("|№|   Дата   |Дела\n");
		for (i = 0; i < len_mass; i++) {
			int index = i + 1;
			printf("|%d|%s|", index, today_dates[i]);
			puts(today_heads[i]);
		}
	}
	
	printf("\nenter - назад\n");
	getchar();
}
