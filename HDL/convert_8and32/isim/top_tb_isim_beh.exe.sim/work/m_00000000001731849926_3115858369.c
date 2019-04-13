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
static const char *ng0 = "C:/Users/HRUSHIKESH/Desktop/proj/convert_8and32/top_tb.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static int ng3[] = {-2104317254, 0};
static int ng4[] = {520, 0};
static int ng5[] = {10, 0};
static int ng6[] = {9, 0};
static int ng7[] = {10400, 0};
static int ng8[] = {2, 0};



static void Initial_51_0(char *t0)
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

LAB0:    t1 = (t0 + 3488U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(51, ng0);

LAB4:    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(59, ng0);
    t2 = (t0 + 3296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 5696);
    *((int *)t8) = t7;

LAB6:    t9 = (t0 + 5696);
    if (*((int *)t9) > 0)
        goto LAB7;

LAB8:    goto LAB1;

LAB7:    xsi_set_current_line(63, ng0);
    t10 = (t0 + 3296);
    xsi_process_wait(t10, 1000LL);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(63, ng0);
    t12 = (t0 + 1608);
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
        goto LAB13;

LAB11:    if (*((unsigned int *)t15) == 0)
        goto LAB10;

LAB12:    t21 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t21) = 1;

LAB13:    t22 = (t11 + 4);
    t23 = (t14 + 4);
    t24 = *((unsigned int *)t14);
    t25 = (~(t24));
    *((unsigned int *)t11) = t25;
    *((unsigned int *)t22) = 0;
    if (*((unsigned int *)t23) != 0)
        goto LAB15;

LAB14:    t30 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t30 & 1U);
    t31 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t31 & 1U);
    t32 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t32, t11, 0, 0, 1, 0LL);
    t2 = (t0 + 5696);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB6;

LAB10:    *((unsigned int *)t11) = 1;
    goto LAB13;

LAB15:    t26 = *((unsigned int *)t11);
    t27 = *((unsigned int *)t23);
    *((unsigned int *)t11) = (t26 | t27);
    t28 = *((unsigned int *)t22);
    t29 = *((unsigned int *)t23);
    *((unsigned int *)t22) = (t28 | t29);
    goto LAB14;

}

static void Always_67_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    int t25;
    char *t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;

LAB0:    t1 = (t0 + 3736U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(68, ng0);

LAB4:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 3544);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(69, ng0);
    t4 = (t0 + 1608);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t7) == 0)
        goto LAB6;

LAB8:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB9:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB11;

LAB10:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t24, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(70, ng0);
    t2 = (t0 + 2248);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng5)));
    memset(t3, 0, 8);
    xsi_vlog_signed_equal(t3, 32, t5, 32, t6, 32);
    t7 = (t3 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB12;

LAB13:
LAB14:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB11:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB10;

LAB12:    xsi_set_current_line(71, ng0);

LAB15:    xsi_set_current_line(72, ng0);
    t13 = (t0 + 2408);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t24 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t24, t15, 0, 0, 32, 0LL);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 3544);
    xsi_process_wait(t2, 1000000LL);
    *((char **)t1) = &&LAB16;
    goto LAB1;

LAB16:    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng6)));
    t4 = (t2 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t2);
    t25 = (t10 & t9);
    t5 = (t0 + 5700);
    *((int *)t5) = t25;

LAB17:    t6 = (t0 + 5700);
    if (*((int *)t6) > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    goto LAB14;

LAB18:    xsi_set_current_line(75, ng0);

LAB20:    xsi_set_current_line(76, ng0);
    t7 = (t0 + 2568);
    t13 = (t7 + 56U);
    t14 = *((char **)t13);
    t15 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t15, t14, 0, 0, 1, 0LL);
    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng7)));
    t4 = (t2 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t2);
    t25 = (t10 & t9);
    t5 = (t0 + 5704);
    *((int *)t5) = t25;

LAB21:    t6 = (t0 + 5704);
    if (*((int *)t6) > 0)
        goto LAB22;

LAB23:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 2248);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng8)));
    memset(t3, 0, 8);
    xsi_vlog_signed_mod(t3, 32, t5, 32, t6, 32);
    t7 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t7, t3, 0, 0, 32, 0LL);
    xsi_set_current_line(80, ng0);
    t2 = (t0 + 2248);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng2)));
    memset(t3, 0, 8);
    xsi_vlog_signed_rshift(t3, 32, t5, 32, t6, 32);
    t7 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t7, t3, 0, 0, 32, 0LL);
    t2 = (t0 + 5700);
    t25 = *((int *)t2);
    *((int *)t2) = (t25 - 1);
    goto LAB17;

LAB22:    xsi_set_current_line(78, ng0);
    t7 = (t0 + 3544);
    xsi_process_wait(t7, 1000LL);
    *((char **)t1) = &&LAB24;
    goto LAB1;

LAB24:    xsi_set_current_line(78, ng0);
    t13 = (t0 + 1608);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memset(t3, 0, 8);
    t24 = (t15 + 4);
    t11 = *((unsigned int *)t24);
    t12 = (~(t11));
    t16 = *((unsigned int *)t15);
    t17 = (t16 & t12);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB28;

LAB26:    if (*((unsigned int *)t24) == 0)
        goto LAB25;

LAB27:    t26 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t26) = 1;

LAB28:    t27 = (t3 + 4);
    t28 = (t15 + 4);
    t19 = *((unsigned int *)t15);
    t20 = (~(t19));
    *((unsigned int *)t3) = t20;
    *((unsigned int *)t27) = 0;
    if (*((unsigned int *)t28) != 0)
        goto LAB30;

LAB29:    t30 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t30 & 1U);
    t31 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t31 & 1U);
    t32 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t32, t3, 0, 0, 1, 0LL);
    t2 = (t0 + 5704);
    t25 = *((int *)t2);
    *((int *)t2) = (t25 - 1);
    goto LAB21;

LAB25:    *((unsigned int *)t3) = 1;
    goto LAB28;

LAB30:    t21 = *((unsigned int *)t3);
    t22 = *((unsigned int *)t28);
    *((unsigned int *)t3) = (t21 | t22);
    t23 = *((unsigned int *)t27);
    t29 = *((unsigned int *)t28);
    *((unsigned int *)t27) = (t23 | t29);
    goto LAB29;

}


extern void work_m_00000000001731849926_3115858369_init()
{
	static char *pe[] = {(void *)Initial_51_0,(void *)Always_67_1};
	xsi_register_didat("work_m_00000000001731849926_3115858369", "isim/top_tb_isim_beh.exe.sim/work/m_00000000001731849926_3115858369.didat");
	xsi_register_executes(pe);
}
