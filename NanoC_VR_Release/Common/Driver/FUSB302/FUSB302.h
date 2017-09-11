#ifndef FUSB302_H
#define FUSB302_H

//#define FUSB_VCONN_SUPPORT
/* TODO: more modes would be added here later on */
//#define FUSB_HAVE_DRP
#define FUSB_HAVE_UFP

#define SUPPORT_VDM

const char *FUSB_DT_INTERRUPT_INTN =	"fsc_interrupt_int_n";
#define FUSB_DT_GPIO_INTN		        "fairchild,int_n"
#define FUSB_DT_GPIO_VBUS_5V		    "fairchild,vbus5v"
#define FUSB_DT_GPIO_VBUS_OTHER		    "fairchild,vbusOther"

#define FUSB30X_I2C_DRIVER_NAME		    "fusb302"
#define FUSB30X_I2C_DEVICETREE_NAME	    "fairchild,fusb302"

/* FUSB300 Register Addresses */
#define FUSB_REG_DEVICEID		0x01
#define FUSB_REG_SWITCHES0		0x02
#define FUSB_REG_SWITCHES1		0x03
#define FUSB_REG_MEASURE		0x04
#define FUSB_REG_SLICE			0x05
#define FUSB_REG_CONTROL0		0x06
#define FUSB_REG_CONTROL1		0x07
#define FUSB_REG_CONTROL2		0x08
#define FUSB_REG_CONTROL3		0x09
#define FUSB_REG_MASK			0x0A
#define FUSB_REG_POWER			0x0B
#define FUSB_REG_RESET			0x0C
#define FUSB_REG_OCPREG			0x0D
#define FUSB_REG_MASKA			0x0E
#define FUSB_REG_MASKB			0x0F
#define FUSB_REG_CONTROL4		0x10
#define FUSB_REG_STATUS0A		0x3C
#define FUSB_REG_STATUS1A		0x3D
#define FUSB_REG_INTERRUPTA		0x3E
#define FUSB_REG_INTERRUPTB		0x3F
#define FUSB_REG_STATUS0		0x40
#define FUSB_REG_STATUS1		0x41
#define FUSB_REG_INTERRUPT		0x42
#define FUSB_REG_FIFO			0x43

#define FUSB_DISABLE_WORKFUNC   0x00
#define FUSB_ENABLE_WORKFUNC    0x01
#define FUSB_GET_WORKFUNC_STATE 0x02


enum connection_state {
	disabled = 0,
	error_recovery,
	unattached,
	attach_wait_sink,
	attach_wait_source,
	attached_source,
	attached_sink, //6

	policy_src_startup,
	policy_src_send_caps,
	policy_src_discovery,
	policy_src_negotiate_cap,
	policy_src_cap_response,
	policy_src_transition_supply,
	policy_src_transition_default, //13

	policy_src_ready,
	policy_src_get_sink_caps,

	policy_src_send_softrst,
	policy_src_send_hardrst, //17

	policy_snk_startup,
	policy_snk_discovery,
	policy_snk_wait_caps,
	policy_snk_evaluate_caps,
	policy_snk_select_cap,
	policy_snk_transition_sink,
	policy_snk_ready, //24

	policy_snk_send_softrst,
	policy_snk_send_hardrst,

	policy_snk_transition_default, //27
};

#define SBF(s, v)		        ((s) << (v))
#define SWITCHES0_PDWN1		    SBF(1, 0)
#define SWITCHES0_PDWN2		    SBF(1, 1)
#define SWITCHES0_MEAS_CC1	    SBF(1, 2)
#define SWITCHES0_MEAS_CC2	    SBF(1, 3)
#define SWITCHES0_VCONN_CC1	    SBF(1, 4)
#define SWITCHES0_VCONN_CC2	    SBF(1, 5)
#define SWITCHES0_PU_EN1	    SBF(1, 6)
#define SWITCHES0_PU_EN2	    SBF(1, 7)

#define SWITCHES1_TXCC1		    SBF(1, 0)
#define SWITCHES1_TXCC2		    SBF(1, 1)
#define SWITCHES1_AUTO_CRC	    SBF(1, 2)
#define SWITCHES1_DATAROLE	    SBF(1, 4)
#define SWITCHES1_SPECREV	    SBF(3, 5)
#define SWITCHES1_POWERROLE	    SBF(1, 7)

#define MEASURE_MDAC		    SBF(0x3f, 0)
#define MEASURE_VBUS		    SBF(1, 6)

