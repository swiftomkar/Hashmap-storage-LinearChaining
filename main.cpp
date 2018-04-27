#include "LinearChaning.h"
#include <cstring>
using namespace std;
int main() {
    linearChaining<int> myHash(10);

    myHash.add("hello");
    myHash.add("hi");
    myHash.add("omkar");
    myHash.add("desai");
    myHash.add("vishwa");
    myHash.add("shah");
    myHash.add("hello");
    myHash.add("seema");
    myHash.add("swaroop");
    myHash.add("bajirao");
    myHash.add("hello1");
    myHash.add("hi1");
    myHash.add("omkar1");
    myHash.add("desai1");
    myHash.add("vishwa1");
    myHash.add("shah1");
    myHash.add("hello2");
    myHash.add("seema2");
    myHash.add("swaroop2");
    myHash.add("bajirao2");
    myHash.add("hello2");
    myHash.add("hi2");
    myHash.add("omkar3");
    myHash.add("desai4");
    myHash.add("vishwa3");
    myHash.add("shah");
    myHash.add("hello3");
    myHash.add("seemadf");
    myHash.add("swaroopef");
    myHash.add("bajirao");
    myHash.add("helloef");
    myHash.add("hief");
    myHash.add("omkarwf");
    myHash.add("desaiwe");
    myHash.add("vishwaew");
    myHash.add("shahwe");
    myHash.add("hell4o");
    myHash.add("seemtya");
    myHash.add("swaroopr");
    myHash.add("bajiraort");
    myHash.add("Omkar");
    myHash.add("desai");
    //myHash.readList("C:\\Users\\Omkar Desai\\Documents\\C++\\LinearChaining\\smallList.txt");

    cout<<myHash.find("bajirao")<<std::endl;
    myHash.histogram();
    return 0;
}
