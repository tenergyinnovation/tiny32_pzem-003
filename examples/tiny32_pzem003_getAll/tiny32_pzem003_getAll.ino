/***********************************************************************
 * Project      :     tiny32_pzem003_getAll
 * Description  :     Get All parameter with 1 command from PZEM-003 Modbus RTU power meter module
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14/04/2022
 * Revision     :     1.2
 * Rev1.0       :     Origital
 * Rev1.1       :     Add Relay On, Show Library version
 *                    Add PZEM_003_begin
 * REv1.2       :     Add tiny32_v3
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <Arduino.h>
//#include <tiny32.h> //for tiny32 original board
#include <tiny32_v3.h> //for tiny32 v3

tiny32 mcu; //define object

uint8_t id = 1; //Address if PZEM-003, You can change here if it differance

float volt, amp, power;
uint16_t energy;


void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_pzem003_getAll ****\r\n");
  mcu.PZEM_003_begin(RXD2,TXD2);
  mcu.Relay(1);
  vTaskDelay(3000);
  mcu.buzzer_beep(2); //buzzer 2 beeps
  mcu.library_version();
}

void loop()
{
  
  //Get parameter from PZEM-003
  if(mcu.PZEM_003(id, volt, amp, power, energy)) //function return: true=success, false=unsuccess
  {
    Serial.printf("Info: volt = %.2fV\r\n",volt);
    Serial.printf("Info: current = %.2fA\r\n",amp);
    Serial.printf("Info: Power = %.1fW\r\n",power);
    Serial.printf("Info: energy = %dWh\r\n",energy);
    Serial.println("********************************\r\n");
  }
  else  //can't get data from PZEM-003
  {
    Serial.printf("Error: Can't get data from PZEM-003!!\r\n");
  }

  vTaskDelay(5000);

}