/*
Realizado por Juan Flores ;)
*/
#include <p18cxxx.h>
#include <delays.h>
#include <stdio.h>
#include <stdlib.h>
#include "18F2550BOLT.h"

extern void _startup( void ); // See c018i.c in your C18 compiler dir 
#pragma code _RESET_INTERRUPT_VECTOR = 0x000800 
void _reset( void ) 
{ 
    _asm goto _startup _endasm 
} 
#pragma code
const rom char wav[100]="...........CALCULADORA DE 16 FUNCIONES PARA EL SISTEMA BOLT.........";

char s[6]="ERROR", no[9]="NO SOPOR", ta[5]="TADO", sw[3]="SW", web[20];
char suit=0;
char w, conta=0, conta_nu2=0,conta2=0, conta3=0, num1=0, num2=0, operador=0, operacion=0;
char simb_1[4], simb_2[3],simb_3[3], numero_1[5], numero_2[8], resultado_fin[8], binario[10];
int numerouno=0, numerodos=0, entero_d=0, decimal_d=0;
unsigned int resultado=0;
float resultado_div=0.0,numerouno_d=0.0, numerodos_d=0.0;
void ingresa_datos_0(void);
void ingresa_datos_1(void);
void ingresa_datos_2(void);
void ingresa_datos_4(void);
void ingresa_datos_8(void);
void creditos(void);
void main()
{
// el enter es F
init_bolt();
InitLCD(); 
suit=microsw();
switch (suit)
{
	case 0:
	//funcion suma, multiplicacion, division
	ingresa_datos_0();
	break;
	case 1:
	//funcion resta, potencia, raiz cuadrada
	ingresa_datos_1();
	break;
	case 2:
	ingresa_datos_2();
	break;
	case 4:
	ingresa_datos_4();
	break;
	case 8:
	ingresa_datos_8();
	break;
	case 9:
	creditos();
	break;
	default:
	ClearScreen();//no soportado
	PrintString(s);
	GotoXY(1,0);
	PrintString(sw);
	delay_ms(1000);
}
}
void incializa(void)
{
	for(conta=0; conta < 5; conta++)//incializa las cadenas de numeros
	{
		numero_1[conta]=0;//asigna un caracter nulo
	}
	for(conta=0; conta < 5; conta++)
	{
		numero_2[conta]=0;
	}
	for(conta=0; conta < 8; conta++)
	{
		resultado_fin[conta]=0;
	}
	for(conta=0; conta < 10; conta++)
	{
		binario[conta]=0;
	}
	conta=0;
	conta_nu2=0;
	conta2=0;
	conta3=0;
	num1=0;
	num2=0;
	operador=0;
	operacion=0;
	numerouno=0;
	numerodos=0;
	resultado=0;
	resultado_div=0.0;
	entero_d=0;
	decimal_d=0;
	numerouno_d=0.0;
	numerodos_d=0.0;
}
void lee_datos(void)
{
	while(conta3 < 16)
	{
		if(conta<=7)
		{
			w=GetBot();
			switch(w)
			{
				case 66://entra una B
				PrintString(simb_1);
				operacion=1;
				operador++;
				break;
				case 67://entra una C
				PrintString(simb_2);
				operacion=2;
				operador++;
				break;
				case 68://entra una D
				PrintString(simb_3);
				operacion=3;
				operador++;
				break;
				case 48://entra un 0
				PutLCD(w);
				if(operador == 0)
				{
					numero_1[conta]='0';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='0';
					conta_nu2++;
					num2++;
				}
				break;
				case 49://entra un 1
				PutLCD(w);
				if(operador == 0)
				{
					numero_1[conta]='1';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='1';
					conta_nu2++;
					num2++;
				} 
				break;
				case 50://entra un 2
				PutLCD(w);
				if(operador == 0)
				{
					numero_1[conta]='2';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='2';
					conta_nu2++;
					num2++;
				} 
				break;
				case 51://entra un 3
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='3';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='3';
					conta_nu2++;
					num2++;
				}
				break;
				case 52://entra un 4
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='4';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='4';
					conta_nu2++;
					num2++;
				}
				break;
				case 53://entra un 5
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='5';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='5';
					conta_nu2++;
					num2++;
				}
				break;
				case 54://entra un 6
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='6';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='6';
					conta_nu2++;
					num2++;
				}
				break;
				case 55://entra un 7
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='7';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='7';
					conta_nu2++;
					num2++;
				}
				break;
				case 56://entra un 8
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='8';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='8';
					conta_nu2++;
					num2++;
				}
				break;
				case 57://entra un 9
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='9';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='9';
					conta_nu2++;
					num2++;
				}
				break;
				default://al ingresar una F
				conta3=17;
			}
			conta++; 
		}
		if(conta>7)
		{
			GotoXY(1,conta2);
			conta2++;
			w=GetBot();
			switch(w)
			{
				case 66://entra una B
				PrintString(simb_1);
				operacion=1;
				operador++;
				break;
				case 67://entra una C
				PrintString(simb_2);
				operacion=2;
				operador++;
				break;
				case 68://entra una D
				PrintString(simb_3);
				operacion=3;
				operador++;
				break;
				case 48://entra un 0
				PutLCD(w);
				if(operador == 0)
				{
					numero_1[conta]='0';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='0';
					conta_nu2++;
					num2++;
				}
				break;
				case 49://entra un 1
				PutLCD(w);
				if(operador == 0)
				{
					numero_1[conta]='1';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='1';
					conta_nu2++;
					num2++;
				} 
				break;
				case 50://entra un 2
				PutLCD(w);
				if(operador == 0)
				{
					numero_1[conta]='2';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='2';
					conta_nu2++;
					num2++;
				} 
				break;
				case 51://entra un 3
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='3';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='3';
					conta_nu2++;
					num2++;
				}
				break;
				case 52://entra un 4
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='4';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='4';
					conta_nu2++;
					num2++;
				}
				break;
				case 53://entra un 5
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='5';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='5';
					conta_nu2++;
					num2++;
				}
				break;
				case 54://entra un 6
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='6';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='6';
					conta_nu2++;
					num2++;
				}
				break;
				case 55://entra un 7
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='7';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='7';
					conta_nu2++;
					num2++;
				}
				break;
				case 56://entra un 8
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='8';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='8';
					conta_nu2++;
					num2++;
				}
				break;
				case 57://entra un 9
				PutLCD(w); 
				if(operador == 0)
				{
					numero_1[conta]='9';
					num1++;
				}
				else
				{
					numero_2[conta_nu2]='9';
					conta_nu2++;
					num2++;
				}
				break;
				default://al ingresar una F
				conta3=17;
			}
			conta++; 
		}
		if(conta>15)
		{
			conta=0;
			conta2=0;
			conta3=17;
			ClearScreen();
		}
		conta3++;
	}//end while
}

