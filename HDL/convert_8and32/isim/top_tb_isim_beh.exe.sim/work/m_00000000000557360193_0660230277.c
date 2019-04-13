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
static const char *ng0 = "C:/Users/HRUSHIKESH/Desktop/proj/convert_8and32/UART_rx.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {8U, 0U};
static unsigned int ng5[] = {15U, 0U};
static unsigned int ng6[] = {7U, 0U};
static unsigned int ng7[] = {6U, 0U};



static void Always_30_0(char *t0)
{
    char t4[8];
    char t20[8];
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
    char *t21;

LAB0:    t1 = (t0 + 4720U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(30, ng0);
    t2 = (t0 + 6032);
    *((int *)t2) = 1;
    t3 = (t0 + 4752);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(31, ng0);

LAB5:    xsi_set_current_line(32, ng0);
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

LAB11:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 3000);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 2840);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 2, 0LL);

LAB12:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(32, ng0);
    t19 = ((char*)((ng1)));
    memcpy(t20, t19, 8);
    t21 = (t0 + 2840);
    xsi_vlogvar_wait_assign_value(t21, t20, 0, 0, 2, 0LL);
    goto LAB12;

}

static void Always_48_1(char *t0)
{
    char t9[8];
    char t20[8];
    char t58[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    int t43;
    int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    char *t59;

LAB0:    t1 = (t0 + 4968U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 6048);
    *((int *)t2) = 1;
    t3 = (t0 + 5000);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(49, ng0);

LAB5:    xsi_set_current_line(50, ng0);
    t4 = (t0 + 2840);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 2, t7, 1);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 2, t2, 1);
    if (t8 == 1)
        goto LAB9;

LAB10:
LAB12:
LAB11:    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng1)));
    memcpy(t9, t2, 8);
    t3 = (t0 + 3000);
    xsi_vlogvar_assign_value(t3, t9, 0, 0, 2);

LAB13:    goto LAB2;

LAB7:    xsi_set_current_line(51, ng0);
    t10 = (t0 + 1800U);
    t11 = *((char **)t10);
    memset(t9, 0, 8);
    t10 = (t11 + 4);
    t12 = *((unsigned int *)t10);
    t13 = (~(t12));
    t14 = *((unsigned int *)t11);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB17;

LAB15:    if (*((unsigned int *)t10) == 0)
        goto LAB14;

LAB16:    t17 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t17) = 1;

LAB17:    t18 = (t0 + 1640U);
    t19 = *((char **)t18);
    t21 = *((unsigned int *)t9);
    t22 = *((unsigned int *)t19);
    t23 = (t21 & t22);
    *((unsigned int *)t20) = t23;
    t18 = (t9 + 4);
    t24 = (t19 + 4);
    t25 = (t20 + 4);
    t26 = *((unsigned int *)t18);
    t27 = *((unsigned int *)t24);
    t28 = (t26 | t27);
    *((unsigned int *)t25) = t28;
    t29 = *((unsigned int *)t25);
    t30 = (t29 != 0);
    if (t30 == 1)
        goto LAB18;

LAB19:
LAB20:    t51 = (t20 + 4);
    t52 = *((unsigned int *)t51);
    t53 = (~(t52));
    t54 = *((unsigned int *)t20);
    t55 = (t54 & t53);
    t56 = (t55 != 0);
    if (t56 > 0)
        goto LAB21;

LAB22:    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng1)));
    memcpy(t9, t2, 8);
    t3 = (t0 + 3000);
    xsi_vlogvar_assign_value(t3, t9, 0, 0, 2);

LAB23:    goto LAB13;

LAB9:    xsi_set_current_line(53, ng0);
    t3 = (t0 + 2520);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 4);
    t12 = *((unsigned int *)t7);
    t13 = (~(t12));
    t14 = *((unsigned int *)t5);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB24;

LAB25:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng2)));
    memcpy(t9, t2, 8);
    t3 = (t0 + 3000);
    xsi_vlogvar_assign_value(t3, t9, 0, 0, 2);

LAB26:    goto LAB13;

LAB14:    *((unsigned int *)t9) = 1;
    goto LAB17;

