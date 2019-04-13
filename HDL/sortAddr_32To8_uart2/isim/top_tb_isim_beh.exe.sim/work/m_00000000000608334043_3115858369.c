/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xa0883be4 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/HRUSHIKESH/Desktop/proj/sortAddr_32To8_uart2/top_tb.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static int ng3[] = {5200, 0};
static int ng4[] = {8, 0};
static int ng5[] = {9, 0};
static int ng6[] = {10400, 0};
static int ng7[] = {2, 0};
static unsigned int ng8[] = {32U, 0U};
static int ng9[] = {450000, 0};



static void Initial_46_0(char *t0)
{
    char t11[8];
    char *t1;
    char *t2;
    char *t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;

LAB0:    t1 = (t0 + 3168U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(46, ng0);

LAB4:    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(49, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(53, ng0);
    t2 = (t0 + 2976);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2976);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 5096);
    *((int *)t8) = t7;

LAB7:    t9 = (t0 + 5096);
    if (*((int *)t9) > 0)
        goto LAB8;

LAB9:    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 5100);
    *((int *)t8) = t7;

LAB17:    t9 = (t0 + 5100);
    if (*((int *)t9) > 0)
        goto LAB18;

LAB19:    goto LAB1;

LAB8:    xsi_set_current_line(60, ng0);
    t10 = (t0 + 2976);
    xsi_process_wait(t10, 1000LL);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB10:    xsi_set_current_line(60, ng0);
    t12 = (t0 + 1448);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memset(t11, 0, 8);
    t15 = (t14 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t14);
    t19 = (t18 & t17);
    t20 = (t19 & 1U);
    if (t20 != 0)
        goto LAB14;

LAB12:    if (*((unsigned int *)t15) == 0)
        goto LAB11;

LAB13:    t21 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t21) = 1;

LAB14:    t22 = (t11 + 4);
    t23 = (t14 + 4);
    t24 = *((unsigned int *)t14);
    t25 = (~(t24));
    *((unsigned int *)t11) = t25;
    *((unsigned int *)t22) = 0;
    if (*((unsigned int *)t23) != 0)
        goto LAB16;

LAB15:    t30 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t30 & 1U);
    t31 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t31 & 1U);
    t32 = (t0 + 1448);
    xsi_vlogvar_assign_value(t32, t11, 0, 0, 1);
    t2 = (t0 + 5096);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB7;

LAB11:    *((unsigned int *)t11) = 1;
    goto LAB14;

LAB16:    t26 = *((unsigned int *)t11);
    t27 = *((unsigned int *)t23);
    *((unsigned int *)t11) = (t26 | t27);
    t28 = *((unsigned int *)t22);
    t29 = *((unsigned int *)t23);
    *((unsigned int *)t22) = (t28 | t29);
    goto LAB15;

LAB18:    xsi_set_current_line(63, ng0);

LAB20:    xsi_set_current_line(64, ng0);
    t10 = (t0 + 2088);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    t14 = (t0 + 1928);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 5104);
    *((int *)t8) = t7;

LAB21:    t9 = (t0 + 5104);
    if (*((int *)t9) > 0)
        goto LAB22;

LAB23:    xsi_set_current_line(74, ng0);
    t2 = (t0 + 2088);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng8)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_add(t11, 32, t8, 32, t9, 32);
    t10 = (t0 + 2088);
    xsi_vlogvar_assign_value(t10, t11, 0, 0, 32);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 5112);
    *((int *)t8) = t7;

LAB35:    t9 = (t0 + 5112);
    if (*((int *)t9) > 0)
        goto LAB36;

LAB37:    t2 = (t0 + 5100);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB17;

LAB22:    xsi_set_current_line(67, ng0);

LAB24:    xsi_set_current_line(68, ng0);
    t10 = (t0 + 2248);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    t14 = (t0 + 1768);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 5108);
    *((int *)t8) = t7;

LAB25:    t9 = (t0 + 5108);
    if (*((int *)t9) > 0)
        goto LAB26;

