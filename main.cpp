#include <iostream>
#include <ncurses.h>
#include <fstream>
#include "base.h"
#include "commands.h"
using namespace std;


int32_t lnum = 0; // line number iterator





int main() {

	initscr(); // start ncurses
  noecho(); // prevents input from drawing itself

  // runtime code

  printLG("logo.lg"); // print logo
  for (bool x = 0; x != 1;){
    string command = COMMANDinput();

    if (command.substr(0, 4) == "exit") {
      mvprintw(lnum, 0, "|are you sure? [y] or [n]");
      ++lnum;
      if (getch() == 'y') {
        x = true;
      } else {
        mvprintw(lnum, 0, "|exit procces terminated");
        ++lnum;
      }
    }

    iocommand(command);

  }
	endwin(); // kill ncurses

	return 0;

}
