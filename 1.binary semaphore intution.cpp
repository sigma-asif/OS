/*Key Characteristics of Implementation:

1. **Initial State (S = 0)**
   - Resource is immediately blocked
   - No thread can acquire resource initially
   - Threads are queued

2. **Wait Operation**
   - If S = 0, thread is blocked and added to waiting queue
   - If S = 1, thread acquires resource

3. **Signal Operation**
   - Releases resource (sets S = 1)
   - Checks waiting queue
   - Releases next waiting thread*/

#include<bits/stdc++.h>
using namespace std;

queue<char>waiting;
void solve(char t);
int s = 1;
void wait(char ct){
    if(s == 1){
        //resource free
        //accquire
        s = 0;
        cout<<"thread"<<ct<<" acquires resource"<<endl;
    }
    else{
        //s = 0
        waiting.push(ct);
        cout<<"thread"<<ct<<" added to waiting queue"<<endl;
    }
}

void signal(char ct){
    if(s == 0){
        //release resource
        s = 1;
        cout<<"thread"<<ct<<" released resource"<<endl;

        if (!waiting.empty()) {
            char next_thread = waiting.front();
            waiting.pop();
            
            // When this method is called
            //next_thread.acquire_resource();
            cout<<"thread"<<next_thread<<" unlocked"<<endl;
            solve(next_thread);
        }
    }

}

void solve(char t){
    wait(t);
    signal(t);

}
int main()
{
    queue<char> q;  // Declare a queue

    q.push('A');
    q.push('B');
    q.push('C');


    while (!q.empty()) {
        char ct = q.front();
        q.pop();
        
        solve(ct);
    }

}  