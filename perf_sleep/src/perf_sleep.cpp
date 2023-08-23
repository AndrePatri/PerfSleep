#include <perf_sleep/perf_sleep.h>

PerfSleep::PerfSleep()
{
    _req.tv_sec = 0; 
}

void PerfSleep::thread_sleep(int nsecs)
{   
    std::this_thread::sleep_for(std::chrono::nanoseconds(nsecs));
}

void PerfSleep::clock_sleep(int nsecs)
{         
    _req.tv_nsec = nsecs;

    clock_nanosleep(CLOCK_REALTIME, 0, &_req, &_rem);
}