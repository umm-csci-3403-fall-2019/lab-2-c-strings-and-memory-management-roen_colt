#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

char *disemvowel(char *str) {
	//aeiou
	int j = 0;
	char* strcopy;
       strcopy = (char*)calloc(strlen(str)+1, sizeof(char));
	for(int i=0;i<strlen(str);i++){
		if(str[i]== 'a' || str[i]== 'e' || str[i]== 'i' || str[i]== 'o' || str[i]== 'u' || str[i]== 'A' || str[i]== 'E' || str[i]== 'I' || str[i]== 'O' || str[i]== 'U'){
		//	str[i] = str[i];
		}
		else{
			strcopy[j] = str[i];
			j++;
		}
	}
	strcopy[j] = '\0';
	
  return strcopy;
}
