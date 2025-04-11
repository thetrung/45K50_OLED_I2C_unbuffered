include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(45K50_SSD1306_I2C_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_assemble)
add_library(A_45K50_SSD1306_I2C_default_default_XC8_assemble OBJECT ${45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_assemble})
    A_45K50_SSD1306_I2C_default_default_XC8_assemble_rule(A_45K50_SSD1306_I2C_default_default_XC8_assemble)
    list(APPEND 45K50_SSD1306_I2C_default_library_list "$<TARGET_OBJECTS:A_45K50_SSD1306_I2C_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(A_45K50_SSD1306_I2C_default_default_XC8_assemblePreprocess OBJECT ${45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_assemblePreprocess})
    A_45K50_SSD1306_I2C_default_default_XC8_assemblePreprocess_rule(A_45K50_SSD1306_I2C_default_default_XC8_assemblePreprocess)
    list(APPEND 45K50_SSD1306_I2C_default_library_list "$<TARGET_OBJECTS:A_45K50_SSD1306_I2C_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_compile)
add_library(A_45K50_SSD1306_I2C_default_default_XC8_compile OBJECT ${45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_compile})
    A_45K50_SSD1306_I2C_default_default_XC8_compile_rule(A_45K50_SSD1306_I2C_default_default_XC8_compile)
    list(APPEND 45K50_SSD1306_I2C_default_library_list "$<TARGET_OBJECTS:A_45K50_SSD1306_I2C_default_default_XC8_compile>")
endif()

add_executable(${45K50_SSD1306_I2C_default_image_name} ${45K50_SSD1306_I2C_default_library_list})

target_link_libraries(${45K50_SSD1306_I2C_default_image_name} PRIVATE ${45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
A_45K50_SSD1306_I2C_default_link_rule(${45K50_SSD1306_I2C_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${45K50_SSD1306_I2C_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${45K50_SSD1306_I2C_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${45K50_SSD1306_I2C_default_image_name} ${45K50_SSD1306_I2C_default_output_dir}/${45K50_SSD1306_I2C_default_original_image_name}
                    BYPRODUCTS ${45K50_SSD1306_I2C_default_output_dir}/${45K50_SSD1306_I2C_default_original_image_name})