#define SLICE_SDAC		        SBF(0x3f, 0)
#define SLICE_SDAC_HYS		    SBF(3, 6)

#define CONTROL0_TX_START	    SBF(1, 0)
#define CONTROL0_AUTO_PRE	    SBF(1, 1)
#define CONTROL0_HOST_CUR	    SBF(3, 2)
#define CONTROL0_INT_MASK	    SBF(1, 5)
#define CONTROL0_TX_FLUSH	    SBF(1, 6)

#define CONTROL1_ENSOP1		    SBF(1, 0)
#define CONTROL1_ENSOP2		    SBF(1, 1)
#define CONTROL1_RX_FLUSH	    SBF(1, 2)
#define CONTROL1_BIST_MODE2	    SBF(1, 4)
#define CONTROL1_ENSOP1DB	    SBF(1, 5)
#define CONTROL1_ENSOP2DB	    SBF(1, 6)

#define CONTROL2_TOGGLE		    SBF(1, 0)
#define CONTROL2_MODE		    SBF(3, 1)
#define CONTROL2_WAKE_EN	    SBF(1, 3)
#define CONTROL2_TOG_RD_ONLY	SBF(1, 5)
#define CONTROL2_TOG_SAVE_PWR1	SBF(1, 6)
#define CONTROL2_TOG_SAVE_PWR2	SBF(1, 7)

#define CONTROL3_AUTO_RETRY	    SBF(1, 0)
#define CONTROL3_N_RETRIES	    SBF(3, 1)
#define CONTROL3_AUTO_SOFTRESET	SBF(1, 3)
#define CONTROL3_AUTO_HARDRESET	SBF(1, 4)
#define CONTROL3_SEND_HARDRESET	SBF(1, 6)

#define MASK_M_BC_LVL		    SBF(1, 0)
#define MASK_M_COLLISION	    SBF(1, 1)
#define MASK_M_WAKE		        SBF(1, 2)
#define MASK_M_ALERT		    SBF(1, 3)
#define MASK_M_CRC_CHK		    SBF(1, 4)
#define MASK_M_COMP_CHNG	    SBF(1, 5)
#define MASK_M_ACTIVITY		    SBF(1, 6)
#define MASK_M_VBUSOK		    SBF(1, 7)

#define POWER_PWR		        SBF(0xf, 0)

#define RESET_SW_RESET		    SBF(1, 0)
#define RESET_PD_RESET		    SBF(1, 1)

#define MASKA_M_HARDRST		    SBF(1, 0)
#define MASKA_M_SOFTRST		    SBF(1, 1)
#define MASKA_M_TXSENT		    SBF(1, 2)
#define MASKA_M_HARDSENT	    SBF(1, 3)
#define MASKA_M_RETRYFAIL	    SBF(1, 4)
#define MASKA_M_SOFTFAIL	    SBF(1, 5)
#define MASKA_M_TOGDONE		    SBF(1, 6)
#define MASKA_M_OCP_TEMP	    SBF(1, 7)

#define MASKB_M_GCRCSEND	    SBF(1, 0)

#define CONTROL4_TOG_USRC_EXIT	SBF(1, 0)

#define MDAC_1P6V		        0x26

#define STATUS0A_HARDRST	    SBF(1, 0)
#define STATUS0A_SOFTRST	    SBF(1, 1)
#define STATUS0A_POWER23	    SBF(3, 2)
#define STATUS0A_RETRYFAIL	    SBF(1, 4)
#define STATUS0A_SOFTFAIL	    SBF(1, 5)
#define STATUS0A_TOGDONE	    SBF(1, 6)
#define STATUS0A_M_OCP_TEMP	    SBF(1, 7)

#define STATUS1A_RXSOP		    SBF(1, 0)
#define STATUS1A_RXSOP1DB	    SBF(1, 1)
#define STATUS1A_RXSOP2DB	    SBF(1, 2)
#define STATUS1A_TOGSS		    SBF(7, 3)

#define INTERRUPTA_HARDRST	    SBF(1, 0)
#define INTERRUPTA_SOFTRST	    SBF(1, 1)
#define INTERRUPTA_TXSENT	    SBF(1, 2)
#define INTERRUPTA_HARDSENT	    SBF(1, 3)
#define INTERRUPTA_RETRYFAIL	SBF(1, 4)
#define INTERRUPTA_SOFTFAIL	    SBF(1, 5)
#define INTERRUPTA_TOGDONE	    SBF(1, 6)
#define INTERRUPTA_OCP_TEMP	    SBF(1, 7)

#define INTERRUPTB_GCRCSENT	    SBF(1, 0)

