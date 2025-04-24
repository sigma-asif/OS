#include<bits/stdc++.h>
using namespace std;

double switching_time = 0.5;
int cnt = 0;

struct process {
    string name;
    int at, bt, remaining_bt, ct, tat, wt;
};

vector<process> pro = {
    {"P1", 0, 8, 8, 0, 0, 0}, // at, bt, remaining bt, ct, tat, wt
    {"P2", 1, 5, 5, 0, 0, 0}, 
    {"P4", 3, 4, 4, 0, 0, 0},
    {"P3", 2, 10, 10, 0, 0, 0},

};

bool compareByAT(const process &p1, const process &p2){
    return p1.at < p2.at; // sort ascending order
}

void solve(){
    //sort by arrival time
    sort(pro.begin(), pro.end(), compareByAT);
    int n = pro.size();
    vector<bool>visited(n, 0);
    int completed = 0;
    int tc = 3;

    int current_time = 0;
    while(completed<n){
        for(int i = 0; i<n; i++){
            if(visited[i] == 0 && pro[i].at<= current_time){
                if(pro[i].remaining_bt == tc){

                    pro[i].remaining_bt -= tc;
                    current_time += tc;

                    visited[i] = 1;
                    completed++;

                    pro[i].ct = current_time;
                    pro[i].tat = pro[i].ct - pro[i].at;
                    pro[i].wt = pro[i].tat - pro[i].bt;

                }
                else if(pro[i].remaining_bt<tc){
                    current_time += pro[i].remaining_bt;
                    pro[i].remaining_bt = 0;
                    visited[i] = 1;
                    completed++;

                    pro[i].ct = current_time;
                    pro[i].tat = pro[i].ct - pro[i].at;
                    pro[i].wt = pro[i].tat - pro[i].bt;

                }
                else{
                    pro[i].remaining_bt -= tc;
                    current_time += tc;
                }
            }
        }
    }
}

void show() {
    cout << setw(10) << "Process" << setw(10) << "AT" << setw(10) << "BT" << setw(10) << "CT"
         << setw(10) << "TAT" << setw(10) << "WT" << endl;

    for (auto &p : pro) {
        cout << setw(10) << p.name << setw(10) << p.at << setw(10) << p.bt << setw(10) << p.ct
             << setw(10) << p.tat << setw(10) << p.wt << endl;
    }
}

int main()
{
   solve();
   show(); 
}