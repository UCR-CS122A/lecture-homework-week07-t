#ifndef __DEBUG_H__
#define __DEBUG_H__
#include <stdarg.h>
#include "uart_int.h"

#ifndef LOG_UART_INDEX
#define LOG_UART_INDEX 0
#endif

#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARN  2
#define LOG_LEVEL_DEBUG 3
#define LOG_LEVEL_INFO  4

#ifndef LOG_LEVEL_MAX
#define LOG_LEVEL_MAX 0
#endif

void log_message(UART* uart, int level, const char *fmt, ...);

#if LOG_LEVEL_MAX == 0
#define DBG_ERROR(fmt, ...)
#define DBG_WARN(fmt, ...)
#define DBG_DEBUG(fmt, ...)
#define DBG_INFO(fmt, ...)
#endif

#if LOG_LEVEL_MAX == 1
#define DBG_ERROR(fmt, ...) log_message(uart[LOG_UART_INDEX], 0, fmt, ##__VA_ARGS__) 
#define DBG_WARN(fmt, ...)
#define DBG_DEBUG(fmt, ...)
#define DBG_INFO(fmt, ...)
#endif

#if LOG_LEVEL_MAX == 2
#define DBG_ERROR(fmt, ...) log_message(uart[LOG_UART_INDEX], 0, fmt, ##__VA_ARGS__) 
#define DBG_WARN(fmt, ...) log_message(uart[LOG_UART_INDEX], 1, fmt, ##__VA_ARGS__)
#define DBG_DEBUG(fmt, ...)
#define DBG_INFO(fmt, ...)
#endif

#if LOG_LEVEL_MAX == 3
#define DBG_ERROR(fmt, ...) log_message(uart[LOG_UART_INDEX], 0, fmt, ##__VA_ARGS__) 
#define DBG_WARN(fmt, ...) log_message(uart[LOG_UART_INDEX], 1, fmt, ##__VA_ARGS__)
#define DBG_DEBUG(fmt, ...) log_message(uart[LOG_UART_INDEX], 2, fmt, ##__VA_ARGS__)
#define DBG_INFO(fmt, ...)
#endif

#if LOG_LEVEL_MAX == 4
#define DBG_ERROR(fmt, ...) log_message(&uart[LOG_UART_INDEX], 0, fmt, ##__VA_ARGS__) 
#define DBG_WARN(fmt, ...) log_message(&uart[LOG_UART_INDEX], 1, fmt, ##__VA_ARGS__)
#define DBG_DEBUG(fmt, ...) log_message(&uart[LOG_UART_INDEX], 2, fmt, ##__VA_ARGS__)
#define DBG_INFO(fmt, ...) log_message(&uart[LOG_UART_INDEX], 3, fmt, ##__VA_ARGS__)
#endif

#endif