#include <iostream>
#include <fstream>
using namespace std;


extern int32_t lnum; // line number iterator
string lastcommand = "####";

void scommandoutput(string output) {
  move(lnum - 1, 0);
  clrtoeol();
  mvprintw(lnum - 1, 0, "%s", output.c_str());
  refresh();
}


string getargument(string command, int argnumber) {
  for (int x = 2; x != command.length() - 1; ++x) {

        cout << "char number " << x << " is not a space" << endl;
        cout << "command.substr(x, 0) returns: " << command.substr(x - 2, 1) << endl;



        }

    }


void commandoutput(string output) {
  mvprintw(lnum, 0, "%s", output.c_str());
  ++lnum;
}

string COMMANDinput() {
  int8_t screeny = getmaxy(stdscr); // get the height of the screen
  string command; // what will be the final output
  for (int8_t i = 0; i != 1;) { // while '~' is not pressed
    char input = getch(); // get char
    if (input == '-') {
      ++i; // break
    } else if (input == 42 && command.length() != 0) {
      command.pop_back();
      move(screeny - 1, 0);
      clrtoeol();
      mvprintw(screeny - 1, 0, "%s", command.c_str());
    } else if (input == '+') {
      if (lastcommand != "####") {
        command = lastcommand;
        refresh();
      }
    } else {
      command.push_back(input); // append the newest char to the command
      mvprintw(screeny - 1, 0, "%s", command.c_str()); // draw the command to the screen
    }
  }
  move(screeny - 1, 0);
  clrtoeol();
  lastcommand = command;
  return command;
}


void scrolldown(int lines) {
  move(getmaxy(stdscr) + 1, 0);
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
    mvprintw(lnum, 0, "|file not found:");
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
