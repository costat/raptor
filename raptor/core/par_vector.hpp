// Copyright (c) 2015, Raptor Developer Team, University of Illinois at Urbana-Champaign
// License: Simplified BSD, http://opensource.org/licenses/BSD-2-Clause
#ifndef RAPTOR_CORE_PARVECTOR_HPP
#define RAPTOR_CORE_PARVECTOR_HPP

#include <mpi.h>
#include <math.h>

#include "types.hpp"
#include "vector.hpp"

namespace raptor
{

    class ParVector
    {
    public:
        ParVector(index_t glbl_n, index_t lcl_n)
        {
            global_n = glbl_n;
            local_n = lcl_n;
            if (local_n)
            {
                local = new Vector(local_n);
            }
        }
        ParVector(ParVector&& x);
        ~ParVector()
        {
            if (local_n)
            {
                delete local;
            }
        }

        template<int p> data_t norm() const
        {
            data_t result;
            if (local_n)
            {
                result = local->lpNorm<p>();
                result = pow(result, p); // undoing root of p from local operation
            }
            else
            {
                result = 0.0;
            }
            MPI_Allreduce(MPI_IN_PLACE, &result, 1, MPI_DATA_T, MPI_SUM, MPI_COMM_WORLD);
            return pow(result, 1./p);
        }

        void axpy(const ParVector & x, data_t alpha);
        void scale(data_t alpha);
        void set_const_value(data_t alpha);
        void set_rand_values();

        Vector* local;
        int global_n;
        int local_n;
    };

}
#endif
