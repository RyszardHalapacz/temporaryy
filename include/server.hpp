#pragma once
#include <vector>
#include <thread>

#include "httpserver.hpp"




class Server
{
    public :
    Server(uint32_t thread = static_cast<uint32_t>(std::thread::hardware_concurrency()),
           std::vector<std::unique_ptr<DatabaseHandler>> * httpServ = nullptr );    
    ~Server();
    

    void run();
    uint32_t getReqNum(uint32_t i ) { return vecHadler[i]->handlingEvent(); };
    global::DatabaseConntetion::status addEvent();
    uint32_t getMaxThread () {return maxThreads_;};

    private:
        uint32_t maxThreads_;
        uint32_t  requestNumber = 0; 
        std::vector<std::unique_ptr<DatabaseHandler>> vecHadler;
        std::unique_ptr<HttpServer> httpServ_;

};
