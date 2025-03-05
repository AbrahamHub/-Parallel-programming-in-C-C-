#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <pthread.h>

using namespace std;

void *ThreadChecker(void *thread_ID) {
    long t_id;
    t_id = (long)thread_ID;
    cout << "Checking thread: " << t_id << endl;
    pthread_exit(NULL);
}

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

void *assign_thread_writerandom(void *thread_ID) {
    long t_id;
    t_id = (long)thread_ID;
    stringstream filename_extender;
    filename_extender << "Written_By_Thread_ID_" << t_id;
    writerandom(1000000, filename_extender.str().c_str());
    pthread_exit(NULL);
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

void *assign_thread_writeaverage(void *thread_ID) {
    long t_id;
    t_id = (long)thread_ID;
    stringstream filename_extender;
    filename_extender << "Written_By_Thread_ID_" << t_id;
    writeaverage(filename_extender.str().c_str(), "average");
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) { //Main begins
    const int max_threads_used = 8;
    const int mtu = max_threads_used;

    pthread_t threads[mtu];
    int runcommand;

    for (int i = 0; i < mtu; i++) {
        runcommand = pthread_create(&threads[0], NULL, ThreadChecker, (void *)i);
        if (runcommand) {
            cout << "Error:unable to create thread," << runcommand << endl;
            exit(-1);
        }
    }
    for (int i = 0; i < mtu; i++) {
        runcommand = pthread_create(&threads[0], NULL, assign_thread_writerandom, (void *)i);
        if (runcommand) {
            cout << "Error:unable to create thread," << runcommand << endl;
            exit(-1);
        }
    }

    for (int i = 0; i < mtu; i++) {
        runcommand = pthread_create(&threads[0], NULL, assign_thread_writeaverage, (void *)i);
        if (runcommand) {
            cout << "Error:unable to create thread," << runcommand << endl;
            exit(-1);
        }
    }

    pthread_exit(NULL);
    return 0;
} //Main Ends
