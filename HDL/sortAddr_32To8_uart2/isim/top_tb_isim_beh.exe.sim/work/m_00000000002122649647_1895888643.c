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
static const char *ng0 = "C:/Users/HRUSHIKESH/Desktop/proj/sortAddr_32To8_uart2/UART_tx.v";
static int ng1[] = {1, 0};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {0U, 0U};
static unsigned int ng4[] = {1U, 0U};
static unsigned int ng5[] = {15U, 0U};



static void Initial_27_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(28, ng0);

LAB2:    xsi_set_current_line(29, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);
    xsi_set_current_line(30, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 4120);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 8, 0LL);

LAB1:    return;
}

static void Always_36_1(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 5448U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 7008);
    *((int *)t2) = 1;
    t3 = (t0 + 5480);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(37, ng0);

LAB5:    xsi_set_current_line(38, ng0);
    t5 = (t0 + 1480U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t6 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t5) == 0)
        goto LAB6;

LAB8:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;

LAB9:    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t4);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 3160);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 3000);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);

LAB12:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(38, ng0);
    t19 = ((char*)((ng3)));
    t20 = (t0 + 3000);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 1, 0LL);
    goto LAB12;

}

static void Always_52_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;

LAB0:    t1 = (t0 + 5696U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 7024);
    *((int *)t2) = 1;
    t3 = (t0 + 5728);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(53, ng0);

LAB5:    xsi_set_current_line(54, ng0);
    t4 = (t0 + 3000);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 1, t7, 1);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 1, t2, 1);
    if (t8 == 1)
        goto LAB9;

LAB10:
LAB12:
LAB11:    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3160);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB13:    goto LAB2;

LAB7:    xsi_set_current_line(55, ng0);
    t9 = (t0 + 2280U);
    t10 = *((char **)t9);
    t9 = (t10 + 4);
    t11 = *((unsigned int *)t9);
    t12 = (~(t11));
    t13 = *((unsigned int *)t10);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3160);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB16:    goto LAB13;

LAB9:    xsi_set_current_line(57, ng0);
    t3 = (t0 + 2840);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 4);
    t11 = *((unsigned int *)t7);
    t12 = (~(t11));
    t13 = *((unsigned int *)t5);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB17;

LAB18:    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3160);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB19:    goto LAB13;

LAB14:    xsi_set_current_line(55, ng0);
    t16 = ((char*)((ng4)));
    t17 = (t0 + 3160);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 1);
    goto LAB16;

LAB17:    xsi_set_current_line(57, ng0);
    t9 = ((char*)((ng3)));
    t10 = (t0 + 3160);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 1);
    goto LAB19;

}

static void Always_68_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 5944U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 7040);
    *((int *)t2) = 1;
    t3 = (t0 + 5976);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(69, ng0);

LAB5:    xsi_set_current_line(70, ng0);
    t4 = (t0 + 3000);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 1, t7, 1);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 1, t2, 1);
    if (t8 == 1)
        goto LAB9;

LAB10:
LAB11:    goto LAB2;

LAB7:    xsi_set_current_line(71, ng0);

LAB12:    xsi_set_current_line(72, ng0);
    t9 = ((char*)((ng4)));
    t10 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 1, 0LL);
    goto LAB11;

LAB9:    xsi_set_current_line(75, ng0);

LAB13:    xsi_set_current_line(76, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB11;

}

