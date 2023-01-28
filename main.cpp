#include <iostream>
#include <ncurses.h>
#include <fstream>
#include "base.h"
#include "commands.h"
using namespace std;


int32_t lnum = 0; // line number iterator


void scommandoutput(string output) {
  move(lnum - 1, 0);
  clrtoeol();
  mvprintw(lnum - 1, 0, "%s", output.c_str());
  refresh();
}


char getargument(string command, int argnumber) {

}


void commandoutput(string output) {
  mvprintw(lnum, 0, "%s", output.c_str());
  ++lnum;
}


int main() {

	initscr(); // start ncurses
  noecho(); // prevents input from drawing itself

  // runtime code

  printLG("logo.lg"); // print logo
  for (bool x = 0; x != 1;){
    string command = COMMANDinput();

    // clear the screen
    if (command == "cls") {
      ClearAll();
    }

    if (command.substr(0, 4) == "exit") {
      commandoutput("are you sure? [y] or [n]");
      if (getch() == 'y') {
        x = true;
      } else {
        commandoutput("exit procces terminated");
      }
    }

    if (command == "plogo") {
      ClearAll();
      printLG("logo.lg");
    }

    if (command == "echo") {
      commandoutput("!enter text!");
      command = COMMANDinput();
      scommandoutput(command);
    }

    if (command == "logo") {
      commandoutput("file path:");
      command = COMMANDinput();
      commandoutput(command);
      printLG(command);
    }

    if (command == "addline") {
      addlnum(3);
    }

  }


	endwin(); // kill ncurses

	return 0;
}
