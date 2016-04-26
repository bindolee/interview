// AnagramOfFirstAsSubstring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

/*
https://www.careercup.com/question?id=5389078581215232
Given two strings a and b, find whether any anagram of string a is a sub-string of string b. For eg:
if a = xyz and b = afdgzyxksldfm then the program should return true.
Assume this is based on ascii characters.

second thing.. I need to consider to check if src is substring of target <- this wasn't considered here..I guess

this is java solution which has substring thing too
bool hasAnagramSubstring(const string& src, const string& target)
{
	if(target.size() > src.size()) return false;

	int srcLen = src.size(), targetLen = target.size();
	int targetCount[128] = {0}, count[128] = {0}, i, j;
	//initialize
	for(i = 0; i < target.size(); ++i){
		++targetCount[target[i]];
		++count[src[i]];
	}
	//loop
	i = 0;
	while(true){
		//check if substring is an anagram
		for(j = 0; j < targetLen; ++j){
			if(count[target[j]] != targetCount[target[j]]) break;
		}
		if(j == targetLen) return true;
		//slide window
		if(i + 1 + targetLen > srcLen) break;

		--count[src[i]];
		++count[src[i + targetLen]];
		++i;
	}

	return false;
}

*/

#define ASCII_LEN 128

int AnagramOfFirstAsSubstring(char* src, char* target) {
	int target_table[ASCII_LEN];
	int i, lensrc, lentarget;

	lensrc = strlen(src);
	lentarget = strlen(target);
	if (lensrc > lentarget)
		return 0;

	for (i = 0; i < ASCII_LEN; i++)
		target_table[i] = 0;

	for (i = 0; i < lentarget; i++) {
		target_table[target[i]]++;
	}

	for (i = 0; i < lensrc; i++) {
		if (--target_table[src[i]] < 0)
			return 0;
	}

	return 1;
}

int main()
{
	char * str_src = "xyz";
	char * str_target = "afdgzyxksldfm";

	if (AnagramOfFirstAsSubstring(str_src, str_target))
		printf("source %s, is anagram of target %s\n", str_src, str_target);
	else
		printf("source %s, is not anagram of target %s\n", str_src, str_target);

	char * str_src2 = "xyfzams";
	char * str_target2 = "afdgzyxksldfm";

	if (AnagramOfFirstAsSubstring(str_src2, str_target2))
		printf("source %s, is anagram of target %s\n", str_src2, str_target2);
	else
		printf("source %s, is not anagram of target %s\n", str_src2, str_target2);

	char * str_src3 = "xyfzaa";
	char * str_target3 = "afdgzyxksldfm";

	if (AnagramOfFirstAsSubstring(str_src3, str_target3))
		printf("source %s, is anagram of target %s", str_src3, str_target3);
	else
		printf("source %s, is not anagram of target %s", str_src3, str_target3);
    return 0;
}