static void Always_95_4(char *t0)
{
    char t4[8];
    char t23[8];
    char t65[8];
    char t70[8];
    char t71[8];
    char t75[8];
    char t113[8];
    char t114[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
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
    int t40;
    int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    char *t64;
    char *t66;
    char *t67;
    char *t68;
    char *t69;
    char *t72;
    char *t73;
    char *t74;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;
    char *t80;
    char *t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    int t99;
    int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    char *t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    char *t115;
    char *t116;
    char *t117;
    char *t118;
    char *t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    char *t126;
    char *t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;

LAB0:    t1 = (t0 + 6192U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(95, ng0);
    t2 = (t0 + 7056);
    *((int *)t2) = 1;
    t3 = (t0 + 6224);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(96, ng0);

LAB5:    xsi_set_current_line(98, ng0);
    t5 = (t0 + 3320);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t4, 0, 8);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    t14 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t14) = 1;

LAB9:    t15 = (t4 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t4);
    t19 = (t18 & t17);
    t20 = (t19 != 0);
    if (t20 > 0)
        goto LAB10;

LAB11:
LAB12:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t5 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB14;

LAB15:
LAB16:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(99, ng0);

LAB13:    xsi_set_current_line(100, ng0);
    t21 = ((char*)((ng3)));
    t22 = (t0 + 2840);
    xsi_vlogvar_wait_assign_value(t22, t21, 0, 0, 1, 0LL);
    xsi_set_current_line(101, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(102, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3640);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB12;

LAB14:    xsi_set_current_line(106, ng0);

LAB17:    xsi_set_current_line(107, ng0);
    t7 = (t0 + 3960);
    t8 = (t7 + 56U);
    t14 = *((char **)t8);
    t15 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_unsigned_add(t4, 32, t14, 4, t15, 32);
    t21 = (t0 + 3960);
    xsi_vlogvar_wait_assign_value(t21, t4, 0, 0, 4, 0LL);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 3480);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 3640);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t4, 0, 8);
    t14 = (t8 + 4);
    t9 = *((unsigned int *)t14);
    t10 = (~(t9));
    t11 = *((unsigned int *)t8);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB21;

LAB19:    if (*((unsigned int *)t14) == 0)
        goto LAB18;

LAB20:    t15 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t15) = 1;

LAB21:    t16 = *((unsigned int *)t5);
    t17 = *((unsigned int *)t4);
    t18 = (t16 & t17);
    *((unsigned int *)t23) = t18;
    t21 = (t5 + 4);
    t22 = (t4 + 4);
    t24 = (t23 + 4);
    t19 = *((unsigned int *)t21);
    t20 = *((unsigned int *)t22);
    t25 = (t19 | t20);
    *((unsigned int *)t24) = t25;
    t26 = *((unsigned int *)t24);
    t27 = (t26 != 0);
    if (t27 == 1)
        goto LAB22;

LAB23:
LAB24:    t48 = (t23 + 4);
    t49 = *((unsigned int *)t48);
    t50 = (~(t49));
    t51 = *((unsigned int *)t23);
    t52 = (t51 & t50);
    t53 = (t52 != 0);
    if (t53 > 0)
        goto LAB25;

LAB26:
LAB27:    xsi_set_current_line(116, ng0);
    t2 = (t0 + 3960);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t7 = (t5 + 4);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t6);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t16 = (t12 ^ t13);
    t17 = (t11 | t16);
    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t8);
    t20 = (t18 | t19);
    t25 = (~(t20));
    t26 = (t17 & t25);
    if (t26 != 0)
        goto LAB32;

LAB29:    if (t20 != 0)
        goto LAB31;

LAB30:    *((unsigned int *)t4) = 1;

LAB32:    t15 = (t0 + 3480);
    t21 = (t15 + 56U);
    t22 = *((char **)t21);
    t27 = *((unsigned int *)t4);
    t28 = *((unsigned int *)t22);
    t29 = (t27 & t28);
    *((unsigned int *)t23) = t29;
    t24 = (t4 + 4);
    t30 = (t22 + 4);
    t31 = (t23 + 4);
    t32 = *((unsigned int *)t24);
    t33 = *((unsigned int *)t30);
    t34 = (t32 | t33);
    *((unsigned int *)t31) = t34;
    t35 = *((unsigned int *)t31);
    t36 = (t35 != 0);
    if (t36 == 1)
        goto LAB33;

LAB34:
LAB35:    t55 = (t23 + 4);
    t58 = *((unsigned int *)t55);
    t59 = (~(t58));
    t60 = *((unsigned int *)t23);
    t61 = (t60 & t59);
    t62 = (t61 != 0);
    if (t62 > 0)
        goto LAB36;

LAB37:
LAB38:    xsi_set_current_line(123, ng0);
    t2 = (t0 + 3960);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t7 = (t5 + 4);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t6);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t16 = (t12 ^ t13);
    t17 = (t11 | t16);
    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t8);
    t20 = (t18 | t19);
    t25 = (~(t20));
    t26 = (t17 & t25);
    if (t26 != 0)
        goto LAB43;

LAB40:    if (t20 != 0)
        goto LAB42;

LAB41:    *((unsigned int *)t4) = 1;

LAB43:    t15 = (t0 + 3480);
    t21 = (t15 + 56U);
    t22 = *((char **)t21);
    memset(t23, 0, 8);
    t24 = (t22 + 4);
    t27 = *((unsigned int *)t24);
    t28 = (~(t27));
    t29 = *((unsigned int *)t22);
    t32 = (t29 & t28);
    t33 = (t32 & 1U);
    if (t33 != 0)
        goto LAB47;

