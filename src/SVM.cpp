#include "headers/SVM.hpp"

SVM::SVM(){
    this->varspace.fill(0);
    this->ram.fill(0);
    this->rom.fill(0);
    this->rom_pointer = 0;
    this->ram_pointer = 0;
}

void SVM::reset_pc(){
    this->rom_pointer = 0;
}