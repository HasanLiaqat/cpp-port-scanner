#include <iostream>
#include "PortScanner.h"

using namespace std;

int main()
{
    PortScanner scanner;

    if (!scanner.initialize())
    {
        return 1;
    }

    string target;
    string ip;
    int startPort, endPort;

    cout << "Enter Target (IP or Domain): ";
    cin >> target;

    // Resolve domain name to IP
    ip = scanner.resolveHostname(target);

    // If it's already an IP address, use it directly
    if (ip == "")
    {
        ip = target;
    }

    cout << "Target IP: " << ip << endl;

    cout << "Start Port: ";
    cin >> startPort;

    cout << "End Port: ";
    cin >> endPort;

    scanner.scanRange(ip, startPort, endPort);

    scanner.cleanup();

    return 0;
}
