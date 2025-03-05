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

int main(int argc, char *argv[]) { // Main begins
    const int max_threads_used = 8;
    const int mtu = max_threads_used;

    pthread_t threads[mtu];
    int runcommand;

    for (int i = 0; i < mtu; i++) {
        runcommand = pthread_create(&threads[i], NULL, ThreadChecker, (void *)i);
        if (runcommand) {
            cout << "Error: unable to create thread," << runcommand << endl;
            exit(-1);
        }
    }

    pthread_exit(NULL);
    return 0;
} // Main Ends
