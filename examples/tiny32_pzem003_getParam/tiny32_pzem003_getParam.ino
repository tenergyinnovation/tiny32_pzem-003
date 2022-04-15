/***********************************************************************
 * Project      :     tiny32_pzem003_getParam
 * Description  :     Get each parameter from PZEM-003 Modbus RTU power meter module
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14/04/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32.h>

tiny32 mcu; //define object

uint8_t id = 1; //Address if PZEM-003, You can change here if it differance

float volt, amp, power;
uint16_t energy;


void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_pzem003_getParam ****\r\n");
  mcu.buzzer_beep(2); //buzzer 2 beeps
}

void loop()
{

    /* Read voltage parameter */
    volt = mcu.PZEM_003_Volt(id);
    if(volt != -1)
    {
      Serial.printf("Info: volt = %.2fV\r\n",volt);
    }
    else
    {
      Serial.printf("Error: can't read volt!!\r\n");
    }

    /* Read current parameter */
    amp = mcu.PZEM_003_Amp(id);
     if(amp != -1)
     {
       Serial.printf("Info: current = %.2fA\r\n",amp);
     }
    else
    {
      Serial.printf("Error: can't read current!!\r\n");
    }


    /* Read power parameter */
    power = mcu.PZEM_003_Power(id);
    if(volt != -1)
    {
      Serial.printf("Info: Power = %.1fW\r\n",power);
    }
    else
    {
      Serial.printf("Error: can't read power!!\r\n");
    }

    /* Read energy parameter */
    energy = mcu.PZEM_003_Energy(id);
    if(volt != -1)
    {
      Serial.printf("Info: energy = %dWh\r\n",energy);
    }
    else
    {
      Serial.printf("Error: can't read engergy!!\r\n");
    }

    Serial.println("********************************\r\n");
  
    vTaskDelay(5000);

}