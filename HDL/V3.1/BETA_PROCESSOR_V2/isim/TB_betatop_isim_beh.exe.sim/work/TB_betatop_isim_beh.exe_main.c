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
    work_m_00000000002594981038_1733832700_init();
    work_m_00000000001013100073_3013183664_init();
    work_m_00000000002853792346_1608899886_init();
    work_m_00000000001972031363_3509000235_init();
    work_m_00000000002641920924_2394749694_init();
    work_m_00000000001099455878_0886308060_init();
    work_m_00000000001282419994_3502763270_init();
    work_m_00000000003058831752_0417928461_init();
    work_m_00000000004161471116_2976069611_init();
    work_m_00000000002185753942_4060065668_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000002185753942_4060065668");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
