#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int opt;

	if(*(argv + 1) && strncmp(*(argv + 1), "--help", 7) == 0) {
		puts("EloDev pwd v1.0.0, a rewrite of GNU pwd.\x0Apwd: pwd [-LP]\x0A\tPrint the name of the current working directory.\x0A\x0A\tOptions:\x0A\t-L\t\tprint the value of $PWD if it names the current working directory\x0A\t-P\t\tprint the psysical directory, wihout any symbolic links\x0A\x0A\tBy default, `pwd' behaves as if `-L' were specified.\x0A\x0A\tExit status:\x0A\tReturns 0 unless an invalid option is given or the current directory cannot be read.");
		return 0;
	}

	const char *pwd = getenv("PWD");

	while((opt = getopt(argc, argv, "LP")) != -1)
		switch(opt) {
			case 'L':
				printf("%s\x0A", pwd);
				return 0;
			case 'P':
				char *rpath = realpath(pwd, NULL);
				
				if(rpath) {
					puts(rpath);
					free(rpath);
				}

				return 0;
			case '?':
				puts("pwd: usage: pwd [-LP]");
				return -1;
			default:
				return -1;
		}

	puts(pwd);

	return 0;
}
