
/* RCC clock control register */
#define RCC_CR_HSION		0x00000001
#define RCC_CR_HSIRDY		0x00000002
#define RCC_CR_HSITRIM_MASK	0x000000f8
#define	RCC_CR_HSITRIM_SHIFT	3
#define RCC_CR_HSICAL_MASK	0x0000ff00
#define RCC_CR_HSICAL_SHIFT	8
#define RCC_CR_HSEON		0x00010000
#define RCC_CR_HSERDY		0x00020000
#define RCC_CR_HSEBYP		0x00040000
#define RCC_CR_CSSON		0x00080000
#define RCC_CR_PLLON		0x01000000
#define RCC_CR_PLLRDY		0x02000000
#define	RCC_CR_PLLI2SON		0x04000000
#define RCC_CR_PLLI2SRDY	0x08000000

/* RCC PLL configuration register */
#define RCC_PLLCFGR_PLLM0	0x00000001
#define RCC_PLLCFGR_PLLM1	0x00000002
#define RCC_PLLCFGR_PLLM2	0x00000004
#define RCC_PLLCFGR_PLLM3	0x00000008
#define RCC_PLLCFGR_PLLM4	0x00000010
#define RCC_PLLCFGR_PLLM5	0x00000020
#define RCC_PLLCFGR_PLLN_MASK	0x00007fc0
#define RCC_PLLCFGR_PLLN_SHIFT	6
#define RCC_PLLCFGR_PLLP0	0x00010000
#define RCC_PLLCFGR_PLLP1	0x00020000
#define RCC_PLLCFGR_PLLSRC	0x00400000
#define RCC_PLLCFGR_PLLQ0	0x01000000
#define RCC_PLLCFGR_PLLQ1	0x02000000
#define RCC_PLLCFGR_PLLQ2	0x04000000
#define RCC_PLLCFGR_PLLQ3	0x08000000	

/* RCC clock configuration register */
#define RCC_CFGR_SW0		0x00000001
#define RCC_CFGR_SW1		0x00000002
#define RCC_CFGR_SWS0		0x00000004
#define RCC_CFGR_SWS1		0x00000008
#define RCC_CFGR_SWS_MASK	0x0000000c
#define RCC_CFGR_SWS_SHIFT	2
#define RCC_CFGR_HPRE_MASK	0x000000f0
#define RCC_CFGR_HPRE_SHIFT	4
#define RCC_CFGR_PPRE1_MASK	0x00001c00
#define RCC_CFGR_PPRE1_SHIFT	10
#define RCC_CFGR_PPRE2_MASK	0x0000e000
#define RCC_CFGR_PPRE2_SHIFT	13
#define RCC_CFGR_RTCPRE_MASK	0x001f0000
#define RCC_CFGR_RTCPRE_SHIFT	16
#define RCC_CFGR_MCO1_MASK	0x00600000
#define RCC_CFGR_MCO1_SHIFT	21
#define RCC_CFGR_I2SSRC		0x00800000
#define RCC_CFGR_MCO1_PRE_MASK	0x07000000
#define RCC_CFGR_MCO1_PRE_SHIFT 24
#define RCC_CFGR_MCO2_PRE_MASK	0x38000000
#define RCC_CFGR_MCO2_PRE_SHIFT 27
#define RCC_CFGR_MCO2_MASK	0xc0000000
#define RCC_CFGR_MCO2_SHIFT	30

/* RCC clock interrupt register */
#define RCC_CIR_LSIRDYF		0x00000001
#define RCC_CIR_LSERDYF		0x00000002
#define RCC_CIR_HSIRDYF		0x00000004
#define RCC_CIR_HSERDYF		0x00000008
#define RCC_CIR_PLLRDYF		0x00000010
#define RCC_CIR_PLLI2SRDYF	0x00000020
#define RCC_CIR_CSSF		0x00000080
#define RCC_CIR_LSIRDYIE	0x00000100
#define RCC_CIR_LSERDYIE	0x00000200
#define RCC_CIR_HSIRDYIE	0x00000400
#define RCC_CIR_HSERDYIE	0x00000800
#define RCC_CIR_PLLRDYIE	0x00001000
#define RCC_CIR_PLLI2SRDYIE	0x00002000
#define RCC_CIR_LSIRDYC		0x00010000
#define RCC_CIR_LSERDYC		0x00020000
#define RCC_CIR_HSIRDYC		0x00040000
#define RCC_CIR_HSERDYC		0x00080000
#define RCC_CIR_PLLRDYC		0x00100000
#define RCC_CIR_PLLI2SRDYC	0x00200000
#define RCC_CIR_CSSC		0x00800000

