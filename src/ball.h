#ifndef __BALL_AGENT__H
#define __BALL_AGENT__H

#include "enviro.h"

using namespace enviro;

//The controller of the ball
class BallController : public Process, public AgentInterface {

    public:
    BallController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    
    //checks if the position satisfies the goal requirement (enters the gate)
    void update() {
        if(position().x> -540  && position().x< -523 && position().y> -130 && position().y< 130 ){
        teleport(0,0,0);
            emit(Event("A goal"));
    }
         else if(position().x> 523  && position().x< 540 && position().y> -130 && position().y< 130){
             teleport(0,0,0);
             emit(Event("B goal"));
         }
         
    }
    void stop() {}

};

class Ball : public Agent {
    public:
    Ball(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    BallController c;
};

DECLARE_INTERFACE(Ball)

#endif
