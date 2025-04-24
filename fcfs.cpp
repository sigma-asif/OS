#include<bits/stdc++.h>
using namespace std;

struct process{
    string name;
    int at, bt;
};

// List of processes
vector<process> pro = {
    {"P1", 0, 7}, //name, at , bt
    {"P2", 3, 4},
    {"P3", 2, 3}
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

void solve(){
    // sort processes by at
    sort(pro.begin(), pro.end(), compareByAT);

    int ct_prev = 0;
    for(int i = 0; i<pro.size(); i++){
        string name;
        int at, bt, ct, tat, wt;

        name = pro[i].name;
        at = pro[i].at;
        bt = pro[i].bt;
        ct = bt + max(ct_prev, at);
        tat = ct - at;
        wt = tat - bt;

        table.push_back(times(name,at,bt,ct,tat,wt));
        ct_prev = ct;
    }
}


int main()
{

    solve();
    show();
}
