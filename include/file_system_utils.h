using std::ios;
using std::string;
using std::fstream;


int OpenFile(const string& name, ios::openmode mode, fstream& fs);

int CloseFile(const string& name, fstream& fs);

int GetFileSize(fstream& file, int& size);

int Overwrite(fstream& stream, char c);