LAB18:    t31 = *((unsigned int *)t20);
    t32 = *((unsigned int *)t25);
    *((unsigned int *)t20) = (t31 | t32);
    t33 = (t9 + 4);
    t34 = (t19 + 4);
    t35 = *((unsigned int *)t9);
    t36 = (~(t35));
    t37 = *((unsigned int *)t33);
    t38 = (~(t37));
    t39 = *((unsigned int *)t19);
    t40 = (~(t39));
    t41 = *((unsigned int *)t34);
    t42 = (~(t41));
    t43 = (t36 & t38);
    t44 = (t40 & t42);
    t45 = (~(t43));
    t46 = (~(t44));
    t47 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t47 & t45);
    t48 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t48 & t46);
    t49 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t49 & t45);
    t50 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t50 & t46);
    goto LAB20;

LAB21:    xsi_set_current_line(51, ng0);
    t57 = ((char*)((ng2)));
    memcpy(t58, t57, 8);
    t59 = (t0 + 3000);
    xsi_vlogvar_assign_value(t59, t58, 0, 0, 2);
    goto LAB23;

LAB24:    xsi_set_current_line(53, ng0);
    t10 = ((char*)((ng1)));
    memcpy(t9, t10, 8);
    t11 = (t0 + 3000);
    xsi_vlogvar_assign_value(t11, t9, 0, 0, 2);
    goto LAB26;

}

static void Always_67_2(char *t0)
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

LAB0:    t1 = (t0 + 5216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 6064);
    *((int *)t2) = 1;
    t3 = (t0 + 5248);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(68, ng0);

LAB5:    xsi_set_current_line(69, ng0);
    t4 = (t0 + 2840);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 2, t7, 1);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 2, t2, 1);
    if (t8 == 1)
        goto LAB9;

LAB10:
LAB11:    goto LAB2;

LAB7:    xsi_set_current_line(70, ng0);

LAB12:    xsi_set_current_line(71, ng0);
    t9 = ((char*)((ng2)));
    t10 = (t0 + 3160);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 1, 0LL);
    goto LAB11;

LAB9:    xsi_set_current_line(74, ng0);

LAB13:    xsi_set_current_line(75, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 3160);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    goto LAB11;

}

static void Always_93_3(char *t0)
{
    char t15[8];
    char t25[8];
    char t65[8];
    char t70[8];
    char t73[8];
    char t115[8];
    char *t1;
    char *t2;
    char *t3;
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
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
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
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
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
    char *t71;
    char *t72;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    char *t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    char *t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    int t97;
    int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    char *t111;
    char *t112;
    char *t113;
    char *t114;
    char *t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;

LAB0:    t1 = (t0 + 5464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 6080);
    *((int *)t2) = 1;
    t3 = (t0 + 5496);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(95, ng0);

LAB5:    xsi_set_current_line(96, ng0);
    t4 = (t0 + 3160);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:
LAB8:    xsi_set_current_line(124, ng0);
    t2 = (t0 + 2520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t15, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t5);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t16 = (t11 ^ t12);
    t17 = (t10 | t16);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t7);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB65;

LAB62:    if (t20 != 0)
        goto LAB64;

LAB63:    *((unsigned int *)t15) = 1;

LAB65:    t14 = (t15 + 4);
    t26 = *((unsigned int *)t14);
    t27 = (~(t26));
    t28 = *((unsigned int *)t15);
    t32 = (t28 & t27);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB66;

LAB67:
LAB68:    goto LAB2;

LAB6:    xsi_set_current_line(97, ng0);

LAB9:    xsi_set_current_line(98, ng0);
    t13 = ((char*)((ng1)));
    t14 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t14, t13, 0, 0, 1, 0LL);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 3640);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t15, 0, 8);
    xsi_vlog_unsigned_add(t15, 32, t4, 4, t5, 32);
    t6 = (t0 + 3640);
    xsi_vlogvar_wait_assign_value(t6, t15, 0, 0, 4, 0LL);
    xsi_set_current_line(102, ng0);
    t2 = (t0 + 3640);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t15, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t5);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t16 = (t11 ^ t12);
    t17 = (t10 | t16);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t7);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB13;

LAB10:    if (t20 != 0)
        goto LAB12;

LAB11:    *((unsigned int *)t15) = 1;

