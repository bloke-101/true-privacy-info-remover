using std::ios;
using std::string;
using std::fstream;


bool OpenFile(const string& name, ios::openmode mode, fstream& fs);

void CloseFile(const string& name, fstream& fs);
