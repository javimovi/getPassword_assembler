// C骴igo compilaci髇 gcc -m32 -o bomba bomba.c

#include <stdio.h>	// para printf()
#include <stdlib.h>	// para exit()
#include <string.h>	// para strncmp()/strlen()
#include <sys/time.h>	// para gettimeofday(), struct timeval

char password[]="12342222\n";
int  passcode  = 3457;

void boom(){
	printf("***************\n");
	printf("*** BOOM!!! ***\n");
	printf("***************\n");
	exit(-1);
}

void defused(){
	printf("路路路路路路路路路路路路路路路路路路路路路路路路路\n");
	printf("路路路 bomba desactivada 路路路\n");
	printf("路路路路路路路路路路路路路路路路路路路路路路路路路\n");
	exit(0);
}

int main(){
#define SIZE 100
	char pass[SIZE];
	int  pasv;
	
#define TLIM 60
	struct timeval tv1,tv2;	// gettimeofday() secs-usecs

	gettimeofday(&tv1,NULL);

	printf("Introduce la contrase帽a: ");
	fgets(pass,SIZE,stdin);
	if (strncmp(pass,password,strlen(password)))
	    boom();

	gettimeofday(&tv2,NULL);
	if (tv2.tv_sec - tv1.tv_sec > TLIM)
	    boom();
 
	printf("Introduce el c贸digo: ");
	scanf("%i",&pasv);
	if (pasv!=(atoi(password)+passcode)>>10 ) boom();

	gettimeofday(&tv1,NULL);
	if (tv1.tv_sec - tv2.tv_sec > TLIM)
	    boom();

	defused();
}
