// Gabriel de Oliveira Pontarolo GRR20203895
// Rordrigo Soffner Saviam GRR20205092
#include <iostream>
#include <string>
#include "lp.h"
using namespace std;

int main(int argc, char const *argv[])
{
    const string output_file = "lp_output.txt";

    if (argc < 2)
    {
        LinearProgram pl;
        pl.toFile("lp_output.txt");
    }
    else
    {
        LinearProgram pl(argv[1]);
        pl.toFile("lp_output.txt");
    }

    return 0;
}
