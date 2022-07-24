#include "pl.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

LinearProgram::LinearProgram()
{
    cin >> this->month;

    this->afluencia.reserve(this->month);
    this->demandas.reserve(this->month);

    for (size_t i = 0; i < this->month; i++)
    {
        cin >> this->demandas[i];
    }

    for (size_t i = 0; i < this->month; i++)
    {
        cin >> this->afluencia[i];
    }

    cin >> this->vini >> this->min >> this->max >> this->k;
    cin >> this->tmax >> this->ct >> this->ca;
}

LinearProgram::LinearProgram(string filename)
{
    fstream input_file(filename, ios_base::in);

    input_file >> this->month;

    this->afluencia.reserve(this->month);
    this->demandas.reserve(this->month);

    for (size_t i = 0; i < this->month; i++)
    {
        input_file >> this->demandas[i];
    }

    for (size_t i = 0; i < this->month; i++)
    {
        input_file >> this->afluencia[i];
    }

    input_file >> this->vini >> this->min >> this->max >> this->k;
    input_file >> this->tmax >> this->ct >> this->ca;
}

void LinearProgram::toFile(string filename)
{
    ofstream output_file(filename, ios_base::out);

    output_file << "min: "; // funcao objetivo
    for (size_t i = 0; i < this->month; i++)
    {
        output_file << this->ca << "x" << i + 1 << " + " << this->ca << "z" << i + 1 << " + " << this->ct << "t" << i + 1;
        if (i + 1 == this->month)
            output_file << ";\n"
                        << endl;
        else
            output_file << " + ";
    }

    output_file << "/* restricoes para a retirada do modulo */" << endl;
    for (size_t i = 0; i < this->month; i++)
        output_file << "x" << i + 1 << " - z" << i + 1 << " = " << this->afluencia[i] << " - h" << i + 1 << ";" << endl;

    output_file << "\n/* volume do mes atual */" << endl;
    output_file << "v1 = " << this->vini << " + " << this->afluencia[0] << ";" << endl;
    for (size_t i = 1; i < this->month; i++)
        output_file << "v" << i + 1 << " = v" << i << " + " << this->afluencia[i] << " - h" << i << ";" << endl;

    output_file << "\n/* restricoes para o volume minimo e maximo da hidroeletrica */" << endl;
    for (size_t i = 0; i < this->month; i++)
        output_file << "v" << i + 1 << " - h" << i + 1 << " <= " << this->max << ";" << endl;
    for (size_t i = 0; i < this->month; i++)
        output_file << "v" << i + 1 << " - h" << i + 1 << " >= " << this->min << ";" << endl;

    output_file << "\n/* restricoes para o consumo maximo de agua */" << endl;
    for (size_t i = 0; i < this->month; i++)
        output_file << "h" << i + 1 << " <= v" << i + 1 << ";" << endl;

    output_file << "\n/* geracao maxima da termoeletrica */" << endl;
    for (size_t i = 0; i < this->month; i++)
        output_file << "t" << i + 1 << " <= " << this->tmax << ";" << endl;

    output_file << "\n/* demanda minima de energia */" << endl;
    for (size_t i = 0; i < this->month; i++)
        output_file << k << "h" << i + 1 << " + t" << i + 1 << " >= " << this->demandas[i] << ";" << endl;

    output_file << "\n/* restricoes de nao negativade */" << endl;
    for (size_t i = 0; i < this->month; i++)
    {
        output_file << "x" << i + 1 << " >= 0;" << endl;
        output_file << "z" << i + 1 << " >= 0;" << endl;
        output_file << "h" << i + 1 << " >= 0;" << endl;
        output_file << "t" << i + 1 << " >= 0;" << endl;
    }

    output_file << "\n"
                << endl;
    for (size_t i = 0; i < this->month; i++)
    {
        output_file << "Consumo_agua_mes_" << i + 1 << " = h" << i + 1 << ";" << endl;
        output_file << "Geracao_termo_mes_" << i + 1 << " = t" << i + 1 << ";" << endl;
    }

    output_file.close();
}