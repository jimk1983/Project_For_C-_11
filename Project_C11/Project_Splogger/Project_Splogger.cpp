#include "utils_spdlogger.h"


int main(int argc, char *argv[])
{
    std::string logPath = "./log.txt";
    SPDLOGOUT_Init(logPath);

    SPDLOGOUT_SetLevel(log_module_type_default, spdlog::level::trace);

    SPDLOGOUT(log_module_type_default)->critical("critical hello world,hex:{0:x},int:{1:d}; floats {2:03.2f}",42, 12345678987654321, 3.56789);
    SPDLOGOUT(log_module_type_default)->error("error hello world, logpath={0}", logPath);
    SPDLOGOUT(log_module_type_default)->warn("warn hello world");
    SPDLOGOUT(log_module_type_default)->info("info hello world");
    SPDLOGOUT(log_module_type_default)->debug("debug hello world");
    SPDLOGOUT(log_module_type_default)->trace("trace hello world");
    SPDLOGOUT_Flush(log_module_type_default, spdlog::level::trace);

    SPDLOGOUT_Register(log_module_type_gw_login);
    SPDLOGOUT_SetLevel(log_module_type_gw_login, spdlog::level::trace);

    SPDLOGOUT(log_module_type_gw_login)->critical("critical hello world,hex:{0:x},int:{1:d}; floats {2:03.2f}", 42, 12345678987654321, 3.56789);
    SPDLOGOUT(log_module_type_gw_login)->error("error hello world, logpath={0}", logPath);
    SPDLOGOUT(log_module_type_gw_login)->warn("warn hello world");
    SPDLOGOUT(log_module_type_gw_login)->info("info hello world");
    SPDLOGOUT(log_module_type_gw_login)->debug("debug hello world");
    SPDLOGOUT(log_module_type_gw_login)->trace("trace hello world");
    SPDLOGOUT_Flush(log_module_type_gw_login, spdlog::level::trace);


    SPDLOGOUT_Register(log_module_type_gw_access);
    SPDLOGOUT_SetLevel(log_module_type_gw_login, spdlog::level::info);
    SPDLOGOUT(log_module_type_gw_access)->critical("critical hello world,hex:{0:x},int:{1:d}; floats {2:03.2f}", 42, 12345678987654321, 3.56789);
    SPDLOGOUT(log_module_type_gw_access)->error("error hello world, logpath={0}", logPath);
    SPDLOGOUT(log_module_type_gw_access)->warn("warn hello world");
    SPDLOGOUT(log_module_type_gw_access)->info("info hello world");
    SPDLOGOUT(log_module_type_gw_access)->debug("debug hello world");
    SPDLOGOUT(log_module_type_gw_access)->trace("trace hello world");


    SPDLOGOUT_SetLevel(log_module_type_gw_login, spdlog::level::info);

    SPDLOGOUT(log_module_type_gw_login)->critical("critical hello world,hex:{0:x},int:{1:d}; floats {2:03.2f}", 42, 12345678987654321, 3.56789);
    SPDLOGOUT(log_module_type_gw_login)->error("error hello world, logpath={0}", logPath);
    SPDLOGOUT(log_module_type_gw_login)->warn("warn hello world");
    SPDLOGOUT(log_module_type_gw_login)->info("info hello world");
    SPDLOGOUT(log_module_type_gw_login)->debug("debug hello world");
    SPDLOGOUT(log_module_type_gw_login)->trace("trace hello world");



    SPDLOGOUT_UnInit();

    return 0;
}

