/** 
 * @file        hss-board.cpp
 * @brief       Defenition of the High-Side-Switch-Board class fucntions
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "hss-board.hpp"

/**
 * @brief High-Side-Switch-Board consturctor
 * Initialize all protected class pointers with a null pointer.
 */
HssBoard::HssBoard()
{
    filterVbat = NULL;

    led1 = NULL;
    led2 = NULL;
    led3 = NULL;
    led4 = NULL;

    hss1 = NULL;
    hss2 = NULL;
    hss3 = NULL;
    hss4 = NULL;

    oloff = NULL;
    pushButtonDigital = NULL;
    
    pushButtonAnalog = NULL;
    vBat = NULL;
}

/**
 * @brief Destructor of the High-Side-Switch-Board
 * 
 */
HssBoard::~HssBoard()
{

}

/**
 * @brief Initialize all necessary objects of the High-Side-Switch-Board
 * 
 * This function initializes all necessary objects of the High-Side-Switch-Board.
 * It retruns an error code to see if everything was initialized correctly.
 * 
 * @return HssBoard::Error_t
 */
HssBoard::Error_t HssBoard::init()
{
    filterVbat = new ExponentialFilter(0.0, 0.3);

    led1->init();
    led2->init();
    led3->init();
    led4->init();

    hss1->init();
    hss2->init();
    hss3->init();
    hss4->init();

    oloff->init();
    pushButtonDigital->init();

    pushButtonAnalog->init();
    vBat->init();

    return OK;
}

/**
 * @brief Switch on the selected High-Side-Switch
 * 
 * This function turns on the desired High-Side-Switch.
 * It also turns on the corresponding LED of the switch.
 * 
 * @param[in]   x   Number of the Switch the should be turned on (1-4)      
 * @return          HssBoard::Error_t 
 */
HssBoard::Error_t HssBoard::switchHxOn(uint8_t x)
{
    switch(x)
    {
        case 1:
            hss1->enable();
            led1->enable();
            break;
        
        case 2:
            hss2->enable();
            led2->enable();
            break;
        
        case 3:
            hss3->enable();
            led3->enable();
            break;
        
        case 4:
            hss4->enable();
            led4->enable();
            break;
    }
    return OK;
}

// /**
//  * @brief Switch on the selected High-Side-Switch with PWM
//  * 
//  * This function turns on the desired High-Side-Switch with PWM.
//  * It also turns on the corresponding LED of the switch.
//  * 
//  * @param[in]   x           Number of the Switch the should be turned on (1-4)  
//  * @param[in]   dutycyle    Desired dutycyle of the switch (0-255)
//  * @return      HssBoard::Error_t 
//  */
// HssBoard::Error_t HssBoard::switchHxOnPWM(uint8_t x, uint8_t dutycyle)
// {
//     switch(x)
//     {
//         case 1:
//             hss1->enable(dutycyle);
//             led1->enable();
//             break;
        
//         case 2:
//             hss2->enable(dutycyle);
//             led2->enable();
//             break;
        
//         case 3:
//             hss3->enable(dutycyle);
//             led3->enable();
//             break;
        
//         case 4:
//             hss4->enable(dutycyle);
//             led4->enable();
//             break;
//     }
//     return OK;
// }

/**
 * @brief Switch off the selected High-Side-Switch
 * 
 * This function turns off the desired High-Side-Switch.
 * It also turns off the corresponding LED of the switch.
 * 
 * @param[in]   x   Number of the Switch the should be turned off (1-4)  
 * @return          HssBoard::Error_t 
 */
HssBoard::Error_t HssBoard::switchHxOff(uint8_t x)
{
    switch(x)
    {
        case 1:
            hss1->disable();
            led1->disable();
            break;
        
        case 2:
            hss2->disable();
            led2->disable();
            break;
        
        case 3:
            hss3->disable();
            led3->disable();
            break;
        
        case 4:
            hss4->disable();
            led4->disable();
            break;
    }
    return OK;
}

