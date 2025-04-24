#include<bits/stdc++.h>
using namespace std;

struct process{
    string name;
    int at, bt,remaining_bt, priority, ct, tat, wt;
};

vector<process> pro = {
    {"P1", 0, 5, 5, 2, 0, 0, 0},
    {"P2", 1, 3, 3, 1, 0, 0, 0},
    {"P3", 2, 8, 8, 4, 0, 0, 0},
    {"P4", 3, 6, 6, 3, 0, 0, 0}
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
    vector<bool> visited(n, 0);
    int completed = 0;
    int current_time = 0;

    while(completed<n){
        int min_prio = DBL_MAX;
        int indx = -1;
        for(int i = 0; i<n; i++){
            if(visited[i] == 0 && pro[i].at<=current_time && pro[i].priority < min_prio){
                min_prio = pro[i].priority;
                indx = i;
            }
        }
        

        if(indx == -1){
            current_time++;
        }
        else{
            
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


int main()
{

    solve();
    show();
}