#define STATUS0_BC_LVL		    SBF(3, 0)
#define STATUS0_WAKE		    SBF(1, 2)
#define STATUS0_ALERT		    SBF(1, 3)
#define STATUS0_CRC_CHK		    SBF(1, 4)
#define STATUS0_COMP		    SBF(1, 5)
#define STATUS0_ACTIVITY	    SBF(1, 6)
#define STATUS0_VBUSOK		    SBF(1, 7)

#define STATUS1_OCP		        SBF(1, 0)
#define STATUS1_OVRTEMP		    SBF(1, 1)
#define STATUS1_TX_FULL		    SBF(1, 2)
#define STATUS1_TX_EMPTY	    SBF(1, 3)
#define STATUS1_RX_FULL		    SBF(1, 4)
#define STATUS1_RX_EMPTY	    SBF(1, 5)
#define STATUS1_RXSOP1		    SBF(1, 6)
#define STATUS1_RXSOP2		    SBF(1, 7)

#define INTERRUPT_BC_LVL	    SBF(1, 0)
#define INTERRUPT_COLLISION	    SBF(1, 1)
#define INTERRUPT_WAKE		    SBF(1, 2)
#define INTERRUPT_ALERT		    SBF(1, 3)
#define INTERRUPT_CRC_CHK	    SBF(1, 4)
#define INTERRUPT_COMP_CHNG	    SBF(1, 5)
#define INTERRUPT_ACTIVITY	    SBF(1, 6)
#define INTERRUPT_VBUSOK	    SBF(1, 7)

#define FUSB_TKN_TXON		    0xa1
#define FUSB_TKN_SYNC1		    0x12
#define FUSB_TKN_SYNC2		    0x13
#define FUSB_TKN_SYNC3		    0x1b
#define FUSB_TKN_RST1		    0x15
#define FUSB_TKN_RST2		    0x16
#define FUSB_TKN_PACKSYM	    0x80
#define FUSB_TKN_JAMCRC		    0xff
#define FUSB_TKN_EOP		    0x14
#define FUSB_TKN_TXOFF		    0xfe

/* USB PD Control Message Types */
#define CONTROLMESSAGE		    0
#define CMT_GOODCRC		        1
#define CMT_GOTOMIN		        2
#define CMT_ACCEPT		        3
#define CMT_REJECT		        4
#define CMT_PING		        5
#define CMT_PS_RDY		        6
#define CMT_GETSOURCECAP	    7
#define CMT_GETSINKCAP		    8
#define CMT_DR_SWAP		        9
#define CMT_PR_SWAP		        10
#define CMT_VCONN_SWAP		    11
#define CMT_WAIT		        12
#define CMT_SOFTRESET		    13

/* USB PD Data Message Types */
#define DATAMESSAGE		        1
#define DMT_SOURCECAPABILITIES	1
#define DMT_REQUEST		        2
#define DMT_BIST		        3
#define DMT_SINKCAPABILITIES	4
#define DMT_VENDERDEFINED	    15

/* VDM Command Types */
#define VDM_DISCOVERY_ID	    0X01
#define VDM_DISCOVERY_SVIDS	    0X02
#define VDM_DISCOVERY_MODES	    0X03
#define VDM_ENTER_MODE		    0X04
#define VDM_EXIT_MODE		    0X05
#define VDM_ATTENTION		    0X06
#define VDM_DP_STATUS_UPDATE	0X10
#define VDM_DP_CONFIG		    0X11

#define VDM_TYPE_INIT		    0
#define VDM_TYPE_ACK		    1
#define VDM_TYPE_NACK		    2
#define VDM_TYPE_BUSY		    3

#define N_DEBOUNCE_CNT		    (10 - 1)
#define N_CAPS_COUNT		    1000
#define N_HARDRESET_COUNT	    0

#define T_NO_RESPONSE		    5000
#define T_SRC_RECOVER		    830
#define T_TYPEC_SEND_SOURCECAP	3
#define T_SENDER_RESPONSE	    30
#define T_SRC_TRANSITION	    30
#define T_TYPEC_SINK_WAIT_CAP	500
#define T_PS_TRANSITION		    500
#define T_BMC_TIMEOUT		    5
#define T_PS_HARD_RESET_MAX	    35
#define T_SAFE_0V		        650
#define T_SRC_TURN_ON		    275
#define T_SRC_RECOVER_MAX	    1000

#define T_NO_TRIGGER		    500
#define T_DISABLED		        0xffff

