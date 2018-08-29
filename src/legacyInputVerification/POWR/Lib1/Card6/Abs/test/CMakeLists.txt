
add_executable( legacyInputVerification.POWR.Lib1.Card6.Abs.test Abs.test.cpp )
target_compile_options( legacyInputVerification.POWR.Lib1.Card6.Abs.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${LegacyInputVerification_appended_flags} )
target_link_libraries( legacyInputVerification.POWR.Lib1.Card6.Abs.test PUBLIC LegacyInputVerification ) 
add_test( NAME legacyInputVerification.POWR.Lib1.Card6.Abs COMMAND legacyInputVerification.POWR.Lib1.Card6.Abs.test )