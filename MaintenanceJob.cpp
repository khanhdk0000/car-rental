#include "MaintenanceJob.h"

using namespace std;

////////////////////////////////

int operator-(const MaintenanceJob &obj1, const MaintenanceJob &obj2)
{
    int ans;
    ans = obj1._mileage - obj2._mileage;
    return ans;
}

bool operator>(const MaintenanceJob &obj1, const MaintenanceJob &obj2)
{
    return obj1._when > obj2._when;
}

bool operator<(const MaintenanceJob &obj1, const MaintenanceJob &obj2)
{
    return obj1._when < obj2._when;
}

void MaintenanceJob::printDetail()
{
    cout << "What: " << _what << endl;
    cout << "Where: " << _what << endl;
    cout << "When: ";
    _when.printDate();
    cout <<"\n";
    cout << "Mileage: " << _mileage << endl;
}

void MaintenanceJob::SetValue(int kind, string mess, int time)
{
    timeth = time;
    _what = mess;
    string choice;
    int oil_type = 0;
    if(kind == 1)
    {
        type = "Engine Service";
        cout << "Do you want to change oil?(Enter yes or no)";
        cin >> choice;
        if(choice == "yes")
        {
            cout << "How much you want to change(1 for minor, 2 for major)";
            cin >> oil_type;
            if(oil_type == 1)
            {
                oil_service_ = "minor";
            }
            else if(oil_type == 2)
            {
                oil_service_ = "major";
            }
        }
    }
    else if(kind == 2)
    {
        type = "Transmission Service";
        cout << "Do you want to change fluid?(Enter yes or no)";
        cin >> choice;
        if(choice == "yes")
        {
            cout << "How much you want to change(1 for minor, 2 for overhaul)";
            cin >> oil_type;
            if(oil_type == 1)
            {
                fluid_service_ = "minor";
            }
            else if(oil_type == 2)
            {
                fluid_service_ = "overhaul";
            }
        }
    }
    else if(kind == 3)
    {
        type = "Tire Service";
        cout << "Do you want to service your tyre?(Enter yes or no)";
        cin >> choice;
        if(choice == "yes")
        {
            cout << "How much you want to change(1 for adjust, 2 for replace)";
            cin >> oil_type;
            if(oil_type == 1)
            {
                tyre_service_ = "adjust";
            }
            else if(oil_type == 2)
            {
                tyre_service_ = "replace";
            }
        }
    }

}

void MaintenanceJob::SetDate(string day)
{
    Date tem(day);
    _when = tem;
}

void MaintenanceJob::PrintHistory(string _ID, string _brand)
{
    Document d;
    int _day = _when.GetDay();
    int month = _when.GetMonth();
    int year = _when.GetYear();
    string date_service = to_string(_day) + "/" + to_string(month) + "/" + to_string(year);
    StringBuffer s;
    PrettyWriter<StringBuffer> writer(s);
    const char* tem1 = type.c_str();
    const char* tem2 = _ID.c_str();
    const char* tem3 = _brand.c_str();
    const char* tem4 = oil_service_.c_str();
    const char* tem5 = fluid_service_.c_str();
    const char* tem6 = tyre_service_.c_str();
    const char* tem7 = _where.c_str();
    const char* tem8 = date_service.c_str();
    writer.StartObject();
    writer.String("ID ");
    writer.String(tem2);
    writer.String("Brand ");
    writer.String(tem3);
    writer.String("Oil Service ");
    writer.String(tem4);
    writer.String("Fluid Service ");
    writer.String(tem5);
    writer.String("Tyre Service ");
    writer.String(tem6);
    writer.String("Location ");
    writer.String(tem8);
    writer.String("Date ");
    writer.String(tem8);
    writer.String("Type ");
    writer.String(tem1);
    writer.String("Timeth: ");
    writer.Uint(timeth);
    writer.EndObject();
    cout << s.GetString();
    ofstream ofs("output.json", std::ios_base::app);
    OStreamWrapper osw(ofs);
    FILE* fp = fopen("fleet.json", "wb"); // non-Windows use "w"

    char writeBuffer[65536];
    char* x = (char*)s.GetString();
    d.Parse(x);
    FileWriteStream os(fp, x, sizeof(x));

    PrettyWriter<FileWriteStream> writerz(os);
    d.Accept(writerz);

    fclose(fp);

}