/* RCC AHB1 peripheral reset reqister */
#define RCC_AHB1RSTR_GPIOARST	0x00000001
#define RCC_AHB1RSTR_GPIOBRST	0x00000002
#define RCC_AHB1RSTR_GPIOCRST	0x00000004
#define RCC_AHB1RSTR_GPIODRST	0x00000008
#define RCC_AHB1RSTR_GPIOERST	0x00000010
#define RCC_AHB1RSTR_GPIOFRST	0x00000020
#define RCC_AHB1RSTR_GPIOGRST	0x00000040
#define RCC_AHB1RSTR_GPIOHRST	0x00000080
#define RCC_AHB1RSTR_GPIOIRST	0x00000100
#define RCC_AHB1RSTR_CRCRST	0x00001000
#define RCC_AHB1RSTR_DMA1RST	0x00200000
#define RCC_AHB1RSTR_DMA2RST	0x00400000
#define RCC_AHB1RSTR_ETHMACRST	0x02000000
#define	RCC_AHB1RSTR_OTGHSRST	0x20000000

/* RCC AHB2 peripheral reset register */
#define RCC_AHB2RSTR_DCMIRST	0x00000001
#define RCC_AHB2RSTR_CRYPRST	0x00000010
#define RCC_AHB2RSTR_HASHRST	0x00000020
#define RCC_AHB2RSTR_RNGRST	0x00000040
#define RCC_AHB2RSTR_OTGFSRST	0x00000080

/* RCC AHB3 peripheral reset register */
#define RCC_AHB3RSTR_FMCRST	0x00000001

/* RCC APB1 peripheral reset register */
#define RCC_APB1RSTR_TIM2RST	0x00000001
#define RCC_APB1RSTR_TIM3RST	0x00000002
#define RCC_APB1RSTR_TIM4RST	0x00000004
#define RCC_APB1RSTR_TIM5RST	0x00000008
#define RCC_APB1RSTR_TIM6RST	0x00000010
#define RCC_APB1RSTR_TIM7RST	0x00000020
#define RCC_APB1RSTR_TIM12RST 	0x00000040
#define RCC_APB1RSTR_TIM13RST	0x00000080
#define RCC_APB1RSTR_TIM14RST	0x00000100
#define RCC_APB1RSTR_WWDGRST	0x00000800
#define RCC_APB1RSTR_SPI2RST	0x00004000
#define RCC_APB1RSTR_SPI3RST	0x00008000
#define RCC_APB1RSTR_UART2RST	0x00020000
#define RCC_APB1RSTR_UART3RST	0x00040000
#define RCC_APB1RSTR_UART4RST	0x00080000
#define RCC_APB1RSTR_UART5RST	0x00100000
#define RCC_APB1RSTR_I2C1RST	0x00200000
#define RCC_APB1RSTR_I2C2RST	0x00400000
#define RCC_APB1RSTR_I2C3RST	0x00800000
#define RCC_APB1RSTR_CAN1RST	0x02000000
#define RCC_APB1RSTR_CAN2RST	0x04000000
#define RCC_APB1RSTR_PWRRST	0x10000000
#define RCC_APB1RSTR_DACRST	0x20000000

/* RCC APB2 peripheral reset register */
#define RCC_APB2RSTR_TIM1RST	0x00000001
#define RCC_APB2RSTR_TIM8RST	0x00000002
#define RCC_APB2RSTR_USART1RST	0x00000010
#define RCC_APB2RSTR_USART6RST	0x00000020
#define RCC_APB2RSTR_ADCRST	0x00000100
#define RCC_APB2RSTR_SDIORST	0x00000800
#define RCC_APB2RSTR_SP1RST	0x00001000
#define RCC_APB2RSTR_SYSCFGRST	0x00004000
#define RCC_APB2RSTR_TIM9RST	0x00010000
#define RCC_APB2RSTR_TIM10RST	0x00020000
#define RCC_APB2RSTR_TIM11RST	0x00040000

