#include <string>
#include <fstream>
#include <iostream>

#include "file_system_utils.h"

using std::ios;
using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::fstream;


bool IsArgsInRange(int argc) {
    return argc > 1 && argc < 4;
}

void ShowHelpMessage() {
    string message {"This tool is meant to wipe files "
        "by overwriting them.\n\n"

        "The tool supports the following modes:\n"
        "1. Overwriting a file with the Bruce Schneier's algorithm.\n"
        "2. Overwriting a file with the provided byte values.\n\n"

        "Use-cases:\n"
        "1. true_privacy_info_remover file-to-overwrite\n"
        "2. true_privacy_info_remover file-to-overwrite byte-values.txt"
    };
    cout << message << '\n';
}

void ShowWrongArgsMessage() {
    cout << "Wrong CLI arguments!\nRead the help message.\n\n";
    ShowHelpMessage();
}

int main(int argc, const char* argv[]) {
    if (!IsArgsInRange(argc)) {
        ShowWrongArgsMessage();
        return 0;
    }
    fstream fileToOverwrite;
    ios::openmode mode = ios::in | ios::out | ios::binary;
    if (OpenFile(argv[1], mode, fileToOverwrite)) {
        return -1;
    }
    if (argc == 2) {

    }
    else {
        fstream overwritingValues;
        if (OpenFile(argv[2], ios::in, overwritingValues)) {
            CloseFile(argv[2], overwritingValues);
            return -1;
        }
    }
    return 0;
}
