#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int main()
{
    string filename;
    bool flag;
    cout << "Input file name: ";
    cin >> filename;

    cout << "Do you want to display the contents of the file (1/0):";
    cin >> flag;
    cout << endl;
    int polynomials;
    int variables;
    ifstream in;
    in.open(filename);
    in >> polynomials;
    in >> variables;
    int array[polynomials][variables];
    int sum[variables];

    for (int i = 0; i < polynomials; i++)
    {
        for (int k = 0; k < variables; k++)
        {
            in >> array[i][k];
        }
    }

    for (int i = 0; i < variables; i++)
    {
        sum[i] = 0;
    }

    clock_t tStart = clock();

    for (int i = 0; i < polynomials; i++)
    {
        for (int j = 0; j < variables; j++)
        {
            sum[j] = sum[j] + array[i][j];
        }
    }

    if (flag == 1)
    {
        cout << polynomials << endl;
        cout << variables << endl;

        for (int i = 0; i < polynomials; i++)
        {
            for (int k = 0; k < variables; k++)
            {
                cout << array[i][k] << " ";
            }
            cout << endl;
        }
    }

    cout << "Result:" << endl;

    for (int i = 0; i < variables; i++)
    {
        cout << sum[i] << " ";
    }

    cout << endl;

    ofstream out;
    out.open("result_addition.txt");
    out << filename << endl;
    out << "Result:" << endl;

    for (int i = 0; i < variables; i++)
    {
        out << sum[i] << " ";
    }

    int nonzero = 0;

    for (int i = 0; i < polynomials; i++)
    {
        for (int k = 0; k < variables; k++)
        {
            if (array[i][k] != 0)
            {
                nonzero++;
            }
        }
    }

    cout << "File name is: " << filename << endl;
    cout << "The number of polynomials in the file: " << polynomials << endl;
    cout << "The number of variables in the file: " << variables << endl;
    cout << "The number of non zero values: " << nonzero << endl;
    cout << "Data structure used: array" << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

    return 0;
}