LAB45:    if (*((unsigned int *)t24) == 0)
        goto LAB44;

LAB46:    t30 = (t23 + 4);
    *((unsigned int *)t23) = 1;
    *((unsigned int *)t30) = 1;

LAB47:    t34 = *((unsigned int *)t4);
    t35 = *((unsigned int *)t23);
    t36 = (t34 & t35);
    *((unsigned int *)t65) = t36;
    t31 = (t4 + 4);
    t48 = (t23 + 4);
    t54 = (t65 + 4);
    t37 = *((unsigned int *)t31);
    t38 = *((unsigned int *)t48);
    t39 = (t37 | t38);
    *((unsigned int *)t54) = t39;
    t42 = *((unsigned int *)t54);
    t43 = (t42 != 0);
    if (t43 == 1)
        goto LAB48;

LAB49:
LAB50:    t64 = (t0 + 3800);
    t66 = (t64 + 56U);
    t67 = *((char **)t66);
    t68 = (t0 + 1960U);
    t69 = *((char **)t68);
    t68 = ((char*)((ng1)));
    memset(t70, 0, 8);
    xsi_vlog_unsigned_minus(t70, 32, t69, 4, t68, 32);
    memset(t71, 0, 8);
    t72 = (t67 + 4);
    if (*((unsigned int *)t72) != 0)
        goto LAB52;

LAB51:    t73 = (t70 + 4);
    if (*((unsigned int *)t73) != 0)
        goto LAB52;

LAB55:    if (*((unsigned int *)t67) < *((unsigned int *)t70))
        goto LAB53;

LAB54:    t76 = *((unsigned int *)t65);
    t77 = *((unsigned int *)t71);
    t78 = (t76 & t77);
    *((unsigned int *)t75) = t78;
    t79 = (t65 + 4);
    t80 = (t71 + 4);
    t81 = (t75 + 4);
    t82 = *((unsigned int *)t79);
    t83 = *((unsigned int *)t80);
    t84 = (t82 | t83);
    *((unsigned int *)t81) = t84;
    t85 = *((unsigned int *)t81);
    t86 = (t85 != 0);
    if (t86 == 1)
        goto LAB56;

LAB57:
LAB58:    t107 = (t75 + 4);
    t108 = *((unsigned int *)t107);
    t109 = (~(t108));
    t110 = *((unsigned int *)t75);
    t111 = (t110 & t109);
    t112 = (t111 != 0);
    if (t112 > 0)
        goto LAB59;

LAB60:
LAB61:    xsi_set_current_line(132, ng0);
    t2 = (t0 + 3960);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t7 = (t5 + 4);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t6);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t16 = (t12 ^ t13);
    t17 = (t11 | t16);
    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t8);
    t20 = (t18 | t19);
    t25 = (~(t20));
    t26 = (t17 & t25);
    if (t26 != 0)
        goto LAB66;

LAB63:    if (t20 != 0)
        goto LAB65;

LAB64:    *((unsigned int *)t4) = 1;

LAB66:    t15 = (t0 + 3800);
    t21 = (t15 + 56U);
    t22 = *((char **)t21);
    t24 = (t0 + 1960U);
    t30 = *((char **)t24);
    t24 = ((char*)((ng1)));
    memset(t23, 0, 8);
    xsi_vlog_unsigned_minus(t23, 32, t30, 4, t24, 32);
    memset(t65, 0, 8);
    t31 = (t22 + 4);
    t48 = (t23 + 4);
    t27 = *((unsigned int *)t22);
    t28 = *((unsigned int *)t23);
    t29 = (t27 ^ t28);
    t32 = *((unsigned int *)t31);
    t33 = *((unsigned int *)t48);
    t34 = (t32 ^ t33);
    t35 = (t29 | t34);
    t36 = *((unsigned int *)t31);
    t37 = *((unsigned int *)t48);
    t38 = (t36 | t37);
    t39 = (~(t38));
    t42 = (t35 & t39);
    if (t42 != 0)
        goto LAB70;

LAB67:    if (t38 != 0)
        goto LAB69;

LAB68:    *((unsigned int *)t65) = 1;

