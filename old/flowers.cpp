#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char lline[10000], *line = lline;
	while(1) {
		line = lline;
		fgets(line, 10000, stdin);
		//printf("line: %s\n", line);
		if(line[strlen(line) - 1] == '\n') {
			line[strlen(line) - 1] = 0;
		}
		if(!strncmp(line, "*", 1)) break;
		char word[30];
		sscanf(line, " %s", word);
		//printf("word: %s\n", word);
		line += strlen(word);
		char c = toupper(word[0]);
		bool found = false;
		word[0] = 0;
		while(sscanf(line, " %s", word)) {
			if(word[0] == 0)  break;
		//printf("word: %s\n", word);
			line += strlen(word) + 1;
			if(toupper(word[0]) != c) {
				found = true;
				break;
			}
			word[0] = 0;
		}
		printf("%s\n", !found ? "Y" : "N");
	}
}

