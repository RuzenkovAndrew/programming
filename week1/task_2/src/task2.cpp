#include <iostream>
#include <limits>

int main() {
    // byte: 8 бит (1 байт)
    std::cout << "byte: от " << static_cast<int>(std::numeric_limits<int8_t>::min()) 
              << " до " << static_cast<int>(std::numeric_limits<int8_t>::max()) << "\n"; 
    
    // short: 16 бит (2 байта)
    std::cout << "short: от " << std::numeric_limits<int16_t>::min() 
              << " до " << std::numeric_limits<int16_t>::max() << "\n"; 

    // int: 32 бита (4 байта)
    std::cout << "int: от " << std::numeric_limits<int32_t>::min() 
              << " до " << std::numeric_limits<int32_t>::max() << "\n"; 

    // long: 64 бита (8 байт)
    std::cout << "long: от " << std::numeric_limits<int64_t>::min() 
              << " до " << std::numeric_limits<int64_t>::max() << "\n"; 
    
    // float: 32 бита (4 байта)
    std::cout << "float: от " << std::numeric_limits<float>::min() 
              << " до " << std::numeric_limits<float>::max() << "\n"; 
    // Ограничения связаны с форматом представления чисел с плавающей запятой (1 знак, 8 экспонент, 23 мантисса).

    // double: 64 бита (8 байт)
    std::cout << "double: от " << std::numeric_limits<double>::min() 
              << " до " << std::numeric_limits<double>::max() << "\n"; 
    // Аналогично float, но с большей точностью и диапазоном.

    return 0;
}

