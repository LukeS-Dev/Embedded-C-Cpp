idf_component_register(
    SRCS "logging_demo.c"
    INCLUDE_DIRS "."
    REQUIRES 
        freertos
        esp_common
        ledControl
    )
