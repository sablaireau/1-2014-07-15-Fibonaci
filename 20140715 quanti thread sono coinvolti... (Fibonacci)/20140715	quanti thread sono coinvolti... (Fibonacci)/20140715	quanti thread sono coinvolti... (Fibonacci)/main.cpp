//
//  main.cpp
//  20140715	quanti thread sono coinvolti... (Fibonacci)
//
//  Created by Chopper on 08/07/16.
//  Copyright © 2016 Chopper. All rights reserved.
//

#include <future>
#include <iostream>

//template <typename Iter> Iter fibonacci(Iter n) { //Se si usa il template del prof da errore
int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    //Lancia un thread che ti ritorna un int, questo tread lancialo subito (std::launch::async) e sarà
    //La funzione fibonaci a cui passi n-1;
    std::future <int> handle = std::async(std::launch::async, fibonacci, n - 1);

    int val = handle.get(); //Ottieni il valore di ritorno dal thread e se non c'è rimani in attesa, finché non termina il
    //treadh
    
    std::cout<< std::this_thread::get_id()<< "\n"; //Per sare Id del thread.
    
    return (fibonacci(n - 2) +  val);
    }

int main() {
    fibonacci(5);
}
/*
 Dovrebbe esserci 3 thread:
 0x700000187000
 0x700000104000
 0x700000081000
 0x700000081000
 0x100088000
 0x700000081000
 0x100088000
 Program ended with exit code: 0
 */


/* TESTO professore *
 
 template <typename Iter>
 int fibonacci(int n) {
 if (n == 0)
 return 0;
 if (n == 1)
 return 1;
 auto handle = std::async(std::launch::async, fibonacci, n - 1);
 return (fibonacci(n - 2) +  handle.get());
 }
 int main() {
 fibonacci(5);
 }
*/