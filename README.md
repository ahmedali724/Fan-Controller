# Fan Controller System

Welcome to the Fan Controller System project repository. This project is designed to create a temperature-controlled fan using the ATmega32 microcontroller, with a focus on efficiency, precision, and real-time temperature management. Below, you'll find all the essential information you need to get started with this project.

## Introduction

In this project, we've developed a sophisticated temperature-controlled fan system that offers precise control and automation. By utilizing an ATmega32 microcontroller, an LM35 temperature sensor, and other components, we've created a system that automatically adjusts the fan's speed based on the surrounding temperature. 

## Specifications

Here are the key specifications and features of the Fan Controller System:

1. **Objective**: Design a temperature-controlled fan using the ATmega32 microcontroller with a 1MHz clock frequency.

2. **Temperature Sensing**: The LM35 temperature sensor provides continuous analog output, which is then converted to digital values using the ADC.

3. **Display**: The system displays the temperature on an LCD screen for real-time monitoring.

4. **Temperature-Dependent Fan Control**:
   - Below 30°C: Fan is turned off.
   - 30°C - 60°C: Fan operates at 25% of its maximum speed.
   - 60°C - 90°C: Fan operates at 50% of its maximum speed.
   - 90°C - 120°C: Fan operates at 75% of its maximum speed.
   - Above 120°C: Fan operates at 100% of its maximum speed.

5. **Circuit Operation and diagram**: The system works by switching the fan on or off based on the temperature value, which controls a DC motor's rotation.
![Screenshot 2023-10-15 115518](https://github.com/ahmedali724/Fan-Controller/assets/111287464/713bcfc2-bf1c-4287-816d-8471bb4397c3)

6. **PWM Control**: The fan speed is precisely controlled using PWM signals generated from Timer0.

7. **Layered Architecture**: The project is designed with a layered architecture model, comprising:
   - HAL Layer: LCD, LM35, and DC motor drivers.
   - MCAL Layer: GPIO, ADC, and Timer0 PWM drivers.

Happy coding! 🚀
