# DGUS Screen Library

This library facilitates communication between an Arduino/ESP microcontroller and a DGUS screen. It ensures proper handling of text display and serial communication.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
  - [Setup](#setup)
  - [Example Code](#example-code)
- [Notes](#notes)
- [Contributing](#contributing)

## Features

- Display text on a DGUS screen.
- Handle serial communication.
- Prevent CPU issues on the DGUS screen by avoiding certain commands.

## Installation

1. Download the library files and add them to your Arduino/ESP project.
2. Connect the main RX and TX of the microcontroller to the TX and RX of the DGUS screen respectively.
3. Ensure the serial baud rate matches the baud rate of the DGUS project.

## Usage

### Setup

1. **Connect the Hardware:**
   - Connect the RX of the microcontroller to the TX of the DGUS screen.
   - Connect the TX of the microcontroller to the RX of the DGUS screen.

2. **Set Baud Rate:**
   - Ensure that the serial baud rate in your code matches the baud rate configured in your DGUS project.

### Example Code

Create an example usage file `example.ino`:

```cpp
#define SERIAL_BAUDRATE 9600
#include "batu_dwin.h"

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  delay(1000);
}

void loop() {
// get page 1
  GO_PAGE(1);

// write in vp 1000
  SET_TEXT(0x10, "example");
  delay(3000);

// erase letters in vp 1000
  ERASE_TEXT(0x10, 7) // example length
  delay(3000);

// get page 0
  GO_PAGE(0);
}
```

## Notes

1. **Connection:**
   - Connect the main RX of the microcontroller to the TX of the screen.
   - Connect the main TX of the microcontroller to the RX of the screen.

2. **Baud Rate:**
   - The serial baud rate must match the baud rate of the DGUS project.

3. **Text Length:**
   - Keep track of the text length each time you write to a VP address to be able to erase it properly later.

4. **Serial Communication:**
   - Avoid using `Serial.println` as it sends extra data to the screen and may harm the screen's CPU.

## Contributing

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes.
4. Commit your changes (`git commit -m 'Add some feature'`).
5. Push to the branch (`git push origin feature-branch`).
6. Open a pull request.

## Contact

For any inquiries or issues, please contact [me](https://github.com/mego354).
