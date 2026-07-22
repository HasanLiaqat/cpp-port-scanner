#include "PortScanner.h"
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <fstream>

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

bool PortScanner::createSocket()
{
    SOCKET sock;

    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sock == INVALID_SOCKET)
    {
        cout << "Failed to create socket!" << endl;
        return false;
    }

    cout << "Socket created successfully!" << endl;

    closesocket(sock);

    return true;
}

bool PortScanner::scanPort(const string& ip, int port)
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sock == INVALID_SOCKET)
    {
        return false;
    }

    sockaddr_in target;

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = inet_addr(ip.c_str());

    int result = connect(sock, (sockaddr*)&target, sizeof(target));

    closesocket(sock);

    return (result == 0);
}

void PortScanner::scanRange(const string& ip, int startPort, int endPort)
{
    ofstream file("scan_results.txt");

    file << "Target: " << ip << endl;
    file << "==========================" << endl;
    file << "Open Ports\n\n";

    cout << "\nScanning " << ip << "...\n\n";

    for (int port = startPort; port <= endPort; port++)
    {
        if (scanPort(ip, port))
        {
            cout << "[OPEN] Port "
                 << port
                 << " ("
                 << getServiceName(port)
                 << ")"
                 << endl;

            file << "Port "
                 << port
                 << " ("
                 << getServiceName(port)
                 << ")"
                 << endl;
        }
    }

    file.close();

    cout << "\nScan Complete!" << endl;
    cout << "Results saved to scan_results.txt" << endl;
}

void PortScanner::cleanup()
{
    WSACleanup();
}

string PortScanner::getServiceName(int port)
{
    switch(port)
    {
        case 20:
        case 21:
            return "FTP";

        case 22:
            return "SSH";

        case 23:
            return "Telnet";

        case 25:
            return "SMTP";

        case 53:
            return "DNS";

        case 80:
            return "HTTP";

        case 110:
            return "POP3";

        case 143:
            return "IMAP";

        case 443:
            return "HTTPS";

        case 3306:
            return "MySQL";

        case 3389:
            return "RDP";

        default:
            return "Unknown";
    }
}

string PortScanner::resolveHostname(string hostname)
{
    hostent* host = gethostbyname(hostname.c_str());

    if (host == NULL)
    {
        return "";
    }

    in_addr addr;

    addr.s_addr = *(u_long*)host->h_addr;

    return string(inet_ntoa(addr));
}
