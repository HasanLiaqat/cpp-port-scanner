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

    cout << "Ready to scan ports..." << endl;

    return 0;
}
