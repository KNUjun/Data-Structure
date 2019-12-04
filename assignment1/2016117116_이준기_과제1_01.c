//2016117116_LeeJunGi_Assignment1_01 

#include <stdio.h>
#include <string.h>

int main(){
	int i=10, j=15, *p=&i, *q=&j, *r;
	char s1[]="C programming is easy.";
	char *s2[]={"C programming is easy.", "java", "c#"};
	
	printf("%d\n", (*p)++);		// 10
	
	printf("%d\n", i);			// 11
	printf("%d\n", (*(r=q)%=i)); // 4
	
	printf("%d\n", j);			//4
	printf("%d\n", sizeof(i)-sizeof(j));	// 0
	
	printf("%d\n", strlen(s2[1]));		// 4
	
	printf("%d\n", strcmp(s1, s2[1]));	// -1
	
	printf("%s\n", (s1+2));				// prograiming is easy.
	
	return 0;
}
