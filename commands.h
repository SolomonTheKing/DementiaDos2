#include <iostream>
#include <fstream>
using namespace std;


void iocommand(string command) {
  if (command.substr(0, 3) == "cls") {
    ClearAll();
  }


  if (command.substr(0, 5) == "plogo") {
    ClearAll();
    printLG("logo.lg");
  }

  if (command.substr(0, 4) == "echo") {
    commandoutput("!enter text!");
    command = COMMANDinput();
    scommandoutput(command);
  }

  if (command.substr(0, 4) == "logo") {
    commandoutput("|file path:");
    command = COMMANDinput();
    commandoutput(command);
    printLG(command);
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
