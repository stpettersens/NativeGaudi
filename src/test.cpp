#include <cstdio>
#include <cstring>
#include "json_spirit.h"

using namespace std;
using namespace json_spirit;

//A sample get file request 
char *jsonInput = 
"{\"request\" : { \
                \"service\" : \"fmgr\", \
                \"cookie\"  : \"Abxruyyeziyrolsu\", \
                \"req\"     : \"read\", \
                \"fname\"   : \"Junk.txt\", \
                \"size\"    :  1024, \
                \"data\"    :  \"data\" \
}}";


int main(int argc, char **argv)
{
    Value val;
    const string s = jsonInput;
    read(s, val); //read the jsonInput to the value
    Object obj = val.get_obj();
    std::string service, cookie, req, fname, data;
    uint32_t size;

    const Pair& pair = val.get_obj()[0]; //gets the name:value pair, named "request".
    const Object& obj = pair.value_.get_obj(); //gets the service, cookie... object.

    /*for(Object::size_type i = 0; i != obj.size(); ++i) {   
        //const Pair& pair = obj[i];
        const string& name  = pair.name_;
        const Value&  value = pair.value_;

        if( name == "service" ) service  = value.get_str();
        else if( name == "cookie") cookie  = value.get_str();
        else if( name == "req" ) req = value.get_str();
        else if( name == "fname" ) fname = value.get_str();
        else if( name == "size" ) size = value.get_int();
        else if( name == "data" ) data = value.get_str();
    }
    std::cout<<service << " " << cookie << " " << req << " " << fname << " " << size << " " << data ;*/
    return 0;
}
