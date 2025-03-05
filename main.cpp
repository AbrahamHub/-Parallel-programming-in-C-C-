#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void writerandom(int variable, string filename) {
    stringstream filename_extender;
    filename_extender << "randoms/" << filename << ".txt";
    ofstream outputfile;
    outputfile.open(filename_extender.str().c_str());
    for (int i = 0; i < variable; i++) {
        outputfile << rand() << endl;
    }
    outputfile.close();
}

void writeaverage(string inputfilename, string outputfilename) {
    stringstream inputfilename_extender;
    inputfilename_extender << "randoms/" << inputfilename << ".txt";
    stringstream outputfilename_extender;
    outputfilename_extender << "randoms/" << outputfilename << ".txt";
    ifstream inputfile;
    inputfile.open(inputfilename_extender.str().c_str());
    inputfilename_extender.str(string());
    inputfilename_extender << inputfilename << ".txt";
    ofstream outputfile;
    outputfile.open(outputfilename_extender.str().c_str(), ios::app);
    int temp_int = 0;
    int sum = 0;
    int counter = 0;
    while (inputfile >> temp_int) {
        sum += temp_int;
        counter++;
    }
    int average = sum / counter;
    outputfile << inputfilename_extender.str() << "\t" << average << endl;
    inputfile.close();
    outputfile.close();
}

int main(int argc, char *argv[]) {
    //Main begins

    if (argc == 1) {
        string filename = "name";
        stringstream namecounter;

        for (int i = 0; i < 1000; i++) {
            namecounter.str(string());
            namecounter << filename << i;
            writerandom(100, namecounter.str().c_str());
            writeaverage(namecounter.str().c_str(), "averages");
        }
    }

    if (argc == 2) {
        string filename = argv[1];
        stringstream namecounter;

        for (int i = 0; i < 1000; i++) {
            namecounter.str(string());
            namecounter << filename << i;
            writerandom(100, namecounter.str().c_str());
            writeaverage(namecounter.str().c_str(), "averages");
        }
    }

    if (argc == 3) {
        string filename = argv[1];
        int number_of_random_files = strtol(argv[2], NULL, 10);
        stringstream namecounter;
        for (int i = 0; i < number_of_random_files; i++) {
            namecounter.str(string());
            namecounter << filename << i;
            writerandom(100, namecounter.str().c_str());
            writeaverage(namecounter.str().c_str(), "averages");
        }
    }

    return 0;
} //Main Ends
