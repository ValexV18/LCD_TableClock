#define NOTE_C3  131
#define NOTE_CS3 138
#define NOTE_D3  147
#define NOTE_DS3 155
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  496
#define NOTE_C5  526
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define REST      0
#include <RTClib.h>
#include <LiquidCrystal.h>

int tempo = 95;
int buzzer = 5; 
int melody[] = {

  NOTE_AS3,8, NOTE_AS3,8, NOTE_AS3,8, NOTE_AS3,8,
  NOTE_D4,8, NOTE_D4,8, NOTE_D4,8, NOTE_D4,8,
  NOTE_C4,8, NOTE_C4,8, NOTE_C4,8, NOTE_C4,8,
  NOTE_F4,8, NOTE_F4,8, NOTE_F4,8, NOTE_F4,8,
  NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8,
 
  NOTE_C4,8, NOTE_AS3,8, NOTE_A3,8, NOTE_F3,8, NOTE_G3,6,
  NOTE_G3,8, NOTE_D4,8, NOTE_C4,6,
  NOTE_AS3,6, NOTE_A3,6, NOTE_A3,8, NOTE_A3,8, NOTE_C4,6,
  NOTE_AS3,8, NOTE_A3,8, NOTE_G3,6,
  NOTE_G3,6, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_G3,6,
  
  NOTE_G3,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_G3,6,
  NOTE_G3,8, NOTE_D4,8, NOTE_C4,6,
  NOTE_AS3,6, NOTE_A3,6, NOTE_A3,8, NOTE_A3,8, NOTE_C4,6,
  NOTE_AS3,8, NOTE_A3,8, NOTE_G3,6,
  NOTE_G3,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_G3,6,
 
  NOTE_G3,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_G3,6,
  NOTE_G3,8, NOTE_D4,8, NOTE_C4,6,
  NOTE_AS3,6, NOTE_A3,6, NOTE_A3,8, NOTE_A3,8, NOTE_C4,6,
  NOTE_AS3,8, NOTE_A3,8, NOTE_G3,6,
  NOTE_G3,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_G3,6,
  
  NOTE_G3,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, 
  NOTE_AS3,8, NOTE_AS3,8, NOTE_AS3,8, NOTE_AS3,8,
  NOTE_D4,8, NOTE_D4,8, NOTE_D4,8, NOTE_D4,8,
  NOTE_C4,8, NOTE_C4,8, NOTE_C4,8, NOTE_C4,8,
  NOTE_F4,8, NOTE_F4,8, NOTE_F4,8, NOTE_F4,8,
  NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8,

  NOTE_C4,8, NOTE_AS3,8, NOTE_A3,8, NOTE_F3,8, NOTE_G3,6,
  NOTE_G3,8, NOTE_D4,8, NOTE_C4,6,
  NOTE_AS3,6, NOTE_A3,6, NOTE_A3,8, NOTE_A3,8, NOTE_C4,6,
  NOTE_AS3,8, NOTE_A3,8, NOTE_G3,6,
  NOTE_G3,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_G3,6,
  
  NOTE_G3,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_G3,6,
  NOTE_G3,8, NOTE_D4,8, NOTE_C4,6,
  NOTE_AS3,6, NOTE_A3,6, NOTE_A3,8, NOTE_A3,8, NOTE_C4,6,
  NOTE_AS3,8, NOTE_A3,8, NOTE_G3,6,
  NOTE_G3,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_G3,6,

  NOTE_G3,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8, NOTE_A4,8, NOTE_AS4,8,
  NOTE_AS3,8, NOTE_AS3,8, NOTE_AS3,8, NOTE_AS3,8,
  NOTE_D4,8, NOTE_D4,8, NOTE_D4,8, NOTE_D4,8,
  NOTE_C4,8, NOTE_C4,8, NOTE_C4,8, NOTE_C4,8,
  NOTE_F4,8, NOTE_F4,8, NOTE_F4,8, NOTE_F4,8,
  NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8, NOTE_G4,8,
    
};
int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
RTC_DS1307 RTC;
DateTime now;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char *menu_str[] = {"\251c\277a\275o\263\272a \263pe\274e\275\270", "Ta\246\274ep", "\240y\343\270\273\304\275\270\272", "Ce\272y\275\343o\274ep"};
String time_now;
int Select_menu = 4;
char *month_str[] = {"\261\275\263ap\307", "\252e\263pa\273\307", "Map\277a", "A\276pe\273\307", "Ma\307", "\270\306\275\307", "\270\306\273\307", "A\263\264yc\277a", "Ce\275\277\307\262p\307", "O\272\277\307\262p\307", "Ho\307\262p\307", "\340e\272a\262p\307"};
int menu_page = 0;
int bemin;
int behour;
bool be_on = false;
bool ON_OFF = false;


