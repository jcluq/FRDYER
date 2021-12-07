# FRDYER

![Cover](./photos/DSC08678.JPG)



The FRDYER is a musical instrument inspired on the characteristical touchless insteraction of the well-known theremin. Similar to the Theremin, the FRDYER relies on the electromagnetic field to operate. An electromagnetic microphone converts the electromagnetic fields into an oscillating signal, thus creating a sound output with a very particular character. This signal is then connected to a microcontroller which modifies the sound by passing it through a  Low Pass filter and then a Feedback Delay. This generates a looping atmospherical sound which can be modified by moving the microphone or adding different electromagnetic sources. 

The name FRDYER is a tribute to Michael Faraday, for his contributions towards the study of electromagnetic fields.

 ## Technical aspects

As stated before, the FRDYER is built upon a microphone and a signal processor. 

- ### Microphone

The microphone is based on the open source project "Electrolush" designed by Jonas Gruska. Two inductors convert the electromagnetic field into electricity which is then passed to an operational amplifier to create an oscillating signal and amplify it. An audio jack is connected to this ciruitry in order to output the signal. The microphone is powered by a 9V battery.  

- ### Processor 

A Teensy 4.0 + Audio shield Rev D constitute the sound processor. 2 potentiontimeters are used; one for changing the time of the feedback delay and one for changing the cutoff frequency of the low pass filter. 3 buttons are used, one for overdriving the feedback delay, allowing asynchronous overlapping, and one for mutting. Two 3.5mm female jacks are used for input and output. 

## Schematics
<details>
<summary>Microphone</summary>

![Microphone](./Schematics/MicSchem.jpg)
</details>
<details>
<summary>Processor</summary>

![Processor](./Schematics/ProSchem.jpg)
</details>

## Code

The full Teensy code for the arduino IDE is located [here](./code/frdyer.ino).

The code uses the [Audio System Design Tool](https://www.pjrc.com/teensy/gui). 

This routing used for the FRDYER:

![routing](./code/FRDYERAudioSystemDesign.PNG)

## Photos

![](./photos/DSC08654.JPG)
![](./photos/DSC08656.JPG)
![](./photos/DSC08657.JPG)
![](./photos/DSC08665.JPG)
![](./photos/DSC08686.JPG)
![](./photos/DSC08677.JPG)
![](./photos/DSC08697.JPG)


## Video Demonstration

<iframe width="560" height="315" src="https://www.youtube.com/embed/Cuoqb1JkojY" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

