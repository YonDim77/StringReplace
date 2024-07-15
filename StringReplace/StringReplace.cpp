// StringReplace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include "StringReplaceOtherVersion.h"


int main()
{
	const char *haystack = "jabcaaabaabbcjabncjaa abc fgabjaabcj";
	const char *needle = "abc";
	const char *replace = "AAA";

	std::cout << "Needle: \"" << needle << "\"\n";
	std::cout << "Replace: \"" << replace << "\"\n\n";
	std::cout << "Original string:    \"" << haystack << "\"\n";

	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	char *resultString = stringReplace(haystack, needle, replace);

	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::cout << "stringReplace() time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds\n";

	if (resultString)
	{
		std::cout << "Result string:      \"" << resultString << "\"\n\n";
	}

	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();

	char *sameResultString = stringReplaceOtherVersion(haystack, needle, replace);

	std::chrono::high_resolution_clock::time_point final = std::chrono::high_resolution_clock::now();
	std::cout << "stringReplaceOtherVersion() time: " << std::chrono::duration_cast<std::chrono::microseconds>(final - begin).count() << " microseconds\n";

	if (sameResultString)
	{
		std::cout << "Same result string: \"" << sameResultString << "\"\n";
	}

	delete[] sameResultString;
	delete[] resultString;

	return 0;
}

// stringReplaceOtherVersion() is 2 times faster than stringReplace() most of the cases.
// It seems that insert() performance is slower than memcpy()'s;




