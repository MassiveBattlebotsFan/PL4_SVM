#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <string>
#include "PL4_SVM_Config.hpp"
#include "headers/SVM.hpp"

int main(){
    std::cout << "Version: " << PL4_SVM_VERSION_MAJOR << '.' << PL4_SVM_VERSION_MINOR << '.' << PL4_SVM_VERSION_PATCH << '-' << PL4_SVM_VERSION_TWEAK << '\n';
    #ifdef DEBUG
    std::cout << "Debug build\n";
    #endif
    
    SVM svm;
    std::string buffer;
    //char *ptr;
    uint16_t tmp = 0;
    while(strcmp(buffer.c_str(), "exit") != 0){
        for(int i = 0; i < 256; i++) buffer[i] = 0;
        std::cout << std::hex << std::setfill('0') << std::setw(4) << svm.get_rom_ptr() << "> ";
        getline(std::cin, buffer);
        if(strcmp(buffer.c_str(), "exec") == 0){
            svm.exec();
            std::cout << '\n';
            continue;
        }
        if(strcmp(buffer.c_str(), "reset") == 0){
            svm.reset();
            continue;
        }
        if(buffer.length() < 2){
            std::cerr << "cmd below minlen\n";
            continue;
        }
        svm.rom[svm.inc_rom_ptr(1)] = buffer[0];
        svm.rom[svm.inc_rom_ptr(1)] = buffer[1];
        tmp = 0;
        if(buffer.length() > 3 && (buffer[3] == '@' || buffer[3] == '$')){
            tmp = buffer[3];
        }else{
            tmp = static_cast<uint16_t>(std::strtol(&buffer[2], NULL, 0));
        }
        svm.rom[svm.inc_rom_ptr(1)] = (tmp>>8)&0b11111111;
        svm.rom[svm.inc_rom_ptr(1)] = tmp&0b11111111;
    }
    return 0;
}