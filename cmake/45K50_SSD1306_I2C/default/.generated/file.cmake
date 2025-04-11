# The following variables contains the files used by the different stages of the build process.
set(45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)
set(45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)
set(45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../I2CMaster.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../OLED.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../init.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../main.c")
set_source_files_properties(${45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(45K50_SSD1306_I2C_default_default_XC8_FILE_TYPE_link)

# The (internal) path to the resulting build image.
set(45K50_SSD1306_I2C_default_internal_image_name "${CMAKE_CURRENT_SOURCE_DIR}/../../../_build/45K50_SSD1306_I2C/default/default.elf")

# The name of the resulting image, including namespace for configuration.
set(45K50_SSD1306_I2C_default_image_name "45K50_SSD1306_I2C_default_default.elf")

# The name of the image, excluding the namespace for configuration.
set(45K50_SSD1306_I2C_default_original_image_name "default.elf")

# The output directory of the final image.
set(45K50_SSD1306_I2C_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/45K50_SSD1306_I2C")
