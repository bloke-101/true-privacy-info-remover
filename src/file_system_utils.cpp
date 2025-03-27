#include <string>
#include <fstream>
#include <iostream>

#include "file_system_utils.h"

using std::ios;
using std::cerr;
using std::string;
using std::fstream;


int OpenFile(const string& name, ios::openmode mode, fstream& file) {
    file.open(name, mode);
    if (!file) {
        cerr << "Failed to open " << name << '\n';
        return -1;
    }
    return 0;
}

int CloseFile(const string& name, fstream& file) {
    file.close();
    if (file.fail()) {
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

int Overwrite(fstream& file, int c) {
    int size;
    if (GetFileSize(file, size) == -1) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        file.put(c);
        if (!file) {
            cerr << "Failed to put " << static_cast<int>(c) << '\n';
            return -1;
        }
    }
    return 0;
}

int ReadByte(fstream& file) {
    string line;
    int number;
    try {
        getline(file, line);
        number = std::stoi(line);
    }
    catch (std::invalid_argument const& ex) {
        cerr << "Failed to convert '" << line << "' to number\n";
        return -1;
    }
    catch (std::out_of_range const& ex) {
        cerr << "Converted number '" << line << "' is out of range\n";
        return -1;
    }
    if (!(number >= 0 && number <= 255)) {
        cerr << "'" << number << "' is not a byte\n";
        return -1;
    }
    return number;
}
