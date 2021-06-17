#include <chrono>
#include <thread>

namespace sc = std::chrono;

class Timer{
    sc::steady_clock::time_point m_StartPoint;
    sc::steady_clock::time_point m_EndPoint;

    public:
        void Start(){
            m_StartPoint = sc::steady_clock::now();
        }

        void LimitFramerate(int fps){
            sc::milliseconds limit(1000/fps);
            m_EndPoint = sc::steady_clock::now();
            sc::milliseconds timeSpan = sc::duration_cast<sc::milliseconds>(m_EndPoint - m_StartPoint);
            if(timeSpan < limit)
                std::this_thread::sleep_for(limit - timeSpan);
        }

};