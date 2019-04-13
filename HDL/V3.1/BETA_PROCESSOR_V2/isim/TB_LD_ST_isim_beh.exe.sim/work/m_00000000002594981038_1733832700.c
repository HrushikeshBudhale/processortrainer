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
static const char *ng0 = "E:/EPD2FINAL/BETA_PROCESSOR_V2/Verilog/PC.v";
static int ng1[] = {4, 0};
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {13, 0};
static unsigned int ng4[] = {2147483648U, 0U};
static int ng5[] = {0, 0};
static int ng6[] = {1, 0};
static int ng7[] = {2, 0};
static int ng8[] = {3, 0};
static unsigned int ng9[] = {2147483652U, 0U};
static unsigned int ng10[] = {2147483656U, 0U};
static unsigned int ng11[] = {4294967295U, 4294967295U};



static void Cont_17_0(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;

LAB0:    t1 = (t0 + 3648U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(17, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 5104);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t11, 0, 8);
    t12 = 2147483647U;
    t13 = t12;
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t12 = (t12 & t15);
    t16 = *((unsigned int *)t14);
    t13 = (t13 & t16);
    t17 = (t11 + 4);
    t18 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t18 | t12);
    t19 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t19 | t13);
    xsi_driver_vfirst_trans(t7, 0, 30);
    t20 = (t0 + 4960);
    *((int *)t20) = 1;

LAB1:    return;
}

static void Cont_18_1(char *t0)
{
    char t3[8];
    char t7[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    t1 = (t0 + 3896U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(18, ng0);
    t2 = (t0 + 2008U);
    t4 = *((char **)t2);
    t2 = (t0 + 2728);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t7, 0, 8);
    t8 = (t7 + 4);
    t9 = (t6 + 4);
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 31);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t9);
    t14 = (t13 >> 31);
    t15 = (t14 & 1);
    *((unsigned int *)t8) = t15;
    xsi_vlogtype_concat(t3, 32, 32, 2U, t7, 1, t4, 31);
    t16 = (t0 + 5168);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t3, 8);
    xsi_driver_vfirst_trans(t16, 0, 31);
    t21 = (t0 + 4976);
    *((int *)t21) = 1;

LAB1:    return;
}

static void Cont_21_2(char *t0)
{
    char t3[8];
    char t5[8];
    char t6[8];
    char t16[8];
    char t20[8];
    char t28[8];
    char *t1;
    char *t2;
    char *t4;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t17;
    char *t18;
    char *t19;
    char *t21;
    unsigned int t22;
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
    char *t34;
    char *t35;

LAB0:    t1 = (t0 + 4144U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(21, ng0);
    t2 = (t0 + 2008U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng2)));
    t7 = (t0 + 1528U);
    t8 = *((char **)t7);
    memset(t6, 0, 8);
    t7 = (t6 + 4);
    t9 = (t8 + 4);
    t10 = *((unsigned int *)t8);
    t11 = (t10 >> 0);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t9);
    t13 = (t12 >> 0);
    *((unsigned int *)t7) = t13;
    t14 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t14 & 65535U);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t15 & 65535U);
    t17 = ((char*)((ng3)));
    t18 = (t0 + 1528U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t20 + 4);
    t21 = (t19 + 4);
    t22 = *((unsigned int *)t19);
    t23 = (t22 >> 15);
    t24 = (t23 & 1);
    *((unsigned int *)t20) = t24;
    t25 = *((unsigned int *)t21);
    t26 = (t25 >> 15);
    t27 = (t26 & 1);
    *((unsigned int *)t18) = t27;
    xsi_vlog_mul_concat(t16, 13, 1, t17, 1U, t20, 1);
    xsi_vlogtype_concat(t5, 31, 31, 3U, t16, 13, t6, 16, t2, 2);
    memset(t28, 0, 8);
    xsi_vlog_unsigned_add(t28, 31, t4, 31, t5, 31);
    t29 = ((char*)((ng2)));
    xsi_vlogtype_concat(t3, 32, 32, 2U, t29, 1, t28, 31);
    t30 = (t0 + 5232);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    memcpy(t34, t3, 8);
    xsi_driver_vfirst_trans(t30, 0, 31);
    t35 = (t0 + 4992);
    *((int *)t35) = 1;