LAB70:    t43 = *((unsigned int *)t4);
    t44 = *((unsigned int *)t65);
    t45 = (t43 & t44);
    *((unsigned int *)t70) = t45;
    t55 = (t4 + 4);
    t63 = (t65 + 4);
    t64 = (t70 + 4);
    t46 = *((unsigned int *)t55);
    t47 = *((unsigned int *)t63);
    t49 = (t46 | t47);
    *((unsigned int *)t64) = t49;
    t50 = *((unsigned int *)t64);
    t51 = (t50 != 0);
    if (t51 == 1)
        goto LAB71;

LAB72:
LAB73:    t68 = (t0 + 3640);
    t69 = (t68 + 56U);
    t72 = *((char **)t69);
    memset(t71, 0, 8);
    t73 = (t72 + 4);
    t86 = *((unsigned int *)t73);
    t87 = (~(t86));
    t88 = *((unsigned int *)t72);
    t91 = (t88 & t87);
    t92 = (t91 & 1U);
    if (t92 != 0)
        goto LAB77;

LAB75:    if (*((unsigned int *)t73) == 0)
        goto LAB74;

LAB76:    t74 = (t71 + 4);
    *((unsigned int *)t71) = 1;
    *((unsigned int *)t74) = 1;

LAB77:    t93 = *((unsigned int *)t70);
    t94 = *((unsigned int *)t71);
    t95 = (t93 & t94);
    *((unsigned int *)t75) = t95;
    t79 = (t70 + 4);
    t80 = (t71 + 4);
    t81 = (t75 + 4);
    t96 = *((unsigned int *)t79);
    t97 = *((unsigned int *)t80);
    t98 = (t96 | t97);
    *((unsigned int *)t81) = t98;
    t101 = *((unsigned int *)t81);
    t102 = (t101 != 0);
    if (t102 == 1)
        goto LAB78;

LAB79:
LAB80:    t107 = (t75 + 4);
    t129 = *((unsigned int *)t107);
    t130 = (~(t129));
    t131 = *((unsigned int *)t75);
    t132 = (t131 & t130);
    t133 = (t132 != 0);
    if (t133 > 0)
        goto LAB81;

LAB82:
LAB83:    xsi_set_current_line(139, ng0);
    t2 = (t0 + 3960);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t7 = (t5 + 4);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t6);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t16 = (t12 ^ t13);
    t17 = (t11 | t16);
    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t8);
    t20 = (t18 | t19);
    t25 = (~(t20));
    t26 = (t17 & t25);
    if (t26 != 0)
        goto LAB88;

LAB85:    if (t20 != 0)
        goto LAB87;

LAB86:    *((unsigned int *)t4) = 1;

LAB88:    t15 = (t0 + 3800);
    t21 = (t15 + 56U);
    t22 = *((char **)t21);
    t24 = (t0 + 1960U);
    t30 = *((char **)t24);
    t24 = ((char*)((ng1)));
    memset(t23, 0, 8);
    xsi_vlog_unsigned_minus(t23, 32, t30, 4, t24, 32);
    memset(t65, 0, 8);
    t31 = (t22 + 4);
    t48 = (t23 + 4);
    t27 = *((unsigned int *)t22);
    t28 = *((unsigned int *)t23);
    t29 = (t27 ^ t28);
    t32 = *((unsigned int *)t31);
    t33 = *((unsigned int *)t48);
    t34 = (t32 ^ t33);
    t35 = (t29 | t34);
    t36 = *((unsigned int *)t31);
    t37 = *((unsigned int *)t48);
    t38 = (t36 | t37);
    t39 = (~(t38));
    t42 = (t35 & t39);
    if (t42 != 0)
        goto LAB92;

LAB89:    if (t38 != 0)
        goto LAB91;

LAB90:    *((unsigned int *)t65) = 1;

LAB92:    t43 = *((unsigned int *)t4);
    t44 = *((unsigned int *)t65);
    t45 = (t43 & t44);
    *((unsigned int *)t70) = t45;
    t55 = (t4 + 4);
    t63 = (t65 + 4);
    t64 = (t70 + 4);
    t46 = *((unsigned int *)t55);
    t47 = *((unsigned int *)t63);
    t49 = (t46 | t47);
    *((unsigned int *)t64) = t49;
    t50 = *((unsigned int *)t64);
    t51 = (t50 != 0);
    if (t51 == 1)
        goto LAB93;

