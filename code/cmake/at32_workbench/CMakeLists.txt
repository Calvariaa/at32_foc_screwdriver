cmake_minimum_required(VERSION 3.22)
# Enable CMake support for ASM and C languages
enable_language(C ASM)
# AT32 WorkBench generated symbols (macros)
set(WK_Defines_Syms
    USE_STDPERIPH_DRIVER
    ARM_MATH_CM4
    ARM_MATH_MATRIX_CHECK
    ARM_MATH_ROUNDING
    ARM_MATH_LOOPUNROLL
    AT32M416EBP7
    $<$<CONFIG:Debug>:DEBUG>
)

# AT32 WorkBench generated include paths
set(WK_Include_Dirs
    ${CMAKE_SOURCE_DIR}/project/inc
    ${CMAKE_SOURCE_DIR}/libraries/drivers/inc
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/cm4/core_support
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/cm4/device_support
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/include
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/PrivateInclude
)

# AT32 WorkBench generated application sources
set(WK_Application_Src
    ${CMAKE_SOURCE_DIR}/project/src/main.c
    ${CMAKE_SOURCE_DIR}/project/src/syscalls.c
    ${CMAKE_SOURCE_DIR}/project/src/sysmem.c
    ${CMAKE_SOURCE_DIR}/project/src/at32m412_416_wk_config.c
    ${CMAKE_SOURCE_DIR}/project/src/at32m412_416_int.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_system.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_adc.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_i2c.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_tmr.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_usart.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_gpio.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_exint.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_dma.c
    ${CMAKE_SOURCE_DIR}/startup_at32m412_416.s
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/BasicMathFunctions/BasicMathFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/BayesFunctions/BayesFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/CommonTables/CommonTables.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/ComplexMathFunctions/ComplexMathFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/ControllerFunctions/ControllerFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/DistanceFunctions/DistanceFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/FastMathFunctions/FastMathFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/FilteringFunctions/FilteringFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/InterpolationFunctions/InterpolationFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/MatrixFunctions/MatrixFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/QuaternionMathFunctions/QuaternionMathFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/StatisticsFunctions/StatisticsFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/SupportFunctions/SupportFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/SVMFunctions/SVMFunctions.c
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/dsp/Source/TransformFunctions/TransformFunctions.c
)

# AT32 Drivers
set(AT32_Drivers_Src
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/cm4/device_support/system_at32m412_416.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_crm.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_tmr.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_gpio.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_i2c.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_usart.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_pwc.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_adc.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_dma.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_debug.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_flash.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_exint.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_misc.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32m412_416_scfg.c
)

# Drivers Middlewares

# Link directories setup
set(WK_LINK_DIRS

)

# Project static libraries
set(WK_LINK_LIBS
    AT32_Drivers
)

# Interface library for includes and symbols
add_library(at32_workbench INTERFACE)
target_include_directories(at32_workbench INTERFACE ${WK_Include_Dirs})
target_compile_definitions(at32_workbench INTERFACE ${WK_Defines_Syms})

# Create AT32_Drivers static library
add_library(AT32_Drivers OBJECT)
target_sources(AT32_Drivers PRIVATE ${AT32_Drivers_Src})
target_link_libraries(AT32_Drivers PUBLIC at32_workbench)

# Add AT32 WorkBench generated application sources to the project
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${WK_Application_Src})

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${WK_LINK_DIRS})

# Add libraries to the project
target_link_libraries(${CMAKE_PROJECT_NAME} ${WK_LINK_LIBS})

# Add the map file to the list of files to be removed with 'clean' target
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES ADDITIONAL_CLEAN_FILES ${CMAKE_PROJECT_NAME}.map)

# Validate that AT32 WorkBench code is compatible with C standard
if((CMAKE_C_STANDARD EQUAL 90) OR (CMAKE_C_STANDARD EQUAL 99))
    message(ERROR "Generated code requires C11 or higher")
endif()