void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  delay(1000);
  pinMode(2, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(A1, OUTPUT);
  
  RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
  }
}

void song() {
  Serial.println(9600);
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)

}

void loop() {
  now = RTC.now();
  digitalWrite(A1, digitalRead(A3));
  if (!digitalRead(2)) { //нижняя
    Select_menu = Select_menu + 1;
  }
  if (!digitalRead(7)) { //верхняя
    Select_menu = Select_menu - 1;
  }
  Select_menu = Select_menu % 5;
  if (!digitalRead(4)) { //самая левая
    menu_page = menu_page + 1;
  }
  if (!digitalRead(A0)) { //самая правая
    menu_page = menu_page - 1;
  }
  menu_page = menu_page % 3;
  if (Select_menu == -1) Select_menu = 4;
  if (menu_page == -1) menu_page = 0;
  lcd.clear();
  if (menu_page == 0)
  {
    display_menu();
  }
  else {
    display_page();
  }
  Serial.print(Select_menu);
  Serial.print(",");
  Serial.println(menu_page);
  delay(200);
  if (now.hour() == behour && now.minute() == bemin && ON_OFF) 
  {
    while(true)
    {
       for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) 
       {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Bc\277a\263a\271,");  
        lcd.setCursor(0, 1);
        lcd.print("\250poc\275\270c\304 \245 \250o\271");
        divider = melody[thisNote + 1];
        if (divider > 0) 
          {noteDuration = (wholenote) / divider;} 
        else if (divider < 0) 
        {noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.5;}
        tone(buzzer, melody[thisNote], noteDuration * 0.9);
        delay(noteDuration);
        noTone(buzzer);
        
          if(!digitalRead(2) || !digitalRead(3) || !digitalRead(4) || !digitalRead(6) || !digitalRead(7) || !digitalRead(A0))
          {
            ON_OFF = false; 
            menu_page = 0;
            return 0;
          }
        }
    
   } 
  }


}

void display_menu()
{
  if (Select_menu >= 0 && Select_menu < 4 && menu_page == 0)
  {
    lcd.print(menu_str[Select_menu]);
  }
  else
  {
    lcd.setCursor(6, 0);
    lcd.print(month_str[now.month() - 1]);
    lcd.setCursor(3, 0);
    lcd.print(now.day());
    lcd.setCursor(5, 1);
    lcd.print(now.hour());
    lcd.print(":");
    if (now.minute() < 10)
    {
      lcd.print("0");
    }
    lcd.print(now.minute());

   
  }
}

