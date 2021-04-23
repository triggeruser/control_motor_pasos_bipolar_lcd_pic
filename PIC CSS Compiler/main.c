#include <main.h>
#include <lcd.c>

#use standard_io(a)
#use standard_io(c)

void main()
{
   lcd_init();
   set_tris_a(0b111111);
   set_tris_b(0b00000000);
   int steps[4]={0b00001010,0b00001001,0b00000101,0b00000110};
   
   
   while(TRUE)
   {
      if (input(PIN_A0)==1)
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Motor encendido");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Giro a la derecha");
         
         for (int i=0; i<4; i++){
            output_c(steps[i]);
            delay_ms(500);
         }
      }
      else if (input(PIN_A1)==1)
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Motor encendido");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Giro a la izquierda");
         
         for (int j=4; j>=1; j--){
            output_c(steps[j-1]);
            delay_ms(500);
         }
      } 
      else
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc,"\fMotor apagado");
         delay_ms(200);
      }
      
      //TODO: User Code
   }

}
