#include <vector>
#include <memory>
#include "httplib.h"
#include "databasehandler.hpp"


class HttpServer : public httplib::Server 
{
    public:
    HttpServer(std::vector<std::unique_ptr<DatabaseHandler>> * ptr = nullptr){};
    void run()


{
    Get("/hello", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hello, World!", "text/plain");
    });

    Get(R"(/greet/(\w+))", [](const httplib::Request& req, httplib::Response& res) {
        std::smatch matches;
        std::regex_match(req.path, matches, std::regex(R"(/greet/(\w+))"));
        if (matches.size() == 2) {
            std::string name = matches[1];
            res.set_content("Hello, " + name + "!", "text/plain");
        } else {
            res.set_content("Invalid request", "text/plain");
        }
    });

    Post("/post", [](const httplib::Request& req, httplib::Response& res) {
        if (req.has_param("data")) {
            std::string data = req.get_param_value("data");
            res.set_content("Received data: " + data, "text/plain");
        } else {
            res.set_content("No data received", "text/plain");
        }
    });

    std::cout << "Starting server on port 8080..." << std::endl;
    listen("localhost", 8080);
}



};