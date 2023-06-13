#include <iostream>
using namespace std;
ostream& operator << (ostream& os,const string* str) {
    os << "Entering the Hello program saying..." << endl;
    os << str;
    os << "Then exiting..." << endl;
    return os;
}
int main() {
    cout << "Hello, world.\n";
    return 0;
}
