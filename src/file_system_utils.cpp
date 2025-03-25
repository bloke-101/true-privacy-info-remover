#include <string>
#include <fstream>
#include <iostream>

#include "file_system_utils.h"

using std::ios;
using std::cerr;
using std::string;
using std::fstream;


int OpenFile(const string& name, ios::openmode mode, fstream& fs) {
    fs.open(name, mode);
    if (!fs) {
        cerr << "Failed to open " << name << '\n';
        return -1;
    }
    return 0;
}

int CloseFile(const string& name, fstream& fs) {
    fs.close();
    if (fs.fail()) {
        cerr << "Failed to close " << name << '\n';
        return -1;
    }
    return 0;
}

int GetFileSize(fstream& file, int& size) {
    file.seekg(0, ios::end);
    if (file.fail()) {
        cerr << "Failed to move the file pointer to the end\n";
        return -1;
    }
    size = file.tellg();
    if (file.fail()) {
        cerr << "Failed to get the file pointer position\n";
        return -1;
    }
    file.seekg(0, ios::beg);
    if (file.fail()) {
        cerr << "Failed to move the file pointer to the begin\n";
        return -1;
    }
    return 0;
}

int Overwrite(fstream& stream, char c) {
    int size;
    if (GetFileSize(stream, size) == -1) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        stream.put(c);
        if (!stream) {
            cerr << "Failed to put " << static_cast<int>(c) << '\n';
            return -1;
        }
    }
    return 0;
}
