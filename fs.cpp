#include <fstream>
#include <iostream>


int comp(std::string pname, std::string filepath) {
  int err = 0;
  std::ifstream file(filepath);
  if (file.is_open()) {
      std::string line;
      while (std::getline(file, line)) {
          if (line == pname) {
            err = 1;
          }
      }

  }
  file.close();
  return err;
}



void appendfile(std::string file, std::string filepath) {
  std::ofstream outfile;
  outfile.open(filepath, std::ios_base::app); // append instead of overwrite
  outfile << file << std::endl;
  outfile.close();
}

void addfile(std::string input) {
  if (comp(input, "flist.ddos") != 1) {

    std::ofstream file(input);
    file.close();

    appendfile(input, "flist.ddos");

  } else {
    commandoutput("shut yo ass up boy");
  }

}

void readfile(std::string filepath) {
  std::ifstream file(filepath);
  if (file.is_open()) {
      std::string line;
      while (std::getline(file, line)) {
          commandoutput(line);
      }

  }
  file.close();
}
