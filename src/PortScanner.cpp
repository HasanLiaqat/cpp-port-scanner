#include "PortScanner.h"
#include <iostream>
#include <winsock2.h>

using namespace std;

bool PortScanner::initialize()
{
    WSADATA wsaData;

    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

    if (result != 0)
    {
        cout << "Winsock initialization failed!" << endl;
        return false;
    }

    cout << "Winsock initialized successfully!" << endl;

    return true;
}
