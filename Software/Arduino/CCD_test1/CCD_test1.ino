int vOut = A1;               //connected to pin 1
int clock = 9;               //connected to pin 5
int shutter = 10;            //connected to pin 9
int roc = 11;                //connected to pin 11

unsigned int upArray[2048/100];
unsigned int downArray[2048/100];

void setup(){
	Serial.begin(9600);
	pinMode(clock, OUTPUT);
	pinMode(shutter, OUTPUT);
	pinMode(roc, OUTPUT);
        Serial.print("STARTING\n");
}

void loop(){
	digitalWrite(roc, LOW);
	delay(1);
	digitalWrite(roc, HIGH);
	for(int i = 0; i < 33; ++i){
		digitalWrite(clock, LOW);
		digitalWrite(clock, HIGH);
	}

	for(int i = 0; i < 2048; ++i){
		digitalWrite(clock, LOW);
//		array[i] = analogRead(vOut);
                if(i % 100 == 0){
                  downArray[i/100] = analogRead(vOut);
		 // Serial.print(i/100);
		//  Serial.print(" - ");
           //       if(i < 1000){Serial.print(" ");}
	  //	  Serial.print(array[i]);
            //      Serial.print(analogRead(vOut));
	//	  Serial.print("\n");
		}
                digitalWrite(clock, HIGH);
                if(i % 100 == 0){
                  upArray[i/100] = analogRead(vOut);
		}
	}

	for(int i = 0; i < 7; ++i){
		digitalWrite(clock, LOW);
		digitalWrite(clock, HIGH);
	}
        for(int i = 0; i < 20; ++i){
		digitalWrite(clock, LOW);
		  Serial.print(i);
		  Serial.print(" - ");        
	  	  Serial.print(upArray[i]);
                  Serial.print(" - ");        
	  	  Serial.print(downArray[i]);
		  Serial.print("\n");
                digitalWrite(clock, HIGH);
	}
	Serial.print("-------------------------------\n\n");

	//delay(1000);
          for(int i = 0; i < 500; ++i){
		digitalWrite(clock, LOW);
                delay(1);
		digitalWrite(clock, HIGH);
                delay(1);
	}
        //digitalWrite(shutter, LOW);
        //delay(1);
        //digitalWrite(shutter, HIGH);
    }
