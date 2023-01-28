#include <iostream>
#include <fstream>
using namespace std;


extern int32_t lnum; // line number iterator

string COMMANDinput() {
  int8_t screeny = getmaxy(stdscr); // get the height of the screen
  string command; // what will be the final output
  for (int8_t i = 0; i != 1;) { // while '~' is not pressed
    char input = getch(); // get char
    if (input == '-') {
      ++i; // break
    } else {
      command.push_back(input); // append the newest char to the command
      mvprintw(screeny - 1, 0, "%s", command.c_str()); // draw the command to the screen
    }
  }
  move(screeny - 1, 0);
  clrtoeol();
  return command;
}


void printLG(string Ifile) {
  string line; // "pointer" for line output
  fstream Ffile;
  Ffile.open (Ifile); // grab declared file
  if (Ffile.is_open()) { // if the file is real
    while (getline (Ffile, line)) {  // for each line
      mvprintw(lnum, 0, "%s", line.c_str()); // convert string to char*, then print to line
      ++lnum; // iterate line number
    }
  } else { // if the file is not real
    mvprintw(lnum, 0, "file not found:");
    mvprintw(lnum, 16, "%s", Ifile);
    ++lnum;
  }
  Ffile.close(); // don't ever buy no weed from the gas station bro
  return;
}

void addlnum(int amount) {
  lnum = lnum + amount;
  return;
}



void ClearAll() {
  erase();    // erase entire screen
  refresh();  // show erasure
  lnum = 0;
  return;

}
