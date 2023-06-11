#include <iostream>

int digits(int x){
    int n = 0;
    while(x != 0){
        x /= 10;
        n++;
    }
    return n;
}


int main(){
    int x;
    std::cout << "Insert a number:" << std::endl;  
    std::cin >> x;
    int i; 
    std::cout << "Insert a number of iterations:" << std::endl;
    std::cin >> i;
    
    int n = digits(x); 
    while(i > 0){
        x = x*x; 
        //int y = middleNDigits(x, n);
        //x = y;
        i--; 
    }
    std::cout << "Your number is:" << x << std::endl;

    return 0;
}