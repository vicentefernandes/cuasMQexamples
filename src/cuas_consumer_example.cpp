//
// Created by vicente on 10/13/21.
//

#include "KafkaConsumer.h"

std::string ts_(){
    auto value_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch()).count();
    return std::to_string(value_ms);
}

class Mano {
public:
    Mano(std::string s, int i) :  x(i) , y(s){}
    int x;
    std::string y;
};


void cbts_(const std::string data, std::any x) {
    std::cout << "data: " << data << " curr ts: " << ts_() << std::endl;
}

void cb01(const std::string data, std::any x) {
    std::cout << "data:  >>> " << data << std::endl;

    //auto x_ = std::any_cast<std::shared_ptr<Mano>>(x);
    //std::cout << "data: mano >>> " << ++x_->x <<  " " << x_->y << std::endl;
}

void cb02(const std::string data, std::any x) {
    //std::cout << "CB0202020202020200202 :  >>>> " << data << std::endl;

    //auto x_ = std::any_cast<std::vector<Mano>>(x);
    //std::cout << "data: x >>>> " << x_[0].x <<  " " << x_[1].y << std::endl;
}




int main(){
    KafkaConsumer kc("localhost:9092", 1);
    Mano mano2("fdx", 777);

    //if you want to use your current variables data inside the callback you must store it as shared_ptr
    //and pass the shared_prt as subscribe() arg
    //otherwise, the data will be passed as copy

    auto mano = std::make_shared<Mano>("carallo", 333);
    kc.subscribe("wifi01.detections", cbts_, mano);

    std::vector<Mano> mvec = {mano2, mano2};
    kc.subscribe("wifi01.status", cbts_, mvec);
    kc.subscribe("rf.status", cbts_, mvec);

    kc.process();


    while(true) {
        sleep(4);
        ///std::cout << "main mano: " << mano->x << " " << mano->y << std::endl;
    }
}