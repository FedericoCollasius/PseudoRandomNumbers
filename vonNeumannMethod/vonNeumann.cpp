#include <iostream>
#include <cmath>

//O(log(x))
int countDigits(long long int x){
    int digits = 0;
    while(x > 0){
        x = x / 10;
        digits++;
    }
    return digits;
}

//O(log(seed))
long long int middleNDigits(long long int seed, int n){
    long long int seed_squared = seed * seed; 
    int totalDigits = countDigits(seed_squared); 

    if(n >= totalDigits){
        return seed_squared;
    }
    // Si el número tiene un total de "totalDigits" dígitos, necesitamos extraer "n" dígitos centrales. Entonces, si calculamos 
    // "start" como "(totalDigits - n) / 2", nos aseguramos de que los dígitos extraídos sean realmente los dígitos centrales.
    int start = (totalDigits - n) / 2;

    // Elimina los dígitos menos significativos que están despues de la posición "end" = start + n, dejándonos con los dígitos desde el inicio 
    // hasta "end".
    seed_squared /= pow(10, start);
    // Esto eliminará los dígitos mas significativos que están desde el inicio hasta "start", dejándonos con los "n" dígitos centrales.
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