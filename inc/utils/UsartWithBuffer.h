#pragma once

#include "config/stm32plus.h"
#include "config/usart.h"

using namespace stm32plus;

template<class USARTX, class UsartXInterruptFeature>
class UsartWithBuffer {

protected:
  /*
   * The USART1 peripheral configured with the interrupt feature
   */

  typedef UsartXInterruptFeature MyUsartInterrupt;
  USARTX _usart;

  const static int UART_BUFSIZE = 1024;
  /* @brief Receive buffer. */
  volatile uint8_t RX[UART_BUFSIZE];
  /* @brief Transmit buffer. */
  volatile uint8_t TX[UART_BUFSIZE];
  /* @brief Receive buffer head. */
  volatile uint16_t RX_Head;
  /* @brief Receive buffer tail. */
  volatile uint16_t RX_Tail;
  /* @brief Transmit buffer head. */
  volatile uint16_t TX_Head;
  /* @brief Transmit buffer tail. */
  volatile uint16_t TX_Tail;

public:

  /*
   * Use the constructor base initialiser to set up the USART at 57600
   */

  UsartWithBuffer( int _baud = 115200): _usart(_baud) {
    RX_Tail = 0;
    RX_Head = 0;
    TX_Tail = 0;
    TX_Head = 0;

    _usart.UsartInterruptEventSender.insertSubscriber(
	UsartInterruptEventSourceSlot::bind(this,&UsartWithBuffer::onInterrupt)
    );

    // enable receive and transmit interrupts. this will start the whole chain of events
    _usart.enableInterrupts(MyUsartInterrupt::RECEIVE);
  }

  bool TXBuffer_Empty()
  {
    /* Make copies to make sure that volatile access is specified. */
    uint16_t tempHead = TX_Head;
    uint16_t tempTail = TX_Tail;
    /* There are data left in the buffer unless Head and Tail are equal. */
    return (TX_Head == tempTail);
  }

  bool TXBuffer_FreeSpace()
  {
    /* Make copies to make sure that volatile access is specified. */
    uint16_t tempHead = (TX_Head + 1) & (UART_BUFSIZE-1);
    uint16_t tempTail = TX_Tail;
    /* There are data left in the buffer unless Head and Tail are equal. */
    return (tempHead != tempTail);
  }

  bool putch(uint8_t data)
  {

    uint16_t tempTX_Head;
    bool isFree = TXBuffer_FreeSpace();

    if(isFree)
      {
	tempTX_Head = TX_Head;

	__disable_irq();
	TX[tempTX_Head]= data;
	/* Advance buffer head. */
	TX_Head = (tempTX_Head + 1) & (UART_BUFSIZE-1);
	__enable_irq();

	/* Enable TXE interrupt. */
	_usart.enableInterrupts(MyUsartInterrupt::TRANSMIT);
      }
    return isFree;
  }

  /* Send a string */
  void puts(char *s)
  {
    while (*s) putch(*s++);
  }

  bool dataAvailable(){
    uint16_t tempHead = RX_Head;
    uint16_t tempTail = RX_Tail;
    /* There are data left in the buffer unless Head and Tail are equal. */
    return (tempHead != tempTail);
  }

  uint8_t getch(){
    uint8_t ans;

    __disable_irq();
    ans = (RX[RX_Tail]);
    /* Advance buffer tail. */
    RX_Tail = (RX_Tail + 1) & (UART_BUFSIZE-1);
    __enable_irq();

    return ans;
  }

  /*
   * Interrupt callback function.
   */
  void onInterrupt(UsartEventType uet) {

    if(uet==UsartEventType::EVENT_RECEIVE) {

	/* Advance buffer head. */
	uint16_t tempRX_Head = (RX_Head + 1) & (UART_BUFSIZE-1);

	/* Check for overflow. */
	uint16_t tempRX_Tail = RX_Tail;
	uint8_t data = _usart.receive();

	if (tempRX_Head == tempRX_Tail) {
	    /* Disable the Receive interrupt */
	    _usart.disableInterrupts(MyUsartInterrupt::RECEIVE);
	}else{
	    RX[RX_Head] = data;
	    RX_Head = tempRX_Head;
	}

    }
    else if(uet==UsartEventType::EVENT_READY_TO_TRANSMIT) {

	/* Check if all data is transmitted. */
	uint16_t tempTX_Tail = TX_Tail;
	if (TX_Head == tempTX_Tail){
	    /* Overflow MAX size Situation */
	    /* Disable the Transmit interrupt */
	    _usart.disableInterrupts(MyUsartInterrupt::TRANSMIT);
	}else{
	    /* Start transmitting. */
	    uint8_t data = TX[TX_Tail];
	    _usart.send(data);

	    /* Advance buffer tail. */
	    TX_Tail = (TX_Tail + 1) & (UART_BUFSIZE-1);
	}

    }
  }
};
