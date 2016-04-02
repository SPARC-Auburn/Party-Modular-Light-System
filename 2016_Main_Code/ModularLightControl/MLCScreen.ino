/* **************************************************
  *  MLCScreen.ino
  *   Part of the ModularLightControl sketch.
  *
  *  Author:  Ben Straub
  *  Revision: 1.0
  *  Date: 06/06/13
  *
  *  Description:  This handles all  the screen stuff,
  *     like displaying the appropriate things for the
  *     given menuState.
  *
   ***************************************************/
   
const String LINE_0_0 = "  Settings";
const String LINE_0_1 = "  Mode";
const String LINE_0_2 = "  About";

const String LINE_1_0 = " Channel 1 mode:";
const String LINE_1_1 = " Channel 2 mode:";
const String LINE_1_2 = " Brightness:";
const String LINE_1_3 = " Blink On-time:";
const String LINE_1_4 = " Blink Off-time:";

const String LINE_2_0 = "  Blink";
const String LINE_2_1 = "  Only 1 On";
const String LINE_2_2 = "  Only 2 On";
const String LINE_2_3 = "  Alternate";

const String LINE_3_0 = "Modular Light";
const String LINE_3_1 = "Controller";
const String LINE_3_2 = "SW Version 1.0";
const String LINE_3_3 = "by Ben Straub";
const String LINE_3_4 = "-JUN 6, 2013-";
const String LINE_3_5 = "";

const String CURSOR = ">";

const String MODE_STRING[] = {"OFF      ", "ON       ",
                              "BLINK    ", "ALTERNATE"};


void initScreen()
{
  mySerial.begin(9600);
  delay(100);
  mySerial.write(12);                 // Clear             
  mySerial.write(17);                 // Turn backlight on
  delay(5);                           // Required delay
  printScreen();
}

void printScreen()
{
  mySerial.write(12);                 // Clear   
  mySerial.write(128);                 // Move to 0,0 -> Home
  switch (menuContext) {
    case 0:
      switch (menuNum) {
        case 0:
          print0_0(); break;
        case 1:
          print0_1(); break;
        case 2:
          print0_2(); break;
      } 
      printCursor();
      break;
    case 1:
      switch (menuNum) {
        case 0:
          print1_0(); break;
        case 1:
          print1_1(); break;
        case 2:
          print1_2(); break;
        case 3:
          print1_3(); break;
        case 4:
          print1_4(); break;
      } break;
    case 2:
      switch (menuNum) {
        case 0:
          print2_0(); break;
        case 1:
          print2_1(); break;
        case 2:
          print2_2(); break;
        case 3:
          print2_2(); break;
      } 
      printCursor();
      break;
    case 3:
      switch (menuNum) {
        case 0:
          print3_0(); break;
        case 1:
          print3_1(); break;
        case 2:
          print3_2(); break;
        case 3:
          print3_3(); break;
        case 4:
          print3_4(); break;
        case 5:
          print3_5(); break;
      } break;
  }
}

//begin ugly boring print functions:
void print0_0()
{ mySerial.print(LINE_0_0); mySerial.write(148); mySerial.print(LINE_0_1); }
void print0_1()
{ mySerial.print(LINE_0_1); mySerial.write(148); mySerial.print(LINE_0_2); }
void print0_2()
{ mySerial.print(LINE_0_2); mySerial.write(148); mySerial.print(LINE_0_0); }
void print1_0()
{ mySerial.print(LINE_1_0);  update1_0();} 
void print1_1()
{ mySerial.print(LINE_1_1); update1_1(); } 
void print1_2()
{ mySerial.print(LINE_1_2); update1_2(); mySerial.print(" / 254");}  
void print1_3()
{ mySerial.print(LINE_1_3);  update1_3();} 
void print1_4()
{ mySerial.print(LINE_1_4);  update1_4();}
void print2_0()
{ mySerial.print(LINE_2_0);}
void print2_1()
{ mySerial.print(LINE_2_1);}
void print2_2()
{ mySerial.print(LINE_2_2);}
void print2_3()
{ mySerial.print(LINE_2_3);}
void print3_0()
{ mySerial.print(LINE_3_0); mySerial.write(148); mySerial.print(LINE_3_1); }  
void print3_1()
{ mySerial.print(LINE_3_1); mySerial.write(148); mySerial.print(LINE_3_2); }
void print3_2()
{ mySerial.print(LINE_3_2); mySerial.write(148); mySerial.print(LINE_3_3); }
void print3_3()
{ mySerial.print(LINE_3_3); mySerial.write(148); mySerial.print(LINE_3_4); }
void print3_4()
{ mySerial.print(LINE_3_4); mySerial.write(148); mySerial.print(LINE_3_5); }
void print3_5()
{ mySerial.print(LINE_3_5); mySerial.write(148); mySerial.print(LINE_3_0); }
void printCursor()
{ if (menuCursor == 0) {mySerial.write(128);}
  else {mySerial.write(148);}
  mySerial.print(CURSOR); }
//end ugly boring print functions
        
        
        
void updateScreen()
{
  switch (menuContext) {
    case 1:
      switch (menuNum) {
        case 0:
          update1_0(); break;
        case 1:
          update1_1(); break;
        case 2:
          update1_2(); break;
        case 3:
          update1_3(); break;
        case 4:
          update1_4(); break;
      } break;
    case 2:
       break;
  }
}

void update1_0()
{ mySerial.write(152);
  mySerial.print(MODE_STRING[ch1Mode]);
}
void update1_1()
{ mySerial.write(152);
  mySerial.print(MODE_STRING[0]);
}
void update1_2()
{ mySerial.write(152);
  if (brightness >= 100) {  } //nothing
  else if (brightness >= 10) { mySerial.print("0"); }
  else { mySerial.print("00"); }
  mySerial.print(brightness, DEC);
}
void update1_3()
{ mySerial.write(152);
  mySerial.print((onTime/10), DEC);
  mySerial.print(".");
  mySerial.print((onTime%10), DEC);
  mySerial.print(" s");
}
void update1_4()
{ mySerial.write(152);
  mySerial.print((offTime/10), DEC);
  mySerial.print(".");
  mySerial.print((offTime%10), DEC);
  mySerial.print(" s");
}
void update2_0()
{ mySerial.write(152);
  mySerial.print((v12 / 100), DEC);
  mySerial.print(".");
  mySerial.print((v12 % 100)/10, DEC);
  mySerial.print((v12 % 10), DEC);
  mySerial.print(" V");
}
void update2_1()
{ mySerial.write(152);
  mySerial.print((v5 / 100), DEC);
  mySerial.print(".");
  mySerial.print((v5 % 100)/10, DEC);
  mySerial.print((v5 % 10), DEC);
  mySerial.print(" V");
}
void update2_2()
{ mySerial.write(152);
  mySerial.print((iCh1 / 100), DEC);
  mySerial.print(".");
  mySerial.print((iCh1 % 100)/10, DEC);
  mySerial.print((iCh1 % 10), DEC);
  mySerial.print(" A");
}
void update2_3()
{ mySerial.write(152);
  mySerial.print((iCh2 / 100), DEC);
  mySerial.print(".");
  mySerial.print((iCh2 % 100)/10, DEC);
  mySerial.print((iCh2 % 10), DEC);
  mySerial.print(" A");
}

void drawSelection()
{
  mySerial.write(148);
  mySerial.print(CURSOR);
  mySerial.print(CURSOR);
}

void drawDeselection()
{
  mySerial.write(148);
  mySerial.print("  ");
  updateScreen();
}

