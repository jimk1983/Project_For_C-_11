#include "utils_spdlogger.h"


int main(int argc, char *argv[])
{
    std::string logPath = "./log.txt";
    SPDLOGOUT_Init(logPath);
    SPDLOGOUT_SetLevel(log_level_trace);
    SPDLOGOUT_Flush();

    SPDLOGOUT->critical("critical hello world,hex:{0:x},int:{1:d}; floats {2:03.2f}",42, 12345678987654321, 3.56789);
    SPDLOGOUT->error("error hello world, logpath={0}", logPath);
    SPDLOGOUT->warn("warn hello world");
    SPDLOGOUT->info("info hello world");
    SPDLOGOUT->debug("debug hello world");
    SPDLOGOUT->trace("trace hello world");

    SPDLOGOUT_SetLevel(log_level_info);

    SPDLOGOUT->critical("critical hello world");
    SPDLOGOUT->error("error hello world");
    SPDLOGOUT->warn("warn hello world");
    SPDLOGOUT->info("info hello world");
    SPDLOGOUT->debug("debug hello world");
    SPDLOGOUT->trace("trace hello world");
    

    SPDLOGOUT_UnInit();

    return 0;
}

