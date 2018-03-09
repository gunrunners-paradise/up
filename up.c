#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
struct utsname unameData;

int checkos()
{
	uname(&unameData);
	if (strcmp(unameData.nodename, "raspbian") == 0)
	    printf("Up - Debian/Ubuntu/Raspbian update tool\n");
	if (strcmp(unameData.nodename, "raspberrypi") == 0)
	    printf("Up - Debian/Ubuntu/Raspbian update tool\n");
	else if (strcmp(unameData.nodename, "debian") == 0)
	    printf("Up - Debian/Ubuntu/Raspbian update tool\n");
	else if (strcmp(unameData.nodename, "ubuntu") == 0)
	    printf("Up - Debian/Ubuntu/Raspbian update tool\n");
	else {
	    printf("Your system is not compatible with up.\n");
	    exit(0);
	}
	return 0;
}

int clean()
{
	printf("Cleaning up...\n");
	system("sudo apt-get autoremove -yy");
	system("sudo apt-get autoclean");
	return 0;
}

int update()
{
	printf("Starting update...\n");
	system("sudo apt-get update");
	system("sudo apt-get dist-upgrade -yy");
	return 0;
}

void error()
{
	printf("Please type \"--help\" for more details on how to use up.\n");
	exit(0);
}

void help()
{
	printf("\nUp is a tool that automates the update procedure for Debian, Raspbian\n"
	" and Ubuntu based Linux systems.\n\n"
	" Commands:\n"
	" \tup = full system update.\n"
	" \tRunning \"up\" with no options will update the apt cache and then perform a\n"
	" \tfull distribution update automatically.\n\n"
	" \tup --clean = full system update with cleanup.\n"
	" \tAdding the \"--clean\" option will invoke the apt commands to search for and\n"
	" \tremove locally cached packages that are no longer in the repositories and\n"
	" \tremove orphaned packages that are no longer needed by programs.\n"
	" \tup --help = shows this help page.\n"
	" \tup -h = same as above.\n\n"
	" By Oleg Cherkasky www.github.com/gunrunners-paradise (GNU/General Public License version 2.0)\n"
	" Inspired by Joe Collins www.ezeelinux.com\n\n");
	
	exit(0);
}

int finish()
{
	printf("\n\n------------------\n"
		   "-Update complete!-\n"
		   "------------------\n\n");
	return 0;
}

int main(int argc, char *argv[])
{
	checkos();
	if (argc > 1) {
		if (strcmp(argv[1], "--help") == 0)
			help();
		else if (strcmp(argv[1], "-h") == 0)
			help();
		else if (strcmp(argv[1], "--clean") == 0)
			clean();
		else
	    	error();
	}
	
	update();
	finish();
	return 0;
}
