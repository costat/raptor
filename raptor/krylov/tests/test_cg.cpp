#include <assert.h>

#include "core/types.hpp"
#include "core/matrix.hpp"
#include "core/vector.hpp"
#include "krylov/cg.hpp"
#include "gallery/diffusion.hpp"
#include "gallery/stencil.hpp"

using namespace raptor;

int main(int argc, char* argv[])
{    
    int grid[2] = {50, 50};
    double* stencil = diffusion_stencil_2d(0.001, M_PI/8.0);
    CSRMatrix* A = stencil_grid(stencil, grid, 2);
    Vector x(A->n_rows);
    Vector b(A->n_rows);
    aligned_vector<double> residuals;

    x.set_const_value(1.0);
    A->mult(x, b);
    x.set_const_value(0.0);

    CG(A, x, b, residuals);
    printf("Residuals[0] = %e\n", residuals[0]);

    FILE* f = fopen("../../../../test_data/cg_res.txt", "r");
    double res;
    for (int i = 0; i < residuals.size(); i++)
    {
        fscanf(f, "%lf\n", &res);
        assert(fabs(res - residuals[i]) < 1e-06);
    }
    fclose(f);

    delete[] stencil;
    delete A;

    return 0;
}
