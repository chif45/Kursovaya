#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include"add_task.h"
#include"print_all_tasks.h"
#include"print_today_tasks.h"

//����������
char menu_selection;
char main_break;
char c;
//����������

int main() {



	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//��������
	printf("�������� ������\n�� ���������� ���������������� \n�� ���� :\"����������\"\n\n�������� ������� ������ 22���1 �������� \n������: ������� �.�.");
	getchar();
	system("cls");

	while (1)
	{
		// ����� ����
		printf("�������� ������ �������:\n");
		printf("1) �������� ������\n");
		printf("2) ���������� ��� ������\n");
		printf("3) ���������� ������ �� �������\n");
		printf("0) �����\n");
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