LAB94:
LAB95:    t68 = (t0 + 3640);
    t69 = (t68 + 56U);
    t72 = *((char **)t69);
    t86 = *((unsigned int *)t70);
    t87 = *((unsigned int *)t72);
    t88 = (t86 & t87);
    *((unsigned int *)t71) = t88;
    t73 = (t70 + 4);
    t74 = (t72 + 4);
    t79 = (t71 + 4);
    t91 = *((unsigned int *)t73);
    t92 = *((unsigned int *)t74);
    t93 = (t91 | t92);
    *((unsigned int *)t79) = t93;
    t94 = *((unsigned int *)t79);
    t95 = (t94 != 0);
    if (t95 == 1)
        goto LAB96;

LAB97:
LAB98:    t89 = (t71 + 4);
    t122 = *((unsigned int *)t89);
    t123 = (~(t122));
    t124 = *((unsigned int *)t71);
    t125 = (t124 & t123);
    t128 = (t125 != 0);
    if (t128 > 0)
        goto LAB99;

LAB100:
LAB101:    goto LAB16;

LAB18:    *((unsigned int *)t4) = 1;
    goto LAB21;

LAB22:    t28 = *((unsigned int *)t23);
    t29 = *((unsigned int *)t24);
    *((unsigned int *)t23) = (t28 | t29);
    t30 = (t5 + 4);
    t31 = (t4 + 4);
    t32 = *((unsigned int *)t5);
    t33 = (~(t32));
    t34 = *((unsigned int *)t30);
    t35 = (~(t34));
    t36 = *((unsigned int *)t4);
    t37 = (~(t36));
    t38 = *((unsigned int *)t31);
    t39 = (~(t38));
    t40 = (t33 & t35);
    t41 = (t37 & t39);
    t42 = (~(t40));
    t43 = (~(t41));
    t44 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t44 & t42);
    t45 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t45 & t43);
    t46 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t46 & t42);
    t47 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t47 & t43);
    goto LAB24;

LAB25:    xsi_set_current_line(111, ng0);

LAB28:    xsi_set_current_line(112, ng0);
    t54 = ((char*)((ng3)));
    t55 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t55, t54, 0, 0, 1, 0LL);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = (t0 + 4120);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    goto LAB27;

LAB31:    t14 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB32;

LAB33:    t37 = *((unsigned int *)t23);
    t38 = *((unsigned int *)t31);
    *((unsigned int *)t23) = (t37 | t38);
    t48 = (t4 + 4);
    t54 = (t22 + 4);
    t39 = *((unsigned int *)t4);
    t42 = (~(t39));
    t43 = *((unsigned int *)t48);
    t44 = (~(t43));
    t45 = *((unsigned int *)t22);
    t46 = (~(t45));
    t47 = *((unsigned int *)t54);
    t49 = (~(t47));
    t40 = (t42 & t44);
    t41 = (t46 & t49);
    t50 = (~(t40));
    t51 = (~(t41));
    t52 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t52 & t50);
    t53 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t53 & t51);
    t56 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t56 & t50);
    t57 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t57 & t51);
    goto LAB35;

LAB36:    xsi_set_current_line(117, ng0);

LAB39:    xsi_set_current_line(118, ng0);
    t63 = ((char*)((ng3)));
    t64 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t64, t63, 0, 0, 1, 0LL);
    xsi_set_current_line(119, ng0);
    t2 = (t0 + 4120);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    memset(t23, 0, 8);
    t6 = (t23 + 4);
    t7 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 1);
    *((unsigned int *)t23) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 1);
    *((unsigned int *)t6) = t12;
    t13 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t13 & 127U);
    t16 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t16 & 127U);
    t8 = ((char*)((ng3)));
    xsi_vlogtype_concat(t4, 8, 8, 2U, t8, 1, t23, 7);
    t14 = (t0 + 4120);
    xsi_vlogvar_wait_assign_value(t14, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(120, ng0);
    t2 = (t0 + 4120);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    memset(t4, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t4) = t11;
    t12 = *((unsigned int *)t7);
    t13 = (t12 >> 0);
    t16 = (t13 & 1);
    *((unsigned int *)t6) = t16;
    t8 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t8, t4, 0, 0, 1, 0LL);
    goto LAB38;

LAB42:    t14 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB43;

LAB44:    *((unsigned int *)t23) = 1;
    goto LAB47;

