#include "databasehandler.hpp"

void DatabaseHandler::run()
{
    while(true)
    {
        if(vecEvent.empty()) 
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        else
        {
            std::lock_guard<std::mutex> blockMutex(mut);
            handlingEvent();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            vecEvent.pop_back();
        }
    }
}
global::DatabaseConntetion::status DatabaseHandler::addEvent(/*param of event*/)
{
    
    using namespace global::DatabaseConntetion;
    std::lock_guard<std::mutex> blockMutex(mut);
    auto oldSizeVec = vecEvent.size();
    vecEvent.emplace_back(/*param of event*/);
    return  oldSizeVec!= vecEvent.size() ? status::succes : status::error;
}