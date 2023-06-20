#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//переменные
int name_string_size = 16;
char *name_of_task = (char*)malloc(name_string_size);
char date_of_task[50];
char tmp[50];
//переменные

void add_task_main() {
    FILE* file_head;
    FILE* file_date;
    file_head = fopen("tasks.txt", "a");
    file_date = fopen("dates.txt", "a");
    

    if (file_head && file_date)
    {   
        printf("Введите дату в формате DD.MM.YYYY: \n");
        gets_s(date_of_task, 15);
        if (strlen(date_of_task) > 10) {
           puts("Неверный ввод даты");
           getchar();
            
        }
        else {
            fputs(date_of_task, file_date);
            fputs("\n", file_date);
            printf("Введите название: \n");
            scanf("%s", tmp);
            while (char c = getchar() != '\n' && c != EOF);
            name_of_task = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
            strcpy(name_of_task, tmp);
            fputs(name_of_task, file_head);
            fputs("\n", file_head);
        }
        fclose(file_head);
        fclose(file_date);
        free(name_of_task);
    }

}