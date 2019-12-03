#ifndef JSON_H_INCLUDED
#define JSON_H_INCLUDED

#include <rapidjson/document.h>
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include "date.h"
#include <rapidjson/ostreamwrapper.h>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
using namespace rapidjson;

class Json
{
private:
    //Document doc;
public:
    Json(){}
    ~Json(){}
    void PrintHistory(string type, string veh_id, string brand, int timeth, string location, string mess, Date day, string oil, string fluid, string tyre)
    {
        int _day = day.GetDay();
        int month = day.GetMonth();
        int year = day.GetYear();
        string date_service = to_string(_day) + "/" + to_string(month) + "/" + to_string(year);
        Document doc;
        doc.SetObject();
        Document::AllocatorType& allocator = doc.GetAllocator();
        StringBuffer s;
        PrettyWriter<StringBuffer> writer(s);
        const char* tem1 = type.c_str();
        writer.String("Type");
        writer.String(tem1);
//        doc.AddMember("Vehicle ID: ", veh_id, allocator);
//        doc.AddMember("Brand: ", brand, allocator);
//        doc.AddMember("Timeth: ", timeth, allocator);
//        doc.AddMember("Location: ", location, allocator);
//        doc.AddMember("Date: ", date_service, allocator);
//        doc.AddMember("User mess: ", mess, allocator);
//        doc.AddMember("Oil Service: ", oil, allocator);
//        doc.AddMember("Fluid Service: ",fluid, allocator);
//        doc.AddMember("Tyre Service: ", tyre, allocator);

//        Value arr(kArrayType);
//        Value obj(kObjectType);
//        obj.AddMember("Ferrari", "18/11/2000", allocator);
//        obj.AddMember("Lamborghini", "20/11/2000", allocator);
//        arr.PushBack(obj, allocator);
//        doc.AddMember("Lists", arr, allocator);

//        ofstream ofs("output.json");
//        OStreamWrapper osw(ofs);
//
//        PrettyWriter<OStreamWrapper> writer(osw);
//        doc.Accept(writer);
//
//        StringBuffer str;
//        PrettyWriter<StringBuffer> writer2(str);
//        doc.Accept(writer2);
        cout << s.GetString();
    }

};
#endif // JSON_H_INCLUDED