void ingresa_datos_0(void)
{
	incializa();
	simb_1[0]='+';
	simb_1[1]='\0';
	simb_2[0]='*';
	simb_2[1]='\0';
	simb_3[0]='/';
	simb_3[1]='\0';
	lee_datos();	
	if((operador > 1) || (operador < 1))
	{
		ClearScreen();
		PrintString(s);
		delay_ms(1000);
	}
	else
	{
		if((num1 > 4) || (num1 < 1))
		{
			ClearScreen();
			PrintString(s);
			delay_ms(1000);
		}
		else
		{
			if((num2 > 4) || (num2 < 1))
			{
				ClearScreen();
				PrintString(s);
				delay_ms(1000);
			}
			else//bien
			{
				numerouno=atoi(numero_1);
				numerodos=atoi(numero_2);
				switch(operacion)
				{
					case 1://suma
					resultado=numerouno+numerodos;
					sprintf(resultado_fin, "%d", resultado);
					ClearScreen();
					PrintString(resultado_fin);
					delay_ms(2000);
					break;
					case 2://multiplicacion
					resultado=numerouno*numerodos;
					if(resultado > 14000 || resultado < 0)
					{
						ClearScreen();//no soportado
						PrintString(no);
						GotoXY(1,0);
						PrintString(ta);
						delay_ms(1000);
					}
					else
					{
						sprintf(resultado_fin, "%d", resultado);
						ClearScreen();
						PrintString(resultado_fin);
						delay_ms(2000);
					}
					break;
					case 3://division
					if(numerodos == 0)//division entre cero
					{
						ClearScreen();
						PrintString(s);
						delay_ms(1000);
					}
					else
					{
						numerouno_d=atof(numero_1);
						numerodos_d=atof(numero_2);
						resultado_div=numerouno_d/numerodos_d;//resultado en flotante
						resultado=numerouno/numerodos;
						conta=numerouno%numerodos;
						sprintf(resultado_fin, "C=%d", resultado);
						sprintf(numero_1, "R=%d", conta);
						ClearScreen();
						PrintString(resultado_fin);
						GotoXY(1,2);
						PrintString(numero_1);
						delay_ms(2000);
						entero_d=resultado_div;//parte entera
						decimal_d=(resultado_div-entero_d)*10000;
						sprintf(resultado_fin, "%d.%04d", entero_d, decimal_d);
						ClearScreen();
						PrintString(resultado_fin);
						delay_ms(2000);
					}
					break;
				}
			}
		}
	}
}
void ingresa_datos_1(void)
{	
	incializa();
	simb_1[0]='-';
	simb_1[1]='\0';
	simb_2[0]='^';
	simb_2[1]='\0';
	simb_3[0]='r';
	simb_3[1]='\0';
	lee_datos();
	if((operador > 1) || (operador < 1))
	{
		ClearScreen();
		PrintString(s);
		delay_ms(1000);
	}
	else
	{//start else
		if(operacion == 3)//es raiz
		{//start if raiz
			if(num1 > 0)
			{
				ClearScreen();
				PrintString(s);
				delay_ms(1000);
			}
			else
			{
				if((num2 > 4) || (num2 < 1))
				{
					ClearScreen();
					PrintString(s);
					delay_ms(1000);
				}
				else//bien
				{
					numerodos=atoi(numero_2);
					//raiz
					numerouno_d=0.0;
				    while( (numerouno_d*numerouno_d) <= numerodos)
				            numerouno_d+=0.1;
				    numerodos_d=numerouno_d;
				    for(conta=0;conta<10;conta++)
				    {
				        resultado_div=numerodos;
				        resultado_div/=numerodos_d;
				        resultado_div+=numerodos_d;
				        resultado_div/=2;
				        numerodos_d=resultado_div;
				    }
					entero_d=resultado_div;//parte entera
					decimal_d=(resultado_div-entero_d)*10000;
					sprintf(resultado_fin, "%2d.%04d", entero_d, decimal_d);
					ClearScreen();
					PrintString(resultado_fin);
					delay_ms(2000);
				}
			}
		}//end if raiz
		else
		{//start else no raiz
			if(operacion == 2)
			{//start if potencia
				if((num1 > 2) || (num1 < 1))
				{
					ClearScreen();
					PrintString(s);
					delay_ms(1000);
				}
				else
				{
					if((num2 > 1) || (num2 < 1))
					{
						ClearScreen();
						PrintString(no);
						GotoXY(1,0);
						PrintString(ta);
						delay_ms(1000);
					}
					else//bien
					{
						numerouno=atoi(numero_1);
						numerodos=atoi(numero_2);
						if(((numerouno < 4) && (numerodos < 10)) || ((numerouno < 5) && (numerodos < 8)) || ((numerouno < 6) && (numerodos < 7)) || ((numerouno < 7) && (numerodos < 6)) || ((numerouno < 8) && (numerodos < 6)) || ((numerouno < 9) && (numerodos < 5)) || ((numerouno < 10) && (numerodos < 5)))//3 ^ 9 || 4 ^ 7 || 5 ^ 6 || 6 ^ 6
						{
							//potencia
							resultado=1;
							for(conta=0; conta < numerodos; conta++)
							{
								resultado=resultado*numerouno;
							}
							sprintf(resultado_fin, "%d", resultado);
							ClearScreen();
							PrintString(resultado_fin);
							delay_ms(2000);
						}
						else
						{
							ClearScreen();
							PrintString(no);
							GotoXY(1,0);
							PrintString(ta);
							delay_ms(1000);
						}
						
					}
			}
			}//end if potencia	
			else
			{//start else resta
				if((num1 > 4) || (num1 < 1))
				{
					ClearScreen();
					PrintString(s);
					delay_ms(1000);
				}
				else
				{
					if((num2 > 4) || (num2 < 1))
					{
						ClearScreen();
						PrintString(s);
						delay_ms(1000);
					}
					else//bien
					{
						numerouno=atoi(numero_1);
						numerodos=atoi(numero_2);
						//resta
						resultado=numerouno-numerodos;
						sprintf(resultado_fin, "%d", resultado);
						ClearScreen();
						PrintString(resultado_fin);
						delay_ms(2000);
					}
				}
			}//end else resta
		}//end else no raiz
	}//end else
}
void ingresa_datos_2(void)
{
	incializa();
	simb_1[0]='&';
	simb_1[1]='\0';
	simb_2[0]='$';
	simb_2[1]='\0';
	simb_3[0]='x';
	simb_3[1]='\0';
	lee_datos();	
	if((operador > 1) || (operador < 1))
	{
		ClearScreen();
		PrintString(s);
		delay_ms(1000);
	}
	else
	{
		if((num1 > 4) || (num1 < 1))
		{
			ClearScreen();
			PrintString(s);
			delay_ms(1000);
		}
		else
		{
			if((num2 > 4) || (num2 < 1))
			{
				ClearScreen();
				PrintString(s);
				delay_ms(1000);
			}
			else//bien
			{
				numerouno=atoi(numero_1);
				numerodos=atoi(numero_2);
				if(operacion == 3)
				{
					resultado=numerouno^numerodos;
					sprintf(resultado_fin, "%d", resultado);
					ClearScreen();
					PrintString(resultado_fin);
					delay_ms(2000);
				}
				switch(operacion)
				{
					case 1://AND
					resultado=numerouno&numerodos;
					sprintf(resultado_fin, "%d", resultado);
					ClearScreen();
					PrintString(resultado_fin);
					delay_ms(2000);
					break;
					case 2://OR
					resultado=numerouno|numerodos;
					sprintf(resultado_fin, "%d", resultado);
					ClearScreen();
					PrintString(resultado_fin);
					delay_ms(2000);
					break;
				}
			}
		}
	}
}
void ingresa_datos_4(void)
{	
	incializa();
	simb_1[0]='B';
	simb_1[1]='\0';
	simb_2[0]='H';
	simb_2[1]='\0';
	simb_3[0]='F';
	simb_3[1]='L';
	simb_3[2]='\0';
	lee_datos();
	if((operador > 1) || (operador < 1))
	{
		ClearScreen();
		PrintString(s);
		delay_ms(1000);
	}
	else
	{//start else
		if(operacion == 1)//es conversion a binario
		{//start if CONVERSION BINARIO
			if(num1 > 0)
			{
				ClearScreen();
				PrintString(s);
				delay_ms(1000);
			}
			else
			{
				if((num2 > 3) || (num2 < 1))
				{
					ClearScreen();//no soportado
					PrintString(no);
					GotoXY(1,0);
					PrintString(ta);
					delay_ms(1000);
				}
				else//bien
				{
					numerodos=atoi(numero_2);
					conta=0;
					//conversion a binario
					while(numerodos > 0)
				    {
				    	num1=numerodos % 2;
				    	if(num1 == 0)
				    	{
				            binario[conta]='0';
				        }
				        else
				        {
				            binario[conta]='1';
				        }
				    	conta++;
				    	numerodos=numerodos/2;
				    }
				    conta3=conta;
				    binario[conta3]='\0';
				    conta2=0;
				    num2=0;
				    for(conta=conta3; conta > 0 ; conta--)
				    {
				    	if(conta2 < 8)
				    	{
				    		resultado_fin[conta2]=binario[conta-1];
				    	}
				    	else
				    	{
				    		numero_1[num2]=binario[conta-1];
				    		num2++;
				    	}
				        conta2++;
				    }
				    resultado_fin[8]='\0';
				    numero_1[num2]='\0';
					ClearScreen();
					PrintString(resultado_fin);
					GotoXY(1,0);
					PrintString(numero_1);
					delay_ms(2000);
				}
			}
		}//end if CONVERSION BINARIO
		else
		{//start else no conv binario
			if(operacion == 2)
			{//start if conv hexa
				if(num1 > 0)
				{
					ClearScreen();
					PrintString(s);
					delay_ms(1000);
				}
				else
				{
					if((num2 > 4) || (num2 < 1))
					{
						ClearScreen();
						PrintString(s);
						delay_ms(1000);
					}
					else//bien
					{
						numerodos=atoi(numero_2);
						//conversion a hexadecimal
						sprintf(resultado_fin, "%X", numerodos);
						ClearScreen();
						PrintString(resultado_fin);
						delay_ms(2000);
					}
				}
			}//end if conve hexa
			else
			{//start else flasheo leds
				if(num1 > 0)
				{
					ClearScreen();
					PrintString(s);
					delay_ms(1000);
				}
				else
				{
					if(num2 > 0)
					{
						ClearScreen();
						PrintString(s);
						delay_ms(1000);
					}
					else//bien
					{
						for(conta=0; conta < 50; conta++)
						{
							PORTB=255;
							delay_ms(50);
							PORTB=0;
							delay_ms(50);
						}
					}
				}
			}//end else flasheo leds
		}//end else no conv bin
	}//end else
}
void ingresa_datos_8(void)
{	
	incializa();
	simb_1[0]='>';
	simb_1[1]='\0';
	simb_2[0]='<';
	simb_2[1]='\0';
	simb_3[0]='E';
	simb_3[1]='L';
	simb_3[2]='\0';
	lee_datos();
	if((operador > 1) || (operador < 1))
	{
		ClearScreen();
		PrintString(s);
		delay_ms(1000);
	}
	else
	{//start else
		if(operacion == 1)//es corrimiento a la derecha
		{//start if corrimiento
			if(num1 > 0)
			{
				ClearScreen();
				PrintString(s);
				delay_ms(1000);
			}
			else
			{
				if(num2 > 1 || num2 < 1)
				{
					ClearScreen();//no soportado
					PrintString(no);
					GotoXY(1,0);
					PrintString(ta);
					delay_ms(1000);
				}
				else//bien
				{
					conta3=atoi(numero_2);
					conta2=0;
					while( conta2 < conta3)
					{
						PORTB=0;
						RB0=1;
						delay_ms(100);
						for(conta=0; conta < 7; conta++)
						{
							PORTB=PORTB<<1;
							delay_ms(100);
						}	
						conta2++;
					}
				}
			}
		}//end if corrimiento
		else
		{//start else 
			if(operacion == 2)
			{//start 
				if(num1 > 0)
				{
					ClearScreen();
					PrintString(s);
					delay_ms(1000);
				}
				else
				{
					if(num2 > 1 || num2 < 1)
					{
						ClearScreen();//no soportado
						PrintString(no);
						GotoXY(1,0);
						PrintString(ta);
						delay_ms(1000);
					}
					else//bien
					{
						conta3=atoi(numero_2);
						conta2=0;
						while( conta2 < conta3)
						{
							PORTB=0;
							RB7=1;
							delay_ms(100);
							for(conta=0; conta < 7; conta++)
							{
								PORTB=PORTB>>1;
								delay_ms(100);
							}	
							conta2++;
						}
					}
				}
			}//end if 
			else
			{//start else encendido leds
				if(num1 > 0)
				{
					ClearScreen();
					PrintString(s);
					delay_ms(1000);
				}
				else
				{
					if(num2 > 8)
					{
						ClearScreen();
						PrintString(s);
						delay_ms(1000);
					}
					else//bien
					{
						PORTB=0;
						conta=0;
						while(conta < num2)
						{
							if(numero_2[conta] == '0')
							{
								RB0=1;
							}
							if(numero_2[conta] == '1')
							{
								RB1=1;
							}
							if(numero_2[conta] == '2')
							{
								RB2=1;
							}
							if(numero_2[conta] == '3')
							{
								RB3=1;
							}
							if(numero_2[conta] == '4')
							{
								RB4=1;
							}
							if(numero_2[conta] == '5')
							{
								RB5=1;
							}
							if(numero_2[conta] == '6')
							{
								RB6=1;
							}
							if(numero_2[conta] == '7')
							{
								RB7=1;
							}
							conta++;
						}
						delay_ms(3000);
					}
				}
			}//end else leds encendidos
		}//end else 
	}//end else
}
void creditos(void)
{
	numerouno=0;
	numerodos=0;
	ClearScreen();
	malla:
	numerodos=numerodos+1;
		for(numerouno=0;numerouno<16;numerouno++)	//CARGA MENSAJE DE BUFFER PRINCIPAL
		{web[numerouno]=wav[numerouno+numerodos];}

	GotoXY(0,0);			//ESCRIBE EN RENGLON 0, 8 CARACTERES
		for(numerouno=0;numerouno<8;numerouno++)
		{PutLCD(web[numerouno]);}

	GotoXY(1,0);			//ESCRIBE EN RENGLON 1, 8 CARACTERES
		for(numerouno=8;numerouno<16;numerouno++)
		{PutLCD(web[numerouno]);}

	delay_ms(275);
	if(wav[numerodos+16]==0)numerodos=0;
	goto malla;
}