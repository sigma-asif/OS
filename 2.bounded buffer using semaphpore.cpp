#include<bits/stdc++.h>
using namespace std;
int s = 1;
int buffer_size = 3;
int emp = 3;
int filled = 0;

queue<int>producer_waiting;
queue<int>consumer_waiting;

void consumer(int n2);
void producer(int n1){
    for(int i = 0; i<n1; i++){
        //wait
        //check buffer avaibility
        if(emp>=1){ //min n1 ta slot empty thakte hbe
            if(s == 1){
                //add to buffer
                emp--;
                s = 0;
                cout<<"product working on buffer"<<endl;
            }     
        }
        else{
            // emp<=0, since buffer has no empty slot
            producer_waiting.push(i);
            cout<<"product added to producer waiting queue"<<endl;

        }

        // now signal part

        if(filled <3){ //i.e min 1 ta slot faka ache
            s = 1;// i.e release resource
            filled++;
            cout<<"product added to buffer"<<endl;

            // consumer waiting portion
            // filled = 3, so consumer ekhn service dite parbo
            if(!consumer_waiting.empty()){
                consumer_waiting.pop();
                cout<<"consumer request granted from waiting"<<endl;
                consumer(1); //consume only one peace
            }

        }

    }

}

void consumer(int n2){
    for(int i = 0; i<n2; i++){
        //wait
        //check buffer avaibility
        if(filled>=1){ //min 1 ta slot filled
            if(s == 1){
                //acquire resource
                filled--;
                s = 0;
                cout<<"product working"<<endl;
            }     
        }
        else{
            // filled <=0, since buffer has full
            consumer_waiting.push(i);
            cout<<"product added to consumer waiting queue"<<endl;

        }

        // now signal part
        
        if(emp <3){ //1,2 min 1ta  pos3 can be empty
            s = 1; //release resourse
            emp++;
            cout<<"product consumed"<<endl;

            //producer waiting portion
            //lets say emp = 1, producer request grant
            if(!producer_waiting.empty()){
                producer_waiting.pop();

                cout<<"producer request granted from waiting"<<endl;
                producer(1); // only one product add to buffer

            }

        }


    }

}
int main(){
    int n1 = 5, n2 = 2;
    producer(n1);
    consumer(n2);
    

}