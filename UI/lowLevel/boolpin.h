#include <stdint.h>
#include "stm32f4xx.h"
#include <stdbool.h>

#ifndef __BOOLPIN_H
#define __BOOLPIN_H

//����������� ��������� ��� ������ 1
#define BTN_DEBOUNCE_MS 10
#define BTN_LONG_DELAY_MS 1000
#define BTN_LONG_PERIOD_MS 300

//����������� ������ ��� ���������� ��������
#define BTN_PREV_PORT    GPIOA
#define BTN_PREV_PIN     GPIO_PIN_12

#define BTN_NEXT_PORT    GPIOA
#define BTN_NEXT_PIN     GPIO_PIN_11

#define BTN_BACK_PORT    GPIOA
#define BTN_BACK_PIN     GPIO_PIN_10

#define BTN_FUNC_PORT    GPIOA
#define BTN_FUNC_PIN     GPIO_PIN_9

typedef struct {
    bool event;     // ������� ������
    GPIO_TypeDef* port;
    uint16_t      pin;
    uint16_t debounce_ms;//�����������
    uint16_t delay_ms;//�������� ����� ������� ����������� (���� 0, �� ���������� ��������)
    uint16_t defaultPeriod_ms;//������ ����������� �� ���������

    uint16_t currentPeriod_ms;//������� ������ �����������
    bool autoClick; // ����������
    bool state;     // ������� ���������
    bool flag;      //
    uint32_t start; //
    bool flagLong;  //
    
}Boolpin;

void Boolpin_init(Boolpin* boolpin,GPIO_TypeDef* port,uint16_t pin,uint16_t debounce_ms,uint16_t delay_ms,uint16_t period_ms);
bool Boolpin_update();

#endif /* BOOLPIN_H_ */
