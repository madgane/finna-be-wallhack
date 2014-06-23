
FILE(GLOB filesInDirectory "." "*.cpp")
message (${filesInDirectory})
add_library (schedulers ${filesInDirectory})