LAB27:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng7)));
    memset(t11, 0, 8);
    xsi_vlog_signed_mod(t11, 32, t8, 32, t9, 32);
    t10 = (t0 + 2248);
    xsi_vlogvar_assign_value(t10, t11, 0, 0, 32);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng2)));
    memset(t11, 0, 8);
    xsi_vlog_signed_rshift(t11, 32, t8, 32, t9, 32);
    t10 = (t0 + 1928);
    xsi_vlogvar_assign_value(t10, t11, 0, 0, 32);
    t2 = (t0 + 5104);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB21;

LAB26:    xsi_set_current_line(70, ng0);
    t10 = (t0 + 2976);
    xsi_process_wait(t10, 1000LL);
    *((char **)t1) = &&LAB28;
    goto LAB1;

LAB28:    xsi_set_current_line(70, ng0);
    t12 = (t0 + 1448);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memset(t11, 0, 8);
    t15 = (t14 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t14);
    t19 = (t18 & t17);
    t20 = (t19 & 1U);
    if (t20 != 0)
        goto LAB32;

LAB30:    if (*((unsigned int *)t15) == 0)
        goto LAB29;

LAB31:    t21 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t21) = 1;

LAB32:    t22 = (t11 + 4);
    t23 = (t14 + 4);
    t24 = *((unsigned int *)t14);
    t25 = (~(t24));
    *((unsigned int *)t11) = t25;
    *((unsigned int *)t22) = 0;
    if (*((unsigned int *)t23) != 0)
        goto LAB34;

LAB33:    t30 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t30 & 1U);
    t31 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t31 & 1U);
    t32 = (t0 + 1448);
    xsi_vlogvar_assign_value(t32, t11, 0, 0, 1);
    t2 = (t0 + 5108);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB25;

LAB29:    *((unsigned int *)t11) = 1;
    goto LAB32;

LAB34:    t26 = *((unsigned int *)t11);
    t27 = *((unsigned int *)t23);
    *((unsigned int *)t11) = (t26 | t27);
    t28 = *((unsigned int *)t22);
    t29 = *((unsigned int *)t23);
    *((unsigned int *)t22) = (t28 | t29);
    goto LAB33;

LAB36:    xsi_set_current_line(77, ng0);
    t10 = (t0 + 2976);
    xsi_process_wait(t10, 1000LL);
    *((char **)t1) = &&LAB38;
    goto LAB1;

LAB38:    xsi_set_current_line(77, ng0);
    t12 = (t0 + 1448);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memset(t11, 0, 8);
    t15 = (t14 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t14);
    t19 = (t18 & t17);
    t20 = (t19 & 1U);
    if (t20 != 0)
        goto LAB42;

LAB40:    if (*((unsigned int *)t15) == 0)
        goto LAB39;

LAB41:    t21 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t21) = 1;

LAB42:    t22 = (t11 + 4);
    t23 = (t14 + 4);
    t24 = *((unsigned int *)t14);
    t25 = (~(t24));
    *((unsigned int *)t11) = t25;
    *((unsigned int *)t22) = 0;
    if (*((unsigned int *)t23) != 0)
        goto LAB44;

LAB43:    t30 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t30 & 1U);
    t31 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t31 & 1U);
    t32 = (t0 + 1448);
    xsi_vlogvar_assign_value(t32, t11, 0, 0, 1);
    t2 = (t0 + 5112);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB35;

LAB39:    *((unsigned int *)t11) = 1;
    goto LAB42;

LAB44:    t26 = *((unsigned int *)t11);
    t27 = *((unsigned int *)t23);
    *((unsigned int *)t11) = (t26 | t27);
    t28 = *((unsigned int *)t22);
    t29 = *((unsigned int *)t23);
    *((unsigned int *)t22) = (t28 | t29);
    goto LAB43;

}


extern void work_m_00000000000608334043_3115858369_init()
{
	static char *pe[] = {(void *)Initial_46_0};
	xsi_register_didat("work_m_00000000000608334043_3115858369", "isim/top_tb_isim_beh.exe.sim/work/m_00000000000608334043_3115858369.didat");
	xsi_register_executes(pe);
}