/**
 * @brief Turn on the selected High-Side-Switches
 * 
 * This function is used to enable multiple switches at once.
 *  
 * @param[in] h1    Enable the first switch if h1 == TRUE   
 * @param[in] h2    Enable the second switch if h2 == TRUE 
 * @param[in] h3    Enable the third switch if h3 == TRUE 
 * @param[in] h4    Enable the fourth switch if h4 == TRUE 
 * @return          HssBoard::Error_t 
 */
HssBoard::Error_t HssBoard::switchesHxOn(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL)
{
    if(h1 == TRUE){
        hss1->enable();
        led1->enable();
    }

    if(h2 == TRUE){
        hss2->enable();
        led2->enable();
    }

    if(h3 == TRUE){
        hss3->enable();
        led3->enable();
    }

    if(h4 == TRUE){
        hss4->enable();
        led4->enable();
    }

    return OK;
}

/**
 * @brief Turn off the selected High-Side-Switches
 * 
 * This function is used to disable multiple switches at once.
 *  
 * @param[in] h1    Disable the first switch if h1 == TRUE   
 * @param[in] h2    Disable the second switch if h2 == TRUE 
 * @param[in] h3    Disable the third switch if h3 == TRUE 
 * @param[in] h4    Disable the fourth switch if h4 == TRUE 
 * @return          HssBoard::Error_t 
 */
HssBoard::Error_t HssBoard::switchesHxOff(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL)
{
    if(h1 == TRUE){
        hss1->disable();
        led1->disable();
    }

    if(h2 == TRUE){
        hss2->disable();
        led2->disable();
    }

    if(h3 == TRUE){
        hss3->disable();
        led3->disable();
    }

    if(h4 == TRUE){
        hss4->disable();
        led4->disable();
    }

    return OK;
}

/**
 * @brief Read the desired current value of the chosen channel
 * 
 * This function reads the IS pin of the chosen High-Side-Switch
 * and calculates the current which is flowing through the switch
 * with the acquired ADC value.
 * 
 * @param[in]   x   Number of the desired channel (1-4)
 * @return          The value of the current in [A]      
 */
float HssBoard::readIsx(uint8_t x)
{
    float result;

    switch (x)
    {
        case 1:
            hss1->enableDiag();
            result = hss1->readIs();
            hss1->disableDiag();
            break;
        
        case 2:
            hss2->enableDiag();
            result = hss2->readIs();
            hss2->disableDiag();
            break;
        
        case 3:
            hss3->enableDiag();
            result = hss3->readIs();
            hss3->disableDiag();
            break;

        case 4:
            hss4->enableDiag();
            result = hss4->readIs();
            hss4->disableDiag();
            break;
    }
    return result;
}

/**
 * @brief Read the diagnosis of the chosen channel
 * 
 * This function uses the current signal of the channel to diagnose the channel.
 * It returns the different states depending on the channels condition.
 * 
 * @param[in]   x   Desired channel for the diagnosis (1-4)   
 * @return      HssBoard::DiagStatus_t
 * 
 * @retval      0   Everything works correctly
 * @retval      2   Short to ground
 * @retval      4   Short to battery
 * @retval      5   Open load     
 */
