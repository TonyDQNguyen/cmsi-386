
#include <string>
#include <cassert>

struct sayStruct {
    string totalWords;
    sayStruct operator()(string word){
        if (totalWords == ""){
            totalWords = word;
        } else {
            totalWords = totalWords + " " + word;
        }
    }
    string operator()(){return totalWords;}
} say;

int main(){
    assert(say() == "");
    assert(say("hi")() == "hi");
    assert(say("hi")("I")("am")("Tony")() == "hi I am Tony");
};
