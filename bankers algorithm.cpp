#include <bits/stdc++.h>
using namespace std;

const int n = 5;  // Number of processes
const int m = 3;  // Number of resource types

vector<vector<int>> mx{
    {4, 3, 3},
    {3, 2, 2},
    {9, 0, 2},
    {7, 5, 3},
    {1, 1, 2}
};

vector<vector<int>> allocation{
    {1, 1, 2},
    {2, 1, 2},
    {4, 0, 1},
    {0, 2, 0},
    {1, 1, 2}
};

vector<int> available{2, 1, 0}; // Available resources
vector<vector<int>> need(n, vector<int>(m));

void solve() {
    // Calculate the Need Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = mx[i][j] - allocation[i][j];
        }
    }

    // Print Need Matrix
    cout << "Need Matrix -" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    // check wheter safe or not
    vector<bool>visited(n, 0);
    vector<int> safeSequence;
    int completed = 0;
    while(completed<n){
        bool found = false;
        for(int i = 0; i<n; i++){
            if(visited[i] == 0){
                bool canAllocate = true;

                 // Check if need[i] is less than or equal to available
                for(int j = 0; j<m; j++){
                    if(need[i][j] > available[j]){
                        canAllocate = false;
                        break;
                    }
                }

                //if allocation possible for process i then
                if(canAllocate){
                    for(int j = 0; j<m; j++){
                        available[j]+= allocation[i][j]; //release resource
                    }

                    completed++;
                    safeSequence.push_back(i);
                    visited[i] = true;
                    found = true; //for track in each cycle atleast one process can be completed.
                }
            }
            
        }
        if(found == false){
            cout<<"system is not in safe state."<<endl;
            return;
        }
    }

    // If we reach here, system is safe
    cout << "System is in a SAFE state.\nSafe sequence: ";
    for (int i : safeSequence) cout << "P" << i << " ";
    cout << endl;
}

int main() {
    solve();
}
