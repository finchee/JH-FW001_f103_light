#ifndef __LCD_H
#define __LCD_H		
// #include "sys.h"	 
#include "stdlib.h"
#include "stdint.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEK MiniSTM32F103������
//2.4��/2.8��/3.5��/4.3��/7�� TFTҺ������
//֧������IC�ͺŰ���:ILI9341/NT35310/NT35510/SSD1963/ST7789 ��
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2010/7/4
//�汾��V4.1
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2014-2024
//All rights reserved	
//********************************************************************************
//V4.0 20211110
//1��ȥ���󲿷ֲ���������IC��֧��
//2��������ST7789����IC��֧��
//3���Ż�����ṹ������Դ�룩
//V4.1 20211208
//�޸�NT5510 ID��ȡ��ʽ,��Ϊ�ȷ�����Կ,Ȼ���ȡC500��C501,�Ӷ���ȡ��ȷ��ID(0X5510)
//////////////////////////////////////////////////////////////////////////////////


//LCD��Ҫ������
typedef struct  
{
    uint16_t width;      //LCD ����
    uint16_t height;     //LCD �߶�
    uint16_t id;         //LCD ID
    uint8_t  dir;        //���������������ƣ�0��������1��������
    uint16_t wramcmd;    //��ʼдgramָ��
    uint16_t setxcmd;    //����x����ָ��
    uint16_t  setycmd;   //����y����ָ��
} _lcd_dev;

//LCD����
extern _lcd_dev lcddev; //����LCD��Ҫ����
//LCD�Ļ�����ɫ�ͱ���ɫ
extern uint16_t  POINT_COLOR;//Ĭ�Ϻ�ɫ    
extern uint16_t  BACK_COLOR; //������ɫ.Ĭ��Ϊ��ɫ

////////////////////////////////////////////////////////////////////
//-----------------LCD�˿ڶ���---------------- 
// #define LCD_LED PCout(10)               //LCD����       PC10
 
#define LCD_CS_SET  GPIOC->BSRR=1<<9    //Ƭѡ�˿�      PC9
#define LCD_RS_SET  GPIOC->BSRR=1<<8    //����/����     PC8
#define LCD_WR_SET  GPIOC->BSRR=1<<7    //д����        PC7
#define LCD_RD_SET  GPIOC->BSRR=1<<6    //������        PC6

#define LCD_CS_CLR  GPIOC->BRR=1<<9     //Ƭѡ�˿�      PC9
#define LCD_RS_CLR  GPIOC->BRR=1<<8     //����/����     PC8
#define LCD_WR_CLR  GPIOC->BRR=1<<7     //д����        PC7
#define LCD_RD_CLR  GPIOC->BRR=1<<6     //������        PC6

//PB0~15,��Ϊ������
#define DATAOUT(x) GPIOB->ODR=x; //�������
#define DATAIN     GPIOB->IDR;   //��������

 
//////////////////////////////////////////////////////////////////////
//ɨ�跽����
#define L2R_U2D  0 //������,���ϵ���
#define L2R_D2U  1 //������,���µ���
#define R2L_U2D  2 //���ҵ���,���ϵ���
#define R2L_D2U  3 //���ҵ���,���µ���

#define U2D_L2R  4 //���ϵ���,������
#define U2D_R2L  5 //���ϵ���,���ҵ���
#define D2U_L2R  6 //���µ���,������
#define D2U_R2L  7 //���µ���,���ҵ���

#define DFT_SCAN_DIR  L2R_U2D  //Ĭ�ϵ�ɨ�跽��

//ɨ�跽����
#define L2R_U2D  0 //������,���ϵ���
#define L2R_D2U  1 //������,���µ���
#define R2L_U2D  2 //���ҵ���,���ϵ���
#define R2L_D2U  3 //���ҵ���,���µ���

#define U2D_L2R  4 //���ϵ���,������
#define U2D_R2L  5 //���ϵ���,���ҵ���
#define D2U_L2R  6 //���µ���,������
#define D2U_R2L  7 //���µ���,���ҵ���

