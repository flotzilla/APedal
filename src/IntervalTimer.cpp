#include "IntervalTimer.h"

using namespace std;

IntervalTimer::IntervalTimer(int delay, void (*onActionCallback)() )
{
    delayVal = delay;
    onAction = onActionCallback;
}

IntervalTimer::~IntervalTimer()
{
    // do nothing
}

void IntervalTimer::update(unsigned long currentMills)
{
    if ( (currentMills - lastUpdateTime) > delayVal){
        lastUpdateTime = currentMills;
        onAction();
    }
}
