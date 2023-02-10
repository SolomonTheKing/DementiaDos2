#include <fstream>
#include <iostream>
#include <vector>

vector<string> filesystem;

int deletefile(string filepath, string ifile) {

  // converts file into vector array
  fstream file(filepath);
  int8_t i = 0;
  // check for valid file
  if (file.is_open()) {
      std::string line;
      while (std::getline(file, line)) { // get line of file
          filesystem.push_back(line); // append line to vector
          ++i;
      }
  } else {

    return 1;

  }

      file.close();


      // iterate over vector until inputed string is fund
      for (int z = 0; z != filesystem.size(); ++z) {
        if (filesystem[z] == ifile) {
          filesystem[z].erase();
        }
      }


      // delete acutal file
      fstream dfile;
      dfile.open(filepath, std::ofstream::out | std::ofstream::trunc);
      dfile.close();

      ofstream wfile(filepath);

      // re-write to the file
      for (int8_t x = 0; x != filesystem.size(); ++x) {
        string placeholder = filesystem[x];
        wfile << placeholder << endl;
      }

      wfile.close();
      remove(filepath.c_str());
      return 0;
    }


// look for string in file by line
int comp(std::string pname, std::string filepath) {
  int8_t err = 0;
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