LAB1:    return;
}

static void Cont_23_3(char *t0)
{
    char t3[8];
    char t4[8];
    char t21[8];
    char t22[8];
    char t25[8];
    char t52[8];
    char t57[8];
    char t70[8];
    char t71[8];
    char t74[8];
    char t101[8];
    char t102[8];
    char t115[8];
    char t128[8];
    char t129[8];
    char t132[8];
    char t159[8];
    char t160[8];
    char t173[8];
    char t184[8];
    char t192[8];
    char t228[8];
    char t229[8];
    char t232[8];
    char t264[8];
    char t265[8];
    char t268[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
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
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t72;
    char *t73;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
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
    char *t96;
    char *t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    char *t103;
    char *t104;
    char *t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    char *t112;
    char *t113;
    char *t114;
    char *t116;
    char *t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    char *t130;
    char *t131;
    char *t133;
    char *t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    char *t147;
    char *t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    char *t154;
    char *t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    char *t161;
    char *t162;
    char *t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    char *t170;
    char *t171;
    char *t172;
    char *t174;
    char *t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    char *t182;
    char *t183;
    char *t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    unsigned int t190;
    unsigned int t191;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    char *t196;
    char *t197;
    char *t198;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    unsigned int t205;
    char *t206;
    char *t207;
    unsigned int t208;
    unsigned int t209;
    unsigned int t210;
    unsigned int t211;
    unsigned int t212;
    unsigned int t213;
    unsigned int t214;
    unsigned int t215;
    int t216;
    int t217;
    unsigned int t218;
    unsigned int t219;
    unsigned int t220;
    unsigned int t221;
    unsigned int t222;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    unsigned int t226;
    unsigned int t227;
    char *t230;
    char *t231;
    char *t233;
    char *t234;
    unsigned int t235;
    unsigned int t236;
    unsigned int t237;
    unsigned int t238;
    unsigned int t239;
    unsigned int t240;
    unsigned int t241;
    unsigned int t242;
    unsigned int t243;
    unsigned int t244;
    unsigned int t245;
    unsigned int t246;
    char *t247;
    char *t248;
    unsigned int t249;
    unsigned int t250;
    unsigned int t251;
    unsigned int t252;
    unsigned int t253;
    char *t254;
    char *t255;
    unsigned int t256;
    unsigned int t257;
    unsigned int t258;
    char *t259;
    unsigned int t260;
    unsigned int t261;
    unsigned int t262;
    unsigned int t263;
    char *t266;
    char *t267;
    char *t269;
    char *t270;
    unsigned int t271;
    unsigned int t272;
    unsigned int t273;
    unsigned int t274;
    unsigned int t275;
    unsigned int t276;
    unsigned int t277;
    unsigned int t278;
    unsigned int t279;
    unsigned int t280;
    unsigned int t281;
    unsigned int t282;
    char *t283;
    char *t284;
    unsigned int t285;
    unsigned int t286;
    unsigned int t287;
    unsigned int t288;
    unsigned int t289;
    char *t290;
    char *t291;
    unsigned int t292;
    unsigned int t293;
    unsigned int t294;
    char *t295;
    unsigned int t296;
    unsigned int t297;
    unsigned int t298;
    unsigned int t299;
    char *t300;
    char *t301;
    char *t302;
    char *t303;
    char *t304;
    char *t305;
    char *t306;

LAB0:    t1 = (t0 + 4392U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 1208U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t17 = *((unsigned int *)t4);
    t18 = (~(t17));
    t19 = *((unsigned int *)t12);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t21, 8);

LAB16:    t301 = (t0 + 5296);
    t302 = (t301 + 56U);
    t303 = *((char **)t302);
    t304 = (t303 + 56U);
    t305 = *((char **)t304);
    memcpy(t305, t3, 8);
    xsi_driver_vfirst_trans(t301, 0, 31);
    t306 = (t0 + 5008);
    *((int *)t306) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = ((char*)((ng4)));
    goto LAB9;

LAB10:    t23 = (t0 + 1368U);
    t24 = *((char **)t23);
    t23 = ((char*)((ng5)));
    memset(t25, 0, 8);
    t26 = (t24 + 4);
    t27 = (t23 + 4);
    t28 = *((unsigned int *)t24);
    t29 = *((unsigned int *)t23);
    t30 = (t28 ^ t29);
    t31 = *((unsigned int *)t26);
    t32 = *((unsigned int *)t27);
    t33 = (t31 ^ t32);
    t34 = (t30 | t33);
    t35 = *((unsigned int *)t26);
    t36 = *((unsigned int *)t27);
    t37 = (t35 | t36);
    t38 = (~(t37));
    t39 = (t34 & t38);
    if (t39 != 0)
        goto LAB20;

LAB17:    if (t37 != 0)
        goto LAB19;

LAB18:    *((unsigned int *)t25) = 1;

LAB20:    memset(t22, 0, 8);
    t41 = (t25 + 4);
    t42 = *((unsigned int *)t41);
    t43 = (~(t42));
    t44 = *((unsigned int *)t25);
    t45 = (t44 & t43);
    t46 = (t45 & 1U);
    if (t46 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t41) != 0)
        goto LAB23;

LAB24:    t48 = (t22 + 4);
    t49 = *((unsigned int *)t22);
    t50 = *((unsigned int *)t48);
    t51 = (t49 || t50);
    if (t51 > 0)
        goto LAB25;

LAB26:    t66 = *((unsigned int *)t22);
    t67 = (~(t66));
    t68 = *((unsigned int *)t48);
    t69 = (t67 || t68);
    if (t69 > 0)
        goto LAB27;

LAB28:    if (*((unsigned int *)t48) > 0)
        goto LAB29;

LAB30:    if (*((unsigned int *)t22) > 0)
        goto LAB31;

LAB32:    memcpy(t21, t70, 8);

LAB33:    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t16, 32, t21, 32);
    goto LAB16;

