
add_executable( lipservice.DTFR.Card7.Ngp.test Ngp.test.cpp )
target_compile_options( lipservice.DTFR.Card7.Ngp.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${LegacyInputVerification_appended_flags} )
target_link_libraries( lipservice.DTFR.Card7.Ngp.test PUBLIC LegacyInputVerification ) 
add_test( NAME lipservice.DTFR.Card7.Ngp COMMAND lipservice.DTFR.Card7.Ngp.test )