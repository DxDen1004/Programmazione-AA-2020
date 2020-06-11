#include<iostream>
using namespace std;

struct time{
  int hours;
  int minutes;
  int seconds; 
  
  time(int a = 0, int b = 0, int c = 0){
    hours = a;
    minutes = b;
    seconds = c;
  }
};

struct take{
  int sensorID;
  int playerID;
  time t;
  
  take(int a = 0, int b = 0, time c = time()){
    sensorID = a; 
    playerID = b; 
    t = c;
  }
};

struct player{
  int playerID;
  bool dishonest;
  string reason;
};

istream & operator>>(istream & s, time & x){
  cin >> x.hours;
  cin >> x.minutes;
  cin >> x.seconds;
}

istream & operator>>(istream & s, take & x){
  cin >> x.playerID;
  cin >> x.t;
}

bool operator>(const time & t1, const time & t2){

  if(t1.hours < t2.hours) return false;
  else if (t1.hours == t2.hours){
    if(t1.minutes < t2.minutes) return false;
    else if(t1.minutes == t2.minutes){
      if(t1.seconds < t2.seconds) return false;
      else return true;
    }else return true; 
  }else return true;
}

time operator-(const time & T1, const time & T2){
  time t;
  time t1 = T1;
  time t2 = T2;
  
  if(t1.minutes < t2.minutes){ 
    t1.minutes += 60;
    t1.hours--;
    t.minutes = (t1.minutes - t2.minutes);
  }else t.minutes = (t1.minutes - t2.minutes);
  
  if(t1.seconds < t2.seconds){
    t1.seconds += 60;
    t1.minutes--;
    t.seconds = (t1.seconds - t2.seconds);
  }else t.seconds = (t1.seconds - t2.seconds);

  t.hours = t1.hours - t2.hours;
  return t;
}

bool HasMissedWaypoint(take * T, int player, int playersNumber){
  int passedPoints = 0;

  for(int i = 0; i < playersNumber*3 && passedPoints < 3; i++){
    if(T[i].playerID == player) passedPoints++;
  }
  if(passedPoints < 3) return true;
  else return false;
}

time CalculateMinimumTimeForDistance(time t, int km){
  t.hours = (t.minutes*km)/60;
  t.minutes = (t.minutes*km)%60 + (t.seconds*km)/60;
  t.seconds = (t.seconds*km)%60;

  return t;
}

bool HasCheatedTime(take * T, int player, int playersNumber){
  int timeIndex = 0;
  time minimumTimeVariation(0,2,45); //Minima variazione di tempo accettabile 2.45min*km
  time tm[3];

  minimumTimeVariation = CalculateMinimumTimeForDistance(minimumTimeVariation, 11);

  for(int i = 0; i < playersNumber*3 && timeIndex < 3; i++){
    if(T[i].playerID == player){
      tm[timeIndex] = T[i].t;
      timeIndex++;
    }
  }

  for(int i = timeIndex-1; i > 0; i--)
    if(!(tm[i] - tm[i-1] > minimumTimeVariation)) return true;
  
  return false;
}

main()
{
  int playersNumber;
  time startTime;

  cin >> playersNumber;
  cin >> startTime;

  player P[playersNumber];    //elenco dei players
  take T[playersNumber*3];   //Max 3 rilevazioni per ogni partecipante, quindi mi serviranno almeno 3*partecipanti takes
  
  int value;
  cin >> value;

  for(int i = 0; value != -1; i++){
    T[i].sensorID = value;
    cin >> T[i];
    cin >> value;
  }
  
  for(int i = 0; i < playersNumber; i++){
    P[i].playerID = i;
    P[i].dishonest = HasMissedWaypoint(T, i, playersNumber);
    if(P[i].dishonest) P[i].reason = "salto sensore";
    else{
      P[i].dishonest = HasCheatedTime(T, i, playersNumber);
      if(P[i].dishonest) P[i].reason = "tempo sospetto";
    }
  }

  for(int i = 0; i < playersNumber; i++){
    if(P[i].dishonest) cout << i << ": " << P[i].reason << endl;
  }

}
