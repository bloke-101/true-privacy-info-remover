#include <string>
#include <fstream>
#include <iostream>

#include "file_system_utils.h"

using std::ios;
using std::cerr;
using std::string;
using std::fstream;


bool OpenFile(const string& name, ios::openmode mode, fstream& fs) {
    fs.open(name, mode);
    if (!fs) {
        cerr << "Failed to open " << name << '\n';
        return false;
    }
    return true;
}

void CloseFile(const string& name, fstream& fs) {
    fs.close();
    if (fs.fail()) {
        cerr << "Failed to close " << name << '\n';
    }
}
