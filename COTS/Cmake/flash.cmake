macro(convert_to_hex_and_flash PROJECT_NAME PROGRAMMER MCU)
    
    add_custom_target(
        flash_${PROJECT_NAME}
        ALL
        DEPENDS ${PROJECT_NAME}
        COMMAND avr-objcopy -O ihex ${PROJECT_NAME} ${PROJECT_NAME}.hex
        COMMENT "Converting ${PROJECT_NAME} ELF to HEX file"
    )

    
    set_directory_properties(
        PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${PROJECT_NAME}.hex"
    )

    
    add_custom_target(
        burn_${PROJECT_NAME}
        DEPENDS flash_${PROJECT_NAME}
        COMMAND avrdude -c ${PROGRAMMER} -p ${MCU} -U flash:w:${PROJECT_NAME}.hex:i -B 1
        COMMENT "Flashing ${PROJECT_NAME} firmware to MCU"
    )
endmacro()