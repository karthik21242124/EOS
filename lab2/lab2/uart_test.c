#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "uart_pl011.h"
#include<stdlib.h>

char buf[64];
uint8_t buf_idx = 0u;

static void parse_cmd(void) {
    if (!strncmp("help\r", buf, strlen("help\r"))) {
        uart_write("Just type and see what happens!\n");
    } else if (!strncmp("uname\r", buf, strlen("uname\r"))) {
        uart_write("bare-metal arm 06_uart\n");
    }
}

int main() {
        uart_config config = {
            .data_bits = 8,
            .stop_bits = 1,
            .parity = false,
            .baudrate = 9600
        };
        uart_configure(&config);

        uart_putchar('A');
        uart_putchar('B');
        uart_putchar('C');
        uart_putchar('\n');

        uart_write("I love drivers!\n");
        uart_write("Type below...\n");

        while (1) {
            char c,start[64],end[64],result[64];
            int i,pos,s=0,b=0,a=0,e=0,k=0;
            int l,p,len=0;
            int r;
            if (uart_getchar(&c) == UART_OK) {
                uart_putchar(c);
                buf[buf_idx % 64] = c;
                buf_idx=buf_idx+1;
                if (c == '\r') {
                    l=buf_idx;
                  for(i=0;i<buf_idx;i++){
                     if(buf[i]=='+')
                     {
                     pos=i;
                     }
                     if(buf[i]=='-')
                     {
                     pos=i;
                     }
                     if(buf[i]=='/')
                     {
                     pos=i;
                     }
                     if(buf[i]=='*')
                     {
                     pos=i;
                     }
                     }
                 for(i=4;i<pos;i++){
                     if(buf[i]!=' ')
                     {
                     start[s] = buf[i];
                     s++;
                     }
                     }
                     start[s]='\0';
                               
                 for(i=pos+1;i<buf_idx;i++){
                     if(buf[i]!=' ')
                     {
                     end[e]=buf[i];
                     e++;
                     }
                     }
                     end[e]='\0';
                     a=atoi(start);
                     b=atoi(end);
                     if(buf[pos]=='+'){
                     r=a+b;
                     }
                     if(buf[pos]=='-'){
                     r=a-b;
                     }
                     if(buf[pos]=='*'){
                     r=a*b;
                     }
                     if(buf[pos]=='/'){
                      if(b==0)
                      {
                      k=1;
                      }
                     r=a/b;
                     }
                     
                     if(k!=1)
                     {
                     itoa(r,result,10);
                               
                   
                 
                 
                 
                 
                  uart_write("\n");
                  uart_putchar(buf[pos]);
                  uart_write("\n");
                 
                  for(i=0;i<64;i++){
                  uart_putchar(start[i]);
                  }
                  uart_write("\n");
                 
                  for(i=0;i<64;i++){
                  uart_putchar(end[i]);
                  }
                  uart_write("\n");
                 
                 
                 
                 
                  for(i=0;i<64;i++){
                  uart_putchar(result[i]);
                  result[i]='\0';
                  }
                  uart_write("\n");
                 }
                 else
                 {
                 uart_write("invalid 0 cant be divisor");
                 uart_write("\n");
                 
                 }
                   
                    i=0;
                    buf_idx = 0u;
                    pos=0;
                    s=0;
                    a=0;
                    b=0;
                    parse_cmd();
               
           
        }
  }
  }
 
        return 0;
        }