int display_page()
{
  if (Select_menu == 3) //sekundomer
  {
    int i = 0;
    unsigned long start = 0;
    bool wait = true;

    while (wait)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ha\266\274\270\277e 4,");
      lcd.setCursor(0, 1);
      lcd.print("\300\277o\262\303 \275a\300a\277\304");
      delay(100);
      if (!digitalRead(4))
      { wait = false;
        start = millis();
      }
    }

    while (1)
    {
      unsigned long delta = millis() - start;

      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("A0 - \244a\263ep\301\270\277\304");
      lcd.setCursor(5, 1);
      if (delta / 3600000 < 10)
      {
        lcd.print("0");
      }
      lcd.print(delta / 3600000 % 24);
      lcd.print(":");
      if (delta / 60000 < 10)
      {
        lcd.print("0");
      }
      lcd.print(delta / 60000 % 60);
      lcd.print(":");
      if (delta / 1000 % 60 < 10)
      {
        lcd.print("0");
      }
      lcd.print(delta / 1000 % 60);
      i = i + 1;
      delay(1000);
      if (!digitalRead(A0))
      {
        
        menu_page = 0;
        return 0;
      }
    }
  }
  if (Select_menu == 1) //timer
  {
    int sec = 0;
    int min = 0;
    int hour = 0;
    int cursor_pos = 0; 
    int select = 0;
    int znak = 0;
    
    unsigned long start = 0;
    bool wait = true;

    while (wait)
    {
      delay(200);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("B\303c\277a\263\270\277e \263pe\274\307");
      lcd.blink();
      if (!digitalRead(3))
      {select = (select-1);
      if (select < 0) select = 0;}
      if (!digitalRead(6))
      {select = (select+1);
      if(select > 5) select = 5;}
      

      lcd.setCursor(0, 1);
      if(hour < 10)
      {lcd.print("0");}
      lcd.print(hour);     
      lcd.print(":");
      if(min < 10)
      {lcd.print("0");}
      lcd.print(min);
      lcd.print(":");
      if(sec < 10)
      {lcd.print("0");}
      lcd.print(sec);
      if (select < 2)
      { 
        cursor_pos = select;
      }
      if (select >= 2 && select < 4)
      {
        cursor_pos = select + 1;
      }
      if (select >= 4)
      {
        cursor_pos = select + 2;
      }
      lcd.setCursor(cursor_pos, 1);
      lcd.cursor();
      if(!digitalRead(7) || !digitalRead (2))
      {
        if(!digitalRead (7)) {znak = 1;}
        if(!digitalRead (2)) {znak = -1;} 
        if(select == 0) {hour = hour + (10*znak);}
        if(select == 1) {hour = hour + (1*znak);}
        if(select == 2) {min = min + (10*znak);}
        if(select == 3) {min = min + (1*znak);}
        if(select == 4) {sec = sec + (10*znak);}
        if(select == 5) {sec = sec + (1*znak);}
        if(sec < 0) {sec = 59; min--; }
        if(min < 0) {min = 59; hour--; }
        if(hour < 0) {hour = 23;}
        if(sec >= 60) {sec = 0; min++; }
        if(min >= 60) {min = 0; hour++; }
        if(hour >= 24) {hour = 0;}
      }
      if (!digitalRead(A0))
      {
        menu_page = 0;
        return 0;
      }
      if (!digitalRead(4))
      {
        start = millis();
        unsigned long finish = start + sec*1000 + min*60000 + hour*3600000;
        

        while(true)
        {
          lcd.clear();
          unsigned long delta_timer = finish - millis();
          if(delta_timer < 100)
          {
            delta_timer = 0;
            tone(5, 1000, 2000);
            bool buttons = true;
            while(buttons)
            {
              if(!digitalRead(2) || !digitalRead(3) || !digitalRead(4) || !digitalRead(6) || !digitalRead(7) || !digitalRead(A0))
              {
                buttons = false;
              }
              else
              {tone(5, 1000, 500);
              delay(100);}
            }
            break;
          }
          lcd.print("O\262pa\277\275\303\271 o\277c\300\265\277");
          lcd.setCursor(4, 1);
          if(delta_timer / 3600000 < 10)
          {lcd.print("0");}    
          lcd.print(delta_timer / 3600000 % 24);
          lcd.print(":");
          if(delta_timer / 60000 < 10)
          {lcd.print("0");} 
          lcd.print(delta_timer / 60000 % 60);
          lcd.print(":");
          if(delta_timer / 1000 < 10)
          {lcd.print("0");} 
          lcd.print(delta_timer / 1000 % 60);
          delay(20);
        
           }
         return 0;           
          }
        }
      }
      if(Select_menu == 2) //Будильник
      {
       int select = 0;
       int cursor_pos = 0;
       int znak = 0;
       while(true)
       {
       delay(200);
       lcd.clear();
       lcd.setCursor(0, 0); 
       lcd.print("B\303c\277a\263\270\277e \263pe\274\307");
       if(!digitalRead (3))
       {select = (select-1);
       if (select < 0) select = 0;}
       if (!digitalRead(6))
       {select = (select+1);} 
       if(select > 5) {select = 5;}      
       
       lcd.setCursor(0, 1);
       if(behour < 10)
       {lcd.print("0");}
       lcd.print(behour);     
       lcd.print(":");
       if(bemin < 10)
       {lcd.print("0");}
       lcd.print(bemin);
       if(ON_OFF) {lcd.print(" BK\247");}
       else {lcd.print(" B\256K\247");}
       if(select < 2) {cursor_pos = select;} 
       if (select >= 2 and select < 4) {cursor_pos = select + 1;}
       if(select > 3) {cursor_pos = select+2;} 
       lcd.setCursor(cursor_pos, 1);
       lcd.cursor();

        if(!digitalRead(7) || !digitalRead (2))
       {
        if(!digitalRead (7)) {znak = 1;}
        if(!digitalRead (2)) {znak = -1;} 
        if(select == 0) {behour = behour + (10*znak);}
        if(select == 1) {behour = behour + (1*znak);}
        if(select == 2) {bemin = bemin + (10*znak);}
        if(select == 3) {bemin = bemin + (1*znak);}
        if(select == 4) {ON_OFF = !ON_OFF;}
        if(bemin < 0) {bemin = 59;}
        if(behour < 0) {behour = 23;}
        if(bemin >= 60) {bemin = 0;}
        if(behour >= 24) {behour = 0;}
       }
               
         if (!digitalRead(A0))
         {
          menu_page = 0;
          return 0;
         }      
       }
     }       
            
      if (!digitalRead(A0))
      {
        menu_page = 0;
        return 0;
      }
      
       if(Select_menu == 0) //Установка времён
      {
        int sec = now.second();
        int min = now.minute();
        int hour = now.hour();
        int cursor_pos = 0; 
        int select = 0;
        int znak = 0;
        while(true)
       {     
        delay(200);
        lcd.setCursor(0, 0);
        lcd.print("\251c\277a\275o\263\270\277e \263pe\274\307");
        if (!digitalRead(3))
        {select = (select-1);
        if (select < 0) select = 0;}
        if (!digitalRead(6))
        {select = (select+1);
        if(select > 5) select = 5;}
      
        lcd.setCursor(0, 1);
        if(hour < 10)
        {lcd.print("0");}
        lcd.print(hour);     
        lcd.print(":");
        if(min < 10)
        {lcd.print("0");}
        lcd.print(min);
        lcd.print(":");
        if(sec < 10)
        {lcd.print("0");}
        lcd.print(sec);
        if (select < 2)
       { 
        cursor_pos = select;
       }
        if (select >= 2 && select < 4)
       {
        cursor_pos = select + 1;
       }
        if (select >= 4)
       {
        cursor_pos = select + 2;
       }
        lcd.setCursor(cursor_pos, 1);
        lcd.cursor();
        
        if(!digitalRead(7) || !digitalRead (2))
       {
        if(!digitalRead (7)) {znak = 1;}
        if(!digitalRead (2)) {znak = -1;} 
        if(select == 0) {hour = hour + (10*znak);}
        if(select == 1) {hour = hour + (1*znak);}
        if(select == 2) {min = min + (10*znak);}
        if(select == 3) {min = min + (1*znak);}
        if(select == 4) {sec = sec + (10*znak);}
        if(select == 5) {sec = sec + (1*znak);}
        if(sec < 0) {sec = 59;}
        if(min < 0) {min = 59;}
        if(hour < 0) {hour = 23;}
        if(sec >= 60) {sec = 0;}
        if(min >= 60) {min = 0;}
        if(hour >= 24) {hour = 0;}
       } 
      
      if (!digitalRead(A0))
      {
        menu_page = 0;
        return 0;
      }
       
     
     if(!digitalRead(4))
     {
      int day = now.day();
      int month = now.month()-1;
      int select = 0;
      int znak = 0;
      while(true)
      {
        int max_day_per_month = 0;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("B\303c\277a\263\270\277e \343a\277y");
        lcd.setCursor(2, 1);
        lcd.print(day);
        lcd.setCursor(6, 1);
        lcd.print(month_str[month]);
        lcd.setCursor(select, 1);
//        
        if(month == 0) {max_day_per_month = 31;}
        if(month == 1) {max_day_per_month = 28;}
        if(month == 2) {max_day_per_month = 31;}
        if(month == 3) {max_day_per_month = 30;}
        if(month == 4) {max_day_per_month = 31;}
        if(month == 5) {max_day_per_month = 30;}
        if(month == 6) {max_day_per_month = 31;}
        if(month == 7) {max_day_per_month = 31;}
        if(month == 8) {max_day_per_month = 30;}
        if(month == 9) {max_day_per_month = 31;}
        if(month == 10) {max_day_per_month = 30;}
        if(month == 11) {max_day_per_month = 31;}
//         delay(200);
        if(!digitalRead (3)) {select = 2;}
        if(!digitalRead (6)) {select = 3;}  
        
        if(!digitalRead(7) || !digitalRead (2))
       {
        if(!digitalRead (7)) {znak = 1;}
        if(!digitalRead (2)) {znak = -1;}
 
        if(select == 2) {day = day + (10*znak);}
        if(select == 3) {day = day + (1*znak);}
        if(day > max_day_per_month) {month++; day = 1;}
        if(day < 1) {month--; day = 27;} 
       }
       delay(100);  
       if(!digitalRead (4))
      {
        RTC.adjust(DateTime(now.year(), month + 1, day, hour, min, sec));
        menu_page = 0;
        return 0;
      }
       delay(200); 
       if (!digitalRead(A0))
       {menu_page = 0; return 0;}
      }
     }
    }
   
    lcd.noBlink();
    
 }
}
