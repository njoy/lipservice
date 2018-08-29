
add_executable( legacyInputVerification.GROUPR.Card6b.Egn.test Egn.test.cpp )
target_compile_options( legacyInputVerification.GROUPR.Card6b.Egn.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${LegacyInputVerification_appended_flags} )
target_link_libraries( legacyInputVerification.GROUPR.Card6b.Egn.test PUBLIC LegacyInputVerification ) 
add_test( NAME legacyInputVerification.GROUPR.Card6b.Egn COMMAND legacyInputVerification.GROUPR.Card6b.Egn.test )