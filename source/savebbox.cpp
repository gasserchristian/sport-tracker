#include "savebbox.h"
#include <stdio.h>

bool BboxFile::Open(const char *filename)
{
    file.open("bbox.txt");
    printf("[i] file open with name %s\n", filename);
    return file.is_open();
}

void BboxFile::SaveLine(double x, double y, double width, double height)
{
    if (file.is_open())
    {
        std::string rectString = std::to_string(x) + " " +
                                 std::to_string(y) + " " +
                                 std::to_string(width) + " " +
                                 std::to_string(height);

        file << rectString << '\n';
    }
}

void BboxFile::Close()
{
    if (file.is_open())
    {
        printf("[i] file closes\n");
        file.close();
    }
}
