#include<bits/stdc++.h>
using namespace std;

struct process{
    string name;
    int at, bt, priority, ct, tat, wt;
};

vector<process> pro = {
    {"P1", 0, 5, 2, 0, 0, 0},
    {"P2", 1, 3, 1, 0, 0, 0},
    {"P3", 2, 8, 4, 0, 0, 0},
    {"P4", 3, 6, 3, 0, 0, 0}
};



bool compareByAT(const process &p1, const process &p2){
    return p1.at < p2.at; // sort ascending order
}





void show(){
    cout<<setw(10)<<"name"<<setw(10)<<"at"<<setw(10)<<"bt"<<setw(10)<<"ct"<<setw(10)<<"tat"<<setw(10)<<"wt"<<endl;

    for(auto &p:pro){
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
        int min_prio = DBL_MAX;
        int indx = -1;
        for(int i = 0; i<n; i++){
            if(visitied[i] == 0 && pro[i].at<=current_time && pro[i].priority < min_prio){
                min_prio = pro[i].priority;
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

            //modifie table,
            pro[indx].ct = ct;
            pro[indx].tat = tat;
            pro[indx].wt = wt;

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
