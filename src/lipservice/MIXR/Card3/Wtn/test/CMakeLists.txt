
add_executable( lipservice.MIXR.Card3.Wtn.test Wtn.test.cpp )
target_compile_options( lipservice.MIXR.Card3.Wtn.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${LegacyInputVerification_appended_flags} )
target_link_libraries( lipservice.MIXR.Card3.Wtn.test PUBLIC LegacyInputVerification ) 
add_test( NAME lipservice.MIXR.Card3.Wtn COMMAND lipservice.MIXR.Card3.Wtn.test )