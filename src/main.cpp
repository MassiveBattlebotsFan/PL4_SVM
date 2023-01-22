#include <iostream>
#include "PL4_SVM_Config.hpp"
#include "headers/SVM.hpp"

int main(){
    std::cout << "Version: " << PL4_SVM_VERSION_MAJOR << '.' << PL4_SVM_VERSION_MINOR << '.' << PL4_SVM_VERSION_PATCH << '-' << PL4_SVM_VERSION_TWEAK << '\n';
    SVM svm;
    for(int i = 0; i < 20; i++){
        std::cout << "ROM at " << i << " = " << (int)svm.rom[i] << '\n';
    }
    return 0;
}