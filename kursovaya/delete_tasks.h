#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


void delete_task(int number) {
	int i = 0;
	int counter = 1;
	char stroka[100] = "";
	char* mname[10];
	char* mdate[10];

	FILE* file_head;
	FILE* file_head2;
	FILE* file_date;
	FILE* file_date2;

	file_head = fopen("tasks.txt", "r");
	file_head2 = fopen("tasks_new.txt", "w");
	file_date = fopen("dates.txt", "r");
	file_date2 = fopen("dates_new.txt", "w");


	while (fgets(stroka, 90, file_head))
	{
		if (number == counter) {
			printf("удален %s", stroka);
			counter++;
		}
		else {
			counter++;
			fputs(stroka, file_head2);
		}
	}
	counter = 1;
	while (fgets(stroka, 90, file_date))
	{
		if (number == counter) {
			printf("удален %s", stroka);
			counter++;
		}
		else {
			counter++;
			fputs(stroka, file_date2);
		}
	}
	fclose(file_head);
	fclose(file_head2);
	fclose(file_date);
	fclose(file_date2);

	file_head = fopen("tasks.txt", "w");
	file_head2 = fopen("tasks_new.txt", "r");
	file_date = fopen("dates.txt", "w");
	file_date2 = fopen("dates_new.txt", "r");

	while (fgets(stroka, 90, file_head2))
	{
		fputs(stroka, file_head);
	}
	while (fgets(stroka, 90, file_date2))
	{
		fputs(stroka, file_date);
	}


	fclose(file_head2);
	fclose(file_head);
	fclose(file_date2);
	fclose(file_date);
	counter = 1;
	getchar();
}