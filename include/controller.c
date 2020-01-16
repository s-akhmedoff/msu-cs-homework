#include <stdio.h>

#include "src/task1.h"
#include "src/task2.h"
#include "src/task3.h"
#include "src/task4.h"
#include "src/task7.h"
#include "src/task8.h"
#include "src/task9.h"
#include "src/task10.h"

void controller(void)
{
	int i = 1, task = 0;
	while(i != 0)
	{
		puts("Welcome\nPlease Select Task (1-10)\nSelect 0 - Exit:");
		scanf("%d", &task);
		switch(task)
		{
			default: puts("Enter correct number"); break;
			case 0: i = 0; break;
			case 1: task1(); break;
			case 2: task2(); break;
			case 3: task3(); break;
			case 4: task4(); break;
			case 7: task7(); break;
			case 8: task8(); break;
			case 9: task9(); break;
			case 10: task10(); break;
		}
	}
}