LAB13:    t14 = (t0 + 3320);
    t23 = (t14 + 56U);
    t24 = *((char **)t23);
    t26 = *((unsigned int *)t15);
    t27 = *((unsigned int *)t24);
    t28 = (t26 & t27);
    *((unsigned int *)t25) = t28;
    t29 = (t15 + 4);
    t30 = (t24 + 4);
    t31 = (t25 + 4);
    t32 = *((unsigned int *)t29);
    t33 = *((unsigned int *)t30);
    t34 = (t32 | t33);
    *((unsigned int *)t31) = t34;
    t35 = *((unsigned int *)t31);
    t36 = (t35 != 0);
    if (t36 == 1)
        goto LAB14;

LAB15:
LAB16:    t57 = (t25 + 4);
    t58 = *((unsigned int *)t57);
    t59 = (~(t58));
    t60 = *((unsigned int *)t25);
    t61 = (t60 & t59);
    t62 = (t61 != 0);
    if (t62 > 0)
        goto LAB17;

LAB18:
LAB19:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 3640);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t15, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t5);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t16 = (t11 ^ t12);
    t17 = (t10 | t16);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t7);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB24;

LAB21:    if (t20 != 0)
        goto LAB23;

LAB22:    *((unsigned int *)t15) = 1;

LAB24:    t14 = (t0 + 3320);
    t23 = (t14 + 56U);
    t24 = *((char **)t23);
    memset(t25, 0, 8);
    t29 = (t24 + 4);
    t26 = *((unsigned int *)t29);
    t27 = (~(t26));
    t28 = *((unsigned int *)t24);
    t32 = (t28 & t27);
    t33 = (t32 & 1U);
    if (t33 != 0)
        goto LAB28;

LAB26:    if (*((unsigned int *)t29) == 0)
        goto LAB25;

LAB27:    t30 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t30) = 1;

LAB28:    t34 = *((unsigned int *)t15);
    t35 = *((unsigned int *)t25);
    t36 = (t34 & t35);
    *((unsigned int *)t65) = t36;
    t31 = (t15 + 4);
    t39 = (t25 + 4);
    t40 = (t65 + 4);
    t37 = *((unsigned int *)t31);
    t38 = *((unsigned int *)t39);
    t41 = (t37 | t38);
    *((unsigned int *)t40) = t41;
    t42 = *((unsigned int *)t40);
    t43 = (t42 != 0);
    if (t43 == 1)
        goto LAB29;

LAB30:
LAB31:    t64 = (t0 + 3480);
    t66 = (t64 + 56U);
    t67 = *((char **)t66);
    t68 = (t0 + 2120U);
    t69 = *((char **)t68);
    memset(t70, 0, 8);
    t68 = (t67 + 4);
    if (*((unsigned int *)t68) != 0)
        goto LAB33;

LAB32:    t71 = (t69 + 4);
    if (*((unsigned int *)t71) != 0)
        goto LAB33;

LAB36:    if (*((unsigned int *)t67) < *((unsigned int *)t69))
        goto LAB34;

LAB35:    t74 = *((unsigned int *)t65);
    t75 = *((unsigned int *)t70);
    t76 = (t74 & t75);
    *((unsigned int *)t73) = t76;
    t77 = (t65 + 4);
    t78 = (t70 + 4);
    t79 = (t73 + 4);
    t80 = *((unsigned int *)t77);
    t81 = *((unsigned int *)t78);
    t82 = (t80 | t81);
    *((unsigned int *)t79) = t82;
    t83 = *((unsigned int *)t79);
    t84 = (t83 != 0);
    if (t84 == 1)
        goto LAB37;

LAB38:
LAB39:    t105 = (t73 + 4);
    t106 = *((unsigned int *)t105);
    t107 = (~(t106));
    t108 = *((unsigned int *)t73);
    t109 = (t108 & t107);
    t110 = (t109 != 0);
    if (t110 > 0)
        goto LAB40;

LAB41:
LAB42:    xsi_set_current_line(115, ng0);
    t2 = (t0 + 3640);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t15, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t5);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t16 = (t11 ^ t12);
    t17 = (t10 | t16);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t7);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB47;

LAB44:    if (t20 != 0)
        goto LAB46;

LAB45:    *((unsigned int *)t15) = 1;

