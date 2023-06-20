#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "delete_tasks.h"

//переменные
char menu_selection_pat;
int i = 0;
int numb;
char* mname[10];
char* mdate[10];
//переменные


void print_all_tasks_main() {
	int counter_pat = 0;

	FILE* file_head;
	FILE* file_date;
	file_head = fopen("tasks.txt", "r");
	file_date = fopen("dates.txt", "r");

	while (!feof(file_date) && !ferror(file_date))
	{
		if (fgetc(file_date) == '\n') {
			counter_pat++;
		}
	}

	fclose(file_date);
	FILE* file_dates;
	file_dates = fopen("dates.txt", "r");

	int i = 0;

	while (!feof(file_dates))
	{
		mdate[i] = (char*)malloc(sizeof(char) * 10);
		fscanf(file_dates, "%s", mdate[i]);
		i++;
	}

	i = 0;
	while (!feof(file_head))
	{
		mname[i] = (char*)malloc(sizeof(char) * 10);
		fscanf(file_head, "%s", mname[i]);
		i++;

	}


	fclose(file_head);
	fclose(file_dates);
	if (counter_pat == 0) {
		printf("Задач нет");
	}
	else {
		printf("|№|   Дата   |Дела\n");
		for (int i = 0; i < counter_pat; i++) {
			int index = i + 1;
			printf("|%d|%s| ", index, mdate[i]);
			puts(mname[i]);
		}
	}

	
	printf("\n1) Удалить задачу\n");
	printf("enter - назад\n");
	scanf("%c", &menu_selection_pat);

	switch (menu_selection_pat) {	
	case '1':
		printf("Введите номер удаляемой задачи\n");
		scanf("%d",&numb);
		delete_task(numb);
	}

}