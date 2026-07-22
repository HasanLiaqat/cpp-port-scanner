#ifndef PORTSCANNER_H
#define PORTSCANNER_H

#include <string>

using namespace std;

class PortScanner
{
public:
    bool initialize();
    bool createSocket();
    bool scanPort(const string& ip, int port);
    void scanRange(const string& ip, int startPort, int endPort);
    void cleanup();

    string getServiceName(int port);
    void threadedScan(const string& ip, int port);
    string resolveHostname(string hostname);
};

#endif
