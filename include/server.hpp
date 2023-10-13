#pragma once
#include <vector>
#include <thread>

#include "httplib.h"
#include "databasehandler.hpp"



class Server : public::httplib::Server
{
    public :
    Server(uint32_t thread = static_cast<uint32_t>(std::thread::hardware_concurrency())) :maxThreads_(thread)
    {
        for (uint32_t i = 0; i < maxThreads_; ++i)
        {
            vecHadler.emplace_back(std::make_unique<DatabaseHandler>());
        }
    };
    ~Server()
    {
        vecHadler.clear();
    }
   


    void run();
    uint32_t getReqNum(uint32_t i ) {
        
        return vecHadler[i]->handlingEvent();
        };
    global::DatabaseConntetion::status addEvent();
    uint32_t getMaxThread () {return maxThreads_;};
    private:
        uint32_t maxThreads_;
        uint32_t  requestNumber = 0; 
        std::vector<std::unique_ptr<DatabaseHandler>> vecHadler;

};
