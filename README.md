# PL4 SVM, C++ implementation

## About

PL4 SVM is a small virtual machine, designed to be easy to implement on any hardware. PL4 SVM takes inspiration from uxn.

## Compiling

1. `git clone https://github.com/MassiveBattlebotsFan/PL4_SVM`
2. `cd PL4_SVM/build`
3. `cmake ..`

## Parser commands

- `reset` - resets PL4_SVM
- `exit` - exits the parser
- `exec` - runs contents of ROM, starting at 0x0000

## Using examples

1. Copy contents of the example program you want to run
2. Run PL4_SVM
3. Paste the contents of the example program into the terminal