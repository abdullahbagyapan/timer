# CLOCK System with Baremetal C

This project walks you through the process building an AVR application to exercise the clock and timer/counter on the ATMega328p microcontroller.

## Prerequisites

We need to install library, compiler, binary to hex converter, and AVR MCU programmer

These applications can be install by following line:

```bash
sudo apt install avr-libc avrdude binutils-avr gcc-avr
```

## The Code

The code below initializes the clock module and prepares them for use. The while loop toggles a led on the microcontroller once per 0.25 seconds.

```c++
int main() {

    // Set PORTB5 (built-in led) as output
    DDRB |= _BV(DDB5);

    // Initialize clock
    CLOCK_Init();

    // Enable global interrupts
    sei();

    while(1) {

        // Toggle led
        PORTB ^= _BV(PORTB5);

        // Sleep 250 millisecond (0.25 second)
        CLOCK_DelayMs(250);

    }


    return 0;
}
```


Notice the line of code listed below. This sets the global interrupt flag in SREG enabling interrupts. Since we are using the AVR's service interrupt routine to increase clock/timer on every milliseconds.

```c++
sei();
```

## Compiling The Code

To compile the source code we need to create a Makefile to automate the process. Makefiles allow us to place all build/clean/flash commands into one easy to use file. Each microcontroller has a unique set of parameters prior to compiling and deploying. These commands are listed a the top of the Makefile and are easily changed.

Now that your Makefile is complete issue the make from the command start the build process.

```console
make all
```

## Flashing The Code

Now that we compiled the code we can deploy to our microcontroller.

```console
make flash
```