LAB14:    memcpy(t3, t16, 8);
    goto LAB16;

LAB19:    t40 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t22) = 1;
    goto LAB24;

LAB23:    t47 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB24;

LAB25:    t53 = (t0 + 2008U);
    t54 = *((char **)t53);
    t53 = (t0 + 2728);
    t55 = (t53 + 56U);
    t56 = *((char **)t55);
    memset(t57, 0, 8);
    t58 = (t57 + 4);
    t59 = (t56 + 4);
    t60 = *((unsigned int *)t56);
    t61 = (t60 >> 31);
    t62 = (t61 & 1);
    *((unsigned int *)t57) = t62;
    t63 = *((unsigned int *)t59);
    t64 = (t63 >> 31);
    t65 = (t64 & 1);
    *((unsigned int *)t58) = t65;
    xsi_vlogtype_concat(t52, 32, 32, 2U, t57, 1, t54, 31);
    goto LAB26;

LAB27:    t72 = (t0 + 1368U);
    t73 = *((char **)t72);
    t72 = ((char*)((ng6)));
    memset(t74, 0, 8);
    t75 = (t73 + 4);
    t76 = (t72 + 4);
    t77 = *((unsigned int *)t73);
    t78 = *((unsigned int *)t72);
    t79 = (t77 ^ t78);
    t80 = *((unsigned int *)t75);
    t81 = *((unsigned int *)t76);
    t82 = (t80 ^ t81);
    t83 = (t79 | t82);
    t84 = *((unsigned int *)t75);
    t85 = *((unsigned int *)t76);
    t86 = (t84 | t85);
    t87 = (~(t86));
    t88 = (t83 & t87);
    if (t88 != 0)
        goto LAB37;

