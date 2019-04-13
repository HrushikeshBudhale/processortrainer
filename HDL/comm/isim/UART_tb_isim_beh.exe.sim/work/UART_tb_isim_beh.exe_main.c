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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000000557360193_0660230277_init();
    work_m_00000000002122649647_1895888643_init();
    work_m_00000000001167435975_3119351064_init();
    work_m_00000000002655440624_1970878987_init();
    work_m_00000000004042906234_4194168834_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000004042906234_4194168834");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
