/*

   BLIS
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin
   Copyright (C) 2018 - 2019, Advanced Micro Devices, Inc.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "test_l0.hpp"

/******************************************************************************
 *
 * swaps
 *
 *****************************************************************************/

#undef GENTFUNC
#define GENTFUNC( opname, ctypex, chx, ctypey, chy ) \
UNIT_TEST(chx,chy,opname) \
( \
	for ( auto x : test_values<ctypex>() ) \
	for ( auto y : test_values<ctypey>() ) \
	{ \
		auto x0 = convert<ctypex>( y ); \
		auto y0 = convert<ctypey>( x ); \
\
		INFO( "x (init): " << x ); \
		INFO( "y (init): " << y ); \
\
		bli_tswaps( chx,chy, x, y ); \
\
		INFO( "x (C++):  " << x0 ); \
		INFO( "y (C++):  " << y0 ); \
		INFO( "x (BLIS): " << x ); \
		INFO( "y (BLIS): " << y ); \
\
		check<ctypex>( x, x0 ); \
		check<ctypey>( y, y0 ); \
	} \
)

INSERT_GENTFUNC_MIX2( RC, RC, swaps )

#undef GENTFUNC
#define GENTFUNC( opname, ctypex, chx, ctypey, chy ) \
UNIT_TEST(chx,chy,opname) \
( \
	for ( auto x : test_values<ctypex>() ) \
	for ( auto y : test_values<ctypey>() ) \
	{ \
		auto x0 = convert<ctypex>( y ); \
		auto y0 = convert<ctypey>( x ); \
\
		INFO( "x (init): " << x ); \
		INFO( "y (init): " << y ); \
\
		bli_tswapris( chx,chy, \
		              real( x ), imag( x ), \
		              real( y ), imag( y ) ); \
\
		INFO( "x (C++):  " << x0 ); \
		INFO( "y (C++):  " << y0 ); \
		INFO( "x (BLIS): " << x ); \
		INFO( "y (BLIS): " << y ); \
\
		check<ctypex>( x, x0 ); \
		check<ctypey>( y, y0 ); \
	} \
)

INSERT_GENTFUNC_MIX2( RC, RC, swapris )
