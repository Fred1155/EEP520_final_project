#ifndef __MY_ROBOT2_AGENT__H
#define __MY_ROBOT2_AGENT__H

#include "enviro.h"

using namespace enviro;

//The controller of Robot 2 (Red one)
//Key board control: i,j,k,l,y,u
class RobotTwoController : public Process, public AgentInterface {

    public:
    RobotTwoController() : Process(), AgentInterface() {}

    void start() {}
    void stop() {}
    
    //initial function, checks the keyboard value and modifies f and tau
    //move forward: i
    //move backward: k
    //rotate rightwise: l
    //rotate leftwise: j
    //dash forward: y
    //spin!: u (spins faster than robot 1)
    void init() {
        watch("keydown", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == "i" ) {
                    f = forwardmagnitude;
            } else if ( k == "k" ) {
                    f = -forwardmagnitude;
            } else if ( k == "j" ) {
                    tau = -rotatemagnitude;
            } else if ( k == "l" ) {
                    tau = rotatemagnitude;
            }else if ( k == "y" ){
                f = 2*forwardmagnitude;
            } else if ( k == "u" ){
                tau = 8*rotatemagnitude;
            }
        });
        watch("keyup", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == "i" || k == "k" || k == "y" ) {
                    f = 0;
            } else if ( k == "j" || k== "u") {
                    tau = 0;
            } else if ( k == "l" ) {
                    tau = 0;
            }
        });
    }
    
    //apply the force. If there is goal, reinitialize the position
    void update() {
        apply_force(f,tau);
        
        watch("A goal",[&](Event &e){
           teleport(100,0,135);
        });
       watch("B goal",[&](Event &e){
          teleport(100,0,135);
       });

    }

    private:
    double f, tau;
    // f: the force applied to move forward
    // tau: the torque applied to rotate
    double const forwardmagnitude = 300;
    double const rotatemagnitude = 200;

};

class RobotTwo : public Agent {
    public:
    RobotTwo(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    RobotTwoController c;
};

DECLARE_INTERFACE(RobotTwo)

#endif
