#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial BTSerial(10,11);
byte cmd[128];
int cmd_len = 0;
int led = 13;
int MotorB1 = 3;
int MotorA1 = 5;
int MotorB2 = 6;
int MotorA2 = 8;

/* ▼▼▼▼▼ Finish your own functions below ▼▼▼▼▼ */

void btn_up(){
}

void btn_down(){
}

void btn_left(){
}

void btn_right(){
}

void btn_1(){
}

void btn_2(){
}

void btn_3(){
}

void btn_4(){
}

void btn_5(){
}

void btn_6(){
}

void btn_7(){
}

void btn_8(){
}

void btn_9(){
}

void btn_none(){
}


/* ▲▲▲▲▲ Finish your own functions above ▲▲▲▲▲ */

void setup(){
    Serial.begin(9600);
    BTSerial.begin(38400);
    pinMode(led, OUTPUT);
    pinMode(MotorB1, OUTPUT);
    pinMode(MotorA1, OUTPUT);
    pinMode(MotorB2, OUTPUT);
    pinMode(MotorA2, OUTPUT);
}

void loop(){
    char str[128];
    int cmd_tmp_size, tick = 0;
    while (tick < 128){
      cmd_tmp_size = BTSerial.available();
      for (int i=0; i<cmd_tmp_size; i++){cmd[(cmd_len++)%128] = char(BTSerial.read());}
      tick++;
    }
    if (cmd_len){
        sprintf(str,"%s",cmd);
        cmd[0] = '\0';
        if(str[0]=='0'){btn_none();}
        else if(str[0]=='u'){btn_up();}
        else if(str[0]=='d'){btn_down();}
        else if(str[0]=='l'){btn_left();}
        else if(str[0]=='r'){btn_right();}
        else if(str[0]=='1'){btn_1();}
        else if(str[0]=='2'){btn_2();}
        else if(str[0]=='3'){btn_3();}
        else if(str[0]=='4'){btn_4();}
        else if(str[0]=='5'){btn_5();}
        else if(str[0]=='6'){btn_6();}
        else if(str[0]=='7'){btn_7();}
        else if(str[0]=='8'){btn_8();}
        else if(str[0]=='9'){btn_9();}
        else{btn_none();}

        if(str[0]!='0'){digitalWrite(13,HIGH);}
        else{digitalWrite(13,LOW);}
    }
    cmd_len = 0;
}