LAB48:    t44 = *((unsigned int *)t65);
    t45 = *((unsigned int *)t54);
    *((unsigned int *)t65) = (t44 | t45);
    t55 = (t4 + 4);
    t63 = (t23 + 4);
    t46 = *((unsigned int *)t4);
    t47 = (~(t46));
    t49 = *((unsigned int *)t55);
    t50 = (~(t49));
    t51 = *((unsigned int *)t23);
    t52 = (~(t51));
    t53 = *((unsigned int *)t63);
    t56 = (~(t53));
    t40 = (t47 & t50);
    t41 = (t52 & t56);
    t57 = (~(t40));
    t58 = (~(t41));
    t59 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t59 & t57);
    t60 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t60 & t58);
    t61 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t61 & t57);
    t62 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t62 & t58);
    goto LAB50;

LAB52:    t74 = (t71 + 4);
    *((unsigned int *)t71) = 1;
    *((unsigned int *)t74) = 1;
    goto LAB54;

LAB53:    *((unsigned int *)t71) = 1;
    goto LAB54;

LAB56:    t87 = *((unsigned int *)t75);
    t88 = *((unsigned int *)t81);
    *((unsigned int *)t75) = (t87 | t88);
    t89 = (t65 + 4);
    t90 = (t71 + 4);
    t91 = *((unsigned int *)t65);
    t92 = (~(t91));
    t93 = *((unsigned int *)t89);
    t94 = (~(t93));
    t95 = *((unsigned int *)t71);
    t96 = (~(t95));
    t97 = *((unsigned int *)t90);
    t98 = (~(t97));
    t99 = (t92 & t94);
    t100 = (t96 & t98);
    t101 = (~(t99));
    t102 = (~(t100));
    t103 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t103 & t101);
    t104 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t104 & t102);
    t105 = *((unsigned int *)t75);
    *((unsigned int *)t75) = (t105 & t101);
    t106 = *((unsigned int *)t75);
    *((unsigned int *)t75) = (t106 & t102);
    goto LAB58;

LAB59:    xsi_set_current_line(124, ng0);

LAB62:    xsi_set_current_line(125, ng0);
    t115 = (t0 + 4120);
    t116 = (t115 + 56U);
    t117 = *((char **)t116);
    memset(t114, 0, 8);
    t118 = (t114 + 4);
    t119 = (t117 + 4);
    t120 = *((unsigned int *)t117);
    t121 = (t120 >> 1);
    *((unsigned int *)t114) = t121;
    t122 = *((unsigned int *)t119);
    t123 = (t122 >> 1);
    *((unsigned int *)t118) = t123;
    t124 = *((unsigned int *)t114);
    *((unsigned int *)t114) = (t124 & 127U);
    t125 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t125 & 127U);
    t126 = ((char*)((ng3)));
    xsi_vlogtype_concat(t113, 8, 8, 2U, t126, 1, t114, 7);
    t127 = (t0 + 4120);
    xsi_vlogvar_wait_assign_value(t127, t113, 0, 0, 8, 0LL);
    xsi_set_current_line(126, ng0);
    t2 = (t0 + 3800);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng1)));
    memset(t4, 0, 8);
    xsi_vlog_unsigned_add(t4, 32, t5, 5, t6, 32);
    t7 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t7, t4, 0, 0, 5, 0LL);
    xsi_set_current_line(127, ng0);
    t2 = (t0 + 4120);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    memset(t4, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t4) = t11;
    t12 = *((unsigned int *)t7);
    t13 = (t12 >> 0);
    t16 = (t13 & 1);
    *((unsigned int *)t6) = t16;
    t8 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t8, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(128, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(129, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3960);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    goto LAB61;

LAB65:    t14 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB66;

LAB69:    t54 = (t65 + 4);
    *((unsigned int *)t65) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB70;

LAB71:    t52 = *((unsigned int *)t70);
    t53 = *((unsigned int *)t64);
    *((unsigned int *)t70) = (t52 | t53);
    t66 = (t4 + 4);
    t67 = (t65 + 4);
    t56 = *((unsigned int *)t4);
    t57 = (~(t56));
    t58 = *((unsigned int *)t66);
    t59 = (~(t58));
    t60 = *((unsigned int *)t65);
    t61 = (~(t60));
    t62 = *((unsigned int *)t67);
    t76 = (~(t62));
    t40 = (t57 & t59);
    t41 = (t61 & t76);
    t77 = (~(t40));
    t78 = (~(t41));
    t82 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t82 & t77);
    t83 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t83 & t78);
    t84 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t84 & t77);
    t85 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t85 & t78);
    goto LAB73;

