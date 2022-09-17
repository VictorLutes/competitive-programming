/*
Algoritmos Gulosos:

*/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    
    for(int i=0; i<t; ++i){
        fgetc(stdin);
        cin >> n;
        int speed[n];
        list<int> start, end;
        vector<int> print;
        for(int j=0; j<n; ++j){
            cin >> speed[j];
        }

        sort(speed, speed+n);

        for(int j=0; j<n; ++j){
            start.push_back(speed[j]);
        }

        int sum=0, counter=0, fast, slow, pos=0;

        if(n==1){
            start.pop_front();
        }

        while(!start.empty()){
            if(counter%2==0){
                fast=start.front();
                start.pop_front();
                slow=start.front();
                start.pop_front();
                if(slow<fast){
                    int tmp=fast;
                    fast=slow;
                    slow=tmp;
                }
                sum+=slow;
                end.push_front(slow);
                end.push_front(fast);

                print.push_back(fast);
                print.push_back(slow);
                pos+=2;

                if(!start.empty()){
                    fast=end.front();
                    end.pop_front();
                    sum+=fast;
                    start.push_front(fast);

                    print.push_back(fast);
                    ++pos;
                }                
            }
            else{
                slow=start.back();
                start.pop_back();
                fast=start.back();
                start.pop_back();
                sum+=slow;
                end.push_back(fast);
                end.push_back(slow);

                print.push_back(fast);
                print.push_back(slow);
                pos+=2;

                if(!start.empty()){
                    fast=end.front();
                    end.pop_front();
                    sum+=fast;
                    start.push_front(fast);

                    print.push_back(fast);
                    ++pos;
                }
            }
            
            ++counter;
        }
        
        for(int j=0; j<n; ++j){
            start.push_back(speed[j]);
        }
        if(n==1){
            start.pop_front();
        }

        int sum2=0, pos2=0;
        counter=0;
        vector<int> print2;


        while(!start.empty() && !(n>5 && start.size()<=4)){
            if(counter%2==0){
                fast=start.front();
                start.pop_front();
                slow=start.front();
                start.pop_front();
                if(slow<fast){
                    int tmp=fast;
                    fast=slow;
                    slow=tmp;
                }
                sum2+=slow;
                end.push_front(slow);
                end.push_front(fast);

                print2.push_back(fast);
                print2.push_back(slow);
                pos2+=2;        

                if(!start.empty()){
                    fast=end.front();
                    end.pop_front();
                    sum2+=fast;
                    start.push_front(fast);

                    print2.push_back(fast);
                    ++pos2;
                }        
            }
            else{
                slow=start.back();
                start.pop_back();
                fast=start.back();
                start.pop_back();
                sum2+=slow;
                end.push_back(fast);
                end.push_back(slow);

                print2.push_back(fast);
                print2.push_back(slow);
                pos2+=2;

                if(!start.empty()){
                    fast=end.front();
                    end.pop_front();
                    sum2+=fast;
                    start.push_front(fast);

                    print2.push_back(fast);
                    ++pos2;
                }
            }
            
            ++counter;
        }
        
        counter=0;
        if(n>5){
            int four[4];
            for(int j=0; j<4; ++j){
                four[j]=start.front();
                start.pop_front();
                sum2+=four[j];
            }
            sort(four, four+4);
            sum2+=four[0];
            pos2+=8;
            print2.push_back(four[0]);
            print2.push_back(four[2]);
            print2.push_back(four[0]);
            print2.push_back(four[0]);
            print2.push_back(four[3]);
            print2.push_back(four[0]);
            print2.push_back(four[0]);
            print2.push_back(four[1]);
        }

        int sum3=0, pos3=0;
        counter=1;
        vector<int> print3;
        for(int j=1; j<n; ++j){
            sum3+=speed[n-j];
            pos3+=2;
            print3.push_back(speed[0]);
            if(j==n-1)print3.push_back(speed[1]);
            else if(counter%2==1)print3.push_back(speed[n-j-1]);
            else print3.push_back(speed[n-j+1]);
            if(j!=n-1){
                print3.push_back(speed[0]);
                sum3+=speed[0];
                ++pos3;
            }
            ++counter;
        }


        counter=0;
        if(n==1){
            if(i>0) cout << "\n";
            cout << speed[0];
            cout << "\n";
            cout << speed[0] << "\n";
        }
        else if(n<4 || (sum<sum2 && sum<sum3)){
            if(i>0) cout << "\n";
            cout << sum;
            cout << "\n";
            for(int i=0; i<pos; ){
                if(counter%2==0){
                    cout << print[i] << " " << print[i+1] << "\n";
                    i+=2;
                }
                else{
                    cout << print[i] << "\n";
                    ++i;
                }
                ++counter;
            }
        }
        else if(sum2<sum3){
            if(i>0) cout << "\n";
            cout << sum2;
            cout << "\n";
            for(int i=0; i<pos2; ){
                if(counter%2==0){
                    cout << print2[i] << " " << print2[i+1] << "\n";
                    i+=2;
                }
                else{
                    cout << print2[i] << "\n";
                    ++i;
                }
                ++counter;
            }
        }
        else{
            if(i>0) cout << "\n";
            cout << sum3;
            cout << "\n";
            for(int i=0; i<pos3; ){
                if(counter%2==0){
                    cout << print3[i] << " " << print3[i+1] << "\n";
                    i+=2;
                }
                else{
                    cout << print3[i] << "\n";
                    ++i;
                }
                ++counter;
            }
        }
    }
}