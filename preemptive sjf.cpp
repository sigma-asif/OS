#include<bits/stdc++.h>
using namespace std;

double switching_time = 0.5;
int cnt = 0;

struct process {
    string name;
    int at, bt, remaining_bt, ct, tat, wt;
};

vector<process> pro = {
    {"P1", 0, 7, 7, 0, 0, 0}, // at, bt, remaining bt, ct, tat, wt
    {"P2", 2, 4, 4, 0, 0, 0}, 
    {"P3", 3, 1, 1, 0, 0, 0}
};

bool compareByAT(const process &p1, const process &p2){
    return p1.at < p2.at; // sort ascending order
}

void solve(){
    int n = pro.size();
    vector<bool> visited(n, 0);
    int completed = 0;
    int current_time = 0;
    int prev = 0;
    cout<<"time switching-"<<endl;
    while(completed<n){
        int indx = -1;
        int min_rem_bt = DBL_MAX;

        // sort by at
        sort(pro.begin(), pro.end(),compareByAT);

        for(int i = 0; i<n; i++){
            if(visited[i] == 0 && pro[i].at<=current_time && pro[i].remaining_bt< min_rem_bt){
                indx = i;
            }
        }

        if(indx == -1){
            current_time++;
        }
        else{
            //switching check
            if(indx!= prev){
                cout<<pro[prev].name<<"->"<<pro[indx].name<<endl;
                cnt++;
                prev = indx;
            }
            pro[indx].remaining_bt--;
            current_time++;

            if(pro[indx].remaining_bt == 0){
                visited[indx] = 1;
                completed++;

                pro[indx].ct = current_time;
                pro[indx].tat = pro[indx].ct - pro[indx].at;
                pro[indx].wt = pro[indx].tat - pro[indx].bt;
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