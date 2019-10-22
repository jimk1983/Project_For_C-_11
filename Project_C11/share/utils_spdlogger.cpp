#include "utils_spdlogger.h"


typedef struct tagSpLoggerModuleInfo
{
    log_module_type_e           module_type;
    const char*                 module_name;    //8 Length Align
}splogger_module_info_s;


const splogger_module_info_s g_sploger_info[] =
{
    {
        log_module_type_default,
        " DEFAULT"
    },
    {
        log_module_type_gw_login,
        " GWLOGIN"
    },
    {
        log_module_type_gw_access,
        " GWACESS"
    }
};

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
        m_sinks_.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        m_sinks_.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(full_path, m_file_size_, m_file_rotanums_));
        spdlog::set_pattern(SPLOGER_FMT_PATTERN);
        m_arry_loger_[log_module_type_default] = std::make_shared<spdlog::logger>(g_sploger_info[log_module_type_default].module_name, begin(m_sinks_), end(m_sinks_));
        spdlog::register_logger(m_arry_loger_[log_module_type_default]);
        spdlog::set_level(spdlog::level::trace);
        spdlog::flush_on(spdlog::level::info);

        for (auto loger_item_sptr : m_arry_loger_){
            loger_item_sptr = nullptr;
        }
    }
    catch (const spdlog::spdlog_ex& ex) {
        std::cout << "log initialization failed: " << ex.what() << std::endl;
        return false;
    }

    return true;
}

void SpdLoger::UnInit()
{
    spdlog::drop_all();
}


const std::shared_ptr<spdlog::logger>& SpdLoger::GetLoger(const log_module_type_e& log_type)
{
    if (log_type >= log_module_type_nums ){
        std::cout << "Log type has invalid!type="<< log_type << std::endl;
        return m_arry_loger_[log_module_type_default];
    }
    if ( nullptr == m_arry_loger_[log_type]) {

        return m_arry_loger_[log_module_type_default];
    }
    return m_arry_loger_[log_type];
}

void SpdLoger::LogtypeRegister(const log_module_type_e& log_type)
{
    if (log_type >= log_module_type_nums) {
        std::cout << "Log type has invalid! type="<< log_type << std::endl;
        return;
    }
    m_arry_loger_[log_type] = std::make_shared<spdlog::logger>(g_sploger_info[log_type].module_name, begin(m_sinks_), end(m_sinks_));
    if (nullptr == m_arry_loger_[log_type] ) {
        std::cout << "Make log share ptr failed! type=" << log_type << std::endl;
        return;
    }
    spdlog::register_logger(m_arry_loger_[log_type]);
    return;
}

void SpdLoger::LogtypeSetLevel(const log_module_type_e& log_type, const spdlog::level::level_enum& log_level)
{
    if (log_type >= log_module_type_nums) {
        std::cout << "Log type has invalid! type=" << log_type << std::endl;
        return;
    }
    
    if ( nullptr == m_arry_loger_[log_type] ){
        std::cout << "Make log share ptr failed! type=" << log_type << std::endl;
        return;
    }
    //spdlog::level::trace
    m_arry_loger_[log_type]->set_level(log_level);
    return;
}