/* RCC AHB1 peripheral clock enable register */
#define RCC_AHB1ENR_GPIOAEN	0x00000001
#define RCC_AHB1ENR_GPIOBEN	0x00000002
#define RCC_AHB1ENR_GPIOCEN	0x00000004
#define RCC_AHB1ENR_GPIODEN	0x00000008
#define RCC_AHB1ENR_GPIOEEN	0x00000010
#define RCC_AHB1ENR_GPIOFEN	0x00000020
#define RCC_AHB1ENR_GPIOGEN	0x00000040
#define RCC_AHB1ENR_GPIOHEN	0x00000080
#define RCC_AHB1ENR_GPIOIEN	0x00000100
#define RCC_AHB1ENR_CRCEN	0x00001000
#define RCC_AHB1ENR_BKPSRAMEN	0x00040000
#define RCC_AHB1ENR_CCMDATARAMEN 0x00100000
#define RCC_AHB1ENR_DMA1EN	0x00200000
#define RCC_AHB1ENR_DMA2EN	0x00400000
#define RCC_AHB1ENR_ETHMACEN	0x02000000
#define RCC_AHB1ENR_ETHMACTXEN	0x04000000
#define RCC_AHB1ENR_ETHMACRXEN	0x08000000
#define RCC_AHB1ENR_ETHMACPTPEN 0x10000000
#define RCC_AHB1ENR_OTGHSEN	0x20000000
#define RCC_AHB1ENR_OTGHSULPIEN 0x40000000

/* RCC AHB2 peripheral clock enable register */
#define RCC_AHB2ENR_DCMIEN	0x00000001
#define RCC_AHB2ENR_CRYPEN	0x00000010
#define RCC_AHB2ENR_HASHEN	0x00000020
#define RCC_AHB2ENR_RNGEN	0x00000040
#define RCC_AHB2ENR_OTGFSEN	0x00000080

/* RCC AHB3 peripheral clock enable register */
#define RCC_AHB3ENR_FMCEN	0x00000001

/* RCC APB1 peripheral clock enable register */
#define RCC_APB1ENR_TIM2EN	0x00000001
#define RCC_APB1ENR_TIM3EN	0x00000002
#define RCC_APB1ENR_TIM4EN	0x00000004
#define RCC_APB1ENR_TIM5EN	0x00000008
#define RCC_APB1ENR_TIM6EN	0x00000010
#define RCC_APB1ENR_TIM7EN	0x00000020
#define RCC_APB1ENR_TIM12EN	0x00000040
#define RCC_APB1ENR_TIM13EN	0x00000080
#define RCC_APB1ENR_TIM14EN	0x00000100
#define RCC_APB1ENR_WWDGEN	0x00000800
#define RCC_APB1ENR_SPI2EN	0x00004000
#define RCC_APB1ENR_SPI3EN	0x00008000
#define RCC_APB1ENR_USART2EN	0x00020000
#define RCC_APB1ENR_USART3EN	0x00040000
#define RCC_APB1ENR_UART4EN	0x00080000
#define RCC_APB1ENR_UART5EN	0x00100000
#define RCC_APB1ENR_I2C1EN	0x00200000
#define RCC_APB1ENR_I2C2EN	0x00400000
#define RCC_APB1ENR_I2C3EN	0x00800000
#define RCC_APB1ENR_CAN1EN	0x02000000
#define RCC_APB1ENR_CAN2EN	0x04000000
#define RCC_APB1ENR_PWREN	0x10000000
#define RCC_APB1ENR_DACEN	0x20000000

/* RCC APB2 peripheral clock enable register */
#define RCC_APB2ENR_TIM1EN	0x00000001
#define RCC_APB2ENR_TIM8EN	0x00000002
#define RCC_APB2ENR_USART1EN	0x00000010
#define RCC_APB2ENR_USART6EN	0x00000020
#define RCC_APB2ENR_ADC1EN	0x00000100
#define RCC_APB2ENR_ADC2EN	0x00000200
#define RCC_APB2ENR_ADC3EN	0x00000400
#define RCC_APB2ENR_SDIOEN	0x00000800
#define RCC_APB2ENR_SPI1EN	0x00001000
#define RCC_APB2ENR_SYSCFGEN	0x00004000
#define RCC_APB2ENR_TIM9EN	0x00010000
#define RCC_APB2ENR_TIM10EN	0x00020000
#define RCC_APB2ENR_TIM11EN	0x00040000

