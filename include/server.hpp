#pragma once
#include <vector>
#include <thread>

#include "httplib.h"
#include "databasehandler.hpp"



class Server : public::httplib::Server
{
    public :
    Server() :maxThreads_(static_cast<uint32_t>(std::thread::hardware_concurrency()))
    {
        for (uint32_t i = 0; i < maxThreads_; ++i)
        {
            std::unique_ptr<DatabaseHandler> dbHandler = std::make_unique<DatabaseHandler>();
            
            //dbHandler->DbThread = std::thread(&DatabaseHandler::run, dbHandler.get());
            
            //vecHadler.emplace_back(std::move(dbHandler));
        }
    };
   


    void run();
    uint32_t getReqNum(uint32_t i ) {return vecHadler[i]->handlingEvent();};
    global::DatabaseConntetion::status addEvent();
    uint32_t getMaxThread () {return maxThreads_;};
    private:
        uint32_t maxThreads_;
        uint32_t  requestNumber = 0; 
        std::vector<std::unique_ptr<DatabaseHandler>> vecHadler;

};
