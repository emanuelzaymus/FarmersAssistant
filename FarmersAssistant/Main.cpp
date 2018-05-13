#include <locale>
#include <codecvt>
#include <string>
#include <iostream>

#include "structures\heap_monitor.h"

#include <stdexcept>
#include <clocale>
#include <stdio.h>
#include <windows.h>

#include "CLI.h"


int main() {
	initHeapMonitor();

	setlocale(LC_ALL, "");

	CLI cli;

	cli.run();

	return 0;
}

