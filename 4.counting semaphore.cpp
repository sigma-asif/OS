#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

// Counting semaphore with a max count of 2
counting_semaphore<2> semaphore(2);

void worker(int id) {
    cout << "Thread " << id << " is waiting for the semaphore..." << endl;
    
    semaphore.acquire();  // Acquire semaphore (wait)
    cout << "Thread " << id << " acquired the semaphore and is working." << endl;

    this_thread::sleep_for(chrono::seconds(2)); // Simulate work

    cout << "Thread " << id << " has finished and released the semaphore." << endl;
    semaphore.release();  // Release semaphore
}

int main() {
    vector<thread> threads;

    // Create 5 worker threads
    for (int i = 1; i <= 5; i++) {
        threads.emplace_back(worker, i);
    }

    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}