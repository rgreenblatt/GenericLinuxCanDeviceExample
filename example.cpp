#include "ctre/Phoenix.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include "Platform-linux-socket-can.h"

using namespace ctre::phoenix;
using namespace ctre::phoenix::platform;
using namespace ctre::phoenix::motorcontrol;
using namespace ctre::phoenix::motorcontrol::can;

int main() {

    std::cout << "Please input the name of your can interface: ";
    
    std::string interface;

    std::cin >> interface;

    ctre::phoenix::platform::can::SetCANInterface(interface.c_str());

    TalonSRX * talon = new TalonSRX(1);
    
    while(1) {           
        
        ctre::phoenix::platform::FeedWatchDog(100);
 
        talon->Set(ControlMode::PercentOutput, 0.3);
        
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    return 0;
}



