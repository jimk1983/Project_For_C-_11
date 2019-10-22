#ifndef _UTILS_SPDLOGGER_H_
#define _UTILS_SPDLOGGER_H_

#include <memory>
#include <string>
#include <iostream>
#include <array>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/common.h"
#include "spdlog/formatter.h"
#include "spdlog/sinks/sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "utils/utils_singleton.hpp"



typedef enum
{
    log_module_type_default = 0,
    log_module_type_gw_login,
    log_module_type_gw_access,

    log_module_type_nums
}log_module_type_e;



class SpdLoger
{
public:
    SpdLoger();
	~SpdLoger();

	bool Init(const std::string& logPath);
    void UnInit();
    const std::shared_ptr<spdlog::logger>& GetLoger(const log_module_type_e& log_type);
    void LogtypeRegister(const log_module_type_e& log_type);
    void LogtypeSetLevel(const log_module_type_e& log_type, const spdlog::level::level_enum& log_level);
private:
    std::vector<spdlog::sink_ptr>           m_sinks_;
    std::array<std::shared_ptr<spdlog::logger>, log_module_type_nums>     m_arry_loger_;
    uint32_t                                m_file_size_;
    uint32_t                                m_file_rotanums_;
};

typedef Singleton<SpdLoger>                 CSingletonSpdLoger; 
#define SPDLOGOUT_Init(log_path)            CSingletonSpdLoger::instance().Init(log_path);
#define SPDLOGOUT_UnInit()                  CSingletonSpdLoger::instance().UnInit();
#define SPDLOGOUT_Register(mType)           CSingletonSpdLoger::instance().LogtypeRegister(mType);

#define SPDLOGOUT_SetLevel(mType,mLevel)    CSingletonSpdLoger::instance().GetLoger(mType)->set_level(mLevel)
#define SPDLOGOUT_Flush(mType, mLevel)      CSingletonSpdLoger::instance().GetLoger(mType)->flush_on(mLevel);
#define SPDLOGOUT(mType)                    CSingletonSpdLoger::instance().GetLoger(mType)

#endif 