#define DFT_SCAN_DIR  L2R_U2D  //Ĭ�ϵ�ɨ�跽��

//������ɫ
#define WHITE           0xFFFF
#define BLACK           0x0000
#define BLUE            0x001F
#define BRED            0XF81F
#define GRED            0XFFE0
#define GBLUE           0X07FF
#define RED             0xF800
#define MAGENTA         0xF81F
#define GREEN           0x07E0
#define CYAN            0x7FFF
#define YELLOW          0xFFE0
#define BROWN           0XBC40  //��ɫ
#define BRRED           0XFC07  //�غ�ɫ
#define GRAY            0X8430  //��ɫ
//GUI��ɫ

#define DARKBLUE        0X01CF  //����ɫ
#define LIGHTBLUE       0X7D7C  //ǳ��ɫ  
#define GRAYBLUE        0X5458  //����ɫ
//������ɫΪPANEL����ɫ

#define LIGHTGREEN      0X841F  //ǳ��ɫ 
#define LGRAY           0XC618  //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE       0XA651  //ǳ����ɫ(�м����ɫ)
#define LBBLUE          0X2B12  //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)


void LCD_Init(void);                                                        //��ʼ��
void LCD_DisplayOn(void);                                                   //����ʾ
void LCD_DisplayOff(void);                                                  //����ʾ
void LCD_Clear(uint16_t Color);                                                  //����
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);                                     //���ù��
void LCD_DrawPoint(uint16_t x, uint16_t y);                                           //����
void LCD_Fast_DrawPoint(uint16_t x, uint16_t y, uint16_t color);                           //���ٻ���
uint16_t  LCD_ReadPoint(uint16_t x, uint16_t y);                                           //����
void LCD_Draw_Circle(uint16_t x0, uint16_t y0, uint8_t r);                                 //��Բ
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);                          //����
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);                     //������
void LCD_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color);                   //��䵥ɫ
void LCD_Color_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color);            //���ָ����ɫ
void LCD_ShowChar(uint16_t x, uint16_t y, uint8_t num, uint8_t size, uint8_t mode);                  //��ʾһ���ַ�
void LCD_ShowNum(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t size);                   //��ʾһ������
void LCD_ShowxNum(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t size, uint8_t mode);         //��ʾ ����
void LCD_ShowString(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t size, uint8_t *p);   //��ʾһ���ַ���,12/16����

void LCD_WriteReg(uint16_t LCD_Reg, uint16_t LCD_RegValue);
uint16_t LCD_ReadReg(uint16_t LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(uint16_t RGB_Code);
void LCD_SSD_BackLightSet(uint8_t pwm);                          //SSD1963 �������
void LCD_Scan_Dir(uint8_t dir);                                  //������ɨ�跽��
void LCD_Display_Dir(uint8_t dir);                               //������Ļ��ʾ����
void LCD_Set_Window(uint16_t sx, uint16_t sy, uint16_t width, uint16_t height); //���ô���

//д���ݺ���
#define LCD_WR_DATA(data){\
        LCD_RS_SET;\
        LCD_CS_CLR;\
        DATAOUT(data);\
        LCD_WR_CLR;\
        LCD_WR_SET;\
        LCD_CS_SET;\
    }

//LCD�ֱ�������
#define SSD_HOR_RESOLUTION      800     //LCDˮƽ�ֱ���
#define SSD_VER_RESOLUTION      480     //LCD��ֱ�ֱ���
//LCD������������
#define SSD_HOR_PULSE_WIDTH     1       //ˮƽ����
#define SSD_HOR_BACK_PORCH      46      //ˮƽǰ��
#define SSD_HOR_FRONT_PORCH     210     //ˮƽ����

#define SSD_VER_PULSE_WIDTH     1       //��ֱ����
#define SSD_VER_BACK_PORCH      23      //��ֱǰ��
#define SSD_VER_FRONT_PORCH     22      //��ֱǰ��
//���¼����������Զ�����
#define SSD_HT  (SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS (SSD_HOR_BACK_PORCH)
#define SSD_VT  (SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)

#endif













