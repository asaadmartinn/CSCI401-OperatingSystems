//worked with amira and mary
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//variable dec
int total_alarms = 0;
int alarmTriggered = 0;
time_t start, stop;

void increment_alarm() {
  total_alarms += 1;
}
//interupt signal handler
void sigint_handler(int signum) {     
  stop = time(NULL);
  printf("\nTotal alarms occured in the code: %d\n", total_alarms);
  printf("The program was executed for %lf seconds.\n", (double)(stop-start));
  exit(0);
}
//handles the signal
void myhandler(int signum) {          
  printf("Hello World!\n");
  alarmTriggered = 1;
}
//register handler to handle SIGALRM
int main(int argc, char * argv[]) {
  start = time(NULL);
  signal(SIGALRM, myhandler);        
  signal(SIGINT, sigint_handler);
//Schedule a SIGALRM for 1 second
  while(1) {
    alarm(1);                       
    increment_alarm();

    while(!alarmTriggered)
      ;
                                
    printf("Turing was right!\n");
    alarmTriggered = 0;
  }
  return 0;                         //never reached
}