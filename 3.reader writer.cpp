#include<bits/stdc++.h>
using namespace std;
vector<string>Thread{"R1","R2","R3","W1","R4","W2"};
int n = 6; //size


//control unit
int m = 1;   //mutex, Controls access to reading access
int w = 1;   //Controls write access
int cnt = 0; //Number of readers currently reading

queue<string>ws_wating;
queue<string>reading;

void write(string t){
    //wait operation
    if(w == 1){
        //acquire resource 
        w = 0;
        cout<<t<<" acquires resource"<<endl;
    }
    else{
        // w = 0 go to waiting
        cout<<t<<" pushed to writers waiting queue"<<endl;
        ws_wating.push(t);   
    }

    
    //signal operation
    //release resource
    if(w == 0){
        w = 1;
        cout<<t<<" finishes writing resource"<<endl;

        if(!ws_wating.empty()){
            string temp = ws_wating.front();
            ws_wating.pop();

            write(temp);
        }

    }
    


}

void reader(string t){
    if(m == 1){
        //acquire resource
        m = 0;
        cnt++;
        reading.push(t);
        cout<<t<<" reading resource"<<endl;
        if(cnt == 1){
            w = 0; //block write
        }
        // continuing reading and give access for another reader
        m = 1;
    }

}

void finish_reading(){
    m = 0; //
    while(!reading.empty()){
        string tmp = reading.front();
        reading.pop();
        cout<<tmp<<" finished reading"<<endl;
    }
    
    m = 1;
}

void solve(){
    string first_letter;
    for(int i = 0; i<Thread.size(); i++){
        string first_letter = Thread[i].substr(0,1);

        if(first_letter == "R"){ //reader
            reader(Thread[i]);
        }
        else{
            // finish reading then space for writer
            finish_reading(); //if ekata specific thread finish korte chai just oi thread name dilei hocche
            w = 1;
            write(Thread[i]);
        }

    }

}

int main()
{
   solve();
}