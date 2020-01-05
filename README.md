# simulator
simulator project milestone1

# **Flight Simulator**

This program gives list of commands which help the plan fly, we use a simulator called flight gear and 
we send him the commands.
Fisrt, the simulator is the client to our server and we get from him values that shows the status of the plan.
Then, we are the client to him and we sent commands accordingly to fly.txt.

**Getting Started**

follow the instruction below:

1. install [flight gear](https://www.flightgear.org/)

2. in the additional settings you'll need to write these lines:

	--telnet=socket,in,10,127.0.0.1,5402,tcp

	--generic=socket,out,10,127.0.0.1,5400,tcp,generic_small
   
3. download/create a text file of commands and a xml file to put in the protocol folder.

4. put the fly.txt in the folder of the program.

5. run our program with an argument- fly.txt.

6. open the flight gear simulator and press "fly".

7. wait 2 minutes until the flight will begin.

**Built With**

Clion - Ide by JetBrains

**Versioning**

We used [Github](https://github.com/orelapel/simulator) for version control.

**Authors**

Orel Lichtenstein and Noa Rotem.