LAB34:    if (t86 != 0)
        goto LAB36;

LAB35:    *((unsigned int *)t74) = 1;

LAB37:    memset(t71, 0, 8);
    t90 = (t74 + 4);
    t91 = *((unsigned int *)t90);
    t92 = (~(t91));
    t93 = *((unsigned int *)t74);
    t94 = (t93 & t92);
    t95 = (t94 & 1U);
    if (t95 != 0)
        goto LAB38;

LAB39:    if (*((unsigned int *)t90) != 0)
        goto LAB40;

LAB41:    t97 = (t71 + 4);
    t98 = *((unsigned int *)t71);
    t99 = *((unsigned int *)t97);
    t100 = (t98 || t99);
    if (t100 > 0)
        goto LAB42;

LAB43:    t124 = *((unsigned int *)t71);
    t125 = (~(t124));
    t126 = *((unsigned int *)t97);
    t127 = (t125 || t126);
    if (t127 > 0)
        goto LAB44;

LAB45:    if (*((unsigned int *)t97) > 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t71) > 0)
        goto LAB48;

LAB49:    memcpy(t70, t128, 8);

LAB50:    goto LAB28;

LAB29:    xsi_vlog_unsigned_bit_combine(t21, 32, t52, 32, t70, 32);
    goto LAB33;

LAB31:    memcpy(t21, t52, 8);
    goto LAB33;

LAB36:    t89 = (t74 + 4);
    *((unsigned int *)t74) = 1;
    *((unsigned int *)t89) = 1;
    goto LAB37;

LAB38:    *((unsigned int *)t71) = 1;
    goto LAB41;

LAB40:    t96 = (t71 + 4);
    *((unsigned int *)t71) = 1;
    *((unsigned int *)t96) = 1;
    goto LAB41;

LAB42:    t103 = (t0 + 2328U);
    t104 = *((char **)t103);
    memset(t102, 0, 8);
    t103 = (t102 + 4);
    t105 = (t104 + 4);
    t106 = *((unsigned int *)t104);
    t107 = (t106 >> 0);
    *((unsigned int *)t102) = t107;
    t108 = *((unsigned int *)t105);
    t109 = (t108 >> 0);
    *((unsigned int *)t103) = t109;
    t110 = *((unsigned int *)t102);
    *((unsigned int *)t102) = (t110 & 2147483647U);
    t111 = *((unsigned int *)t103);
    *((unsigned int *)t103) = (t111 & 2147483647U);
    t112 = (t0 + 2728);
    t113 = (t112 + 56U);
    t114 = *((char **)t113);
    memset(t115, 0, 8);
    t116 = (t115 + 4);
    t117 = (t114 + 4);
    t118 = *((unsigned int *)t114);
    t119 = (t118 >> 31);
    t120 = (t119 & 1);
    *((unsigned int *)t115) = t120;
    t121 = *((unsigned int *)t117);
    t122 = (t121 >> 31);
    t123 = (t122 & 1);
    *((unsigned int *)t116) = t123;
    xsi_vlogtype_concat(t101, 32, 32, 2U, t115, 1, t102, 31);
    goto LAB43;

LAB44:    t130 = (t0 + 1368U);
    t131 = *((char **)t130);
    t130 = ((char*)((ng7)));
    memset(t132, 0, 8);
    t133 = (t131 + 4);
    t134 = (t130 + 4);
    t135 = *((unsigned int *)t131);
    t136 = *((unsigned int *)t130);
    t137 = (t135 ^ t136);
    t138 = *((unsigned int *)t133);
    t139 = *((unsigned int *)t134);
    t140 = (t138 ^ t139);
    t141 = (t137 | t140);
    t142 = *((unsigned int *)t133);
    t143 = *((unsigned int *)t134);
    t144 = (t142 | t143);
    t145 = (~(t144));
    t146 = (t141 & t145);
    if (t146 != 0)
        goto LAB54;

