#include<bits/stdc++.h>
using namespace std;
vector<int>memory{25,15,10,13,17};
vector<int>process{20,12,15,10,14};
int n = 5;
vector<bool>visited(n,0);

vector<pair<int,int>>table;

void solve(){
    for(int i = 0; i<process.size(); i++){
            int min_if = INT_MAX;
            int track_pos;
            int cnt = 0;
       for(int j = 0; j<memory.size(); j++){
            if(visited[j] == 0){
                if(memory[j]>= process[i]){
                    int temp = memory[j]-process[i];
                    if(temp<min_if){
                        min_if = temp;
                        //visited[j] = 1;
                        track_pos = j;
                        cnt = 1;
                    }

                }
            }
       }
       visited[track_pos] = 1;
       table.push_back(make_pair(process[i],memory[track_pos]));
       if(cnt == 0){
           cout<<"no fitting partition available for process "<<process[i]<<endl;
       }
    }
}


int main()
{
    solve();
    cout<<"process"<<setw(10)<<"memory"<<endl;
    for(auto &p: table){
        cout<<p.first<<setw(10)<<p.second<<endl;
    }
}

