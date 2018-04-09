#include "LinearChaning.h"
using namespace std;
int main() {
    linearChaining<int> myHash;
    myHash.add(10);
    myHash.add(15);
    for(int i=30;i<4000;i+=5){
        myHash.add(i);
    }
    myHash.add(115);
    cout<<myHash.find(115)<<"\n";
    myHash.histogram();
    return 0;
}