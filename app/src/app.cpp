#include <sstream>
#include <string>
#include <vector>

#include "crow_all.h"
#include "helper.h"
using namespace std ;

int main()
{
    crow::SimpleApp app;
    crow::mustache::set_base("../src");

    addStaticRouting(app);
   
    CROW_ROUTE(app, "/")([](const crow::request &req, crow::response &resp ){
       sendHTML(resp, "index");
        
        //return page;
         
         //return "Hello world";
    });

    

    app.port(8080)
        .multithreaded()
        .run();
}