LAB74:    *((unsigned int *)t71) = 1;
    goto LAB77;

LAB78:    t103 = *((unsigned int *)t75);
    t104 = *((unsigned int *)t81);
    *((unsigned int *)t75) = (t103 | t104);
    t89 = (t70 + 4);
    t90 = (t71 + 4);
    t105 = *((unsigned int *)t70);
    t106 = (~(t105));
    t108 = *((unsigned int *)t89);
    t109 = (~(t108));
    t110 = *((unsigned int *)t71);
    t111 = (~(t110));
    t112 = *((unsigned int *)t90);
    t120 = (~(t112));
    t99 = (t106 & t109);
    t100 = (t111 & t120);
    t121 = (~(t99));
    t122 = (~(t100));
    t123 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t123 & t121);
    t124 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t124 & t122);
    t125 = *((unsigned int *)t75);
    *((unsigned int *)t75) = (t125 & t121);
    t128 = *((unsigned int *)t75);
    *((unsigned int *)t75) = (t128 & t122);
    goto LAB80;

LAB81:    xsi_set_current_line(133, ng0);

LAB84:    xsi_set_current_line(134, ng0);
    t115 = ((char*)((ng4)));
    t116 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t116, t115, 0, 0, 1, 0LL);
    xsi_set_current_line(135, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3960);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3640);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB83;

LAB87:    t14 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB88;

LAB91:    t54 = (t65 + 4);
    *((unsigned int *)t65) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB92;

LAB93:    t52 = *((unsigned int *)t70);
    t53 = *((unsigned int *)t64);
    *((unsigned int *)t70) = (t52 | t53);
    t66 = (t4 + 4);
    t67 = (t65 + 4);
    t56 = *((unsigned int *)t4);
    t57 = (~(t56));
    t58 = *((unsigned int *)t66);
    t59 = (~(t58));
    t60 = *((unsigned int *)t65);
    t61 = (~(t60));
    t62 = *((unsigned int *)t67);
    t76 = (~(t62));
    t40 = (t57 & t59);
    t41 = (t61 & t76);
    t77 = (~(t40));
    t78 = (~(t41));
    t82 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t82 & t77);
    t83 = *((unsigned int *)t64);
    *((unsigned int *)t64) = (t83 & t78);
    t84 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t84 & t77);
    t85 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t85 & t78);
    goto LAB95;

LAB96:    t96 = *((unsigned int *)t71);
    t97 = *((unsigned int *)t79);
    *((unsigned int *)t71) = (t96 | t97);
    t80 = (t70 + 4);
    t81 = (t72 + 4);
    t98 = *((unsigned int *)t70);
    t101 = (~(t98));
    t102 = *((unsigned int *)t80);
    t103 = (~(t102));
    t104 = *((unsigned int *)t72);
    t105 = (~(t104));
    t106 = *((unsigned int *)t81);
    t108 = (~(t106));
    t99 = (t101 & t103);
    t100 = (t105 & t108);
    t109 = (~(t99));
    t110 = (~(t100));
    t111 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t111 & t109);
    t112 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t112 & t110);
    t120 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t120 & t109);
    t121 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t121 & t110);
    goto LAB98;

LAB99:    xsi_set_current_line(140, ng0);

LAB102:    xsi_set_current_line(141, ng0);
    t90 = ((char*)((ng3)));
    t107 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t107, t90, 0, 0, 5, 0LL);
    xsi_set_current_line(142, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2840);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(143, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3960);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    goto LAB101;

}

static void Always_160_5(char *t0)
{
    char t4[8];
    char t21[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 6440U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(160, ng0);
    t2 = (t0 + 7072);
    *((int *)t2) = 1;
    t3 = (t0 + 6472);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(161, ng0);

LAB5:    xsi_set_current_line(163, ng0);
    t5 = (t0 + 1480U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t6 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t5) == 0)
        goto LAB6;

LAB8:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;

LAB9:    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t4);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(169, ng0);

