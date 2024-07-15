#ifndef STRING_REPLACE_OTHER_VERSION_H
#define STRING_REPLACE_OTHER_VERSION_H

#include "StringReplace.h"


inline void saveResultString(const char *haystack, const char *needle, const char *replace, char* saveString)
{
	int lengthNeedle = strlen(needle);
	int lengthReplace = strlen(replace);
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
				saveString[index++] = *replace;
				replace++;
			}
			replace -= lengthReplace;
		}
		else
		{
			needle -= countNeedleSymbols;
			haystack -= countNeedleSymbols;
			saveString[index++] = *haystack;
		}
		haystack++;
	}
	saveString[index] = '\0';
}

inline  char* stringReplaceOtherVersion(const char *haystack, const char *needle, const char *replace)
{
	char saveString[50];
	saveResultString(haystack, needle, replace, saveString);
	int saveStringLength = strlen(saveString);
	char *returnResultString = new (std::nothrow) char[saveStringLength + 1];
	if (!returnResultString)
	{
		std::cout << "Can't allocate memory in function stringReplaceOtherVersion()!\n" << std::endl;
		return returnResultString;
	}
	memcpy(returnResultString, saveString, saveStringLength + 1);

	return returnResultString;
}

#endif