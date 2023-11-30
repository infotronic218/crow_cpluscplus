#include <sstream>
#include <string>
#include <vector>

#include "crow_all.h"
using namespace std ;

int main()
{
    crow::SimpleApp app;
    crow::mustache::set_base("../src");
   
    CROW_ROUTE(app, "/")([](const crow::request &req, crow::response &resp ){
        ifstream in("../templates/index.html", ifstream::in);
        if(in){
            ostringstream contents ;
            contents << in.rdbuf() ;
            in.close();
            resp.write(contents.str());
        }else{
            resp.write("No found ");
        }
        resp.end();
        
        //return page;
         
         //return "Hello world";
    });

    

    app.port(8080)
        .multithreaded()
        .run();
}
