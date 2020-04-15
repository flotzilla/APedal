#ifndef INTERVAL_TIMER_H
#define INTERVAL_TIMER_H

class IntervalTimer
{
private:
    unsigned int delayVal = 30;

    unsigned long lastUpdateTime;
    unsigned long prevTime;

    void (*onAction)();

public:
    IntervalTimer(int delay, void (*onActionCallback)() );
    ~IntervalTimer();

    void update(unsigned long currentMills);
};

#endif