#include<bits/stdc++.h>
using namespace std;

struct process{
    string name;
    int at, bt;
};

// List of processes
vector<process> pro = {
    {"P1", 0, 7}, //name, at , bt
    {"P2", 2, 4},
    {"P3", 4, 1},
    {"p4", 5, 4}
};

bool compareByAT(const process &p1, const process &p2){
    return p1.at < p2.at; // sort ascending order
}

// different times
struct times{
    string name;
    int at, bt, ct, tat, wt;

    times(string name, int at, int bt, int ct, int tat, int wt){
        this-> name = name;
        this-> at = at;
        this-> bt = bt;
        this-> ct = ct;
        this-> tat = tat;
        this-> wt = wt;
    }

};

vector<times> table; // vector of diffrent times

void show(){
    cout<<setw(10)<<"name"<<setw(10)<<"at"<<setw(10)<<"bt"<<setw(10)<<"ct"<<setw(10)<<"tat"<<setw(10)<<"wt"<<endl;

    for(auto &p:table){
        cout<<setw(10)<<p.name<<setw(10)<<p.at<<setw(10)<<p.bt<<setw(10)<<p.ct<<setw(10)<<p.tat<<setw(10)<<p.wt<<endl;
    }
}


// logical section 
void solve(){

    // sort processes by at
    sort(pro.begin(), pro.end(), compareByAT);

    int n = pro.size();
    vector<bool> visitied(n, 0);
    int completed = 0;
    int current_time = 0;

    while(completed<n){
        int min_bt = DBL_MAX;
        int indx = -1;
        for(int i = 0; i<n; i++){
            if(visitied[i] == 0 && pro[i].at<=current_time && pro[i].bt < min_bt){
                min_bt = pro[i].bt;
                indx = i;
            }
        }

        if(indx != -1){
            
            string name = pro[indx].name;
            int at = pro[indx].at;
            int bt = pro[indx].bt;
            int ct = pro[indx].bt + current_time;
            current_time = ct;
            int tat = ct - at;
            int wt = tat - bt;

            table.push_back(times(name, at, bt, ct, tat, wt));

            completed++;
            visitied[indx] = 1;
        }
        else{
            current_time++;
        }
    }

    
}


int main()
{

    solve();
    show();
}
