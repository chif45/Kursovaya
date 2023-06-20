#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include"add_task.h"
#include"print_all_tasks.h"
#include"print_today_tasks.h"

//переменные
char menu_selection;
char main_break;
char c;
//переменные

int main() {



	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//заставка
	printf("Курсовая работа\nПо дисциплине Программирование \nНа тему :\"Органайзер\"\n\nВыполнил студент группы 22ВВП1 Перфилов \nПринял: Федюнин Р.Н.");
	getchar();
	system("cls");

	while (1)
	{
		// Вывод меню
		printf("Выберите нужный вариант:\n");
		printf("1) Добавить задачу\n");
		printf("2) Посмотреть все задачи\n");
		printf("3) Посмотреть задачи на сегодня\n");
		printf("0) Выход\n");
		scanf_s("%c", &menu_selection, 1);
		while (char c = getchar() != '\n' && c != EOF);
		system("cls");
		switch (menu_selection)
		{
		case '1': {
			add_task_main();
			break;
		}
		case '2': {
			print_all_tasks_main();
			break;
		}
		case '3': {
			print_today_tasks_main();
			break;
		}
		case '0': {
			__asm {
				push 500
				call Beep
				call Beep
			}
			main_break = 1;
			break;
		}
		default:
			break;
		}
		system("cls");
		if (main_break) {
			break;
		}
	}
}