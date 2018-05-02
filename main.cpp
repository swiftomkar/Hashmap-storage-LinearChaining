#include "LinearChaning.h"
using namespace std;
int main() {
    linearChaining myHash((1024*1024)*2);
    myHash.readList("C:\\Users\\Omkar Desai\\Documents\\C++\\LinearChaining\\dict.txt");
    myHash.checkList("C:\\Users\\Omkar Desai\\Documents\\C++\\LinearChaining\\hw8.txt");
    myHash.histogram();
    return 0;
}
