#include <iostream>
#include "local_strings.hpp"
#ifdef __cplusplus
extern "C" {
#endif


//typedef const char* StringArray[];

char* en_gb[] = {"How hard should the equations be?\n","Something doesn't seem to work out...","Type outcome of ","Great! You rock.","Exiting...","\aIt is ","; try harder next time! 'X' to quit ...\n"};
char* en_us[] = {"How hard should the equations be?\n","Something doesn't seem to work out...","Type outcome of ","Great! You rock.","Exiting...","\aIt is ","; try harder next time! 'X' to quit ...\n"};
char* en_au[] = {"How hard should the equations be?\n","Something doesn't seem to work out...","Type outcome of ","Great! You rock.","Exiting...","\aIt is ","; try harder next time! 'X' to quit ...\n"};
char* de_at[] = {"Wie schwer sollten die Aufgaben sein?\n","Irgendetwas scheint nicht zu funktionieren...","Berechne das Ergebnis von ","Super! Du rockst.","Das Programm wird geschlossen...","\aEs ist ","; Streng dich das nächste Mal mehr an! 'X' zum Beenden ...\n"};                                                       
char* de_de[] = {"Wie schwer sollten die Aufgaben sein?\n","Irgendetwas scheint nicht zu funktionieren...","Berechne das Ergebnis von ","Super! Du rockst.","Das Programm wird geschlossen...","\aEs ist ","; Streng dich das nächste Mal mehr an! 'X' zum Beenden ...\n"}; 


char** languages[MAX_LANGUAGES] = {en_gb, en_us, en_au, de_at, de_de};
/*const char* languages[MAX_LANGUAGES][7] {
    {"How hard should the equations be?\n","Something doesn't seem to work out...","Type outcome of ","Great! You rock.","Exiting...","\aIt is ","; try harder next time! 'X' to quit ...\n"},
    {"How hard should the equations be?\n","Something doesn't seem to work out...","Type outcome of ","Great! You rock.","Exiting...","\aIt is ","; try harder next time! 'X' to quit ...\n"},
    {"How hard should the equations be?\n","Something doesn't seem to work out...","Type outcome of ","Great! You rock.","Exiting...","\aIt is ","; try harder next time! 'X' to quit ...\n"},
    {"Wie schwer sollten die Aufgaben sein?\n","Irgendetwas scheint nicht zu funktionieren...","Berechne das Ergebnis von ","Super! Du rockst.","Das Programm wird geschlossen...","\aEs ist ","; Streng dich das nächste Mal mehr an! 'X' zum Beenden ...\n"},                                                      
    {"Wie schwer sollten die Aufgaben sein?\n","Irgendetwas scheint nicht zu funktionieren...","Berechne das Ergebnis von ","Super! Du rockst.","Das Programm wird geschlossen...","\aEs ist ","; Streng dich das nächste Mal mehr an! 'X' zum Beenden ...\n"}
}; */

#ifdef __cplusplus
}
#endif