LAB47:    t14 = (t0 + 3480);
    t23 = (t14 + 56U);
    t24 = *((char **)t23);
    t29 = (t0 + 2120U);
    t30 = *((char **)t29);
    memset(t25, 0, 8);
    t29 = (t24 + 4);
    t31 = (t30 + 4);
    t26 = *((unsigned int *)t24);
    t27 = *((unsigned int *)t30);
    t28 = (t26 ^ t27);
    t32 = *((unsigned int *)t29);
    t33 = *((unsigned int *)t31);
    t34 = (t32 ^ t33);
    t35 = (t28 | t34);
    t36 = *((unsigned int *)t29);
    t37 = *((unsigned int *)t31);
    t38 = (t36 | t37);
    t41 = (~(t38));
    t42 = (t35 & t41);
    if (t42 != 0)
        goto LAB51;

LAB48:    if (t38 != 0)
        goto LAB50;

LAB49:    *((unsigned int *)t25) = 1;

LAB51:    t43 = *((unsigned int *)t15);
    t44 = *((unsigned int *)t25);
    t45 = (t43 & t44);
    *((unsigned int *)t65) = t45;
    t40 = (t15 + 4);
    t57 = (t25 + 4);
    t63 = (t65 + 4);
    t46 = *((unsigned int *)t40);
    t47 = *((unsigned int *)t57);
    t48 = (t46 | t47);
    *((unsigned int *)t63) = t48;
    t51 = *((unsigned int *)t63);
    t52 = (t51 != 0);
    if (t52 == 1)
        goto LAB52;

LAB53:
LAB54:    t67 = (t0 + 1800U);
    t68 = *((char **)t67);
    t84 = *((unsigned int *)t65);
    t85 = *((unsigned int *)t68);
    t86 = (t84 & t85);
    *((unsigned int *)t70) = t86;
    t67 = (t65 + 4);
    t69 = (t68 + 4);
    t71 = (t70 + 4);
    t89 = *((unsigned int *)t67);
    t90 = *((unsigned int *)t69);
    t91 = (t89 | t90);
    *((unsigned int *)t71) = t91;
    t92 = *((unsigned int *)t71);
    t93 = (t92 != 0);
    if (t93 == 1)
        goto LAB55;

LAB56:
LAB57:    t78 = (t70 + 4);
    t119 = *((unsigned int *)t78);
    t120 = (~(t119));
    t121 = *((unsigned int *)t70);
    t122 = (t121 & t120);
    t123 = (t122 != 0);
    if (t123 > 0)
        goto LAB58;

LAB59:
LAB60:    goto LAB8;

LAB12:    t13 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB13;

LAB14:    t37 = *((unsigned int *)t25);
    t38 = *((unsigned int *)t31);
    *((unsigned int *)t25) = (t37 | t38);
    t39 = (t15 + 4);
    t40 = (t24 + 4);
    t41 = *((unsigned int *)t15);
    t42 = (~(t41));
    t43 = *((unsigned int *)t39);
    t44 = (~(t43));
    t45 = *((unsigned int *)t24);
    t46 = (~(t45));
    t47 = *((unsigned int *)t40);
    t48 = (~(t47));
    t49 = (t42 & t44);
    t50 = (t46 & t48);
    t51 = (~(t49));
    t52 = (~(t50));
    t53 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t53 & t51);
    t54 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t54 & t52);
    t55 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t55 & t51);
    t56 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t56 & t52);
    goto LAB16;

LAB17:    xsi_set_current_line(103, ng0);

LAB20:    xsi_set_current_line(104, ng0);
    t63 = ((char*)((ng1)));
    t64 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t64, t63, 0, 0, 1, 0LL);
    xsi_set_current_line(105, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3640);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    goto LAB19;

LAB23:    t13 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB24;

LAB25:    *((unsigned int *)t25) = 1;
    goto LAB28;

