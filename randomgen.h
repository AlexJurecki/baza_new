#pragma once

#include <random>
#include <string>
#include <sstream>


std::string Random_MarkaG()
{
    std::vector<std::string> result{
    "Fiat",
    "FSO",
   
    };


    std::mt19937 generator(std::random_device{}());


    std::uniform_int_distribution<std::size_t> distribution(0, result.size() - 1);

    std::size_t number = distribution(generator);

    return result[number];
}
std::string Random_ModelG()
{
    std::vector<std::string> result{
    "126p",
    "Syrena",
    "Polonez",


    };


    std::mt19937 generator(std::random_device{}());

    std::uniform_int_distribution<std::size_t> distribution(0, result.size() - 1);

    std::size_t number = distribution(generator);

    return result[number];
}

std::string Random_MarkaO()
{
    std::vector<std::string> result{
    "Honda",
    "Toyota",
    "BMW",
    "Mercedes",
    "Ford",
    "Daimler",
    "Lada",
    "Fiat",
    "Ferrari",
    "Porsche",
    "Volvo",
    "KIA",
    "Chevrolet",
    "Jeep",
    "Dacia",
    "Subaru",

    };


    std::mt19937 generator(std::random_device{}());


    std::uniform_int_distribution<std::size_t> distribution(0, result.size() - 1);

    std::size_t number = distribution(generator);

    return result[number];
}

std::string Random_MarkaM()
{
    std::vector<std::string> result{
    "Honda",
    "Triumph",
    "BMW",
    "Dukati",
    "Harley",
    "Yamaha",
    "Kawasaki",
    "Suzuki",


    };


    std::mt19937 generator(std::random_device{}());


    std::uniform_int_distribution<std::size_t> distribution(0, result.size() - 1);

    std::size_t number = distribution(generator);

    return result[number];
}

std::string Random_MarkaL()
{
    std::vector<std::string> result{
    "Mercedes",
    "Volvo",
    "Iveco",
    "Scania",
    "Bedford",
    "DAF",
    };

    // gets 'entropy' from device that generates random numbers itself
    // to seed a mersenne twister (pseudo) random generator
    std::mt19937 generator(std::random_device{}());

    // make sure all numbers have an equal chance. 
    // range is inclusive (so we need -1 for vector index)
    std::uniform_int_distribution<std::size_t> distribution(0, result.size() - 1);

    std::size_t number = distribution(generator);

    return result[number];
}
std::string Random_ModelO()
{
    std::vector<std::string> result{
    "Aventador",
    "V90",
    "K1200",
    "Model S",
    "Carnival",
    "Sandero",
    "Civic",
    "DeLorean",
    "Accord",
    "Mustang",
    "Corvette",
    "Wrangler",
    "CR-V",
    "Charger",
    "Toronado",
    "Highlander",
    "Ranger",
    "Renegade",

    };

    // gets 'entropy' from device that generates random numbers itself
    // to seed a mersenne twister (pseudo) random generator
    std::mt19937 generator(std::random_device{}());

    // make sure all numbers have an equal chance. 
    // range is inclusive (so we need -1 for vector index)
    std::uniform_int_distribution<std::size_t> distribution(0, result.size() - 1);

    std::size_t number = distribution(generator);

    return result[number];
}

std::string Random_ModelM()
{
    std::vector<std::string> result{
    "Hayabusa",
    "K1200",
    "Midnight Star",
    "Enduro",
    "Ninja",
    "V-Max",
    "Goldwing ",


    };

    // gets 'entropy' from device that generates random numbers itself
    // to seed a mersenne twister (pseudo) random generator
    std::mt19937 generator(std::random_device{}());

    // make sure all numbers have an equal chance. 
    // range is inclusive (so we need -1 for vector index)
    std::uniform_int_distribution<std::size_t> distribution(0, result.size() - 1);

    std::size_t number = distribution(generator);

    return result[number];
}

std::string Random_ModelL()
{
    std::vector<std::string> result{
    "FL12",
    "Axor",
    "Atkinson 401",
    "Turbostar",
    "1644EPS",
 
    };


    std::mt19937 generator(std::random_device{}());


    std::uniform_int_distribution<std::size_t> distribution(0, result.size() - 1);

    std::size_t number = distribution(generator);

    return result[number];
}
int Random_Boxer()
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<std::mt19937::result_type> result(0,     1);
    return result(generator);
}
int Random_Diesel()
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<std::mt19937::result_type> result(0, 1);
    return result(generator);
}

int Random_Data()
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<std::mt19937::result_type> result(1955,2022);
    return result(generator);
}

int Random_Pasazerowie()
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<std::mt19937::result_type> result(1,7);
    return result(generator);
}
double Random_Power()
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<double> result(20, 500);
    return result(generator);
}
double Random_Ladunek()
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<double> result(1000, 10000);
    return result(generator);
}

double Random_Poj()
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<double> result(100, 5000);
    return result(generator);
}