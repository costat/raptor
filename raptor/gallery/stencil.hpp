// Copyright (c) 2015, Raptor Developer Team, University of Illinois at Urbana-Champaign
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#ifndef STENCIL_HPP
#define STENCIL_HPP

#include <mpi.h>
#include <float.h>
#include <cmath>
#include <stdlib.h>

#include "core/par_matrix.hpp"
#include "core/types.hpp"

using namespace raptor;

ParMatrix* stencil_grid(data_t* stencil, int* grid, int dim, format_t format = CSR);

#endif