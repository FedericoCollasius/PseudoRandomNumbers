#include <iostream>
#include <cmath>


int countDigits(long long int x){
    int digits = 0;
    while(x > 0){
        x = x / 10;
        digits++;
    }
    return digits;
}

long long int middleNDigits(long long int seed, int n){
    long long int seed_squared = seed * seed; 
    int totalDigits = countDigits(seed_squared); 

    if(n >= totalDigits){
        return seed_squared;
    }

    int start = (totalDigits - n) / 2;
    int end = start + n;

    seed_squared /= pow(10, start);
    seed_squared %= (int) pow(10, n);

    if(seed_squared == 0 || seed_squared == 1){
        seed_squared = seed;
    }
    
    return seed_squared;
}


int main(){
    std::cout << "Escribi un numero cualquiera." << std::endl;
    long long int seed;
    int n; 
    std::cin >> seed;
    n = countDigits(seed);
    std::cout << "¿Cuantas iteraciones queres hacer?" << std::endl;
    int i;
    std::cin >> i;
    while(i > 0){
        seed = middleNDigits(seed, n);
        std::cout << seed << std::endl;
        i--;
    }
    std::cout << "Su numero pseudo-aleatorio es: " << seed << std::endl;
    return 0; 
}