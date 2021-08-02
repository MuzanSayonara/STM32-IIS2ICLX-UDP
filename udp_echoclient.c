/**
  ******************************************************************************
  * @file    LwIP/LwIP_UDP_Echo_Client/Src/udp_echoclient.c
  * @author  MCD Application Team
  * @brief   UDP echo client
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "udp_echoclient.h"
#include "main.h"
#include "lwip.h"
#include "lwip/pbuf.h"
#include "lwip/udp.h"
#include "lwip/tcp.h"
#include <string.h>
#include <stdio.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u16_t UDP_SERVER_PORT = 20001;
/* Private function prototypes -----------------------------------------------*/

u8_t data[100];

struct udp_pcb *upcb;

extern ip4_addr_t pcaddr;
extern ip4_addr_t ipaddr;
ip4_addr_t PCaddr;
uint8_t PC_ADDRESS[4];


/* Private functions ---------------------------------------------------------*/


void udp_echoclient_connect(void)
{

  /* Create a new UDP control block  */
  upcb = udp_new();

  if (upcb!=NULL)
  {
    /* configure destination IP address and port */

	   PC_ADDRESS[0] = 169;
	   PC_ADDRESS[1] = 254;
	   PC_ADDRESS[2] = 109;
	   PC_ADDRESS[3] = 119;
	   IP4_ADDR(&PCaddr, PC_ADDRESS[0], PC_ADDRESS[1], PC_ADDRESS[2], PC_ADDRESS[3]);
	   udp_connect(upcb, &PCaddr, UDP_SERVER_PORT);

  }
}
void udp_echoclient_connect2(void){
  struct udp_pcb * UDP_Multicast_init(void)
  {
      struct udp_pcb *upcb;

      /* Create a new UDP control block  */
      upcb = udp_new();

      if (upcb)
      {
          #if LWIP_MULTICAST_TX_OPTIONS
              IP4_ADDR(&(upcb->multicast_ip), 224, 3, 29, 71); //Multicast IP address
          #endif /* LWIP_MULTICAST_TX_OPTIONS */
	  return upcb;
      }
}
  }
void udp_echoclient_send(void)
{
  struct pbuf *p;


  static int T[2] ;
  Measure_I2C(S1,T);
  //printf("%d \r\n",T[0]);
  //printf("%d \r\n",T[1]);

  sprintf((char*)data,"%d %d", T[0],T[1]);
  //printf("%s \r\n",data);

  /* allocate pbuf from pool*/
  p = pbuf_alloc(PBUF_TRANSPORT,strlen((char*)data), PBUF_POOL);

  if (p != NULL)
  {
    /* copy data to pbuf */
	  pbuf_take(p,(char*)data, strlen((char*)data));

    /* send udp data */
    udp_send(upcb, p);
     //udp_sendto(upcb, p,&PCaddr, UDP_SERVER_PORT);
    printf("done sending! \r\n");
    /* free pbuf */
    pbuf_free(p);
  }
}

void udp_echoclient_send_hello(void)
{
  struct pbuf *p;

  sprintf((char*)data, "HELLO!");


  /* allocate pbuf from pool*/
  p = pbuf_alloc(PBUF_TRANSPORT,strlen((char*)data), PBUF_POOL);

  if (p != NULL)
  {
    /* copy data to pbuf */
	  pbuf_take(p, (char*)data, strlen((char*)data));

    /* send udp data */
    //udp_send(upcb, p);
     udp_sendto(upcb, p,&PCaddr, UDP_SERVER_PORT);
    printf("done sending! : %s \r\n",data);
    /* free pbuf */
    pbuf_free(p);
  }
}




/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
