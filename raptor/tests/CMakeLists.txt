add_executable(test_strength test_strength.cpp)
target_link_libraries(test_strength raptor googletest pthread )
add_test(StrengthTest ./test_strength)

if (WITH_MPI)
    add_executable(test_par_strength test_par_strength.cpp)
    target_link_libraries(test_par_strength raptor ${MPI_LIBRARIES}  googletest pthread )
    add_test(ParStrengthTest_1 mpirun -n 1 ./test_par_strength)
    add_test(ParStrengthTest_2 mpirun -n 2 ./test_par_strength)
endif()