LAB51:    if (t144 != 0)
        goto LAB53;

LAB52:    *((unsigned int *)t132) = 1;

LAB54:    memset(t129, 0, 8);
    t148 = (t132 + 4);
    t149 = *((unsigned int *)t148);
    t150 = (~(t149));
    t151 = *((unsigned int *)t132);
    t152 = (t151 & t150);
    t153 = (t152 & 1U);
    if (t153 != 0)
        goto LAB55;

LAB56:    if (*((unsigned int *)t148) != 0)
        goto LAB57;

LAB58:    t155 = (t129 + 4);
    t156 = *((unsigned int *)t129);
    t157 = *((unsigned int *)t155);
    t158 = (t156 || t157);
    if (t158 > 0)
        goto LAB59;

LAB60:    t224 = *((unsigned int *)t129);
    t225 = (~(t224));
    t226 = *((unsigned int *)t155);
    t227 = (t225 || t226);
    if (t227 > 0)
        goto LAB61;

LAB62:    if (*((unsigned int *)t155) > 0)
        goto LAB63;

LAB64:    if (*((unsigned int *)t129) > 0)
        goto LAB65;

LAB66:    memcpy(t128, t228, 8);

LAB67:    goto LAB45;

LAB46:    xsi_vlog_unsigned_bit_combine(t70, 32, t101, 32, t128, 32);
    goto LAB50;

LAB48:    memcpy(t70, t101, 8);
    goto LAB50;

LAB53:    t147 = (t132 + 4);
    *((unsigned int *)t132) = 1;
    *((unsigned int *)t147) = 1;
    goto LAB54;

LAB55:    *((unsigned int *)t129) = 1;
    goto LAB58;

LAB57:    t154 = (t129 + 4);
    *((unsigned int *)t129) = 1;
    *((unsigned int *)t154) = 1;
    goto LAB58;

LAB59:    t161 = (t0 + 1688U);
    t162 = *((char **)t161);
    memset(t160, 0, 8);
    t161 = (t160 + 4);
    t163 = (t162 + 4);
    t164 = *((unsigned int *)t162);
    t165 = (t164 >> 0);
    *((unsigned int *)t160) = t165;
    t166 = *((unsigned int *)t163);
    t167 = (t166 >> 0);
    *((unsigned int *)t161) = t167;
    t168 = *((unsigned int *)t160);
    *((unsigned int *)t160) = (t168 & 2147483647U);
    t169 = *((unsigned int *)t161);
    *((unsigned int *)t161) = (t169 & 2147483647U);
    t170 = (t0 + 2728);
    t171 = (t170 + 56U);
    t172 = *((char **)t171);
    memset(t173, 0, 8);
    t174 = (t173 + 4);
    t175 = (t172 + 4);
    t176 = *((unsigned int *)t172);
    t177 = (t176 >> 31);
    t178 = (t177 & 1);
    *((unsigned int *)t173) = t178;
    t179 = *((unsigned int *)t175);
    t180 = (t179 >> 31);
    t181 = (t180 & 1);
    *((unsigned int *)t174) = t181;
    t182 = (t0 + 1688U);
    t183 = *((char **)t182);
    memset(t184, 0, 8);
    t182 = (t184 + 4);
    t185 = (t183 + 4);
    t186 = *((unsigned int *)t183);
    t187 = (t186 >> 31);
    t188 = (t187 & 1);
    *((unsigned int *)t184) = t188;
    t189 = *((unsigned int *)t185);
    t190 = (t189 >> 31);
    t191 = (t190 & 1);
    *((unsigned int *)t182) = t191;
    t193 = *((unsigned int *)t173);
    t194 = *((unsigned int *)t184);
    t195 = (t193 & t194);
    *((unsigned int *)t192) = t195;
    t196 = (t173 + 4);
    t197 = (t184 + 4);
    t198 = (t192 + 4);
    t199 = *((unsigned int *)t196);
    t200 = *((unsigned int *)t197);
    t201 = (t199 | t200);
    *((unsigned int *)t198) = t201;
    t202 = *((unsigned int *)t198);
    t203 = (t202 != 0);
    if (t203 == 1)
        goto LAB68;

