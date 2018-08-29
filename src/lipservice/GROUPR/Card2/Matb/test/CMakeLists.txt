
add_executable( lipservice.GROUPR.Card2.Matb.test Matb.test.cpp )
target_compile_options( lipservice.GROUPR.Card2.Matb.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${LegacyInputVerification_appended_flags} )
target_link_libraries( lipservice.GROUPR.Card2.Matb.test PUBLIC LegacyInputVerification ) 
add_test( NAME lipservice.GROUPR.Card2.Matb COMMAND lipservice.GROUPR.Card2.Matb.test )