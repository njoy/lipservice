
add_executable( lipservice.ACER.Card6.Ismooth.test Ismooth.test.cpp )
target_compile_options( lipservice.ACER.Card6.Ismooth.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${lipservice_appended_flags} )
target_link_libraries( lipservice.ACER.Card6.Ismooth.test PUBLIC lipservice ) 
add_test( NAME lipservice.ACER.Card6.Ismooth COMMAND lipservice.ACER.Card6.Ismooth.test )