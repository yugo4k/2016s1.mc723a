/******************************************************
 * This is the main file for the mips ArchC model     *
 * This file is automatically generated by ArchC      *
 * WITHOUT WARRANTY OF ANY KIND, either express       *
 * or implied.                                        *
 * For more information on ArchC, please visit:       *
 * http://www.archc.org                               *
 *                                                    *
 * The ArchC Team                                     *
 * Computer Systems Laboratory (LSC)                  *
 * IC-UNICAMP                                         *
 * http://www.lsc.ic.unicamp.br                       *
 ******************************************************/
 

const char *project_name="mips";
const char *project_file="mips.ac";
const char *archc_version="2.2";
const char *archc_options="-abi ";

#include  <iostream>
#include  <systemc.h>
#include  "ac_stats_base.H"
#include  "mips.H"

#include  "ac_tlm_mem.h"
#include  "ac_tlm_router.h"
#include  "ac_tlm_peripheral.h"

using user::ac_tlm_mem;
using user::ac_tlm_router;
using user::ac_tlm_peripheral;

static void free_avn(int ac, char*** avn) {
  int i = 0, j = 0;
  for (i = 0; i < 2; ++i) {
    for (j = 0; j < ac; ++j) {
      free(avn[i][j]);
      avn[i][j] = (char*)NULL;
    }
    free(avn[i]);
    avn[i] = (char**)NULL;
  }
  free(avn);
}

int sc_main(int ac, char *av[])
{
  sc_report_handler::set_actions("/IEEE/Std_1666/deprecated",
				 SC_DO_NOTHING);
  // !  ISA simulator
  mips mips_proc1("mips1"), mips_proc2("mips2");
  ac_tlm_mem mem("mem", 100*1024*1024);
  ac_tlm_router router("router");
  ac_tlm_peripheral peripheral("peripheral"); 

  int ac1 = ac, ac2 = ac;
  int i = 0, j = 0;
  char ***avn = (char***)calloc(2, sizeof(char**));
  for (i = 0; i < 2; ++i) {
    avn[i] = (char**)calloc(ac, sizeof(char*));
    if (avn[i] == (char**)NULL) {
      free_avn(ac, avn);
      avn = (char***)NULL;
      return 0;
    }
    for (j = 0; j < ac; ++j) {
      avn[i][j] = (char*)calloc(1 + strlen(av[j]), sizeof(char));
      if (avn[i] == (char**)NULL) {
    	free_avn(ac, avn);
    	avn = (char***)NULL;
      }
      strncpy(avn[i][j], av[j], strlen(av[j]));
    }
  }

  router.MEM_port(mem.target_export);
  router.PERIPHERAL_port(peripheral.target_export); 

  mips_proc1.DM_port(router.target_export1);
  mips_proc2.DM_port(router.target_export2);


#ifdef AC_DEBUG
  ac_trace("mips_proc1.trace");
  ac_trace("mips_proc2.trace");
#endif 

  // printf("here\n");

  mips_proc1.init(ac1, avn[0]);
  mips_proc2.init(ac2, avn[1]);
  cerr << endl;

  mips_proc1.set_instr_batch_size(1);
  mips_proc2.set_instr_batch_size(1);

  // sc_start(-1);
  sc_start();

  mips_proc1.PrintStat();
  mips_proc2.PrintStat();
  cerr << endl;

#ifdef AC_STATS
  ac_stats_base::print_all_stats(std::cerr);
#endif 

#ifdef AC_DEBUG
  ac_close_trace();
#endif 

  free_avn(ac, avn);
  avn = (char***)NULL;

  return mips_proc1.ac_exit_status + mips_proc2.ac_exit_status;
}
