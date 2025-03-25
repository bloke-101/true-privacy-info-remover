#include <fstream>
#include <iostream>

#include "info_remover.h"
#include "file_system_utils.h"

using std::ios;
using std::cerr;
using std::fstream;


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
