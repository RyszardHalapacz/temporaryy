#pragma once
#include <pqxx/pqxx>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <chrono>
#include <thread>

#include "event.hpp"

class DatabaseHandler 
{
    public:
    DatabaseHandler()
    {
        DbThread = std::thread(&DatabaseHandler::run,this);
    };
    ~DatabaseHandler() 
    {
        if (DbThread.joinable()) 
        {
            DbThread.join();
        }

}
    DatabaseHandler(std::string&, uint32_t ){};
    void run();
    void terminateThreads(){isActive=false;};
    global::DatabaseConntetion::status addEvent(/*param of event*/);
    uint32_t  handlingEvent()
    { 
        return vecEvent.size();
    };
    private:
    std::vector<Event> vecEvent{};
    std::mutex mut;  
    public:
    std::thread DbThread;
    public:
    bool isActive  {true};

};
