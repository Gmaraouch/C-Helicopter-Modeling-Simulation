#Simulation for MECH 415 - Advanced Programming in C++
 
 Credits:  
 Ghassan Maraouch  
 Gian-Carlo Mignacca  
 
This program is a simulation for the equations of motion for a helicopter. See: https://nowere.net/b/arch/87793/src/1358823196340.pdf for equations of motion  
Equations of motion are calculated by using Euler time stepping.  
The program incorporates 2 players (helicopters). The first one is controlled using awsd and the second one is controlled using the arrow keys.  
A summary of all the keys for the program are as follow:  

-1	Change the view to first person view  
-2	Change the view to second person view  
-3	Change the view to third person view  
-P	Change the view from helicopter 1 to helicopter 2  
-Q	Increases the force of the main rotor for helicopter 2  
-W	Decreases the force of the main rotor for helicopter 2  
-A	Decreases the force of the tail rotor for helicopter 2  
-S	Increase the force of the tail rotor for helicopter 2  
-Up	Increases the force of the main rotor for helicopter 1  
-Down 	Decreases the force of the main rotor for helicopter 1  
-Left	Decreases the force of the tail motor for helicopter 1  
-Right	Increases the force of the tail motor for helicopter 1  
-M	Zooms out to the helicopter diagonally when in 3rd person view  
-N	Zooms in to the helicopter diagonally when in 3rd person view  
-L	Moves the camera in the upward in the z direction when in 3rd person view  
-K	Moves the camera down in the z redirection in 3rd person view  
-J	Move the camera away from the helicopter in the y direction in 3rd person view  
-H	Moves the camera towards the helicopter in the y direction in 3rd person view  
-G	Moves the camera away in the x direction in 3rd person view  
-F	Moves the camera towards the helicopter in the x direction in 3rd person view  
-O	Changes the force input of the arrow keys controls both helicopter 1 and 2. Helicopter 2 will only follow 1 if it had the same yaw and velocities prior to pressing the key  
-R	Pick up an object for helicopter 1 when it is within a certain distance.From it  
-T	Pick up an object for helicopter 2 when it is within a certain distance from it  