LAB69:
LAB70:    xsi_vlogtype_concat(t159, 32, 32, 2U, t192, 1, t160, 31);
    goto LAB60;

LAB61:    t230 = (t0 + 1368U);
    t231 = *((char **)t230);
    t230 = ((char*)((ng8)));
    memset(t232, 0, 8);
    t233 = (t231 + 4);
    t234 = (t230 + 4);
    t235 = *((unsigned int *)t231);
    t236 = *((unsigned int *)t230);
    t237 = (t235 ^ t236);
    t238 = *((unsigned int *)t233);
    t239 = *((unsigned int *)t234);
    t240 = (t238 ^ t239);
    t241 = (t237 | t240);
    t242 = *((unsigned int *)t233);
    t243 = *((unsigned int *)t234);
    t244 = (t242 | t243);
    t245 = (~(t244));
    t246 = (t241 & t245);
    if (t246 != 0)
        goto LAB74;

LAB71:    if (t244 != 0)
        goto LAB73;

LAB72:    *((unsigned int *)t232) = 1;

LAB74:    memset(t229, 0, 8);
    t248 = (t232 + 4);
    t249 = *((unsigned int *)t248);
    t250 = (~(t249));
    t251 = *((unsigned int *)t232);
    t252 = (t251 & t250);
    t253 = (t252 & 1U);
    if (t253 != 0)
        goto LAB75;

LAB76:    if (*((unsigned int *)t248) != 0)
        goto LAB77;

LAB78:    t255 = (t229 + 4);
    t256 = *((unsigned int *)t229);
    t257 = *((unsigned int *)t255);
    t258 = (t256 || t257);
    if (t258 > 0)
        goto LAB79;

LAB80:    t260 = *((unsigned int *)t229);
    t261 = (~(t260));
    t262 = *((unsigned int *)t255);
    t263 = (t261 || t262);
    if (t263 > 0)
        goto LAB81;

LAB82:    if (*((unsigned int *)t255) > 0)
        goto LAB83;

LAB84:    if (*((unsigned int *)t229) > 0)
        goto LAB85;

LAB86:    memcpy(t228, t264, 8);

LAB87:    goto LAB62;

LAB63:    xsi_vlog_unsigned_bit_combine(t128, 32, t159, 32, t228, 32);
    goto LAB67;

LAB65:    memcpy(t128, t159, 8);
    goto LAB67;

LAB68:    t204 = *((unsigned int *)t192);
    t205 = *((unsigned int *)t198);
    *((unsigned int *)t192) = (t204 | t205);
    t206 = (t173 + 4);
    t207 = (t184 + 4);
    t208 = *((unsigned int *)t173);
    t209 = (~(t208));
    t210 = *((unsigned int *)t206);
    t211 = (~(t210));
    t212 = *((unsigned int *)t184);
    t213 = (~(t212));
    t214 = *((unsigned int *)t207);
    t215 = (~(t214));
    t216 = (t209 & t211);
    t217 = (t213 & t215);
    t218 = (~(t216));
    t219 = (~(t217));
    t220 = *((unsigned int *)t198);
    *((unsigned int *)t198) = (t220 & t218);
    t221 = *((unsigned int *)t198);
    *((unsigned int *)t198) = (t221 & t219);
    t222 = *((unsigned int *)t192);
    *((unsigned int *)t192) = (t222 & t218);
    t223 = *((unsigned int *)t192);
    *((unsigned int *)t192) = (t223 & t219);
    goto LAB70;

LAB73:    t247 = (t232 + 4);
    *((unsigned int *)t232) = 1;
    *((unsigned int *)t247) = 1;
    goto LAB74;

LAB75:    *((unsigned int *)t229) = 1;
    goto LAB78;

