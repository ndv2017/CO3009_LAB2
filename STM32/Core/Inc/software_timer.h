#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer0_flag;
extern int timer1_flag;

void setTimer0(int duration);
void setTimer1(int duration);
void runTimer();

#endif /* INC_SOFTWARE_TIMER_H_ */
