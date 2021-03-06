add_executable(test_spmv_laplacian test_spmv_laplacian.cpp)
target_link_libraries(test_spmv_laplacian raptor googletest pthread )
add_test(LaplacianSpMVTest ./test_spmv_laplacian)

add_executable(test_spmv_aniso test_spmv_aniso.cpp)
target_link_libraries(test_spmv_aniso raptor googletest pthread )
add_test(AnisoSpMVTest ./test_spmv_aniso)

add_executable(test_spmv_random test_spmv_random.cpp)
target_link_libraries(test_spmv_random raptor googletest pthread )
add_test(RandomSpMVTest ./test_spmv_random)

add_executable(test_bsr_spmv_aniso test_bsr_spmv_aniso.cpp)
target_link_libraries(test_bsr_spmv_aniso raptor googletest pthread )
add_test(AnisoBSRSpMVTest ./test_bsr_spmv_aniso)

add_executable(test_bsr_spmv_laplacian test_bsr_spmv_laplacian.cpp)
target_link_libraries(test_bsr_spmv_laplacian raptor googletest pthread )
add_test(LaplacianBSRSpMVTest ./test_bsr_spmv_laplacian)

add_executable(test_bsr_spmv_random test_bsr_spmv_random.cpp)
target_link_libraries(test_bsr_spmv_random raptor googletest pthread )
add_test(RandomBSRSpMVTest ./test_bsr_spmv_random)

if (WITH_MPI)
    add_executable(test_par_add test_par_add.cpp)
    target_link_libraries(test_par_add raptor ${MPI_LIBRARIES} googletest pthread )
    add_test(ParAddTest_1 mpirun -n 1 ./test_par_add)
    add_test(ParAddTest_16 mpirun -n 16 ./test_par_add)

    add_executable(test_par_spmv_laplacian test_par_spmv_laplacian.cpp)
    target_link_libraries(test_par_spmv_laplacian raptor ${MPI_LIBRARIES} googletest pthread )
    add_test(ParLaplacianSpMVTest_1 mpirun -n 1 ./test_par_spmv_laplacian)
    add_test(ParLaplacianSpMVTest_2 mpirun -n 2 ./test_par_spmv_laplacian)
    add_test(ParLaplacianSpMVTest_4 mpirun -n 4 ./test_par_spmv_laplacian)
    add_test(ParLaplacianSpMVTest_8 mpirun -n 8 ./test_par_spmv_laplacian)
    add_test(ParLaplacianSpMVTest_16 mpirun -n 16 ./test_par_spmv_laplacian)

    add_executable(test_par_spmv_aniso test_par_spmv_aniso.cpp)
    target_link_libraries(test_par_spmv_aniso raptor ${MPI_LIBRARIES} googletest pthread )
    add_test(ParAnisoSpMVTest_1 mpirun -n 1 ./test_par_spmv_aniso)
    add_test(ParAnisoSpMVTest_2 mpirun -n 2 ./test_par_spmv_aniso)
    add_test(ParAnisoSpMVTest_4 mpirun -n 4 ./test_par_spmv_aniso)
    add_test(ParAnisoSpMVTest_8 mpirun -n 8 ./test_par_spmv_aniso)
    add_test(ParAnisoSpMVTest_16 mpirun -n 16 ./test_par_spmv_aniso)

    add_executable(test_par_spmv_random test_par_spmv_random.cpp)
    target_link_libraries(test_par_spmv_random ${MPI_LIBRARIES} raptor googletest pthread )
    add_test(ParRandomSpMVTest_1 mpirun -n 1 ./test_par_spmv_random)
    add_test(ParRandomSpMVTest_2 mpirun -n 2 ./test_par_spmv_random)
    add_test(ParRandomSpMVTest_4 mpirun -n 4 ./test_par_spmv_random)
    add_test(ParRandomSpMVTest_8 mpirun -n 8 ./test_par_spmv_random)
    add_test(ParRandomSpMVTest_16 mpirun -n 16 ./test_par_spmv_random)
    
    add_executable(test_tap_spmv_laplacian test_tap_spmv_laplacian.cpp)
    target_link_libraries(test_tap_spmv_laplacian raptor ${MPI_LIBRARIES} googletest pthread )
    add_test(TAPLaplacianSpMVTest_2 mpirun -n 2 ./test_tap_spmv_laplacian)
    add_test(TAPLaplacianSpMVTest_4 mpirun -n 4 ./test_tap_spmv_laplacian)
    add_test(TAPLaplacianSpMVTest_8 mpirun -n 8 ./test_tap_spmv_laplacian)
    add_test(TAPLaplacianSpMVTest_16 mpirun -n 16 ./test_tap_spmv_laplacian)

    add_executable(test_tap_spmv_aniso test_tap_spmv_aniso.cpp)
    target_link_libraries(test_tap_spmv_aniso raptor ${MPI_LIBRARIES} googletest pthread )
    add_test(TAPAnisoSpMVTest_2 mpirun -n 2 ./test_tap_spmv_aniso)
    add_test(TAPAnisoSpMVTest_4 mpirun -n 4 ./test_tap_spmv_aniso)
    add_test(TAPAnisoSpMVTest_8 mpirun -n 8 ./test_tap_spmv_aniso)
    add_test(TAPAnisoSpMVTest_16 mpirun -n 16 ./test_tap_spmv_aniso)

    add_executable(test_tap_spmv_random test_tap_spmv_random.cpp)
    target_link_libraries(test_tap_spmv_random ${MPI_LIBRARIES} raptor googletest pthread )
    add_test(TAPRandomSpMVTest_2 mpirun -n 2 ./test_tap_spmv_random)
    add_test(TAPRandomSpMVTest_4 mpirun -n 4 ./test_tap_spmv_random)
    add_test(TAPRandomSpMVTest_8 mpirun -n 8 ./test_tap_spmv_random)

    add_executable(test_par_bsr_spmv test_par_bsr_spmv.cpp)
    target_link_libraries(test_par_bsr_spmv raptor ${MPI_LIBRARIES} googletest pthread )
    add_test(ParBSRSpMVTest_1 mpirun -n 1 ./test_par_bsr_spmv)
    add_test(ParBSRSpMVTest_2 mpirun -n 2 ./test_par_bsr_spmv)
    add_test(ParBSRSpMVTest_3 mpirun -n 3 ./test_par_bsr_spmv)
    add_test(ParBSRSpMVTest_6 mpirun -n 6 ./test_par_bsr_spmv)

    if (WITH_PTSCOTCH)
        add_executable(test_repartition test_repartition.cpp)
        target_link_libraries(test_repartition raptor ${MPI_LIBRARIES} googletest pthread )
    endif()
endif()