/* RCC AHB1 peripheral clock enable in low power mode register */
#define RCC_AHB1LPENR_GPIOALPEN	0x00000001
#define RCC_AHB1LPENR_GPIOBLPEN	0x00000002
#define RCC_AHB1LPENR_GPIOCLPEN	0x00000004
#define RCC_AHB1LPENR_GPIODLPEN	0x00000008
#define RCC_AHB1LPENR_GPIOELPEN	0x00000010
#define RCC_AHB1LPENR_GPIOFLPEN	0x00000020
#define RCC_AHB1LPENR_GPIOGLPEN	0x00000040
#define RCC_AHB1LPENR_GPIOHLPEN	0x00000080
#define RCC_AHB1LPENR_GPIOILPEN	0x00000100
#define RCC_AHB1LPENR_CRCLPEN	0x00001000
#define RCC_AHB1LPENR_FLITFLPEN	0x00008000
#define RCC_AHB1LPENR_SRAM1LPEN 0x00010000
#define RCC_AHB1LPENR_SRAM2LPEN 0x00020000
#define RCC_AHB1LPENR_BKPSRAMLPEN 0x00040000
#define RCC_AHB1LPENR_DMA1LPEN	0x00200000
#define RCC_AHB1LPENR_DMA2LPEN	0x00400000
#define RCC_AHB1LPENR_ETHMACLPEN	0x02000000
#define RCC_AHB1LPENR_ETHTXLPEN	0x04000000
#define RCC_AHB1LPENR_ETHRXLPEN	0x08000000
#define RCC_AHB1LPENR_ETHPTPLPEN 0x10000000
#define RCC_AHB1LPENR_OTGHSLPEN	0x20000000
#define RCC_AHB1LPENR_OTGHSULPILPEN 0x40000000

/* RCC AHB2 peripheral clock enable in low power mode register */
#define RCC_AHB2LPENR_DCMILPEN	0x00000001
#define RCC_AHB2LPENR_CRYPLPEN	0x00000010
#define RCC_AHB2LPENR_HASHLPEN	0x00000020
#define RCC_AHB2LPENR_RNGLPEN	0x00000040
#define RCC_AHB2LPENR_OTGFSLPEN	0x00000080

/* RCC AHB3 peripheral clock enable in low power mode register */
#define RCC_AHB3LPENR_FMCLPEN	0x00000001

/* RCC APB1 peripheral clock enable in low power mode register */
#define RCC_APB1LPENR_TIM2LPEN	0x00000001
#define RCC_APB1LPENR_TIM3LPEN	0x00000002
#define RCC_APB1LPENR_TIM4LPEN	0x00000004
#define RCC_APB1LPENR_TIM5LPEN	0x00000008
#define RCC_APB1LPENR_TIM6LPEN	0x00000010
#define RCC_APB1LPENR_TIM7LPEN	0x00000020
#define RCC_APB1LPENR_TIM12LPEN	0x00000040
#define RCC_APB1LPENR_TIM13LPEN	0x00000080
#define RCC_APB1LPENR_TIM14LPEN	0x00000100
#define RCC_APB1LPENR_WWDGLPEN	0x00000800
#define RCC_APB1LPENR_SPI2LPEN	0x00004000
#define RCC_APB1LPENR_SPI3LPEN	0x00008000
#define RCC_APB1LPENR_USART2LPEN 0x00020000
#define RCC_APB1LPENR_USART3LPEN 0x00040000
#define RCC_APB1LPENR_UART4LPEN	0x00080000
#define RCC_APB1LPENR_UART5LPEN	0x00100000
#define RCC_APB1LPENR_I2C1LPEN	0x00200000
#define RCC_APB1LPENR_I2C2LPEN	0x00400000
#define RCC_APB1LPENR_I2C3LPEN	0x00800000
#define RCC_APB1LPENR_CAN1LPEN	0x02000000
#define RCC_APB1LPENR_CAN2LPEN	0x04000000
#define RCC_APB1LPENR_PWRLPEN	0x10000000
#define RCC_APB1LPENR_DACLPEN	0x20000000

/* RCC APB2 peripheral clock enable in low power mode register */
#define RCC_APB2LPENR_TIM1LPEN	0x00000001
#define RCC_APB2LPENR_TIM8LPEN	0x00000002
#define RCC_APB2LPENR_USART1LPEN 0x00000010
#define RCC_APB2LPENR_USART6LPEN 0x00000020
#define RCC_APB2LPENR_ADC1LPEN	0x00000100
#define RCC_APB2LPENR_ADC2LPEN	0x00000200
#define RCC_APB2LPENR_ADC3LPEN	0x00000400
#define RCC_APB2LPENR_SDIOLPEN	0x00000800
#define RCC_APB2LPENR_SPI1LPEN	0x00001000
#define RCC_APB2LPENR_SYSCFGLPEN 0x00004000
#define RCC_APB2LPENR_TIM9LPEN	0x00010000
#define RCC_APB2LPENR_TIM10LPEN	0x00020000
#define RCC_APB2LPENR_TIM11LPEN	0x00040000

