
add_executable( legacyInputVerification.LEAPR.Card19.Cfrac.test Cfrac.test.cpp )
target_compile_options( legacyInputVerification.LEAPR.Card19.Cfrac.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${LegacyInputVerification_appended_flags} )
target_link_libraries( legacyInputVerification.LEAPR.Card19.Cfrac.test PUBLIC LegacyInputVerification ) 
add_test( NAME legacyInputVerification.LEAPR.Card19.Cfrac COMMAND legacyInputVerification.LEAPR.Card19.Cfrac.test )