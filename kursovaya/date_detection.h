#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int CheckDate(const char* const dateStr)
{
	static char result[8];
	int result2;

	time_t current;
	time_t validate;

	struct tm* timeInfo = NULL;

	time(&current);
	time(&validate);

	timeInfo = localtime(&current);
	sscanf(dateStr, "%d.%d.%d", &timeInfo->tm_mday, &timeInfo->tm_mon, &timeInfo->tm_year);
	timeInfo->tm_mon = timeInfo->tm_mon - 1;
	timeInfo->tm_year = timeInfo->tm_year - 1900;
	timeInfo->tm_mday = timeInfo->tm_mday;

	validate = mktime(timeInfo);

	if (difftime(validate, current) == 0.0)
	{
		strcpy(result, "Good");
		result2 = 1;
	}
	else
	{
		strcpy(result, "Bad");
		result2 = 0;
	}
	
	return result2;
}

