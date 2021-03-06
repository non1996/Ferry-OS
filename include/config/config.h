//
// Created by 王耀 on 2017/9/16.
//

#ifndef SDOS_CONFIG_H
#define SDOS_CONFIG_H

#include <string>
#include "macro.h"

class Config {
private:
    std::string mConfigPath;
    static Config *instance;

    explicit Config(const std::string& path);
    void loadDefault();
public:
    static bool mShowErrorLog;
    static Config *getInstance();
    static bool init(const std::string &path = "./config.json", const bool showErrorLog = false);
    bool reload();
    bool check();
    bool mValid;

    struct CPU {
        unsigned int CORE_NUM;
        unsigned long CPU_RATE;             // GHz
    } CPU;

    struct DISK {
        std::string ROOT_PATH;
        unsigned int BLOCK_SIZE;              // Byte
        unsigned long BLOCK_COUNT;            // Block
        struct BUFFER {
            unsigned int DEFAULT_BLOCK;
            unsigned int MAX_BLOCK;
            unsigned int MIN_BLOCK;
        } BUFFER;
        unsigned int DEFAULT_BLOCKS_PER_FILE;
    } DISK;

    struct MEM {
        unsigned long DEFAULT_CAPACITY;        // Page
        unsigned long DEFAULT_PROCESS_PAGE;    // Page
        unsigned long DEFAULT_STACK_PAGE;      // Page
        unsigned char DEFAULT_PAGE_BIT;
        unsigned int DEFAULT_PAGE_SIZE;       // Byte
    } MEM;

    struct OS {
        struct MEM {
            unsigned int DEFAULT_OS_USED_PAGE;  // Page
            unsigned long SWAP_PAGE;            // Page
            unsigned long SWAP_BLOCK;           // Block
            unsigned long SWAP_SIZE;            // Byte
        } MEM;
        unsigned int BOOT_MEMORY_KB;            // KByte
        unsigned int MAXIMUM_TASKS;
        unsigned long MAXIMUM_TASK_PAGE;        // Page
        std::string EXEC_FILE_EXT;              // extension
        unsigned long TICKS_PER_SEC;            // Count
        unsigned long TICKS_PER_SCHED;          // Count
        unsigned long MAX_SEM;
    } OS;
};

#endif //SDOS_CONFIG_H
