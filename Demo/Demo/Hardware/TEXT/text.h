#ifndef __TEXT_H__
#define __TEXT_H__	 
#include <stm32f4xx.h>
#include "fontupd.h"


 					     
void Get_HzMat(unsigned char *code,unsigned char *mat,uint8_t size);			//�õ����ֵĵ�����
void Show_Font(uint16_t x,uint16_t y,uint8_t *font,uint8_t size,uint8_t mode);					//��ָ��λ����ʾһ������
void Show_Str(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t*str,uint8_t size,uint8_t mode);	//��ָ��λ����ʾһ���ַ��� 
void Show_Str_Mid(uint16_t x,uint16_t y,uint8_t*str,uint8_t size,uint8_t len);
#endif
