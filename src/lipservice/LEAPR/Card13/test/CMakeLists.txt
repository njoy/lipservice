
add_executable( lipservice.LEAPR.Card13.test Card13.test.cpp )
target_compile_options( lipservice.LEAPR.Card13.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${LegacyInputVerification_appended_flags} )
target_link_libraries( lipservice.LEAPR.Card13.test PUBLIC LegacyInputVerification ) 
add_test( NAME lipservice.LEAPR.Card13 COMMAND lipservice.LEAPR.Card13.test )