#define PD_HEADER_CNT(header)		(((header) >> 12) & 7)
#define PD_HEADER_TYPE(header)		((header) & 0xF)
#define PD_HEADER_ID(header)		(((header) >> 9) & 7)

#define VDM_HEADER_TYPE(header)		(((header) >> 6) & 3)
#define VDMHEAD_CMD_TYPE_MASK		(3 << 6)
#define VDMHEAD_CMD_MASK		    (0x1f << 0)
#define VDMHEAD_STRUCT_TYPE_MASK	BIT(15)

#define GET_VDMHEAD_CMD_TYPE(head)	    ((head & VDMHEAD_CMD_TYPE_MASK) >> 6)
#define GET_VDMHEAD_CMD(head)		    (head & VDMHEAD_CMD_MASK)
#define GET_VDMHEAD_STRUCT_TYPE(head)	((head & VDMHEAD_STRUCT_TYPE_MASK) >> 15)

#define VDM_IDHEAD_USBVID_MASK		    (0xffff << 0)
#define VDM_IDHEAD_MODALSUPPORT_MASK	BIT(26)
#define VDM_IDHEAD_PRODUCTTYPE		    (7 << 27)
#define VDM_IDHEAD_USBDEVICE		    BIT(30)
#define VDM_IDHEAD_USBHOST		        BIT(30)

#define CAP_POWER_TYPE(PDO)		    ((PDO >> 30) & 3)
#define CAP_FPDO_VOLTAGE(PDO)		((PDO >> 10) & 0x3ff)
#define CAP_VPDO_VOLTAGE(PDO)		((PDO >> 20) & 0x3ff)
#define CAP_FPDO_CURRENT(PDO)		((PDO >> 0) & 0x3ff)
#define CAP_VPDO_CURRENT(PDO)		((PDO >> 0) & 0x3ff)

#define GET_SINK_CAP                0x0008

enum CC_ORIENTATION {
	NONE,
	CC1,
	CC2,
};

struct notify_info {
	enum CC_ORIENTATION orientation;
	/* 0 UFP : 1 DFP */
	BOOL power_role;
	BOOL data_role;

	BOOL is_cc_connected;
	BOOL is_pd_connected;

	BOOL is_enter_mode;
	int pin_assignment_support;
	int pin_assignment_def;
	BOOL attention;
};

enum tx_state {
	tx_idle,
	tx_busy,
	tx_failed,
	tx_success
};

struct PD_CAP_INFO {
	uint32 peak_current;
	uint32 specification_revision;
	uint32 externally_powered;
	uint32 usb_suspend_support;
	uint32 usb_communications_cap;
	uint32 dual_role_power;
	uint32 data_role_swap;
	uint32 supply_type;
};

struct fusb30x_chip {
	struct PD_CAP_INFO pd_cap_info;
	struct notify_info notify;
	struct notify_info notify_cmp;
	enum connection_state conn_state;
	int timer_state;
	int timer_mux;
	int port_num;
	int work_continue;
	/*
	 * ---------------------------------
	 * | role 0x03 << 2, | cc_use 0x03 |
	 * | src  1 << 2,    | cc1 1       |
	 * | snk  2 << 2,    | cc2 2       |
	 * ---------------------------------
	 */
	uint8 cc_state;
	int cc1;
	int cc2;
	/* 0 cc1 : 1 cc2 */
	BOOL cc_polarity;
	uint8 val_tmp;
	uint8 debounce_cnt;
	int sub_state;
	int caps_counter;
	uint32 send_load[7];
	uint32 rec_load[7];
	uint16 send_head;
	uint16 rec_head;
	int msg_id;
	enum tx_state tx_state;
	int hardrst_count;
	uint32 source_power_supply[7];
	/* 50mv unit */
	uint32 source_max_current[7];
	/* 10ma uint*/
	int pos_power;
	/*
	 * if PartnerCap[0] == 0xffffffff
	 * show Partner Device do not support supply
	 */
	uint32 partner_cap[7];
	int n_caps_used;
	int vdm_state;
	int vdm_substate;
	int vdm_send_state;
	uint32 dp_status;
	uint16 vdm_svid[12];
	int vdm_svid_num;
	uint32 vdm_id;
	uint8 chip_id;
	BOOL vconn_enabled;
	int togdone_pullup;
    uint8 PDok;
    uint8 int_toggle;
    uint8 int_vbusok;
};

extern int fusb302_init();
extern void fusb302_work_func();
extern uint8 fusb302_set_workfunc (uint8 value);

#endif /* FUSB302_H */

