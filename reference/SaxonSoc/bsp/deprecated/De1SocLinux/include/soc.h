#ifndef SOC_H
#define SOC_H
#define SYSTEM_MACHINE_TIMER_HZ 100000000
#define SYSTEM_UART_A_PARAMETER_UART_CTRL_CONFIG_DATA_WIDTH_MAX 8
#define SYSTEM_UART_A_PARAMETER_UART_CTRL_CONFIG_CLOCK_DIVIDER_WIDTH 12
#define SYSTEM_UART_A_PARAMETER_UART_CTRL_CONFIG_PRE_SAMPLING_SIZE 1
#define SYSTEM_UART_A_PARAMETER_UART_CTRL_CONFIG_SAMPLING_SIZE 3
#define SYSTEM_UART_A_PARAMETER_UART_CTRL_CONFIG_POST_SAMPLING_SIZE 1
#define SYSTEM_UART_A_PARAMETER_UART_CTRL_CONFIG_RX_SAMPLE_PER_BIT 5
#define SYSTEM_UART_A_PARAMETER_INIT_CONFIG_BAUDRATE 115200
#define SYSTEM_UART_A_PARAMETER_INIT_CONFIG_DATA_LENGTH 7
#define SYSTEM_UART_A_PARAMETER_INIT_CONFIG_PARITY NONE
#define SYSTEM_UART_A_PARAMETER_INIT_CONFIG_STOP ONE
#define SYSTEM_UART_A_PARAMETER_BUS_CAN_WRITE_CLOCK_DIVIDER_CONFIG 0
#define SYSTEM_UART_A_PARAMETER_BUS_CAN_WRITE_FRAME_CONFIG 0
#define SYSTEM_UART_A_PARAMETER_TX_FIFO_DEPTH 128
#define SYSTEM_UART_A_PARAMETER_RX_FIFO_DEPTH 128
#define SYSTEM_PLIC_SYSTEM_UART_A_INTERRUPT 1
#define SYSTEM_PLIC_SYSTEM_GPIO_A_INTERRUPTS_0 4
#define SYSTEM_PLIC_SYSTEM_GPIO_A_INTERRUPTS_1 5
#define SYSTEM_PLIC_SYSTEM_GPIO_A_INTERRUPTS_2 6
#define SYSTEM_PLIC_SYSTEM_GPIO_A_INTERRUPTS_3 7
#define SYSTEM_CPU_D_BUS 0x0
#define SYSTEM_SDRAM_A_BMB 0x80000000
#define SYSTEM_PERIPHERAL_BRIDGE_INPUT 0x10000000
#define SYSTEM_APB_DECODER_INPUT 0x10000000
#define SYSTEM_PLIC_APB 0x10c00000
#define SYSTEM_MACHINE_TIMER_APB 0x10008000
#define SYSTEM_UART_A_APB 0x10010000
#define SYSTEM_GPIO_A_APB 0x10000000
#define SYSTEM_SPI_A_APB 0x10020000
#define SYSTEM_SPI_B_APB 0x10021000
#endif
