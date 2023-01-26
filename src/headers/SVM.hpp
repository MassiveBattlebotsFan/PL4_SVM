#ifndef SVM_H
#define SVM_H

#include <iostream>
#include <vector>
#include <array>
#include <string>

class SVM{
private:
    std::array<uint8_t, 256> varspace;
    uint16_t rom_pointer;
    uint16_t ram_pointer;
    uint8_t acc;
public:
    std::array<uint8_t, 0xFFFF> ram;
    std::array<uint8_t, 0xFFFF> rom;
    void reset();
    void exec();
    void runcmd(uint8_t cmd[3], uint8_t arg8, uint16_t arg16);
    uint16_t get_rom_ptr();
    void set_rom_ptr(uint16_t val);
    uint16_t inc_rom_ptr(uint16_t val);
    SVM();
};

#endif