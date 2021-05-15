int gst=20; //green signal time
int ns=4;  //no.of signals
int sn=1; //current signal number



//pin numbers for LEDS: {{RYG for signal1},{RYG forr signal2}..}
int signal[4][3]={{2,3,4},{5,6,7},{8,9,10},{11,12,13}};

//indexes for the signal array
int red=0;
int yellow=1;
int green=2;

//pin number of "colour" of signal "i" is given by signal[i][colour]
//example: red led of signal 3: signal[2][0]



void setup()
{
  for(int i=2;i<=13;i++){
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
  randomSeed(analogRead(0));
}
  
void loop()
{
    int next_sn= sn+1; //next signal
    if(next_sn==5)
      next_sn=1;
  
    int next2_sn= next_sn+1; //next2next
    if(next2_sn==5)
      next2_sn=1;
  
    int next3_sn= next2_sn+1; //next2next2next
     if(next3_sn==5)
      next3_sn=1;
   
  
   //current signal green (for gst seconds), rest all red.
  
    digitalWrite(signal[sn-1][green],HIGH);
    digitalWrite(signal[sn-1][red],LOW); //this line will make sense 
                                      //for the 2nd iteration
  
    digitalWrite(signal[next_sn-1][red],HIGH);
    digitalWrite(signal[next2_sn-1][red],HIGH);
    digitalWrite(signal[next3_sn-1][red],HIGH);
    

   

  
    delay(gst*1000);
  
    //gst seconds elapsed, now current signal should become yellow
    gst=5; //to enable countdown of 5 secs
  
    digitalWrite(signal[sn-1][green],LOW);
    digitalWrite(signal[sn-1][yellow],HIGH);
  
    delay(5*1000);
    
    
    //snapshot taken for calculating no. of cars, buses etc
  
  
     //calculate gst
  
     gst=random(10,20);
     Serial.println(gst);
  
  //make current signal red
   
    digitalWrite(signal[sn-1][red],HIGH);
    digitalWrite(signal[sn-1][yellow],LOW);
  
  
  //the next signal is our current signal for the next iteration
  //the green signal should turns on for gst seconds in the next
  //iteration,and the red signal turns off
    sn=next_sn;
     
  }


