#include "utils_spdlogger.h"

//spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
//spdlog::set_pattern("[%D %T.%e Pid:%P Tid:%t %@ %n]-[%l] - %v");
//spdlog::set_pattern("[%D %T.%e] [%P:%t] [%n] [%^%l%$] %v");
#define     SPLOGER_FMT_PATTERN "[%D %T.%e] [%P:%t] [%n] [%^%l%$] %v"
#define     SPLOGER_FILE_SIZE   (10<<20)
#define     SPLOGER_FILE_RNUMS  5

SpdLoger::SpdLoger()
    :m_file_size_(SPLOGER_FILE_SIZE),
     m_file_rotanums_(SPLOGER_FILE_RNUMS)
{

}

SpdLoger::~SpdLoger()
{
    
}

bool SpdLoger::Init(const std::string& full_path)
{
    try {
        std::vector<spdlog::sink_ptr> sinks;
        sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(full_path, m_file_size_,m_file_rotanums_));
        m_loger_ = std::make_shared<spdlog::logger>("TRACE", begin(sinks), end(sinks));
        spdlog::register_logger(m_loger_);
        spdlog::set_level(spdlog::level::trace);
        spdlog::set_pattern(SPLOGER_FMT_PATTERN);
    }
    catch (const spdlog::spdlog_ex& ex) {
        std::cout << "log initialization failed: " << ex.what() << std::endl;
        return false;
    }

    return true;
}

void SpdLoger::unInit()
{
    spdlog::drop_all();
}



void SpdLoger::SetLevel(const log_level_enum log_level)
{
    if (log_level >=log_level_nums)
    {
        spdlog::set_level(spdlog::level::off);
        return;
    }

    spdlog::set_level((spdlog::level::level_enum)log_level);
}










