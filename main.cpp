#include "LinearChaning.h"
using namespace std;
int main() {
    linearChaining<int> myHash(10000000);
    myHash.readList("C:\\Users\\Omkar Desai\\Documents\\C++\\LinearChaining\\dict.txt");
    myHash.checkList("C:\\Users\\Omkar Desai\\Documents\\C++\\LinearChaining\\check.txt");
    myHash.histogram();
    return 0;
}
