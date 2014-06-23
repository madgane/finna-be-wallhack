
FILE(GLOB filesInDirectory "." "*.cpp")
message (${filesInDirectory})
add_library (framework ${filesInDirectory})