HssBoard::DiagStatus_t HssBoard::readDiagx(uint8_t x)
{
    DiagStatus_t diagStatus = NORMAL;

    float currentOn = 0.0;
    float currentOff = 0.0;

    switch(x)
    {
        case 1:
            hss1->enableDiag();
            if(hss1->getSwitchStatus() == POWER_ON){
               diagStatus = hss1->diagRead();
            }
            else{
                oloff->enable();
                delayMicroseconds(300);
                currentOn = hss1->readIs();
    
                oloff->disable();
                delayMicroseconds(400);
                currentOff = hss1->readIs();
                diagStatus = diagnosisOff(currentOn, currentOff);
            }
            hss1->disableDiag();
            break;

        case 2:
            hss2->enableDiag();
            if(hss2->getSwitchStatus() == Hss::Status_t::POWER_ON){
                diagStatus = hss2->diagRead();
            }
            else{
                oloff->enable();
                delayMicroseconds(300);
                currentOn = hss2->readIs();

                oloff->disable();
                delayMicroseconds(400);
                currentOff = hss2->readIs();
                diagStatus = diagnosisOff(currentOn, currentOff);
            }
            hss2->disableDiag();
            break;
        
        case 3:
            hss3->enableDiag();
            if(hss3->getSwitchStatus() == Hss::Status_t::POWER_ON){
                diagStatus = hss3->diagRead();
            }
            else{
                oloff->enable();
                delayMicroseconds(300);
                currentOn = hss3->readIs();

                oloff->disable();
                delayMicroseconds(400);
                currentOff = hss3->readIs();
                diagStatus = diagnosisOff(currentOn, currentOff);
            }
            hss3->disableDiag();
            break;
        
        case 4:
            hss4->enableDiag();
            if(hss4->getSwitchStatus() == Hss::Status_t::POWER_ON){
                diagStatus = hss4->diagRead();
            }
            else{
                oloff->enable();
                delayMicroseconds(300);
                currentOn = hss4->readIs();

                oloff->disable();
                delayMicroseconds(400);
                currentOff = hss4->readIs();
                diagStatus = diagnosisOff(currentOn, currentOff);
            }
            hss4->disableDiag();
            break;
    }
    return diagStatus;
}

/**
 * @brief Calculates the diagnosis state
 * 
 * This functions determines the diagnosis state of the High-Side-Switch.
 * It uses the measrued currents with en- and disabled Open-Load-Detection.
 * 
 * @param[in]   currentOn   Measrued current with Open-Load-Detection on 
 * @param[in]   currentOff  Measrued current with Open-Load-Detection off 
 * @return HssBoard::DiagStatus_t 
 */
HssBoard::DiagStatus_t HssBoard::diagnosisOff(float currentOn, float currentOff)
{
    if((currentOn > (0.0018 * btsVariant->kilis)) && (currentOn < (0.0044 * btsVariant->kilis))){
        if((currentOff > (0.0018 * btsVariant->kilis)) && (currentOff < (0.0044 * btsVariant->kilis))){
            return DiagStatus_t::SHORT_TO_VSS;
        }
        else{
            return DiagStatus_t::OPEN_LOAD;
        }
    }
    else{
        if((currentOn > (0.0044 * btsVariant->kilis))){
            return DiagStatus_t::SHORT_TO_GND;
        }
        else{
            return DiagStatus_t::NORMAL;
        }
    }
}

/**
 * @brief Reads the batter voltage
 * 
 * This functions is reading the attached voltage at the Profet-Board.
 * 
 * @return Value of the battery voltage in [V]
 */
float HssBoard::readVss()
{
    uint16_t adcResult = 0;
    float voltage = 0.0;
    
    adcResult = vBat->ADCRead();
    // Serial.print("Raw ADC vlaue");Serial.println(adcResult);
    voltage = adcResult * ((float)5/(float)1024);  // Vmax/1024 LSB = Resolution of the ADC, 57/10 = Reverse Voltage devider to get the Supplyvoltage
    voltage = (voltage - vBatOffset) * vBatGain;
    voltage = voltage * ((float)57/(float)10);

    filterVbat->input(voltage);
    
    return filterVbat->output();
}

/**
 * @brief Read the button state
 * 
 * @retval TRUE if button is pressed
 * @retval FALSE if button is not pressed 
 */
bool HssBoard::digitalReadButton()
{
    if(pushButtonDigital->read() == GPIO::GPIO_HIGH)
    return TRUE;
    else
    return FALSE;
}

/**
 * @brief Read the button state (analog)
 * 
 * @retval TRUE if button is pressed
 * @retval FALSE if button is not pressed 
 */
bool HssBoard::analogReadButton()
{
    uint16_t result = 0;

    result = pushButtonAnalog->ADCRead();
    if(result > 3000){
        return TRUE;
    }
    else{
        return FALSE;
    }
}




