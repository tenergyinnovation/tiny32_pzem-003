/***********************************************************************
 * Project      :     tiny32_pzem003_getParam
 * Description  :     Get each parameter from PZEM-003 Modbus RTU power meter module
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14/04/2022
 * Revision     :     1.2
 * Rev1.0       :     Origital
 * Rev1.1       :     Add Relay On, Show Library version
 *                    Add PZEM_003_begin
 * Rev1.2       :     Add tiny32_v3
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-308-3299
 ***********************************************************************/
#include <Arduino.h>
//#include <tiny32.h> //for tiny32 original board
#include <tiny32_v3.h> //for tiny32 v3


tiny32_v3 mcu; //define object

uint8_t id = 1; //Address if PZEM-003, You can change here if it differance

float volt, amp, power;
uint32_t energy;


void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_pzem003_getParam ****\r\n");
  mcu.PZEM_003_begin(RXD2,TXD2);
  mcu.Relay(1);
  vTaskDelay(3000);
  mcu.buzzer_beep(2); //buzzer 2 beeps
  mcu.library_version();
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
