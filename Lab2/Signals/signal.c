
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//worked on in office hours
int alarmTriggered = 0;

void myhandler(int signum) {          
  printf("Hello World!\n");
  alarmTriggered = 1;
}

int main(int argc, char * argv[]) {
  signal(SIGALRM, myhandler);        
  while(1) {
    alarm(1);                       
    while(!alarmTriggered)
      ;
                                
    printf("Turing was right!\n");
    alarmTriggered = 0;
  }
  return 0;                         