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
    DatabaseHandler(){
       // DbThread(&DatabaseHandler::run, this);


    };
    ~DatabaseHandler() {
    DbThread.join();
}
    DatabaseHandler(std::string&, uint32_t ){};
    void run();
    global::DatabaseConntetion::status addEvent(/*param of event*/);
    uint32_t  handlingEvent(){ return vecEvent.size();};
    private:
    std::vector<Event> vecEvent{};
    std::mutex mut;  
    public:
    std::thread DbThread;

};