/* RCC Backup domain control register */
#define RCC_BDCR_LSEON		0x00000001
#define RCC_BDCR_LSERDY		0x00000002
#define RCC_BDCR_LSEBYP		0x00000004
#define RCC_BDCR_RTCSEL_MASK	0x00000300
#define RCC_BDCR_RTCSEL_SHIFT	8
#define RCC_BDCR_RTCEN		0x00008000
#define RCC_BDCR_BDRST		0x00010000

/* RCC clock control and status register */
#define RCC_CSR_LSION		0x00000001
#define RCC_CSR_LSIRDY		0x00000002
#define RCC_CSR_RMVF		0x01000000
#define RCC_CSR_BORRSTF		0x02000000
#define RCC_CSR_PINRSTF		0x04000000
#define RCC_CSR_PORRSTF		0x08000000
#define RCC_CSR_SFTRSTF		0x10000000
#define RCC_CSR_IWDGRSTF	0x20000000
#define RCC_CSR_WWDGRSTF	0x40000000
#define RCC_CSR_LPWRRSTF	0x80000000

/* RCC spread spectrum clock generation register */
#define RCC_SSCGR_MODPER_MASK	0x00001fff
#define RCC_SSCGR_MODPER_SHIFT  0
#define RCC_SSCGR_INCSTEP_MASK	0x0fffe000
#define RCC_SSCGR_INCSTEP_SHIFT 13
#define RCC_SSCGR_SPREADSEL	0x40000000
#define RCC_SSCGR_SSCGEN	0x80000000

/* RCC PLLI2S configuration register */
#define RCC_PLLI2SCFGR_PLLI2SN0	0x00000040
#define RCC_PLLI2SCFGR_PLLI2SN1 0x00000080
#define RCC_PLLI2SCFGR_PLLI2SN2 0x00000100
#define RCC_PLLI2SCFGR_PLLI2SN3 0x00000200
#define RCC_PLLI2SCFGR_PLLI2SN4 0x00000400
#define RCC_PLLI2SCFGR_PLLI2SN5 0x00000800
#define RCC_PLLI2SCFGR_PLLI2SN6 0x00001000
#define RCC_PLLI2SCFGR_PLLI2SN7 0x00002000
#define RCC_PLLI2SCFGR_PLLI2SN8 0x00004000
#define RCC_PLLI2SCFGR_PLLI2SR0 0x10000000
#define RCC_PLLI2SCFGR_PLLI2SR1 0x20000000
#define RCC_PLLI2SCFGR_PLLI2SR2 0x40000000


struct RCC {
	volatile unsigned int CR;		// 0x00
	volatile unsigned int PLLCFGR;		// 0x04
	volatile unsigned int CFGR;		// 0x08
	volatile unsigned int CIR;		// 0x0c

	volatile unsigned int AHB1RSTR;		// 0x10
	volatile unsigned int AHB2RSTR;		// 0x14
	volatile unsigned int AHB3RSTR;		// 0x18
	unsigned int res1;
	volatile unsigned int APB1RSTR;		// 0x20
	volatile unsigned int APB2RSTR;		// 0x24
	unsigned int res2;
	unsigned int res3;

	volatile unsigned int AHB1ENR;		// 0x30
	volatile unsigned int AHB2ENR;		// 0x34
	volatile unsigned int AHB3ENR; 		// 0x38
	unsigned int res4;
	volatile unsigned int APB1ENR; 		// 0x40
	volatile unsigned int APB2ENR;		// 0x44
	unsigned int res5;
	unsigned int res6;

	volatile unsigned int AHB1LPENR;	// 0x50
	volatile unsigned int AHB2LPENR;	// 0x54
	volatile unsigned int AHB3LPENR;	// 0x58
	unsigned int res7;
	volatile unsigned int APB1LPENR;	// 0x60
	volatile unsigned int APB2LPENR;	// 0x64
	unsigned int res8;
	unsigned int res9;

	volatile unsigned int BDCR;		// 0x70
	volatile unsigned int CSR;		// 0x74
	unsigned int res10;
	unsigned int res11;
	volatile unsigned int SSCGR;		// 0x80
	volatile unsigned int PLLI2SCFGR;	// 0x84
};
