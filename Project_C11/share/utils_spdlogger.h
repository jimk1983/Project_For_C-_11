#ifndef _UTILS_SPDLOGGER_H_
#define _UTILS_SPDLOGGER_H_

#include <memory>
#include <string>
#include <iostream>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/common.h"
#include "spdlog/formatter.h"
#include "spdlog/sinks/sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "utils/utils_singleton.hpp"


enum log_level_enum
{
    log_level_trace= SPDLOG_LEVEL_TRACE,
    log_level_debug= SPDLOG_LEVEL_DEBUG,
    log_level_info= SPDLOG_LEVEL_INFO,
    log_level_warn= SPDLOG_LEVEL_WARN,
    log_level_error= SPDLOG_LEVEL_ERROR,
    log_level_critical= SPDLOG_LEVEL_CRITICAL,
    log_level_off= SPDLOG_LEVEL_OFF,

    log_level_nums
};

class SpdLoger
{
public:
    SpdLoger();
	~SpdLoger();

	bool Init(const std::string& logPath);
	void unInit();
    const std::shared_ptr<spdlog::logger>& GetLoger() { return m_loger_; }
    void SetLevel(const log_level_enum log_level);

private:
    std::shared_ptr<spdlog::logger>     m_loger_;
    uint32_t                            m_file_size_;
    uint32_t                            m_file_rotanums_;
};

typedef Singleton<SpdLoger>             CSingletonSpdLoger; 
#define SPDLOGOUT_Init(log_path)        CSingletonSpdLoger::instance().Init(log_path);
#define SPDLOGOUT_UnInit()              CSingletonSpdLoger::instance().unInit();
#define SPDLOGOUT_SetLevel(log_level)   CSingletonSpdLoger::instance().SetLevel(log_level)
#define SPDLOGOUT_Flush()               CSingletonSpdLoger::instance().GetLoger()->flush_on(spdlog::level::trace);
#define SPDLOGOUT                       CSingletonSpdLoger::instance().GetLoger()

#endif 