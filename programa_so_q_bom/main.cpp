#include <iostream>
#include <string>
#include "pl.h"
using namespace std;

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        LinearProgram pl;
        pl.toFile("output.txt");
    }
    else
    {
        LinearProgram pl(argv[1]);
        pl.toFile(argv[2]);
    }

    return 0;
}
