#pragma once

#include "crow_all.h"
#include <iostream>

using namespace std ;


void sendFile(crow::response &resp, string filename, string contentType){
     ifstream in("../templates/"+filename, ifstream::in);
        if(in){
            ostringstream contents ;
            contents << in.rdbuf() ;
            in.close();
            resp.set_header("Content-Type", contentType);
            resp.write(contents.str());
        }else{
            resp.code = 404 ;
            resp.write("No found ");
        }
        resp.end();
}


void sendHTML(crow::response &resp, string filename){
    sendFile(resp, filename+".html", "text/html");
}

void sendImage(crow::response &resp, string filename){
    sendFile(resp, "images/"+filename, "image/*");
}

void sendScript(crow::response &resp, string filename){
    sendFile(resp, "scripts/"+filename, "text/javascript");
}

void sendStyle(crow::response &resp, string filename){
    sendFile(resp, "styles/"+filename, "text/csss");
}


void addStaticRouting(crow::SimpleApp &app){
    CROW_ROUTE(app, "/styles/<string>")([](crow::request &req, crow::response &resp, string filename){
         sendStyle(resp, filename);
    });

    CROW_ROUTE(app, "/scripts/<string>")([](crow::request &req, crow::response &resp, string filename){
         sendScript(resp, filename);
    });

    CROW_ROUTE(app, "/images/<string>")([](crow::request &req, crow::response &resp, string filename){
         sendImage(resp, filename);
    });
}