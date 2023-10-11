#include "server.hpp"



void Server::run()
{

}

global::DatabaseConntetion::status Server::addEvent()
{
    requestNumber++;
    using namespace global::DatabaseConntetion;
    for(int i=0;i<maxThreads_;i++)
    {
        if(requestNumber%(i+1)==0) 
        {
            return vecHadler[i]->addEvent();
            
        }
    }
}