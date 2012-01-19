/*
 * io_scheduler.h
 *
 *  @date Jan 1, 2012
 *  @author jbaker
 */
#include <xccompat.h>
#include "urdb.h"
#include "xlog_fifo.h"
#include "xlog_support.h"

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

enum protocol {I2C, SPI, UART};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @fn void i2c_server(void)
 * @brief URDB I2C scheduler server
 * @param &req_ch Reference to variable holding the server's request channel resource ID
 * @param &service_ch Reference to variable holding the server's service channel resource ID
 */
void i2c_server(unsigned &req_ch, unsigned &service_ch);

/**
 * @fn void spi_server(void)
 * @brief URDB SPI scheduler server
 * @param &req_ch Reference to variable holding the server's request channel resource ID
 * @param &service_ch Reference to variable holding the server's service channel resource ID
 */
void spi_server(unsigned &req_ch, unsigned &service_ch);

/**
 * @fn void stm32_uart_server(void)
 * @brief URDB STM32 UART scheduler server
 * @param &req_ch Reference to variable holding the server's request channel resource ID
 * @param &service_ch Reference to variable holding the server's service channel resource ID
 */
void stm32_uart_server(unsigned &req_ch, unsigned &service_ch);

/**
 * @fn void uart_service_request(unsigned &server, NULLABLE_REFERENCE_PARAM(unsigned, client), request_fifo_t &request_fifo, msg_fifo_t &msg_fifo)
 * @brief Services UART server requests
 * @param &req_ch Reference to variable holding the server's request channel resource ID
 * @param &service_ch Reference to variable holding the server's service channel resource ID
 * @param client_ch Resource ID of remote client chanend
 * @param request_fifo Server's request FIFO
 * @param msg_fifo Server's message FIFO
 */
void uart_service_request(unsigned &req_ch, unsigned &service_ch, NULLABLE_RESOURCE(unsigned, client_ch),
		request_fifo_t &request_fifo, msg_fifo_t &msg_fifo);

/**
 * @fn unsigned int io_client_enqueue(unsigned &server, unsigned &client, client_fifo_t &client_fifo, int data, int data_len, REFERENCE_PARAM(int, ret_data))
 * @brief Sends a request to be added to a server's queue
 * @param &server_req Reference to variable holding the server's request channel resource ID
 * @param &server_service Reference to variable holding the server's service channel resource ID
 * @param client Reference to variable holding the client's chanend resource ID
 * @param client_fifo Client's IO request bookkeeping FIFO
 * @param request Structure of type io_request_t containing IO request information
 * @return CT_ACK/CT_NACK token value returned by server
 */
unsigned int io_client_enqueue(unsigned &server_req, unsigned &server_service, unsigned &client, client_fifo_t &client_fifo,
		io_request_t &request);

/**
 * @fn void io_server_enqueue(unsigned &server, unsigned int new_req_chanend, REFERENCE_PARAM(request_fifo_t, req_fifo))
 * @brief Gets new client request and adds it to the request FIFO
 * @param &req_ch Reference to variable holding the server's request channel resource ID
 * @param &service_ch Reference to variable holding the server's service channel resource ID
 * @param new_req_chanend Resource ID of client chanend making request
 * @param req_fifo Reference to server's request FIFO
 */
void io_server_enqueue(unsigned &req_ch, unsigned &service_ch, unsigned int new_req_chanend, REFERENCE_PARAM(request_fifo_t, req_fifo));

#ifdef __cplusplus
}
#endif
#endif /* IO_SCHEDULER_H_ */
