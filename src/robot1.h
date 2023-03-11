#ifndef __MY_ROBOT1_AGENT__H
#define __MY_ROBOT1_AGENT__H

#include "enviro.h"

using namespace enviro;

//The controller of Robot 1 (blue one)
//Key board control: w,a,s,d,e,r
class RobotOneController : public Process, public AgentInterface {

    public:
    RobotOneController() : Process(), AgentInterface() {}

    void start() {}
    void stop() {}
    
    //initial function, checks the keyboard value and modifies f and tau
    //move forward: w
    //move backward: s
    //rotate rightwise: d
    //rotate leftwise: a
    //dash forward: e (dashes faster than robot 2)
    //spin!: r
    void init() {
        watch("keydown", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == "w" ) {
                f = forwardmagnitude;
            } else if ( k == "s" ) {
                f = -forwardmagnitude;
            } else if ( k == "a" ) {
                tau = -rotatemagnitude;
            } else if ( k == "d" ) {
                tau = rotatemagnitude;
            } else if ( k == "e" ){
                f = 2*forwardmagnitude+150;
            } else if ( k == "r" ){
                tau = 4*rotatemagnitude;
            }
            
            
        });
        watch("keyup", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == "w" || k == "s" || k == "e" ) {
                f = 0;
            } else if ( k == "a" || k == "r") {
                tau = 0;
            } else if ( k == "d" ) {
                tau = 0;
            }
        });
    }
    //apply the force. If there is goal, reinitialize the position
    void update() {
        apply_force(f,tau);
        
         watch("A goal",[&](Event &e){
            teleport(-100,0,0);
         });
        watch("B goal",[&](Event &e){
           teleport(-100,0,0);
        });

             
         
    }
    private:
    double f, tau;
    // f: the force applied to move forward
    // tau: the torque applied to rotate
    double const forwardmagnitude = 300;
    double const rotatemagnitude = 200;

};

class RobotOne : public Agent {
    public:
    RobotOne(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    RobotOneController c;
};

DECLARE_INTERFACE(RobotOne)

#endif
