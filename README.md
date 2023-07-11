# RoboSim
A robot simulator developed from scratch for evaluating robot programs prior to deployment, utilizing computer-to-robot serial communication to exchange sensory information and actions.

## Features

- Facilitation of testing complex robot programs that are challenging to evaluate in the real world.
- Collection of sensory input from the virtual environment and transmission to the robot.
- Action commands are sent back to the simulator through the serial interface.
- USB serial communication interface facilitates interaction between the simulator and robot.

## Video
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/_9FdrJeimgE/0.jpg)](https://www.youtube.com/watch?v=_9FdrJeimgE)

## Requirements

- Visual Studio 2022+
- .NET Framework 4.0+
- STM32 Standard Peripheral Libraries
- Keil uVision 5+

## Installation

1. Clone the repository.
2. Upload Robot Code into STM32F103 micro controller using Keil uVision.
3. Open Simulator software in Visual Studio and run it.
4. Connect STM32F103 micro controller with the computer using serial port.

## License

This project is licensed under the [GPL-3.0 license](LICENSE).