LAB14:    xsi_set_current_line(170, ng0);
    t2 = (t0 + 1640U);
    t3 = *((char **)t2);
    t2 = (t0 + 4280);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t21, 0, 8);
    t12 = (t21 + 4);
    t13 = (t6 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (t7 >> 0);
    t9 = (t8 & 1);
    *((unsigned int *)t21) = t9;
    t10 = *((unsigned int *)t13);
    t11 = (t10 >> 0);
    t14 = (t11 & 1);
    *((unsigned int *)t12) = t14;
    xsi_vlogtype_concat(t4, 2, 2, 2U, t21, 1, t3, 1);
    t19 = (t0 + 4280);
    xsi_vlogvar_wait_assign_value(t19, t4, 0, 0, 2, 0LL);

LAB12:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(164, ng0);

LAB13:    xsi_set_current_line(165, ng0);
    t19 = ((char*)((ng3)));
    t20 = (t0 + 4280);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 2, 0LL);
    goto LAB12;

}

static void Cont_174_6(char *t0)
{
    char t3[8];
    char t6[8];
    char t25[8];
    char t34[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    int t58;
    int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    char *t67;
    char *t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;

LAB0:    t1 = (t0 + 6688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(174, ng0);
    t2 = (t0 + 4280);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t7 = (t6 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 1);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 1);
    t14 = (t13 & 1);
    *((unsigned int *)t7) = t14;
    memset(t3, 0, 8);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t6);
    t19 = (t18 & t17);
    t20 = (t19 & 1U);
    if (t20 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t15) == 0)
        goto LAB4;

LAB6:    t21 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t21) = 1;

LAB7:    t22 = (t0 + 4280);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    memset(t25, 0, 8);
    t26 = (t25 + 4);
    t27 = (t24 + 4);
    t28 = *((unsigned int *)t24);
    t29 = (t28 >> 0);
    t30 = (t29 & 1);
    *((unsigned int *)t25) = t30;
    t31 = *((unsigned int *)t27);
    t32 = (t31 >> 0);
    t33 = (t32 & 1);
    *((unsigned int *)t26) = t33;
    t35 = *((unsigned int *)t3);
    t36 = *((unsigned int *)t25);
    t37 = (t35 & t36);
    *((unsigned int *)t34) = t37;
    t38 = (t3 + 4);
    t39 = (t25 + 4);
    t40 = (t34 + 4);
    t41 = *((unsigned int *)t38);
    t42 = *((unsigned int *)t39);
    t43 = (t41 | t42);
    *((unsigned int *)t40) = t43;
    t44 = *((unsigned int *)t40);
    t45 = (t44 != 0);
    if (t45 == 1)
        goto LAB8;

LAB9:
LAB10:    t66 = (t0 + 7168);
    t67 = (t66 + 56U);
    t68 = *((char **)t67);
    t69 = (t68 + 56U);
    t70 = *((char **)t69);
    memset(t70, 0, 8);
    t71 = 1U;
    t72 = t71;
    t73 = (t34 + 4);
    t74 = *((unsigned int *)t34);
    t71 = (t71 & t74);
    t75 = *((unsigned int *)t73);
    t72 = (t72 & t75);
    t76 = (t70 + 4);
    t77 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t77 | t71);
    t78 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t78 | t72);
    xsi_driver_vfirst_trans(t66, 0, 0);
    t79 = (t0 + 7088);
    *((int *)t79) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB8:    t46 = *((unsigned int *)t34);
    t47 = *((unsigned int *)t40);
    *((unsigned int *)t34) = (t46 | t47);
    t48 = (t3 + 4);
    t49 = (t25 + 4);
    t50 = *((unsigned int *)t3);
    t51 = (~(t50));
    t52 = *((unsigned int *)t48);
    t53 = (~(t52));
    t54 = *((unsigned int *)t25);
    t55 = (~(t54));
    t56 = *((unsigned int *)t49);
    t57 = (~(t56));
    t58 = (t51 & t53);
    t59 = (t55 & t57);
    t60 = (~(t58));
    t61 = (~(t59));
    t62 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t62 & t60);
    t63 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t63 & t61);
    t64 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t64 & t60);
    t65 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t65 & t61);
    goto LAB10;

}


extern void work_m_00000000002122649647_1895888643_init()
{
	static char *pe[] = {(void *)Initial_27_0,(void *)Always_36_1,(void *)Always_52_2,(void *)Always_68_3,(void *)Always_95_4,(void *)Always_160_5,(void *)Cont_174_6};
	xsi_register_didat("work_m_00000000002122649647_1895888643", "isim/top_tb_isim_beh.exe.sim/work/m_00000000002122649647_1895888643.didat");
	xsi_register_executes(pe);
}
