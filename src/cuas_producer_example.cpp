//
// Created by vicente on 10/15/21.
//

#include <string>
#include <iostream>
#include <producer.h>
#include "KafkaProducer.h"


using std::string;
using std::exception;
using std::cout;
using std::endl;


std::string ts_(){
    auto value_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch()).count();
    return std::to_string(value_ms);
}


int main(){
    KafkaProducer kp("localhost:9092");
    ;

    kp.publishNoFlush("wifi01.detections", ts_());
    kp.publishNoFlush("wifi01.status", ts_());
    kp.publishNoFlush("wifi01.detections", ts_());
    kp.publishNoFlush("wifi01.status", ts_());
    kp.flush();


    std::cout << "now ..." << endl;

    kp.publishNoFlush("wifi01.detections", ts_());
    kp.publishNoFlush("wifi01.status", ts_());
    kp.publishNoFlush("wifi01.detections", ts_());
    kp.publishNoFlush("wifi01.status", ts_());
    kp.flush();
}