#include <iostream>
#include <bitset>
#include <string>
#include <map>
#include <stdio.h>
#include <vector>
#include <typeinfo>

/**
 * @brief Prints a Key, Value std::map pair implemented in the C++ STL. 
 * map type can be infered in decloration.
 * 
 * @param map input map of given type <T1,T2>
 * @return No return Val 
 */

template <typename T1, typename T2>
void printMap(std::map<T1,T2> &map)
{
    std::cout << "Printing Map" << std::endl;
    for(typename std::map<T1,T2>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << "Key : " << it->first << "\tValue : " << it->second << std::endl;
    }
}

template <typename T> 
void printVector(std::vector<T> vect)
{
    for(typename std::vector<T>::iterator it=vect.begin(); it != vect.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

std::vector<std::string> checkEnabledPins(uint16_t bitmask, std::map<std::string, uint16_t> &pinMap);

void printSetBitMap(uint16_t bitmask, std::map<std::string, uint16_t> &pinMap);

/**
 * @brief Simulation of a mapping function for microcontrollers. 
 * Bitshift script created with input parameters to correspond to 
 * Microcontroller Pinmappings.
 */

void clearCmd()
{
    std::cout << "\x1B[2J\x1B[H";
}

int main()
{

    //Initialization
    std::map<std::string, uint16_t> pinSetting
    {
        {"ADC_1", 0u},
        {"ADC_2", 1u},
        {"DIO_1", 2u},
        {"DIO_2", 3u},
        {"DIO_3", 4u},
        {"LED_1", 5u},
        {"LED_2", 6u},
        {"LED_3", 7u},
        {"RESET", 14u},
        {"MASTER_ENABLE", 15u}
    };

    printMap(pinSetting);

    uint16_t togglePins = 0u;
    uint16_t pin_to_toggle = 0u;

    //Input Loop
    for(int i=0; i<10; i++) 
    {   
        std::cout << "Current Pin setting :" << std::bitset<16>(togglePins) << std::endl;
        std::cout << "Choose toggle Pin : ";
        std::cin >> pin_to_toggle;
        std::cout << "Pin Mapping Values " << std::endl;
        
        clearCmd();

        if (pin_to_toggle > 15 || pin_to_toggle < 0) 
        {
            std::cout << "Bit Index exceeeded" << std::endl;
            break;
        }
        togglePins = togglePins ^ (1 << (int)pin_to_toggle);
        printSetBitMap(togglePins,pinSetting);
    }

    std::cout << "Final Bit mapping : " << std::bitset<16>(togglePins) << std::endl;
    std::cout << "Bit map Setting : ";
    printVector(checkEnabledPins(togglePins,pinSetting));
}

std::vector<std::string> checkEnabledPins(uint16_t bitmask, std::map<std::string, uint16_t> &pinMap)
{
    std::vector<std::string> activatedPinsVector;
    for(std::map<std::string, uint16_t>::iterator it = pinMap.begin(); it != pinMap.end(); ++it)
    {
        if (((bitmask >> it->second) & 1) == 1)
        {
            activatedPinsVector.push_back(it->first);
        }
    }

    return activatedPinsVector;
}

/**
 * @brief 
 * 
 * @param bitmask  16 bit toggle mask for Pins.
 * @param pinMap   Pin mapping of registers. Takes pairs of {String -> Pin name | uint16_t -> Bit offset.}
 */
void printSetBitMap(uint16_t bitmask, std::map<std::string, uint16_t> &pinMap)
{

    for (std::map<std::string, uint16_t>::iterator pinIt = pinMap.begin();
        pinIt != pinMap.end(); ++pinIt)
    {
        uint16_t pinNumber = (uint16_t)pinIt->second;
        bool enabled = ((bitmask >> pinNumber) & 1) == 1 ? true : false;
        std::cout << pinIt-> first << " : " << enabled << std::endl;
    }

    std::cout << std::endl;
}