LAB77:    t254 = (t229 + 4);
    *((unsigned int *)t229) = 1;
    *((unsigned int *)t254) = 1;
    goto LAB78;

LAB79:    t259 = ((char*)((ng9)));
    goto LAB80;

LAB81:    t266 = (t0 + 1368U);
    t267 = *((char **)t266);
    t266 = ((char*)((ng1)));
    memset(t268, 0, 8);
    t269 = (t267 + 4);
    t270 = (t266 + 4);
    t271 = *((unsigned int *)t267);
    t272 = *((unsigned int *)t266);
    t273 = (t271 ^ t272);
    t274 = *((unsigned int *)t269);
    t275 = *((unsigned int *)t270);
    t276 = (t274 ^ t275);
    t277 = (t273 | t276);
    t278 = *((unsigned int *)t269);
    t279 = *((unsigned int *)t270);
    t280 = (t278 | t279);
    t281 = (~(t280));
    t282 = (t277 & t281);
    if (t282 != 0)
        goto LAB91;

LAB88:    if (t280 != 0)
        goto LAB90;

LAB89:    *((unsigned int *)t268) = 1;

LAB91:    memset(t265, 0, 8);
    t284 = (t268 + 4);
    t285 = *((unsigned int *)t284);
    t286 = (~(t285));
    t287 = *((unsigned int *)t268);
    t288 = (t287 & t286);
    t289 = (t288 & 1U);
    if (t289 != 0)
        goto LAB92;

LAB93:    if (*((unsigned int *)t284) != 0)
        goto LAB94;

LAB95:    t291 = (t265 + 4);
    t292 = *((unsigned int *)t265);
    t293 = *((unsigned int *)t291);
    t294 = (t292 || t293);
    if (t294 > 0)
        goto LAB96;

LAB97:    t296 = *((unsigned int *)t265);
    t297 = (~(t296));
    t298 = *((unsigned int *)t291);
    t299 = (t297 || t298);
    if (t299 > 0)
        goto LAB98;

LAB99:    if (*((unsigned int *)t291) > 0)
        goto LAB100;

LAB101:    if (*((unsigned int *)t265) > 0)
        goto LAB102;

LAB103:    memcpy(t264, t300, 8);

LAB104:    goto LAB82;

LAB83:    xsi_vlog_unsigned_bit_combine(t228, 32, t259, 32, t264, 32);
    goto LAB87;

LAB85:    memcpy(t228, t259, 8);
    goto LAB87;

LAB90:    t283 = (t268 + 4);
    *((unsigned int *)t268) = 1;
    *((unsigned int *)t283) = 1;
    goto LAB91;

LAB92:    *((unsigned int *)t265) = 1;
    goto LAB95;

LAB94:    t290 = (t265 + 4);
    *((unsigned int *)t265) = 1;
    *((unsigned int *)t290) = 1;
    goto LAB95;

LAB96:    t295 = ((char*)((ng10)));
    goto LAB97;

LAB98:    t300 = ((char*)((ng11)));
    goto LAB99;

LAB100:    xsi_vlog_unsigned_bit_combine(t264, 32, t295, 32, t300, 32);
    goto LAB104;

LAB102:    memcpy(t264, t295, 8);
    goto LAB104;

}

static void Always_31_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 4640U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 5024);
    *((int *)t2) = 1;
    t3 = (t0 + 4672);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(32, ng0);
    t4 = (t0 + 2168U);
    t5 = *((char **)t4);
    t4 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 32, 0LL);
    goto LAB2;

}


extern void work_m_00000000002594981038_1733832700_init()
{
	static char *pe[] = {(void *)Cont_17_0,(void *)Cont_18_1,(void *)Cont_21_2,(void *)Cont_23_3,(void *)Always_31_4};
	xsi_register_didat("work_m_00000000002594981038_1733832700", "isim/TB_LD_ST_isim_beh.exe.sim/work/m_00000000002594981038_1733832700.didat");
	xsi_register_executes(pe);
}
