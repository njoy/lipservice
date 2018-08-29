
add_executable( legacyInputVerification.WIMSR.Card6c.test Card6c.test.cpp )
target_compile_options( legacyInputVerification.WIMSR.Card6c.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${LegacyInputVerification_appended_flags} )
target_link_libraries( legacyInputVerification.WIMSR.Card6c.test PUBLIC LegacyInputVerification ) 
add_test( NAME legacyInputVerification.WIMSR.Card6c COMMAND legacyInputVerification.WIMSR.Card6c.test )