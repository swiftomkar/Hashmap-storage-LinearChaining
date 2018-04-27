#include "LinearChaning.h"
using namespace std;
int main() {
    linearChaining myHash(50000000);
    myHash.readList("C:\\Users\\Omkar Desai\\Documents\\C++\\LinearChaining\\dict.txt");
    myHash.checkList("C:\\Users\\Omkar Desai\\Documents\\C++\\LinearChaining\\check.txt");
    myHash.histogram();
    return 0;
}