LAB29:    t44 = *((unsigned int *)t65);
    t45 = *((unsigned int *)t40);
    *((unsigned int *)t65) = (t44 | t45);
    t57 = (t15 + 4);
    t63 = (t25 + 4);
    t46 = *((unsigned int *)t15);
    t47 = (~(t46));
    t48 = *((unsigned int *)t57);
    t51 = (~(t48));
    t52 = *((unsigned int *)t25);
    t53 = (~(t52));
    t54 = *((unsigned int *)t63);
    t55 = (~(t54));
    t49 = (t47 & t51);
    t50 = (t53 & t55);
    t56 = (~(t49));
    t58 = (~(t50));
    t59 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t59 & t56);
    t60 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t60 & t58);
    t61 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t61 & t56);
    t62 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t62 & t58);
    goto LAB31;

LAB33:    t72 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB35;

LAB34:    *((unsigned int *)t70) = 1;
    goto LAB35;

LAB37:    t85 = *((unsigned int *)t73);
    t86 = *((unsigned int *)t79);
    *((unsigned int *)t73) = (t85 | t86);
    t87 = (t65 + 4);
    t88 = (t70 + 4);
    t89 = *((unsigned int *)t65);
    t90 = (~(t89));
    t91 = *((unsigned int *)t87);
    t92 = (~(t91));
    t93 = *((unsigned int *)t70);
    t94 = (~(t93));
    t95 = *((unsigned int *)t88);
    t96 = (~(t95));
    t97 = (t90 & t92);
    t98 = (t94 & t96);
    t99 = (~(t97));
    t100 = (~(t98));
    t101 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t101 & t99);
    t102 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t102 & t100);
    t103 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t103 & t99);
    t104 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t104 & t100);
    goto LAB39;

LAB40:    xsi_set_current_line(109, ng0);

LAB43:    xsi_set_current_line(110, ng0);
    t111 = (t0 + 3480);
    t112 = (t111 + 56U);
    t113 = *((char **)t112);
    t114 = ((char*)((ng3)));
    memset(t115, 0, 8);
    xsi_vlog_unsigned_add(t115, 32, t113, 5, t114, 32);
    t116 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t116, t115, 0, 0, 5, 0LL);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 3800);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t25, 0, 8);
    t5 = (t25 + 4);
    t6 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 1);
    *((unsigned int *)t25) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 1);
    *((unsigned int *)t5) = t11;
    t12 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t12 & 127U);
    t16 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t16 & 127U);
    t7 = (t0 + 1800U);
    t13 = *((char **)t7);
    xsi_vlogtype_concat(t15, 8, 8, 2U, t13, 1, t25, 7);
    t7 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t7, t15, 0, 0, 8, 0LL);
    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3640);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    goto LAB42;

LAB46:    t13 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB47;

LAB50:    t39 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB51;

LAB52:    t53 = *((unsigned int *)t65);
    t54 = *((unsigned int *)t63);
    *((unsigned int *)t65) = (t53 | t54);
    t64 = (t15 + 4);
    t66 = (t25 + 4);
    t55 = *((unsigned int *)t15);
    t56 = (~(t55));
    t58 = *((unsigned int *)t64);
    t59 = (~(t58));
    t60 = *((unsigned int *)t25);
    t61 = (~(t60));
    t62 = *((unsigned int *)t66);
    t74 = (~(t62));
    t49 = (t56 & t59);
    t50 = (t61 & t74);
    t75 = (~(t49));
    t76 = (~(t50));
    t80 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t80 & t75);
    t81 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t81 & t76);
    t82 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t82 & t75);
    t83 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t83 & t76);
    goto LAB54;

LAB55:    t94 = *((unsigned int *)t70);
    t95 = *((unsigned int *)t71);
    *((unsigned int *)t70) = (t94 | t95);
    t72 = (t65 + 4);
    t77 = (t68 + 4);
    t96 = *((unsigned int *)t65);
    t99 = (~(t96));
    t100 = *((unsigned int *)t72);
    t101 = (~(t100));
    t102 = *((unsigned int *)t68);
    t103 = (~(t102));
    t104 = *((unsigned int *)t77);
    t106 = (~(t104));
    t97 = (t99 & t101);
    t98 = (t103 & t106);
    t107 = (~(t97));
    t108 = (~(t98));
    t109 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t109 & t107);
    t110 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t110 & t108);
    t117 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t117 & t107);
    t118 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t118 & t108);
    goto LAB57;

LAB58:    xsi_set_current_line(116, ng0);

