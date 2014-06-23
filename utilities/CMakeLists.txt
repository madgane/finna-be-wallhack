
FILE(GLOB filesInDirectory "." "*.cpp")
message (${filesInDirectory})
add_library (utilities ${filesInDirectory})

