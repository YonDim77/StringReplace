#ifndef STRING_REPLACE_H
#define STRING_REPLACE_H

#include <iostream>
#include <string>


inline bool isEqualStrings(const char *&needle, const char *&haystack, int &countNeedleSymbols, int lengthNeedle)
{
	while (*needle == *haystack)
	{
		countNeedleSymbols++;
		if (countNeedleSymbols == lengthNeedle)
			break;
		needle++;
		haystack++;
	}
	return *needle == *haystack;
}

inline int resultStringLength(const char *haystack, const char *needle, const char *replace)
{
	int lengthResultString = 0;
	int lengthNeedle = strlen(needle);
	int lengthReplace = strlen(replace);

	while (*haystack)
	{
		int countNeedleSymbols = 0;
		bool isEqualToNeedle = isEqualStrings(needle, haystack, countNeedleSymbols, lengthNeedle);

		if (isEqualToNeedle)
		{
			lengthResultString += lengthReplace;
			needle -= lengthNeedle - 1;
		}
		else
		{
			needle -= countNeedleSymbols;
			haystack -= countNeedleSymbols;
			lengthResultString++;
		}
		haystack++;
	}
	return lengthResultString;
}

inline void insert(const char *haystack, const char *needle, const char *replace, char *returnResultString)
{
	int lengthNeedle = strlen(needle), lengthReplace = strlen(replace);
	int index = 0;
	while (*haystack)
	{
		int countNeedleSymbols = 0;
		bool isEqualToNeedle = isEqualStrings(needle, haystack, countNeedleSymbols, lengthNeedle);

		if (isEqualToNeedle)
		{
			needle -= lengthNeedle - 1;
			while (*replace)
			{
				returnResultString[index++] = *replace;
				replace++;
			}
			replace -= lengthReplace;
		}
		else
		{
			needle -= countNeedleSymbols;
			haystack -= countNeedleSymbols;
			returnResultString[index++] = *haystack;
		}
		haystack++;
	}
	returnResultString[index] = '\0';
}

inline char* stringReplace(const char *haystack, const char *needle, const char *replace)
{
	int count = resultStringLength(haystack, needle, replace);
	char *returnResultString = new (std::nothrow) char[count + 1];
	if (!returnResultString)
	{
		std::cout << "Can't allocate memory in function stringReplace()!\n" << std::endl;
		return returnResultString;
	}
	insert(haystack, needle, replace, returnResultString);
	if (count != strlen(returnResultString))
		std::cout << "Error inserting. Check the result string!\n";

	return returnResultString;
}

#endif 