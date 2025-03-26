#include <string>
#include <fstream>
#include <iostream>

#include "random_generator.h"
#include "file_system_utils.h"

using std::ios;
using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::fstream;

using str = const string;


enum class RemovingMode {
    BruceSchneier = 2,
    UserValues
};

void ShowHelpMessage() {
    str message {"This tool is meant to wipe files "
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

int RemoveFileWithBSAlgorithm(str& filePath) {
    ios::openmode mode = ios::in | ios::out | ios::binary;
    fstream fileToRemove;
    if (OpenFile(filePath, mode, fileToRemove) == -1) {
        return -1;
    }
    if (Overwrite(fileToRemove, 255) == -1) {
        return -1;
    }
    if (Overwrite(fileToRemove, 0) == -1) {
        return -1;
    }
    PRNG generator;
    initGenerator(generator);
    for (int i = 0; i < 5; i++) {
        if (Overwrite(fileToRemove, random(generator, 0, 255)) == -1) {
            return -1;
        }
    }
    return CloseFile(filePath, fileToRemove);
}

int RemoveFileWithUserValues(str& filePath, str& userValuePath) {
    ios::openmode mode = ios::in | ios::out | ios::binary;
    fstream fileToRemove;
    if (OpenFile(filePath, mode, fileToRemove) == -1) {
        return -1;
    }
    fstream userValues;
    if (OpenFile(userValuePath, ios::in, userValues) == -1) {
        CloseFile(filePath, fileToRemove);
        return -1;
    }
    int userValue;
    while (!userValues.eof()) {
        if ((userValue = ReadByte(userValues)) == -1) {
            return -1;
        }
        if (Overwrite(fileToRemove, userValue) == -1) {
            return -1;
        }
    }
    if (CloseFile(filePath, fileToRemove) == -1) {
        return CloseFile(userValuePath, userValues);
    }
    return CloseFile(userValuePath, userValues);
}

int main(int argc, const char* argv[]) {
    RemovingMode mode = static_cast<RemovingMode>(argc);
    switch(mode) {
        case RemovingMode::BruceSchneier:
            return RemoveFileWithBSAlgorithm(argv[1]);
        case RemovingMode::UserValues:
            return RemoveFileWithUserValues(argv[1], argv[2]);
        default:
            ShowWrongArgsMessage();
    }
    return 0;
}
