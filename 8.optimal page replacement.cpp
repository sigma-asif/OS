#include <bits/stdc++.h>
using namespace std;

vector<int> q;
vector<int> s = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

int frame_size = 3; //max capacity
int fault = 0;
int hit = 0;

int pos;
bool exist(int value){
    auto it = find(q.begin(), q.end(), value);
    if(it != q.end()){
        return true;
    }
    else{
        return false;
    }


}
void solve() {
    for(int i = 0; i<s.size(); i++){
        if(frame_size>0 && frame_size<=3){
            if(exist(s[i])){
                hit++;
                continue;
            }

            fault++;
            q.push_back(s[i]);
            frame_size--;
        }
        else{
            if(exist(s[i])){
                hit++;
            }
            else{
                int farthest = -1;
                int indx = -1;

                for(int j = 0; j<q.size(); j++){
                    int next_use = s.size(); //never used again
                    for(int k = i+1; k<s.size(); k++){
                        if(q[j] == s[k]){
                            next_use = k;
                            break;
                        }
                    }
                    if(next_use> farthest){
                        farthest = next_use;
                        indx = j;
                    }
                }

                q[indx] = s[i];
                fault++;
            }
        }
    }
   
}

int main() {
    solve();
    cout << "Hit = " << hit << endl;
    cout << "Fault = " << fault << endl;
    return 0;
}
