#include "ctre/Phoenix.h"

#include <unistd.h>
#include <iostream>
#include <chrono>
#include "Platform-linux-socket-can.h"

using namespace ctre::phoenix;
using namespace ctre::phoenix::platform;
using namespace ctre::phoenix::motorcontrol;
using namespace ctre::phoenix::motorcontrol::can;

int main() {

    TalonSRX * talon = new TalonSRX(1);
    
    while(1) {           
        
        ctre::phoenix::platform::FeedWatchDog(100);
 
        talon->Set(ControlMode::PercentOutput, 0.3);
        
        usleep(20000);
    }

    return 0;
}



