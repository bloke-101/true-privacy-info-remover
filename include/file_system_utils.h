using std::ios;
using std::string;
using std::fstream;


int OpenFile(const string& name, ios::openmode mode, fstream& file);

int CloseFile(const string& name, fstream& file);

int GetFileSize(fstream& file, int& size);

int Overwrite(fstream& file, char c);

int ReadByte(fstream& file);
