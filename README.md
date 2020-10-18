# PC_LED_Control

August 2020

Youtube Demonstration: https://youtu.be/3-z3Ae0HXrE

Pictures Link: https://drive.google.com/drive/folders/1AdE3pFaebV9-Tqy9gpRE1TY-1e1KYuUM?usp=sharing

The PC Light system is composed of three main controls.
Two toggle on-off switches and a potentiometer.
The first toggle switch is a digital on-off switch which ocntrols wether the led lights inside the pc are on or off.
the second toggle switch is used to switch between modes.
The first mode is a static color (a color with no movement).
The second mode is a dynamic color array displayed at various speeds (many colors cycling in a pattern).
Within both modes the potentionmeter controls a certain aspect of the system.
If the lights are static the potentionmeter controls the color which is displayed.
If the lights are dynamic the potentiometer controls the speed at which the lights cycle. 
The light sthemselves are powered by an external 5V power supply and the arduino is plugged into the computer itself from a back-end USB slot.
This allows the lights to stay on even if the computer is shutdown, which gives full control over the lights to the user at any time.

Challenges:

The biggest challenge was figuring out how to code the dynamic color pattern (moving colours). This is the first project where I used math
to solve a problem. Another smaller porblems included fitting eveyrthing into the PC nicely and also switch placement. Coding in differnet fucntions
for different switches depending on the position of others was also tough.

Lessons:

Mathematics came in hand and really gave me a great example of real life application of mathematical equations. 
Working iwth this much hardwrae and applying it to a pre-existing system was also a great learning oppurtunity.

Possible Imporvements:

getting the color white could have been hard coded in but would have made the dynamic pattern weird. i wish I could think of a creative way to code in the color white into the
dynamic pattern smoothly.
