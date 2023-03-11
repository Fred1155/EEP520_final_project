#EEP520 Final Project: Mini Football Game
##Project Overview
This is the readme file for the EEP520 project. This project implements a 2-player game called Mini Football.Two players control two little robots to push the balls into the corresponding score gate to earn points. Once the ball is pushed into the gate, new balls will appear in the middle of the court and two robots will be reinitialized at their initial position. Aparts from moving and rotating, the robots can also dashing forward and fastly spinning. To make the game more interesting, the controller of two robots are not completely the same. Players can determine by themselves on the winning condition(e.g. reaches 5 goals)
##Key Challenges 
The key challenges of this project is the implementation of the robot controller. It need to be controlled by user using key board and react to the corresponding key. So I put "watch("keydown")" and "watch ("keyup")" in the init() function of the robot. When event "keydown" or "keyup" is emitted, the keyboard value is read and then corrsponding parameter(f and tau) is modified. In the update function, I used apply_force(f,tau) to make the robot move by the modified  parameter.
Another challenge is the mechanism of "goal". After the ball is kicked into the gate, the whole court should be reinitialzed. To settle that, the update() function of the ball checks the position of the ball. If the position satisfies the condition of entering the gate, it teleports to the middle of the court and emit an event "goal". Two robots will also be watching this event and teleports back to the initial position and start one mor round.
##How to Install and Run the Code
###Install:
Click the green code button on the side of the repo.The download the repo completely using the Download Zip Button.
###Run:
Assuming you have docker installed, run this command on terminal to run the correspodning docker:
 
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.4 bash

Please use your local address in place of $PWD where you downloaded the code.
After that type in terminal:

Make

enviro

Then you can open http://localhost on your browser, and you can see the program running.
##Acknowedgement
Firstly, I used Professor Klavins Github repo, specifically "ENVIRO: The multi-agent, multi-user, multi-everything simulator" to implement this project. Readme on https://github.com/klavinslab/enviro.
and
https://github.com/klavinslab/enviro/tree/master/examples
for Prof Klavins coded examples.

Secondly, I would like to thank the TA of the course, Sanskar Naik. He provided me much help during the process of developing the project. I also took his project 
https://github.com/sanskarnaik/My_Projects as reference.
Thank You.
