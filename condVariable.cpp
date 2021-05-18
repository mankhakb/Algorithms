#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>
#include <mutex>
#include <condition_variable>
using namespace std;

std::mutex m1;
std::condition_variable cv;
static bool isPrinted_ =false;

bool isPrinted()
{

    std::cout << "waiting" <<endl;
    if(isPrinted_ == true)
    {
        return true;
    }
    else
    {
       return false;
    }
}

void printVector(std::string threadname)
{
    std::vector<int>v1{1,2,3};
    for(const auto &itr: v1)
    {
        cout << itr << endl;
    }
    
    cout << threadname  <<std::this_thread::get_id() <<endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    isPrinted_ = true;
    cv.notify_all();
}

void printMessage(std::string threadname)
{
   std::unique_lock<std::mutex> mlock(m1);
   cv.wait(mlock,std::bind(&isPrinted));
   cout << "mesage printed by " << threadname<< endl;
}

int main()
{
   std::thread t1(printVector,"thread1");
   std::thread t2(printMessage,"thread2");
   
   t2.join();
   t1.join();
  
    return 0;
}
