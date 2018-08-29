
add_executable( lipservice.WIMSR.Card2.Iverw.test Iverw.test.cpp )
target_compile_options( lipservice.WIMSR.Card2.Iverw.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${LegacyInputVerification_appended_flags} )
target_link_libraries( lipservice.WIMSR.Card2.Iverw.test PUBLIC LegacyInputVerification ) 
add_test( NAME lipservice.WIMSR.Card2.Iverw COMMAND lipservice.WIMSR.Card2.Iverw.test )