LAB61:    xsi_set_current_line(117, ng0);
    t79 = ((char*)((ng1)));
    t87 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t87, t79, 0, 0, 5, 0LL);
    xsi_set_current_line(118, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(119, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3640);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(120, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB60;

LAB64:    t13 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB65;

LAB66:    xsi_set_current_line(125, ng0);
    t23 = ((char*)((ng1)));
    t24 = (t0 + 2520);
    xsi_vlogvar_wait_assign_value(t24, t23, 0, 0, 1, 0LL);
    goto LAB68;

}

static void Always_136_4(char *t0)
{
    char t6[8];
    char t28[8];
    char t41[8];
    char *t1;
    char *t2;
    char *t3;
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
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;

LAB0:    t1 = (t0 + 5712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(136, ng0);
    t2 = (t0 + 6096);
    *((int *)t2) = 1;
    t3 = (t0 + 5744);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(137, ng0);

LAB5:    xsi_set_current_line(139, ng0);
    t4 = (t0 + 2120U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:
LAB12:    xsi_set_current_line(144, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB17;

LAB14:    if (t18 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t6) = 1;

LAB17:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB18;

LAB19:
LAB20:    xsi_set_current_line(149, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng7)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB25;

LAB22:    if (t18 != 0)
        goto LAB24;

LAB23:    *((unsigned int *)t6) = 1;

LAB25:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB26;

LAB27:
LAB28:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(140, ng0);

LAB13:    xsi_set_current_line(141, ng0);
    t29 = (t0 + 3800);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memset(t28, 0, 8);
    t32 = (t28 + 4);
    t33 = (t31 + 4);
    t34 = *((unsigned int *)t31);
    t35 = (t34 >> 0);
    *((unsigned int *)t28) = t35;
    t36 = *((unsigned int *)t33);
    t37 = (t36 >> 0);
    *((unsigned int *)t32) = t37;
    t38 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t38 & 255U);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t39 & 255U);
    t40 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t40, t28, 0, 0, 8, 0LL);
    goto LAB12;

LAB16:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(145, ng0);

LAB21:    xsi_set_current_line(146, ng0);
    t21 = (t0 + 3800);
    t22 = (t21 + 56U);
    t29 = *((char **)t22);
    memset(t41, 0, 8);
    t30 = (t41 + 4);
    t31 = (t29 + 4);
    t34 = *((unsigned int *)t29);
    t35 = (t34 >> 1);
    *((unsigned int *)t41) = t35;
    t36 = *((unsigned int *)t31);
    t37 = (t36 >> 1);
    *((unsigned int *)t30) = t37;
    t38 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t38 & 127U);
    t39 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t39 & 127U);
    t32 = ((char*)((ng1)));
    xsi_vlogtype_concat(t28, 8, 8, 2U, t32, 1, t41, 7);
    t33 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t33, t28, 0, 0, 8, 0LL);
    goto LAB20;

LAB24:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB25;

LAB26:    xsi_set_current_line(150, ng0);

LAB29:    xsi_set_current_line(151, ng0);
    t21 = (t0 + 3800);
    t22 = (t21 + 56U);
    t29 = *((char **)t22);
    memset(t41, 0, 8);
    t30 = (t41 + 4);
    t31 = (t29 + 4);
    t34 = *((unsigned int *)t29);
    t35 = (t34 >> 2);
    *((unsigned int *)t41) = t35;
    t36 = *((unsigned int *)t31);
    t37 = (t36 >> 2);
    *((unsigned int *)t30) = t37;
    t38 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t38 & 63U);
    t39 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t39 & 63U);
    t32 = ((char*)((ng1)));
    t33 = ((char*)((ng1)));
    xsi_vlogtype_concat(t28, 8, 8, 3U, t33, 1, t32, 1, t41, 6);
    t40 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t40, t28, 0, 0, 8, 0LL);
    goto LAB28;

}


extern void work_m_00000000000557360193_0660230277_init()
{
	static char *pe[] = {(void *)Always_30_0,(void *)Always_48_1,(void *)Always_67_2,(void *)Always_93_3,(void *)Always_136_4};
	xsi_register_didat("work_m_00000000000557360193_0660230277", "isim/top_tb_isim_beh.exe.sim/work/m_00000000000557360193_0660230277.didat");
	xsi_register_executes(pe);
}
