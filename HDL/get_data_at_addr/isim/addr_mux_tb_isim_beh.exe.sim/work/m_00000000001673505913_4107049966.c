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
static const char *ng0 = "C:/Users/HRUSHIKESH/Desktop/proj/get_data_at_addr/addr_mux_tb.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static int ng3[] = {3, 0};
static int ng4[] = {2, 0};
static int ng5[] = {4, 0};
static int ng6[] = {5, 0};
static int ng7[] = {6, 0};
static int ng8[] = {7, 0};
static int ng9[] = {8, 0};
static int ng10[] = {100, 0};
static int ng11[] = {10, 0};
static unsigned int ng12[] = {32U, 0U};



static void Initial_70_0(char *t0)
{
    char t19[8];
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
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;

LAB0:    t1 = (t0 + 4928U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(70, ng0);

LAB4:    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(86, ng0);
    t2 = (t0 + 4736);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 7264);
    *((int *)t8) = t7;

LAB6:    t9 = (t0 + 7264);
    if (*((int *)t9) > 0)
        goto LAB7;

LAB8:    goto LAB1;

LAB7:    xsi_set_current_line(91, ng0);

LAB9:    xsi_set_current_line(92, ng0);
    t10 = ((char*)((ng10)));
    t11 = (t10 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (~(t12));
    t14 = *((unsigned int *)t10);
    t15 = (t14 & t13);
    t16 = (t0 + 7268);
    *((int *)t16) = t15;

LAB10:    t17 = (t0 + 7268);
    if (*((int *)t17) > 0)
        goto LAB11;

LAB12:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 4008);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = (t0 + 2568);
    xsi_vlogvar_assign_value(t9, t8, 0, 0, 8);
    xsi_set_current_line(95, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(96, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 7272);
    *((int *)t8) = t7;

LAB20:    t9 = (t0 + 7272);
    if (*((int *)t9) > 0)
        goto LAB21;

LAB22:    xsi_set_current_line(98, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(99, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 7276);
    *((int *)t8) = t7;

LAB30:    t9 = (t0 + 7276);
    if (*((int *)t9) > 0)
        goto LAB31;

LAB32:    xsi_set_current_line(101, ng0);
    t2 = (t0 + 4008);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng12)));
    memset(t19, 0, 8);
    xsi_vlog_unsigned_add(t19, 32, t8, 32, t9, 32);
    t10 = (t0 + 4008);
    xsi_vlogvar_assign_value(t10, t19, 0, 0, 32);
    t2 = (t0 + 7264);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB6;

LAB11:    xsi_set_current_line(93, ng0);
    t18 = (t0 + 4736);
    xsi_process_wait(t18, 1000LL);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB13:    xsi_set_current_line(93, ng0);
    t20 = (t0 + 2088);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    memset(t19, 0, 8);
    t23 = (t22 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t22);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB17;

LAB15:    if (*((unsigned int *)t23) == 0)
        goto LAB14;

LAB16:    t29 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t29) = 1;

LAB17:    t30 = (t19 + 4);
    t31 = (t22 + 4);
    t32 = *((unsigned int *)t22);
    t33 = (~(t32));
    *((unsigned int *)t19) = t33;
    *((unsigned int *)t30) = 0;
    if (*((unsigned int *)t31) != 0)
        goto LAB19;

LAB18:    t38 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t38 & 1U);
    t39 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t39 & 1U);
    t40 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t40, t19, 0, 0, 1, 0LL);
    t2 = (t0 + 7268);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB10;

LAB14:    *((unsigned int *)t19) = 1;
    goto LAB17;

LAB19:    t34 = *((unsigned int *)t19);
    t35 = *((unsigned int *)t31);
    *((unsigned int *)t19) = (t34 | t35);
    t36 = *((unsigned int *)t30);
    t37 = *((unsigned int *)t31);
    *((unsigned int *)t30) = (t36 | t37);
    goto LAB18;

LAB21:    xsi_set_current_line(97, ng0);
    t10 = (t0 + 4736);
    xsi_process_wait(t10, 1000LL);
    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB23:    xsi_set_current_line(97, ng0);
    t11 = (t0 + 2088);
    t16 = (t11 + 56U);
    t17 = *((char **)t16);
    memset(t19, 0, 8);
    t18 = (t17 + 4);
    t12 = *((unsigned int *)t18);
    t13 = (~(t12));
    t14 = *((unsigned int *)t17);
    t24 = (t14 & t13);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB27;

LAB25:    if (*((unsigned int *)t18) == 0)
        goto LAB24;

LAB26:    t20 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t20) = 1;

LAB27:    t21 = (t19 + 4);
    t22 = (t17 + 4);
    t26 = *((unsigned int *)t17);
    t27 = (~(t26));
    *((unsigned int *)t19) = t27;
    *((unsigned int *)t21) = 0;
    if (*((unsigned int *)t22) != 0)
        goto LAB29;

LAB28:    t35 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t35 & 1U);
    t36 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t36 & 1U);
    t23 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t23, t19, 0, 0, 1, 0LL);
    t2 = (t0 + 7272);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB20;

LAB24:    *((unsigned int *)t19) = 1;
    goto LAB27;

LAB29:    t28 = *((unsigned int *)t19);
    t32 = *((unsigned int *)t22);
    *((unsigned int *)t19) = (t28 | t32);
    t33 = *((unsigned int *)t21);
    t34 = *((unsigned int *)t22);
    *((unsigned int *)t21) = (t33 | t34);
    goto LAB28;

LAB31:    xsi_set_current_line(100, ng0);
    t10 = (t0 + 4736);
    xsi_process_wait(t10, 1000LL);
    *((char **)t1) = &&LAB33;
    goto LAB1;

LAB33:    xsi_set_current_line(100, ng0);
    t11 = (t0 + 2088);
    t16 = (t11 + 56U);
    t17 = *((char **)t16);
    memset(t19, 0, 8);
    t18 = (t17 + 4);
    t12 = *((unsigned int *)t18);
    t13 = (~(t12));
    t14 = *((unsigned int *)t17);
    t24 = (t14 & t13);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB37;

LAB35:    if (*((unsigned int *)t18) == 0)
        goto LAB34;

LAB36:    t20 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t20) = 1;

LAB37:    t21 = (t19 + 4);
    t22 = (t17 + 4);
    t26 = *((unsigned int *)t17);
    t27 = (~(t26));
    *((unsigned int *)t19) = t27;
    *((unsigned int *)t21) = 0;
    if (*((unsigned int *)t22) != 0)
        goto LAB39;

LAB38:    t35 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t35 & 1U);
    t36 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t36 & 1U);
    t23 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t23, t19, 0, 0, 1, 0LL);
    t2 = (t0 + 7276);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB30;

LAB34:    *((unsigned int *)t19) = 1;
    goto LAB37;

LAB39:    t28 = *((unsigned int *)t19);
    t32 = *((unsigned int *)t22);
    *((unsigned int *)t19) = (t28 | t32);
    t33 = *((unsigned int *)t21);
    t34 = *((unsigned int *)t22);
    *((unsigned int *)t21) = (t33 | t34);
    goto LAB38;

}


extern void work_m_00000000001673505913_4107049966_init()
{
	static char *pe[] = {(void *)Initial_70_0};
	xsi_register_didat("work_m_00000000001673505913_4107049966", "isim/addr_mux_tb_isim_beh.exe.sim/work/m_00000000001673505913_4107049966.didat");
	xsi_register_executes(pe);
}
