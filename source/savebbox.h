#include <fstream>
#include <string>

class BboxFile
{
private:
    std::ofstream file;

public:
    bool Open(const char *filename);
    void SaveLine(double x, double y, double width, double height);
    void Close();
};