///*
#include <iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

//valid function to validate input information and allocate teamNames and number of players per team
bool valid (string race, string &teamName,int &players) {
    if (race != "done") {
    
    sort(race.begin(), race.end());
    race.erase(remove(race.begin(),race.end(),' '),race.end());
    string result = "The teams don't have the same number of runners\n"
                    "Please enter the result of the race(Enter (Done) when finished): ";
    int team=-1,member,k=0;
    players = 0;
    //for (team=0;team<=race.length() || race.length() == 1 ;team++) {
    while (race.length() != 0) {
        team++;
        teamName += race[k];
        for (member=0;member<=race.length();member++) {
//            cout<<"member"<<member<<endl;
            //check the part where different team member starts to appear and cut off first batch of team.
            if (race[k] != race[member]) {
            
                if (team == 0) players = member;
                if (players == &race[member]-&race[k]) {
                    
                    race = &race[member];
//                    cout<<"break:1 at"<<race<<endl;
                    break;
                } else {
//                    cout<<"1:"<<result;
                    return false;}
             }
            //last case to check if loop check is at the end of loop.
            if (member == (race.length()-1)) {
                if (players == &race[member] - &race[k] +1  ) {
                cout<<"\nThere are "<<team+1<<" teams\n";
                cout<<"Each team has "<<players<<" players\n\n";
                return true;
                } else {
//                   cout<<"2:"<<result;
                    return false;
                }
            }
        }
//        cout<<"Team: "<<team+1<<" race length: "<<race.length()<<endl;
    }
    
//    cout<<"3:"<<result;
    return false;
    } else return true;
}

//function for score calcuation per team
double score(string race,char team,int players) {
    double ans=0.00000;
    for (int i=0;i<race.length();i++) {
        if (race[i] == team) {
            ans = ans + (i+1.00000)/players;
        }
    }
    return ans;
}


int main () {
    string race,teams;
    int players;
    
    while (race!="done") {
        
        cout<<"Please enter the result of the race(Enter (Done) when finished): ";
        teams = "";
        cin>>race;
    
        //loop if the input information is not valid.
        while (valid(race,teams,players) == false) {
            teams = "";
            cin>>race;
        
    }
    
        //Setup score table
        cout<<'\t'<<"Team"<<'\t'<<'\t'<<"Score"<<endl<<endl;
    
        //Intialise minimum score for later comparison
        double min_score=score(race,teams[0],players);
    
        //loop to compare scores and output to tables.
        for(char c:teams){
            double s=score(race,c,players);
            cout<<'\t'<<c<<'\t'<<'\t'<<score(race,c,players)<<endl;
            if(s<min_score)
                min_score=s;
        }
        cout<<endl<<"min score= "<<min_score<<endl;
        system("pause");
        cout<<endl;
    }
    return 0;
}
//*/
