//  signal.h
//  Created by Mary Nwosu on 10/22/22.

// given header files
#ifndef SIGNAL_H_
#define SIGNAL_H_

extern int total_alarms;
void increment_alarm();
void sigint_handler(int signum);
#endif