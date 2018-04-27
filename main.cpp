#include "LinearChaning.h"
#include <cstring>
using namespace std;
int main() {
    linearChaining<int> myHash(1000000);
    myHash.readList("C:\\Users\\Omkar Desai\\Documents\\C++\\LinearChaining\\dict.txt");
    //cout<<myHash.find("bajirao")<<std::endl;
    myHash.checkList("C:\\Users\\Omkar Desai\\Documents\\C++\\LinearChaining\\check.txt");
    myHash.histogram();
    return 0;
}
