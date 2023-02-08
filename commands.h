#include <iostream>
#include <fstream>
#include "fs.cpp"
using namespace std;


void iocommand(string command) {

  if (command.substr(0, 3) == "dir") {
    readfile("flist.ddos");
  }

  if (command.substr(0, 2) == "df") {
    commandoutput("|file name:");
    command = COMMANDinput();
    showinput(command);
    deletefile("flist.ddos", command);
  }

  if (command.substr(0, 2) == "cf") {
    commandoutput("|file name:");
    command = COMMANDinput();
    showinput(command);
    addfile(command);
  }

  if (command.substr(0, 2) == "rf") {
    commandoutput("|file:");
    command = COMMANDinput();
    showinput(command);
    readfile(command);
  }

  if (command.substr(0, 3) == "cls") {
    ClearAll();
  }

  if (command.substr(0, 6) == "manual") {
    ClearAll();
    if (getargument(command) == "i") {
      readfile("MANUAL/interface");
    } else if (getargument(command) == "b") {
      readfile("MANUAL/basic");
    } else {
      readfile("MANUAL/manual");
    }
    readfile("MANUAL/end");
  }


  if (command.substr(0, 5) == "plogo") {
    ClearAll();
    readfile("logo.lg");
  }

  if (command.substr(0, 4) == "echo") {
    commandoutput("!enter text!");
    command = COMMANDinput();
    scommandoutput(command);
  }

  if (command.substr(0, 7) == "addline") {
    //getargument(command, 1);

    commandoutput("|");
    //addlnum(1); DEPRECIATED!!!
  }

  if (command.substr(0, 7) == "") {
    //getargument(command, 1);

    commandoutput("|");
    //addlnum(1); DEPRECIATED!!!
  }


}
