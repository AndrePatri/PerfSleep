#include <thread>
#include <chrono>

#include <iostream>
#include <ctime>
#include <cstring>
#include <cerrno>

class PerfSleep
{

    public:

        PerfSleep();

        timespec _req, _rem;

        static void thread_sleep(int nsecs); 

        void clock_sleep(int nsecs);

};

