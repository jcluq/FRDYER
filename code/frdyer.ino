//FRDYER 
//Musical Instrument by Juan Camilo Luque
//New Musical Instruments 2021 / HFK BREMEN 




#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=96.00000953674316,294.0000057220459
AudioFilterStateVariable filter1;        //xy=256.0000114440918,263.00000762939453
AudioFilterStateVariable filter2;        //xy=257.0000114440918,337.00000858306885
AudioEffectDelay         delay1;         //xy=409.00000762939453,499.00000762939453
AudioMixer4              mixer1;         //xy=454.00000762939453,326.00000381469727
AudioOutputI2S           i2s1;           //xy=676.0000152587891,338.0000057220459
AudioConnection          patchCord1(i2s2, 0, filter1, 0);
AudioConnection          patchCord2(i2s2, 1, filter2, 0);
AudioConnection          patchCord3(filter1, 0, mixer1, 0);
AudioConnection          patchCord4(filter2, 0, mixer1, 1);
AudioConnection          patchCord5(delay1, 0, i2s1, 0);
AudioConnection          patchCord6(delay1, 0, i2s1, 1);
AudioConnection          patchCord7(delay1, 0, mixer1, 3);
AudioConnection          patchCord8(mixer1, delay1);
AudioControlSGTL5000     sgtl5000_1;     //xy=233,541.0000057220459
// GUItool: end automatically generated code



#include <Bounce.h>

Bounce button0 = Bounce(0, 5);

void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  AudioMemory(160);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.55);
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN);
  sgtl5000_1.micGain(36);
  mixer1.gain(0, 0.5);
  mixer1.gain(1, 0.5);
  mixer1.gain(3, 0.7);
  delay1.delay(0, 400);
  filter1.resonance(0.7);
  filter2.resonance(0.7);
  delay(1000);
}

void loop() {
  // 
  
  int knob2 = analogRead(A2);
  float feedback = (float)knob2 / 1050.0;
  mixer1.gain(3, feedback);

  int knob1 = analogRead(A3);
  float freq = knob1 * 10;
  Serial.println(freq);
  filter1.frequency(freq);
  filter2.frequency(freq);

  // uncomment for pin 0 button to double the feedback (allowing unstable)
  
  button0.update();
  if (button0.read() == LOW) {
    mixer1.gain(3, feedback * 2.0);
  }
  
}
