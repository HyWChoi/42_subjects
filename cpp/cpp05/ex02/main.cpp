#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "\n=== 기본 생성자 테스트 ===" << std::endl;
    {
        Form f1;
        Bureaucrat b1;
        std::cout << f1 << std::endl;
        std::cout << b1 << std::endl;
    }

    std::cout << "\n=== Form 등급 범위 테스트 ===" << std::endl;
    {
        try {
            Form f1("TooHigh", 0, 1);  // grade too high
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        try {
            Form f2("TooLow", 1, 151);  // grade too low
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Form 서명 성공 테스트 ===" << std::endl;
    {
        try {
            Bureaucrat b1("Bob", 1);  // 최고 등급
            Form f1("Important", 100, 50);
            
            std::cout << "Before signing:" << std::endl;
            std::cout << f1 << std::endl;
            
            b1.signForm(f1);
            
            std::cout << "After signing:" << std::endl;
            std::cout << f1 << std::endl;
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Form 서명 실패 테스트 (등급 부족) ===" << std::endl;
    {
        try {
            Bureaucrat b1("Low", 150);  // 최저 등급
            Form f1("TopSecret", 100, 1);
            b1.signForm(f1);
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Form 중복 서명 테스트 ===" << std::endl;
    {
        try {
            Bureaucrat b1("Alice", 1);
            Form f1("Contract", 100, 50);
            
            b1.signForm(f1);  // 첫 번째 서명
            std::cout << "Trying to sign again..." << std::endl;
            b1.signForm(f1);  // 두 번째 서명 시도
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== 복사 생성자 테스트 ===" << std::endl;
    {
        Form f1("Original", 100, 50);
        Form f2(f1);
        
        std::cout << "Original form:" << std::endl;
        std::cout << f1 << std::endl;
        std::cout << "Copied form:" << std::endl;
        std::cout << f2 << std::endl;
    }

    return 0;
}